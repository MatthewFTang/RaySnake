//
// Created by Matt on 2/07/2024.
//
#include "Game.h"
#include <iostream>

Game::Game() {
    m_MainMenu = MainMenu();
    m_menuState = true;
}


void Game::Clean(){};
void Game::Render() {
    if (m_menuState) {
        m_MainMenu.Render();
    }
}
void Game::Update() {
    if (m_menuState) {
        m_MainMenu.Update();
    }
}
