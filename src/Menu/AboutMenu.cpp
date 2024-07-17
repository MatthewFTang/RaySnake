//
// Created by Matt on 3/07/2024.
//

#include "AboutMenu.h"

#include "MainMenu.h"
#include "src/Core/Game.h"
#include "src/Managers/FontManger.h"
#include "src/Managers/TextureManger.h"

AboutMenu::AboutMenu(Game &game) : game_(game) {
    TextureManger::Instance()->LoadText("src/resources/art/HelpMenu.png", texture_id_);
}
void AboutMenu::Render() {
    TextureManger::Instance()->DrawImage(texture_id_);

    FontManger::Instance()->RenderText("Help me!", 62, ORANGE, GetRenderWidth() / 2, 50, true);

    FontManger::Instance()->RenderText("Use the arrow keys or WASD to control the direction of the bird",
                                       32, ORANGE, GetRenderWidth() / 2, 250, true);
    FontManger::Instance()->RenderText("Eat the fruit to make the flock grow longer.",
                                       32, ORANGE, GetRenderWidth() / 2, 300, true);
    FontManger::Instance()->RenderText("Avoid hitting the walls or yourself.",
                                       32, ORANGE, GetRenderWidth() / 2, 350, true);
    FontManger::Instance()->RenderText("The difficulty controls the speed of the bird.",
                                       32, ORANGE, GetRenderWidth() / 2, 400, true);
    FontManger::Instance()->RenderText("Sound effects from  Zapsplat.com",
                                       32, ORANGE, GetRenderWidth() / 2, 550, true);
    FontManger::Instance()->RenderText("Sprites from Pixel Adventures 1",
                                       32, ORANGE, GetRenderWidth() / 2, 600, true);
    FontManger::Instance()
            ->RenderText("Press SPACE BAR to return to main menu",
                         32, ORANGE, GetRenderWidth() / 2, GetRenderHeight() - 100, true);

}
void AboutMenu::Update() {
    if (IsKeyDown(KEY_SPACE)) {
        game_.SetMenu<MainMenu>();
    }
}