//
// Created by Matt on 2/07/2024.
//

#ifndef SNAKE_APPLICATION_H
#define SNAKE_APPLICATION_H

#include <string>

#include "Game.h"
#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"
struct ApplicationParameters {
    std::string title = "RaySnake";
    bool fullScreen = false;
    int width = 1080;
    int height = 810;
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
    const ApplicationParameters params = ApplicationParameters();
    double m_lastFrameTime = 0.0;
    Music themeMusic;
};


#endif//SNAKE_APPLICATION_H
