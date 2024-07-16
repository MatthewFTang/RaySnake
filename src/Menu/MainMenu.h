//
// Created by Matt on 2/07/2024.
//

#ifndef RAYSNAKE_MAINMENU_H
#define RAYSNAKE_MAINMENU_H


#include <vector>

#include "Menu.h"
#include "src/Game.h"

class Game;
class MainMenu : public Menu {
public:
    void Render() override;
    void Update() override;
    explicit MainMenu(Game &game);

private:
    std::vector<const char *> options_ = {"Play", "About", "Exit"};
    int num_options_ = (int) options_.size();

    Game &game_;
    KeyboardKey last_key_;
    int current_selection_;
    bool key_up_ = true;
    std::string image_id_;
    
    static int PositiveModulo(int i, int n);
};


#endif//RAYSNAKE_MAINMENU_H
