//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_PLAYER_H
#define RAYSNAKE_PLAYER_H
#include "GameObject.h"
#include <raylib.h>
class Player : public GameObject {
public:
    using GameObject::GameObject;
    std::string getGameObjectType() override { return "player"; }
    void Update() override;

private:
    Vector2 CheckBounds(Vector2 pos);

    void updatePosition();
    float m_direction;
    Vector2 m_PosAccum;
    float movementSpeed = 8;
    bool inputThisFrame;
    float m_currentAngle;
    float m_currentAngleDeg;
    int frameCounter = 0;
};


#endif//RAYSNAKE_PLAYER_H
