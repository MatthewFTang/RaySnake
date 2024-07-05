//
// Created by Matt on 2/07/2024.
//

#include "Application.h"

#include <iostream>

static Application *m_instance = nullptr;
Application::Application() {
    m_instance = this;
}
Application::~Application() {

    m_instance = nullptr;
}
void Application::Run() {
    Initialise();
    Loop();
    Clean();
}
void Application::Initialise() {

    InitWindow(params.width, params.height, params.title.c_str());
    if (!IsAudioDeviceReady())
        InitAudioDevice();
    SetExitKey(KEY_NULL);
    if (params.fullScreen) {
        ToggleFullscreen();
    } else {
        int monitor = GetCurrentMonitor();
        int xPos = GetMonitorWidth(monitor) / 2 - params.width / 2;
        int yPos = GetMonitorHeight(monitor) / 2 - params.height / 2;
        SetWindowPosition(xPos, yPos);
    }

    SetTargetFPS(60);

    m_game = new Game();
}

void Application::Clean() {
    CloseWindow();
    UnloadMusicStream(themeMusic);
    CloseAudioDevice();
    m_game->Clean();
}
void Application::Loop() {

    while (m_game->GetRunning()) {
        if (GetTime() - m_lastFrameTime > 0.001) {
            Render();
            Update();
            m_lastFrameTime = GetTime();
        }
    }
}
void Application::Render() {
    BeginDrawing();
    ClearBackground(backgroundColor);
    m_game->Render();
    EndDrawing();
}

void Application::Update() {
    m_game->Update();
}
