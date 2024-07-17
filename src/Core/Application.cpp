//
// Created by Matt on 2/07/2024.
//

#include "Application.h"

std::unique_ptr<Application> Application::s_instance_ = nullptr;

void Application::Run() {
    Initialise();
    Loop();
    Clean();
}
void Application::Initialise() {

    InitWindow(params_.width, params_.height, params_.title.c_str());
    if (!IsAudioDeviceReady())
        InitAudioDevice();
    SetExitKey(KEY_NULL);
    if (params_.full_screen) {
        ToggleFullscreen();
    } else {
        int monitor = GetCurrentMonitor();
        int x_pos = GetMonitorWidth(monitor) / 2 - params_.width / 2;
        int y_pos = GetMonitorHeight(monitor) / 2 - params_.height / 2;
        SetWindowPosition(x_pos, y_pos);
    }

    SetTargetFPS(60);

    game_ = new Game();
}


void Application::Loop() {

    while (game_->GetRunning()) {
        if (GetTime() - last_frame_time_ > 0.001) {
            Render();
            Update();
            last_frame_time_ = GetTime();
        }
    }
}
void Application::Clean() {
    CloseWindow();
    CloseAudioDevice();
    if (game_) {
        Game::Clean();
        delete game_;
        game_ = nullptr;
    }
    Game::Clean();
}
void Application::Render() {
    BeginDrawing();
    ClearBackground(background_color_);
    game_->Render();
    EndDrawing();
}

void Application::Update() {
    game_->Update();
}
