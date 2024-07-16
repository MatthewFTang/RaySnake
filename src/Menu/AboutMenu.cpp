//
// Created by Matt on 3/07/2024.
//

#include "AboutMenu.h"

#include "src/Game.h"
#include "src/Managers/FontManger.h"
#include "src/Managers/TextureManger.h"
#include "src/Menu/MainMenu.h"

AboutMenu::AboutMenu(Game &game) : game_(game) {


    texture_id_ = "aboutMenu";
    TextureManger::Instance()->LoadText("res/art/HelpMenu.png", texture_id_);
}
void AboutMenu::Render() {
    TextureManger::Instance()->DrawImage(texture_id_);

    FontManger::Instance()->RenderText("Help me!", 62, WHITE, GetRenderWidth() / 2, 50, true);

    FontManger::Instance()->RenderText("Sound effects from  Zapsplat.com", 32, WHITE, GetRenderWidth() / 2, 250, true);

    FontManger::Instance()
            ->RenderText("Press SPACE BAR to return to main menu", 32, WHITE, GetRenderWidth() / 2, GetRenderHeight() - 100, true);
}
void AboutMenu::Update() {
    if (IsKeyDown(KEY_SPACE)) {
        game_.SetMenu<MainMenu>();
    }
}