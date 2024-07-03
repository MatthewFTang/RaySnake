//
// Created by Matt on 2/07/2024.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "Menu/MainMenu.h"
#include <raylib.h>
class Game {
public:
    Game();
    ~Game() = default;


    void Clean();
    void Render();
    void Update();

private:
    MainMenu m_MainMenu;
    bool m_running;
    bool m_menuState = false;
};


#endif//SNAKE_GAME_H
