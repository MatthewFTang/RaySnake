//
// Created by Matt on 2/07/2024.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "Menu/MainMenu.h"
#include "Menu/Menu.h"
#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"
#include "src/Objects/Player.h"
#include <memory>
class Game {
public:
    Game();
    ~Game() = default;


    void Clean();
    void Render();
    void Update();
    void Play();
    void Quit();
    [[nodiscard]] bool GetRunning() const { return m_running; }

    template<typename T>
    void SetMenu() {
        m_Menu = std::make_shared<T>(*this);
    }


private:
    bool m_running;
    Player player;
    //    Music themeMusic;

    std::shared_ptr<Menu> m_Menu;
};


#endif//SNAKE_GAME_H
