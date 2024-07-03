//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_ABOUTMENU_H
#define RAYSNAKE_ABOUTMENU_H

#include "Menu.h"
class Game;
class AboutMenu : public Menu {
public:
    AboutMenu(Game &game);
    void Render() override;
    void Update() override;

private:
    Font fontSmalll;
    Font fontBig;
    Texture2D background;
    Game &m_game;

    Vector2 centerPos;

    Rectangle backgroundSrc;
    Rectangle backgroundDest;
};


#endif//RAYSNAKE_ABOUTMENU_H
