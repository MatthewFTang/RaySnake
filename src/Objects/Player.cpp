//
// Created by Matt on 3/07/2024.
//

#include "include/Player.h"

#include <raymath.h>

#include <cmath>
#include <iostream>

#include "include/TextureManger.h"


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
    UpdateTail();
}

void Player::UpdateTail() {

    int number_pos_needed = std::floor(frames_to_jump_back_one_ * (float) current_length_ - 1);
    tail_positions_[0] = GetPosition();

    auto size_squared = (float) (GetDestWidth() * GetDestWidth());
    for (int i = number_pos_needed; i > 0; i--) {

        tail_positions_[i] = tail_positions_[i - 1];


        rotation_positions_[i] = rotation_positions_[i - 1];
    }
    rotation_positions_[0] = GetRotation();


    for (int i = 0; i < current_length_; i++) {
        int new_ind = std::floor(frames_to_jump_back_one_ * (float) i);
        tail_[i] = tail_positions_[new_ind];
        if (i > 1) {
            float dist = pow(tail_[0].x - tail_[i].x, 2) + pow(tail_[0].y - tail_[i].y, 2);
            if (dist < size_squared) {
                is_dead_ = true;
            }
        }


        tail_rotations_[i] = rotation_positions_[new_ind];
    }
}
void Player::IncrementTail() {
    current_length_++;
}
void Player::Render() {
    std::string texture_id = GetTextureId();

    int width = GetWidth();
    int height = GetHeight();
    int items_per_row = GetItemsPerRow();
    int current_frame = GetCurrentFrame();
    int dest_height = GetDestHeight();
    int dest_width = GetDestWidth();


    for (int i = 0; i < current_length_; i++) {
        TextureManger::Instance()->DrawFrame(texture_id, tail_[i].x, tail_[i].y, width, height, items_per_row, current_frame, tail_rotations_[i], dest_height, dest_width);
        current_frame++;
        if (current_frame == GetNumFrames()) current_frame = 0;
    }
}
void Player::NewGame() {
    current_length_ = 1;

    frames_to_jump_back_one_ = (float) GetDestWidth() / movement_speed_;
    tail_.clear();
    rotation_positions_.clear();

    tail_.reserve(256);
    tail_rotations_.reserve(256);
    for (int i = 0; i < 256; i++) {
        tail_.push_back({0, 0});
        tail_rotations_.push_back(0.0f);
    }
    tail_positions_.clear();
    tail_positions_.reserve(256 * 6);
    rotation_positions_.reserve(256 * 6);

    for (int i = 0; i < 256 * 6; i++) {
        tail_positions_.push_back({0, 0});
        rotation_positions_.push_back(0.0f);
    }
    is_dead_ = false;
}

Vector2 Player::NewFruitLocation(int width_max, int height_max) {
    auto temp_x = (float) GetRandomValue(0, width_max);
    auto temp_y = (float) GetRandomValue(0, height_max);

    if (current_length_ > 1) {
        auto size_squared = (float) GetDestWidth();
        size_squared *= size_squared;
        int number_pos_needed = std::floor(frames_to_jump_back_one_ * (float) current_length_ - 1);

        for (int i = 0; i < number_pos_needed; i++) {
            float dist = pow(tail_positions_[i].x - temp_x, 2) + pow(tail_positions_[i].y - temp_y, 2);
            if (dist < size_squared) {
                temp_x = (float) GetRandomValue(0, width_max);
                temp_y = (float) GetRandomValue(0, height_max);
                i = 0;
            }
        }
    }

    return {temp_x, temp_y};
}
