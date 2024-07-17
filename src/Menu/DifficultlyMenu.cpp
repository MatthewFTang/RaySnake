

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
bool DifficultlyMenu::CheckTime() const {
    double current_time = GetTime();
    if ((current_time - start_time_ > 0.1) && (current_time - last_key_press_time_ > 0.1))
        return true;
    else
        return false;
}
void DifficultlyMenu::Update() {

    if (CheckTime()) {

        if (IsKeyDown(KEY_DOWN)) {
            last_key_press_time_ = GetTime();
            current_selection_++;
        } else if (IsKeyDown(KEY_UP)) {
            last_key_press_time_ = GetTime();
            current_selection_--;
        } else if (IsKeyDown(KEY_ENTER)) {
            using enum GameDifficulty;
            GameDifficulty difficulty;
            if (current_selection_ == 0) {
                difficulty = EASY;
            } else if (current_selection_ == 1) {
                difficulty = MEDIUM;
            } else {
                difficulty = HARD;
            }
            game_.NewGame(difficulty);
            game_.Play();
        }
    }


    current_selection_ = PositiveModulo(current_selection_, num_options_);
}
int DifficultlyMenu::PositiveModulo(int i, int n) {
    return (i % n + n) % n;
}
DifficultlyMenu::DifficultlyMenu(Game &game) : game_(game) {
    start_time_ = GetTime();
}
