//
// Created by Matt on 3/07/2024.
//

#pragma once
#include <iostream>
#include <vector>

#include "GameObject.h"
#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"

class Player : public GameObject {
public:
    using GameObject::GameObject;
    std::string GetGameObjectType() override { return "player"; }
    void Update() override;
    void Render() override;
    void NewGame();
    [[nodiscard]] bool HitTail() const { return is_dead_; }
    void IncrementTail();
    Vector2 NewFruitLocation(int width_max, int height_max);
    void SetMovementSpeed(float speed) {
        movement_speed_ = speed;
    }

private:
    void UpdatePosition();
    void UpdateTail();

    std::vector<Vector2> tail_;
    std::vector<float> tail_rotations_;
    std::vector<Vector2> tail_positions_;
    std::vector<float> rotation_positions_;

    Vector2 pos_accum_;
    bool is_dead_ = false;
    float movement_speed_;
    bool input_this_frame_;
    float current_angle_;
    float current_angle_deg_;
    int frame_counter_ = 0;
    int current_length_;
    float frames_to_jump_back_one_;
};
