//
// Created by Matt on 2/07/2024.
//

#include "MainMenu.h"

#include "AboutMenu.h"
#include "Menu.h"
#include "src/Managers/FontManger.h"
#include "src/Managers/TextureManger.h"

void MainMenu::Render() {

    int x_pos = 145;
    TextureManger::Instance()->DrawImage(image_id_);
    FontManger::Instance()->RenderText("RaySnake!", 62, WHITE, x_pos, 100);
    FontManger::Instance()->RenderText("A new version by MFT", 48, WHITE, x_pos, 200);


    Color COL;
    for (auto i = 0; i < options_.size(); i++) {
        if (i == current_selection_) {
            COL = RED;
        } else
            COL = WHITE;

        FontManger::Instance()->RenderText(options_[i], 48, COL, x_pos, 550 + (i * 50));
    }
}
void MainMenu::Update() {
    if (key_up_) {
        if (IsKeyDown(KEY_DOWN)) {
            last_key_ = KEY_DOWN;
            key_up_ = false;

            current_selection_++;
        }

        else if (IsKeyDown(KEY_UP)) {
            last_key_ = KEY_UP;
            key_up_ = false;

            current_selection_--;
        } else if (IsKeyDown(KEY_ENTER)) {
            if (current_selection_ == 0) {
                game_.NewGame();
                game_.Play();
            } else if (current_selection_ == 1) {
                game_.SetMenu<AboutMenu>();
            } else if (current_selection_ == 2) {
                game_.Quit();
            }
        }
    } else {
        if (IsKeyReleased(last_key_)) {
            key_up_ = true;
        }
    }


    current_selection_ = PositiveModulo(current_selection_, num_options_);
}
MainMenu::MainMenu(Game &game) : game_(game) {

    current_selection_ = 0;
    image_id_ = "mainMenu";
    TextureManger::Instance()->LoadText("res/art/background2.png", image_id_);
}
int MainMenu::PositiveModulo(int i, int n) {
    return (i % n + n) % n;
}