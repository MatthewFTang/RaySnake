//
// Created by Matt on 2/07/2024.
//

#pragma once

#include <raylib.h>

#include <memory>
#include <vector>

#include "Level.h"
#include "include/GameObject.h"
#include "include/Menu.h"

class Game {
public:
    Game();
    ~Game() = default;

    static void Clean();
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
