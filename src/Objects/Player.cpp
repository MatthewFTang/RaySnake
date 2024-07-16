//
// Created by Matt on 3/07/2024.
//

#include "Player.h"

#include <raymath.h>

#include <cmath>


void Player::Update() {


    if (IsKeyDown(KEY_DOWN)) {
        pos_accum_.y += 1.0f;
        input_this_frame_ = true;
    }

    if (IsKeyDown(KEY_UP)) {
        pos_accum_.y -= 1.0f;
        input_this_frame_ = true;
    }
    if (IsKeyDown(KEY_LEFT)) {
        pos_accum_.x -= 1.0f;
        input_this_frame_ = true;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        pos_accum_.x += 1.0f;
        input_this_frame_ = true;
    }
    frame_counter_++;
    UpdatePosition();
    int cur_frame = GetCurrentFrame();
    if (frame_counter_ == GetAnimationSpeed()) {
        frame_counter_ = 0;
        cur_frame++;
        if (cur_frame == GetNumFrames()) cur_frame = 0;
        SetCurrentFrame(cur_frame);
    }
}
void Player::UpdatePosition() {

    if (input_this_frame_) {
        current_angle_ = atan2(pos_accum_.y, pos_accum_.x);
        current_angle_deg_ = current_angle_ * 180 / PI;
        current_angle_deg_ = Wrap(current_angle_deg_, 0, 360);
        SetRotation(current_angle_deg_);
    }
    input_this_frame_ = false;

    float dx = movement_speed_ * std::cos(current_angle_);
    float dy = movement_speed_ * std::sin(current_angle_);

    pos_accum_.x = pos_accum_.y = 0.0f;
    Vector2 pos = GetPosition();
    pos.x += dx;
    pos.y += dy;

    SetPosition(pos);
}
