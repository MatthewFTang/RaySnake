//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_FOOD_H
#define RAYSNAKE_FOOD_H
#include <raylib.h>

#include "GameObject.h"

class Food : public GameObject {
public:
    using GameObject::GameObject;
    std::string GetGameObjectType() override { return "Food"; }
    void Update() override;

private:
    int m_frame_count_ = 0;
};


#endif//RAYSNAKE_FOOD_H
