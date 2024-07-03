//
// Created by Matt on 2/07/2024.
//
#include "Game.h"
#include <iostream>


Game::Game() {

    SetMenu<MainMenu>();

    m_running = true;
}


void Game::Clean(){
        //    UnloadMusicStream(themeMusic);
};
void Game::Render() {
    if (m_Menu) {
        m_Menu->Render();
    } else {
        player.Render();
    }
}
void Game::Update() {
    if (m_Menu) {
        m_Menu->Update();
    } else {
        player.Update();
    }
    if (WindowShouldClose())
        Quit();
    if (IsKeyDown(KEY_ESCAPE)) {
        SetMenu<MainMenu>();
    }
}
void Game::Quit() {
    m_running = false;
}
void Game::Play() {
    m_Menu = nullptr;
    //    PauseMusicStream(themeMusic);
    player.Init();
}
