//
// Created by Matt on 2/07/2024.
//

#include "MainMenu.h"

#include <iostream>
void MainMenu::Render() {
    DrawTexturePro(backgroundTex, backgroundSrc, backgroundDest, Vector2({0, 0}), 0, RAYWHITE);
    DrawTextEx(font, "RaySnake!", Vector2({100 + 2, 100 + 2}), 32, 1, BLACK);
    DrawTextEx(font, "RaySnake!", Vector2({100, 100}), 32, 1, WHITE);

    DrawTextEx(font, "A new version by MFT", Vector2({100 + 2, 150 + 2}), 32, 1, BLACK);
    DrawTextEx(font, "A new version by MFT", Vector2({100, 150}), 32, 1, WHITE);

    Color COL;
    for (size_t i = 0; i < m_Options.size(); i++) {
        if (i == m_currentSelection) {
            COL = WHITE;
        } else
            COL = RED;
        Vector2 pos = Vector2{100, 400 + ((float) i * 50)};
        DrawTextEx(font, m_Options[i], pos, 32, 1, COL);
    }
}
void MainMenu::Update() {
    if (keyUp) {
        if (IsKeyDown(KEY_DOWN)) {
            lastKey = KEY_DOWN;
            keyUp = false;

            m_currentSelection++;
        }

        if (IsKeyDown(KEY_UP)) {
            lastKey = KEY_UP;
            keyUp = false;

            m_currentSelection--;
        }
        if (IsKeyDown(KEY_ENTER)) {
        }
    } else {
        if (IsKeyReleased(lastKey)) {
            keyUp = true;
        }
    }


    m_currentSelection = m_currentSelection % m_NumOptions;
}
MainMenu::MainMenu() {


    font = LoadFontEx("res/fonts/Lato-Bold.ttf", 32, nullptr, 0);
    m_currentSelection = 0;
    backgroundTex = LoadTexture("res/art/background2.png");
    backgroundSrc.height = backgroundTex.height;
    backgroundSrc.width = backgroundTex.width;
    backgroundSrc.y = backgroundDest.y = 0;
    backgroundSrc.x = backgroundDest.x = 0;
    backgroundDest.width = GetRenderWidth();
    backgroundDest.height = GetRenderHeight();
}
