//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_SRC_OBJECTS_PLAYER_H_
#define RAYSNAKE_SRC_OBJECTS_PLAYER_H_
#include <raylib.h>

#include "GameObject.h"
class Player : public GameObject {
public:
    using GameObject::GameObject;
    std::string GetGameObjectType() override { return "player"; }
    void Update() override;

private:
    void UpdatePosition();
    Vector2 pos_accum_;
    float movement_speed_ = 8;
    bool input_this_frame_;
    float current_angle_;
    float current_angle_deg_;
    int frame_counter_ = 0;
};


#endif//RAYSNAKE_SRC_OBJECTS_PLAYER_H_
