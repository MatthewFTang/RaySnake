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
    std::vector<const char *> m_Options = {"Play", "Help", "Exit"};
    int m_NumOptions = (int) m_Options.size();

    Game &m_game;
    KeyboardKey lastKey;
    int m_currentSelection;
    bool keyUp = true;
    std::string imageID;
    int positiveModulo(int i, int n);
};


#endif//RAYSNAKE_MAINMENU_H
