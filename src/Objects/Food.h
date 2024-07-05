//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_FOOD_H
#define RAYSNAKE_FOOD_H
#include "GameObject.h"
#include <raylib.h>

class Food : public GameObject {
public:
    using GameObject::GameObject;
    std::string getGameObjectType() override { return "Food"; }
    void Update() override;

private:
    int m_frameCount = 0;
};


#endif//RAYSNAKE_FOOD_H
