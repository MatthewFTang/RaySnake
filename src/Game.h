//
// Created by Matt on 2/07/2024.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H


#include <raylib.h>

#include <memory>
#include <vector>

#include "Level.h"
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
    [[nodiscard]] bool GetRunning() const { return running_; }

    template<typename T>
    void SetMenu() {
        menu_ = std::make_shared<T>(*this);
    }
    void NewGame();


private:
    bool running_;
    Level level_;

    std::shared_ptr<Menu> menu_;
};


#endif//SNAKE_GAME_H
