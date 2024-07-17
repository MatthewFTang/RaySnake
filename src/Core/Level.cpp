//
// Created by Matt on 15/07/2024.
//

#include "Level.h"

#include <raylib.h>

#include <iomanip>
#include <iostream>
#include <sstream>

#include "BaseParams.h"
#include "src/Managers/FontManger.h"
#include "src/Managers/SoundManger.h"
#include "src/Managers/TextureManger.h"
#include "src/Objects/Food.h"
#include "src/Objects/GameObject.h"
#include "src/Objects/Player.h"

Level::Level(GameDifficulty difficulty) {
    SoundManger::Instance()->LoadSounds("src/resources/audio/short_bite.mp3", "bite");
    SoundManger::Instance()->LoadSounds("src/resources/audio/esm_8_bit_game_over_1_arcade_80s_simple_alert_notification_game.mp3", "game_over");
    TextureManger::Instance()
            ->LoadText("src/resources/assets/Brown.png", "background_tile");


    float x_max_width = (float) GetRenderWidth() - x_max_;
    n_cols_tiles_ = (int) std::floor(x_max_width / background_size_);
    x_actual_max_ = x_min_ + (float) n_cols_tiles_ * background_size_;

    float y_max_height = (float) GetRenderHeight() - y_max_;
    n_rows_tiles_ = (int) std::floor(y_max_height / background_size_);
    y_actual_max_ = y_min_ + (float) n_rows_tiles_ * background_size_;
    difficulty_ = difficulty;
    Reset();
}
void Level::Reset() {
    AddPlayer();
    AddFruit();
    SoundManger::Instance()->Play("background_music");

    playing_ = true;
    score_ = 0;
    start_time_ = GetTime();
}

void Level::Render() {
    DrawBackground();
    ShowScore();
    if (playing_) {
        player_->Render();
        fruit_->Render();
    }

    if (!playing_) {

        FontManger::Instance()->RenderText("Game over!", 48, RED,
                                           (x_min_ + (x_actual_max_ - x_min_) / 2),
                                           (y_min_ + (y_actual_max_ - y_min_) / 2 - 150), true);
        FontManger::Instance()->RenderText("Press R to restart ", 32, RED,
                                           (x_min_ + (x_actual_max_ - x_min_) / 2),
                                           (y_min_ + (y_actual_max_ - y_min_) / 2), true);
        FontManger::Instance()->RenderText("Press ESCAPE to go to main menu", 32, RED,
                                           (x_min_ + (x_actual_max_ - x_min_) / 2),
                                           (y_min_ + (y_actual_max_ - y_min_) / 2 + 50), true);
        if (IsKeyDown(KEY_R)) {
            Reset();
        }
    }
}
void Level::Update() {
    if (playing_) {
        player_->Update();
        fruit_->Update();
        CheckCollision();

        current_time_ = GetTime() - start_time_;
    }
    if (score_ > high_score_) {
        high_score_ = score_;
    }
}
void Level::Clean() {
}

void Level::CheckCollision() {

    Rectangle player_bounding_box = player_->GetBoundingBox();

    if (player_->HitTail() || player_bounding_box.x < x_min_ || player_bounding_box.x > x_actual_max_ || player_bounding_box.y < y_min_ || player_bounding_box.y > y_actual_max_) {
        playing_ = false;
        SoundManger::Instance()->Play("game_over");
        SoundManger::Instance()->Pause("background_music");
    }
    Rectangle fruit_box = fruit_->GetBoundingBox();
    player_bounding_box.x += 5;
    player_bounding_box.y += 5;
    player_bounding_box.width -= 10;
    player_bounding_box.height -= 10;

    if (CheckCollisionRecs(player_bounding_box, fruit_box)) {
        SoundManger::Instance()->Play("bite");
        AddFruit();
        player_->IncrementTail();
        score_++;
    }
}

void Level::AddPlayer() {
    PlayerInfo p;
    auto player_params = LoaderParams(p.file_path, p.x, p.y, p.sprite_width, p.sprite_height, "player", p.num_frames, p.animation_speed, p.dest_width, p.dest_height, p.items_per_row);
    player_ = std::make_unique<Player>(player_params);
    if (difficulty_ == GameDifficulty::EASY) {
        player_->SetMovementSpeed(2.0f);
    } else if (difficulty_ == GameDifficulty::MEDIUM) {
        player_->SetMovementSpeed(4.0f);
    } else
        player_->SetMovementSpeed(8.0f);
    player_->NewGame();
}

void Level::AddFruit() {
    FoodInfo p;

    auto new_loc = player_->NewFruitLocation((int) (x_actual_max_ - x_min_) - 20, (int) (y_actual_max_ - y_min_) - 20);
    p.x = 10 + (int) (x_min_ + new_loc.x);
    p.y = 10 + (int) (y_min_ + new_loc.y);

    auto food_params = LoaderParams(p.file_path, p.x, p.y, p.sprite_width, p.sprite_height, "food", p.num_frames, p.animation_speed, p.dest_width, p.dest_height, p.items_per_row);
    fruit_ = std::make_unique<Food>(food_params);
}


void Level::ShowScore() const {

    std::string num_s = std::to_string(score_);
    std::string text = "Score \n" + num_s;
    FontManger::Instance()->RenderText(text.c_str(), 48, WHITE, GetRenderWidth() - 150, 50);

    num_s = std::to_string(high_score_);
    text = "High \nscore \n" + num_s;
    FontManger::Instance()->RenderText(text.c_str(), 48, WHITE, GetRenderWidth() - 150, 250);

    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << current_time_;
    num_s = stream.str();

    text = "Time \n" + num_s;
    FontManger::Instance()->RenderText(text.c_str(), 48, WHITE, GetRenderWidth() - 150, 650);
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
