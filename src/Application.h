//
// Created by Matt on 2/07/2024.
//

#ifndef SNAKE_APPLICATION_H
#define SNAKE_APPLICATION_H

#include "Game.h"
#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"
#include <string>
struct ApplicationParameters {
    std::string title = "RaySnake";
    bool fullScreen = false;
    int width = 1200;
    int height = 600;
};
class Application {

public:
    ~Application();
    Application();
    void Run();

private:
    void Initialise();
    void Render();
    void Update();
    void Loop();
    void Clean();
    Color backgroundColor = {
            249,
            123,
            54,
    };

    Game *m_game;
    const ApplicationParameters &params = ApplicationParameters();
    float m_lastFrameTime = 0.0f;
};


#endif//SNAKE_APPLICATION_H
