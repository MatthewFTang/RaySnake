#pragma once


#include <raylib.h>

#include "MainMenu.h"

class Game;

class DifficultlyMenu : public Menu {

public:
    void Render() override;
    void Update() override;
    explicit DifficultlyMenu(Game &game);


private:
    std::vector<const char *> options_ = {"Easy", "Medium", "Hard"};
    int num_options_ = (int) options_.size();
    KeyboardKey last_key_;
    int current_selection_;
    bool key_up_ = true;
    double start_time_;

    Game &game_;

    static int PositiveModulo(int selection, int options);
};
