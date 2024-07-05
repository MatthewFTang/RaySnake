//
// Created by Matt on 2/07/2024.
//
#include "Game.h"

#include <iostream>

#include "BaseParams.h"
#include "LoaderParams.h"
#include "src/Graphics/FontManger.h"
#include "src/Graphics/TextureManger.h"
#include "src/Menu/MainMenu.h"
#include "src/Objects/Food.h"
#include "src/Objects/Player.h"

Game::Game() {

    SetMenu<MainMenu>();
    backgroundMusic = LoadMusicStream("res/audio/instrumental.mp3");
    themeMusic = LoadMusicStream("res/audio/Theme1.mp3");
    eatSound = LoadSound("res/audio/zapsplat_catoon_bite_munch_single_002_56564.mp3");
    NewGame();
}


void Game::Clean() const {
    for (auto const &obj: m_gameObjects)
        obj->Clean();
    TextureManger::Instance()->Clean();
    UnloadMusicStream(backgroundMusic);
    UnloadMusicStream(themeMusic);
};
void Game::Render() {
    if (m_Menu) {
        m_Menu->Render();
    } else {
        for (auto const &obj: m_gameObjects)
            obj->Render();
        ShowScore();
    }
}
void Game::Update() {
    if (m_Menu) {
        m_Menu->Update();
        UpdateMusicStream(themeMusic);
    } else {
        for (auto const &obj: m_gameObjects)
            obj->Update();
        UpdateMusicStream(backgroundMusic);
        checkCollision();
    }
    if (WindowShouldClose())
        Quit();
    if (IsKeyDown(KEY_ESCAPE)) {
        SetMenu<MainMenu>();
        PauseMusicStream(backgroundMusic);
        PlayMusicStream(themeMusic);
    }
}
void Game::Quit() {
    Clean();
    m_running = false;
}
void Game::Play() {
    m_Menu = nullptr;
    PauseMusicStream(themeMusic);
    PlayMusicStream(backgroundMusic);
}
void Game::NewGame() {
    PlayMusicStream(themeMusic);
    m_running = true;
    m_gameObjects.clear();

    AddPlayer();
    AddFruit();
    m_score = 0;
}

void Game::checkCollision() {

    Rectangle playerBoundingBox;
    for (auto const &obj: m_gameObjects) {
        if (obj->getGameObjectType() == "player") {
            playerBoundingBox = obj->getBoundingBox();
            break;
        }
    };

    for (auto i = 0; i < m_gameObjects.size(); i++) {
        if (m_gameObjects[i]->getGameObjectType() != "player") {
            Rectangle otherBox = m_gameObjects[i]->getBoundingBox();
            if (CheckCollisionRecs(playerBoundingBox, otherBox)) {
                PlaySound(eatSound);
                m_gameObjects.erase(m_gameObjects.begin() + i);
                AddFruit();
                m_score++;
            }
        }
    }
}
void Game::AddPlayer() {
    PlayerInfo p;
    auto playerParams = LoaderParams(p.filePath, p.x, p.y, p.SpriteWidth, p.SpriteHeight, "player", p.numFrames, p.animationSpeed, p.destWidth, p.destHeight, p.ItemsPerRow);
    m_gameObjects.push_back(new Player(playerParams));
}
void Game::AddFruit() {
    FoodInfo p;
    p.x = GetRandomValue(p.destWidth, GetRenderWidth() - p.destWidth);
    p.y = GetRandomValue(p.destHeight, GetRenderHeight() - p.destHeight);
    auto foodParams = LoaderParams(p.filePath, p.x, p.y, p.SpriteWidth, p.SpriteHeight, "food", p.numFrames, p.animationSpeed, p.destWidth, p.destHeight, p.ItemsPerRow);
    m_gameObjects.push_back(new Food(foodParams));
}
void Game::ShowScore() {
    char str[50];
    std::sprintf(str, "Score \n %d", m_score);
    FontManger::Instance()->renderText(str, 48, BLACK, GetRenderWidth() - 150 + 3, 50 + 3);
    FontManger::Instance()->renderText(str, 48, WHITE, GetRenderWidth() - 150, 50);
}
