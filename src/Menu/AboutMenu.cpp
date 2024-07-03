//
// Created by Matt on 3/07/2024.
//

#include "AboutMenu.h"
#include "src/Game.h"
AboutMenu::AboutMenu(Game &game) : m_game(game) {
    fontSmalll = LoadFontEx("res/fonts/Lato-Bold.ttf", 32, nullptr, 0);
    fontBig = LoadFontEx("res/fonts/Lato-Bold.ttf", 48, nullptr, 0);

    background = LoadTexture("res/art/HelpMenu.png");

    backgroundSrc.height = (float) background.height;
    backgroundSrc.width = (float) background.width;
    backgroundSrc.y = backgroundDest.y = 0;
    backgroundSrc.x = backgroundDest.x = 0;
    backgroundDest.width = (float) GetRenderWidth();
    backgroundDest.height = (float) GetRenderHeight();

    centerPos.x = (float) GetRenderWidth() / 2.0f;
    centerPos.y = (float) GetRenderHeight() / 2.0f;
}
void AboutMenu::Render() {
    DrawTexturePro(background, backgroundSrc, backgroundDest, Vector2({0, 0}), 0, RAYWHITE);
    DrawTextEx(fontBig, "Help me!", Vector2({centerPos.x - 100, 50}), 48, 1, BLACK);

    DrawTextEx(fontSmalll, "Press SPACE to return to the main menu", Vector2{50, centerPos.y + 200}, 32, 1, BLACK);
}
void AboutMenu::Update() {
    if (IsKeyDown(KEY_SPACE)) {
        m_game.SetMenu<MainMenu>();
    }
}