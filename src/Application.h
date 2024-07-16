//
// Created by Matt on 2/07/2024.
//

#ifndef SNAKE_APPLICATION_H
#define SNAKE_APPLICATION_H

#include <raylib.h>

#include <string>

#include "Game.h"

struct ApplicationParameters {
    std::string title = "RaySnake";
    bool full_screen = false;
    int width = 1080;
    int height = 810;
};

class Application {

public:
    static Application *s_instance_;
    static Application *Instance() {
        if (s_instance_ == nullptr) {
            s_instance_ = new Application();
        }
        return s_instance_;
    }

    ~Application() = default;
    void Run();

private:
    Application() = default;

    void Initialise();
    void Render();
    void Update();
    void Loop();
    void Clean() const;

    Color background_color_ = {
            249,
            123,
            54,
    };

    Game *game_;
    const ApplicationParameters params_ = ApplicationParameters();
    double last_frame_time_ = 0.0;
};


#endif//SNAKE_APPLICATION_H
