//
// Created by Matt on 2/07/2024.
//

#ifndef RAYSNAKE_MAINMENU_H
#define RAYSNAKE_MAINMENU_H


#include "Menu.h"
#include <vector>
class MainMenu : public Menu {
public:
    void Render() override;
    void Update() override;
    MainMenu();

private:
    std::vector<const char *> m_Options = {"Play", "About", "Exit"};
    int m_NumOptions = (int) m_Options.size();

    Font font;
    Texture2D backgroundTex;
    Rectangle backgroundSrc;
    Rectangle backgroundDest;
    KeyboardKey lastKey;
    int m_currentSelection;
    bool keyUp = true;
};


#endif//RAYSNAKE_MAINMENU_H
