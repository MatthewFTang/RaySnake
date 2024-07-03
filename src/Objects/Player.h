//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_PLAYER_H
#define RAYSNAKE_PLAYER_H


#include "GameObject.h"
class Player : public GameObject {
public:
    Player();
    ~Player();
    void Render() override;
    void Update() override;
    void Clean() override;

    void Init();

    int getHeight() const { return m_height; }
    int getWidth() const { return m_width; }
    Vector2 &getPosition() { return m_position; }

private:
    void CheckBounds();
    float GetDirection();
    void updatePositionParams();


    Texture2D imageTexture;
    Vector2 m_position;
    Vector2 m_lastPosition;
    float m_currentAngle = 0;
    float movementSpeed = 3;
    int m_height;
    float m_width;
    int m_numFrames;
    int m_currentRow;
    int m_currentFrame;
    Rectangle textureDest;
    Rectangle textureSrc;
    int frameCounter = 0;
};


#endif//RAYSNAKE_PLAYER_H
