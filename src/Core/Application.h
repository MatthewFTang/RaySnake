//
// Created by Matt on 2/07/2024.
//

#ifndef SNAKE_APPLICATION_H
#define SNAKE_APPLICATION_H

#include <raylib.h>

#include <memory>
#include <string>

#include "Game.h"

struct ApplicationParameters {
    std::string title = "RaySnake";
    bool full_screen = false;
    int width = 1000;
    int height = 800;
};

class Application {

public:
    static std::unique_ptr<Application> s_instance_;
    static Application *Instance() {
        if (!s_instance_) {
            s_instance_ = std::unique_ptr<Application>(new Application());
        }
        return s_instance_.get();
    }

    ~Application() = default;
    void Run();

private:
    Application() = default;

    void Initialise();
    void Render();
    void Update();
    void Loop();
    static void Clean();

    Color background_color_ = {
            249,
            123,
            154,
    };

    std::unique_ptr<Game> game_;
    const ApplicationParameters params_ = ApplicationParameters();
    double last_frame_time_ = 0.0;
};


#endif//SNAKE_APPLICATION_H
