//
// Created by Matt on 15/07/2024.
//

#include "Level.h"

#include <raylib.h>
#include <src/Objects/GameObject.h>

#include <iostream>

#include "src/BaseParams.h"
#include "src/Managers/FontManger.h"
#include "src/Managers/SoundManger.h"
#include "src/Managers/TextureManger.h"
#include "src/Objects/Food.h"
#include "src/Objects/Player.h"

Level::Level() {
    SoundManger::Instance()->LoadSounds("res/audio/short_bite.mp3", "bite");
    SoundManger::Instance()->LoadSounds("res/audio/esm_8_bit_game_over_1_arcade_80s_simple_alert_notification_game.mp3", "game_over");
    TextureManger::Instance()
            ->LoadText("res/assets/Brown.png", "background_tile");
    TextureManger::Instance()->LoadText("res/assets/Idle.png", "border_tile");


    float x_max_width = (float) GetRenderWidth() - x_max_;
    n_cols_tiles_ = (int) std::floor(x_max_width / background_size_);
    n_cols_border_ = (int) std::floor(x_max_width / border_size_);
    x_actual_max_ = (float) n_cols_tiles_ * background_size_;

    float y_max_height = (float) GetRenderHeight() - y_max_;
    n_rows_tiles_ = (int) std::floor(y_max_height / background_size_);
    n_rows_border_ = (int) std::floor(y_max_height / border_size_);
    y_actual_max_ = (float) n_rows_tiles_ * background_size_;


    playing_ = true;
    score_ = 0;
    AddFruit();
    AddPlayer();
}
void Level::Render() const {
    DrawBackground();
    ShowScore();

    for (auto const &kObj: game_objects_)
        kObj->Render();
    if (!playing_) {

        FontManger::Instance()->RenderText("Game over! \n Press Escape to go to main menu", 32, RED,
                                           (x_min_ + (x_actual_max_ - x_min_) / 2) - 200,
                                           (y_min_ + (y_actual_max_ - y_min_) / 2) - 50);
    }
}
void Level::Update() {
    if (playing_) {
        for (auto const &kObj: game_objects_) {
            kObj->Update();
        }
        CheckCollision();
    }
}
void Level::Clean() {
    UnloadSound(eat_sound_);
    game_objects_.clear();
}

void Level::CheckCollision() {

    Rectangle player_bounding_box;
    for (auto const &kObj: game_objects_) {

        if (kObj->GetGameObjectType() == "player") {
            player_bounding_box = kObj->GetBoundingBox();
            break;
        }
    }


    if (player_bounding_box.x < x_min_ || player_bounding_box.x > x_actual_max_ || player_bounding_box.y < y_min_ || player_bounding_box.y > y_actual_max_) {
        playing_ = false;
        SoundManger::Instance()->Pause("background_music");
        SoundManger::Instance()->Play("game_over");
    }

    for (auto i = 0; i < game_objects_.size(); i++) {
        if (game_objects_[i]->GetGameObjectType() != "player") {
            Rectangle other_box = game_objects_[i]->GetBoundingBox();
            if (CheckCollisionRecs(player_bounding_box, other_box)) {
                SoundManger::Instance()->Play("bite");
                game_objects_.erase(game_objects_.begin() + i);
                AddFruit();
                score_++;
            }
        }
    }
}

void Level::AddPlayer() {
    PlayerInfo p;
    auto player_params = LoaderParams(p.file_path, p.x, p.y, p.sprite_width, p.sprite_height, "player", p.num_frames, p.animation_speed, p.dest_width, p.dest_height, p.items_per_row);
    game_objects_.push_back(new Player(player_params));
}

void Level::AddFruit() {
    FoodInfo p;
    p.x = GetRandomValue((int) x_min_, (int) x_actual_max_);
    p.y = GetRandomValue((int) y_min_, (int) y_actual_max_);

    auto food_params = LoaderParams(p.file_path, p.x, p.y, p.sprite_width, p.sprite_height, "food", p.num_frames, p.animation_speed, p.dest_width, p.dest_height, p.items_per_row);
    game_objects_.push_back(new Food(food_params));
}

void Level::ShowScore() const {

    std::string num_s = std::to_string(score_);
    std::string text = "Score \n" + num_s;
    FontManger::Instance()->RenderText(text.c_str(), 48, WHITE, GetRenderWidth() - 150, 50);
}

void Level::DrawBackground() const {

    for (int x = 0; x < n_cols_tiles_; x++) {
        for (int y = 0; y < n_rows_tiles_; y++) {
            float x1 = x_min_ + (float) x * background_size_;
            float y1 = y_min_ + (float) y * background_size_;
            TextureManger::Instance()->DrawImageWithSize("background_tile", x1, y1, background_size_, background_size_);
        }
    }

    float x1 = x_min_;
    while (x1 < x_actual_max_ + border_size_ + 5) {
        TextureManger::Instance()->DrawImageWithSize("border_tile", x1 - 5, y_min_ - 5, 10, 10);
        TextureManger::Instance()->DrawImageWithSize("border_tile", x1 - 5, y_actual_max_ + 15, 10, 10);
        x1 += border_size_;
    }

    float y1 = y_min_;
    while (y1 < y_actual_max_ + border_size_ + 5) {
        TextureManger::Instance()->DrawImageWithSize("border_tile", x_min_ - 5, y1, 10, 10);
        TextureManger::Instance()->DrawImageWithSize("border_tile", x_actual_max_ + 10, y1, 10, 10);
        y1 += border_size_;
    }
}
