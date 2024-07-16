//
// Created by Matt on 15/07/2024.
//

#ifndef RAYSNAKE__LEVEL_H_
#define RAYSNAKE__LEVEL_H_

#include <raylib.h>

#include <vector>

class GameObject;


class Level {

public:
    Level();
    void Render() const;
    void Update();
    void Clean();

private:
    void CheckCollision();

    void AddFruit();
    void AddPlayer();
    void DrawBackground() const;
    void ShowScore() const;

    bool playing_;
    float x_min_ = 20.0f;
    float y_min_ = 20.0f;
    float x_max_ = 200.0f;
    float y_max_ = 30.0f;
    float background_size_ = 60.0f;
    float border_size_ = 10.0f;
    float x_actual_max_;
    float y_actual_max_;
    int n_cols_tiles_;
    int n_rows_tiles_;
    int n_cols_border_;
    int n_rows_border_;

    int score_;
    Sound eat_sound_;
    std::vector<GameObject *> game_objects_;
};


#endif//RAYSNAKE__LEVEL_H_
