//
// Created by Matt on 2/07/2024.
//

#include "MainMenu.h"

#include "AboutMenu.h"
#include "Menu.h"
#include "src/Graphics/FontManger.h"
#include "src/Graphics/TextureManger.h"

void MainMenu::Render() {
    int shadowOffset = 3;
    int yPos = 145;
    TextureManger::Instance()->drawImage(imageID);
    FontManger::Instance()->renderText("RaySnake!", 62, BLACK, yPos + shadowOffset, 100 + shadowOffset);
    FontManger::Instance()->renderText("RaySnake!", 62, WHITE, yPos, 100);
    FontManger::Instance()->renderText("A new version by MFT", 48, BLACK, yPos + shadowOffset, 200 + shadowOffset);
    FontManger::Instance()->renderText("A new version by MFT", 48, WHITE, yPos, 200);


    Color COL;
    for (auto i = 0; i < m_Options.size(); i++) {
        if (i == m_currentSelection) {
            COL = RED;
        } else
            COL = WHITE;
        FontManger::Instance()->renderText(m_Options[i], 48, BLACK, yPos + shadowOffset, 430 + shadowOffset + (i * 50));

        FontManger::Instance()->renderText(m_Options[i], 48, COL, yPos, 430 + (i * 50));
    }
}
void MainMenu::Update() {
    if (keyUp) {
        if (IsKeyDown(KEY_DOWN)) {
            lastKey = KEY_DOWN;
            keyUp = false;

            m_currentSelection++;
        }

        else if (IsKeyDown(KEY_UP)) {
            lastKey = KEY_UP;
            keyUp = false;

            m_currentSelection--;
        } else if (IsKeyDown(KEY_ENTER)) {
            if (m_currentSelection == 0) {
                m_game.NewGame();
                m_game.Play();
            } else if (m_currentSelection == 1) {
                m_game.SetMenu<AboutMenu>();
            } else if (m_currentSelection == 2) {
                m_game.Quit();
            }
        }
    } else {
        if (IsKeyReleased(lastKey)) {
            keyUp = true;
        }
    }


    m_currentSelection = positiveModulo(m_currentSelection, m_NumOptions);
}
MainMenu::MainMenu(Game &game) : m_game(game) {

    m_currentSelection = 0;
    imageID = "mainMenu";
    TextureManger::Instance()->loadTexture("res/art/background2.png", imageID);
}
int MainMenu::positiveModulo(int i, int n) {
    return (i % n + n) % n;
}