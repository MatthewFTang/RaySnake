//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_ABOUTMENU_H
#define RAYSNAKE_ABOUTMENU_H

#include <string>

#include "Menu.h"
class Game;
class AboutMenu : public Menu {
public:
    explicit AboutMenu(Game &game);
    void Render() override;
    void Update() override;

private:
    Game &game_;
    std::string texture_id_;
};


#endif//RAYSNAKE_ABOUTMENU_H
