//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_ABOUTMENU_H
#define RAYSNAKE_ABOUTMENU_H

#include <string>

#include "Menu.h"
class Game;
class AboutMenu : public Menu {
public:
    AboutMenu(Game &game);
    void Render() override;
    void Update() override;

private:
    Game &m_game;
    std::string textureID;
};


#endif//RAYSNAKE_ABOUTMENU_H
