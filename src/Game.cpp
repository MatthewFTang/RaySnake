//
// Created by Matt on 2/07/2024.
//
#include "Game.h"

#include "src/Managers/SoundManger.h"
#include "src/Managers/TextureManger.h"
#include "src/Menu/MainMenu.h"
#include "src/Objects/Food.h"


Game::Game() {

    SetMenu<MainMenu>();
    SoundManger::Instance()->LoadMusic("res/audio/instrumental.mp3", "background_music");
    SoundManger::Instance()->LoadMusic("res/audio/Theme1.mp3", "theme_music");

    NewGame();
    running_ = true;
}


void Game::Clean() const {
    TextureManger::Instance()->CleanAll();
};
void Game::Render() {
    if (menu_) {
        menu_->Render();
    } else {
        level_.Render();
    }
    SoundManger::Instance()->Render();
}
void Game::Update() {
    if (menu_) {
        menu_->Update();
    } else {
        level_.Update();
    }
    if (WindowShouldClose())
        Quit();
    if (IsKeyDown(KEY_ESCAPE)) {
        SetMenu<MainMenu>();
        SoundManger::Instance()->Pause("background_music");
        SoundManger::Instance()->Play("theme_music");
    }
}
void Game::Quit() {
    Clean();
    running_ = false;
}
void Game::Play() {
    menu_ = nullptr;
    SoundManger::Instance()->Pause("theme_music");
    SoundManger::Instance()->Play("background_music");
}
void Game::NewGame() {
    SoundManger::Instance()->Play("theme_music");
    level_ = Level();
}
