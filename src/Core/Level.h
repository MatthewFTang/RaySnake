//
// Created by Matt on 15/07/2024.
//

#pragma once

#include <vector>

#include "GameDifficulty.h"
#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"
//#include "src/Game.h"
#include "src/Objects/Food.h"
#include "src/Objects/Player.h"

class GameObject;


class Level {

public:
    Level(GameDifficulty difficulty);
    ~Level() = default;
    void Render();
    void Update();
    void Clean();

    void Reset();


private:
    void
    CheckCollision();

    void AddFruit();
    void AddPlayer();
    void DrawBackground() const;
    void ShowScore() const;

    bool playing_;
    float x_min_ = 20.0f;
    float y_min_ = 20.0f;
    float x_max_ = 200.0f;
    float y_max_ = 40.0f;
    float background_size_ = 50.0f;
    float border_size_ = 10.0f;
    float x_actual_max_;
    float y_actual_max_;
    int n_cols_tiles_;
    int n_rows_tiles_;
    int high_score_ = 0;
    double start_time_;
    double current_time_;
    Player *player_{};
    Food *fruit_{};

    GameDifficulty difficulty_;

    int score_;
    Sound eat_sound_{};

    void NewFruit();
};
