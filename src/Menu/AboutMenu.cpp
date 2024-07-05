//
// Created by Matt on 3/07/2024.
//

#include "AboutMenu.h"

#include "src/Game.h"
#include "src/Graphics/FontManger.h"
#include "src/Graphics/TextureManger.h"
#include "src/Menu/MainMenu.h"

AboutMenu::AboutMenu(Game &game) : m_game(game) {


    textureID = "aboutMenu";
    TextureManger::Instance()->loadTexture("res/art/HelpMenu.png", textureID);
}
void AboutMenu::Render() {
    TextureManger::Instance()->drawImage(textureID);
    FontManger::Instance()->renderText("Help me!", 62, BLACK, GetRenderWidth() / 2 - 100, 50);
    FontManger::Instance()->renderText("Press SPACE BAR to return to main menu", 32, BLACK, 50, GetRenderHeight() / 2 + 200);
}
void AboutMenu::Update() {
    if (IsKeyDown(KEY_SPACE)) {
        m_game.SetMenu<MainMenu>();
    }
}