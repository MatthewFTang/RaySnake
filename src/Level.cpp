//
// Created by Matt on 15/07/2024.
//

#include "include/Level.h"

#include <raylib.h>

#include <iostream>

#include "include/BaseParams.h"
#include "include/FontManger.h"
#include "include/Food.h"
#include "include/GameObject.h"
#include "include/Player.h"
#include "include/SoundManger.h"
#include "include/TextureManger.h"

Level::Level() {
    SoundManger::Instance()->LoadSounds("res/audio/short_bite.mp3", "bite");
    SoundManger::Instance()->LoadSounds("res/audio/esm_8_bit_game_over_1_arcade_80s_simple_alert_notification_game.mp3", "game_over");
    TextureManger::Instance()
            ->LoadText("res/assets/Brown.png", "background_tile");


    float x_max_width = (float) GetRenderWidth() - x_max_;
    n_cols_tiles_ = (int) std::floor(x_max_width / background_size_);
    x_actual_max_ = x_min_ + (float) n_cols_tiles_ * background_size_;

    float y_max_height = (float) GetRenderHeight() - y_max_;
    n_rows_tiles_ = (int) std::floor(y_max_height / background_size_);
    y_actual_max_ = y_min_ + (float) n_rows_tiles_ * background_size_;

    AddPlayer();
    AddFruit();

    playing_ = true;
    score_ = 0;
}
void Level::Render() const {
    DrawBackground();
    ShowScore();
    if (playing_) {
        player_->Render();
        fruit_->Render();
    }

    if (!playing_) {

        FontManger::Instance()->RenderText("Game over!", 48, RED,
                                           (x_min_ + (x_actual_max_ - x_min_) / 2),
                                           (y_min_ + (y_actual_max_ - y_min_) / 2 - 50), true);

        FontManger::Instance()->RenderText("Press ESCAPE to go to main menu", 32, RED,
                                           (x_min_ + (x_actual_max_ - x_min_) / 2),
                                           (y_min_ + (y_actual_max_ - y_min_) / 2 + 50), true);
    }
}
void Level::Update() {
    if (playing_) {
        player_->Update();
        fruit_->Update();
        CheckCollision();
    }
    //    Clean();
}
void Level::Clean() {
    delete player_;
    delete fruit_;
}

void Level::CheckCollision() {

    Rectangle player_bounding_box = player_->GetBoundingBox();

    if (player_->HitTail() || player_bounding_box.x < x_min_ || player_bounding_box.x > x_actual_max_ || player_bounding_box.y < y_min_ || player_bounding_box.y > y_actual_max_) {
        playing_ = false;
        SoundManger::Instance()->Pause("background_music");
        SoundManger::Instance()->Play("game_over");
    }
    Rectangle fruit_box = fruit_->GetBoundingBox();
    player_bounding_box.x += 5;
    player_bounding_box.y += 5;
    player_bounding_box.width -= 10;
    player_bounding_box.height -= 10;

    if (CheckCollisionRecs(player_bounding_box, fruit_box)) {
        SoundManger::Instance()->Play("bite");
        NewFruit();
        player_->IncrementTail();
        score_++;
    }
}

void Level::AddPlayer() {
    PlayerInfo p;
    auto player_params = LoaderParams(p.file_path, p.x, p.y, p.sprite_width, p.sprite_height, "player", p.num_frames, p.animation_speed, p.dest_width, p.dest_height, p.items_per_row);
    player_ = new Player(player_params);
    player_->NewGame();
}

void Level::AddFruit() {
    FoodInfo p;

    auto new_loc = player_->NewFruitLocation((int) (x_actual_max_ - x_min_) - 20, (int) (y_actual_max_ - y_min_) - 20);
    p.x = 10 + (int) (x_min_ + new_loc.x);
    p.y = 10 + (int) (y_min_ + new_loc.y);

    auto food_params = LoaderParams(p.file_path, p.x, p.y, p.sprite_width, p.sprite_height, "food", p.num_frames, p.animation_speed, p.dest_width, p.dest_height, p.items_per_row);
    fruit_ = new Food(food_params);
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
    DrawLineEx({x_min_, y_min_}, {x_actual_max_, y_min_}, 4, BLACK);
    DrawLineEx({x_min_, y_actual_max_}, {x_actual_max_, y_actual_max_}, 4, BLACK);
    DrawLineEx({x_min_, y_min_}, {x_min_, y_actual_max_}, 4, BLACK);
    DrawLineEx({x_actual_max_, y_min_}, {x_actual_max_, y_actual_max_}, 4, BLACK);
}
void Level::NewFruit() {
    delete fruit_;
    AddFruit();
}
