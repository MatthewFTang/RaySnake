//
// Created by Matt on 2/07/2024.
//
#include "include/Game.h"

#include "include/Food.h"
#include "include/MainMenu.h"
#include "include/SoundManger.h"
#include "include/TextureManger.h"


Game::Game() {

    SetMenu<MainMenu>();
    SoundManger::Instance()->LoadMusic("res/audio/instrumental.mp3", "background_music");
    SoundManger::Instance()->LoadMusic("res/audio/Theme1.mp3", "theme_music");
}


void Game::Clean() {
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
    NewGame();
    running_ = true;
    SoundManger::Instance()->Pause("theme_music");
    SoundManger::Instance()->Play("background_music");
}
void Game::NewGame() {
    SoundManger::Instance()->Play("theme_music");
    level_ = Level();
}
