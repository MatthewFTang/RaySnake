#pragma once

#include "DifficultlyMenu.h"

#include "src/Managers/FontManger.h"
#include "src/Managers/TextureManger.h"

void DifficultlyMenu::Render() {
    TextureManger::Instance()->DrawImage("mainMenu");

    Color col;
    int x_pos = GetRenderWidth() / 2;
    int y_pos = GetRenderHeight() / 2 - 100;
    for (auto i = 0; i < options_.size(); i++) {
        if (i == current_selection_) {
            col = RED;
        } else
            col = WHITE;

        FontManger::Instance()->RenderText(options_[i], 48, col, x_pos, y_pos + (i * 50), true);
    }
}
void DifficultlyMenu::Update() {

    if (GetTime() - start_time_ < 0.2) {
        return;
    }
    if (key_up_) {
        if (IsKeyDown(KEY_DOWN)) {
            last_key_ = KEY_DOWN;
            key_up_ = false;
            current_selection_++;
        }

        else if (IsKeyDown(KEY_UP)) {
            last_key_ = KEY_UP;
            key_up_ = false;
            current_selection_--;
        } else if (IsKeyDown(KEY_ENTER)) {
            GameDifficulty difficulty;
            if (current_selection_ == 0) {
                difficulty = GameDifficulty::EASY;
            } else if (current_selection_ == 1) {
                difficulty = GameDifficulty::MEDIUM;
            } else {
                difficulty = GameDifficulty::HARD;
            }
            game_.NewGame(difficulty);

            game_.Play();
        }
    } else {
        if (IsKeyReleased(last_key_)) {
            key_up_ = true;
        }
    }


    current_selection_ = PositiveModulo(current_selection_, num_options_);
}
int DifficultlyMenu::PositiveModulo(int i, int n) {
    return (i % n + n) % n;
}
DifficultlyMenu::DifficultlyMenu(Game &game) : game_(game) {

    current_selection_ = 0;
    key_up_ = true;
    last_key_ = KEY_DOWN;
    start_time_ = GetTime();
}
