//
// Created by Matt on 2/07/2024.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H


#include <raylib.h>

#include <memory>
#include <vector>

#include "Menu/Menu.h"
#include "src/Objects/GameObject.h"

class Game {
public:
    Game();
    ~Game() = default;


    void Clean() const;
    void Render();
    void Update();
    void Play();
    void Quit();
    [[nodiscard]] bool GetRunning() const { return m_running; }

    template<typename T>
    void SetMenu() {
        m_Menu = std::make_shared<T>(*this);
    }
    void NewGame();


private:
    void checkCollision();
    bool m_running;
    int m_score;

    std::shared_ptr<Menu> m_Menu;
    Music backgroundMusic{};
    Music themeMusic{};
    Sound eatSound;
    std::vector<GameObject *> m_gameObjects;
    void AddFruit();
    void AddPlayer();
    void ShowScore();
};


#endif//SNAKE_GAME_H
