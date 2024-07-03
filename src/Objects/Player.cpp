//
// Created by Matt on 3/07/2024.
//

#include "Player.h"
#include <cmath>
#include <iostream>
#include <raymath.h>
Player::Player() {
    imageTexture = LoadTexture("res/assets/Bird.png");
    m_numFrames = 8;
    m_currentRow = 0;
    m_height = imageTexture.height;
    m_width = (float) imageTexture.width;
}
void Player::Init() {
    m_height = (float) imageTexture.height / 2;
    textureSrc.height = m_height;
    textureSrc.width = (float) imageTexture.width / 4;
    textureSrc.x = 0;
    textureSrc.y = 0;
    textureDest.x = (float) GetRenderHeight() / 2;
    textureDest.y = (float) GetRenderWidth() / 2;

    textureDest.height = 75;
    textureDest.width = 75;
    m_position = Vector2(textureDest.x, textureDest.y);
}
Player::~Player() {
    UnloadTexture(imageTexture);
}

void Player::Render() {

    DrawTexturePro(imageTexture, textureSrc, textureDest, Vector2({0, 0}), 0, WHITE);
}
void Player::Update() {
    if (frameCounter >= 8) {


        m_lastPosition = m_position;

        textureSrc.x = textureSrc.width * (float) m_currentFrame;
        textureSrc.y = textureSrc.height * (float) m_currentRow;
        m_currentFrame++;

        if (m_currentFrame == 4)
            m_currentRow++;

        m_currentRow = m_currentRow & 2;
        if (m_currentFrame == m_numFrames) m_currentFrame = 0;

        frameCounter = 0;
    }

    if (IsKeyDown(KEY_DOWN)) {
        m_position.y += movementSpeed;
        updatePositionParams();
    }

    if (IsKeyDown(KEY_UP)) {
        m_position.y -= movementSpeed;
        updatePositionParams();
    }
    if (IsKeyDown(KEY_LEFT)) {
        m_position.x -= movementSpeed;
        updatePositionParams();
    }
    if (IsKeyDown(KEY_RIGHT)) {
        m_position.x += movementSpeed;
        updatePositionParams();
    }

    frameCounter++;
}
void Player::updatePositionParams() {
    m_currentAngle = GetDirection();
    //    std::cout << m_currentAngle << std::endl;
    //    if (m_currentAngle == 180 || m_currentAngle == -90) {
    //        textureSrc.height = -m_height;
    //    } else {
    //        textureSrc.height = m_height;
    //    }

    textureDest.x = m_position.x;
    textureDest.y = m_position.y;
    CheckBounds();
}


void Player::Clean() {
}
void Player::CheckBounds() {
    if (m_position.x < 0) m_position.x = 0;
    if (m_position.y < 0) m_position.y = 0;
    if (m_position.x > (float) GetRenderWidth()) m_position.x = (float) GetRenderWidth();
    if (m_position.y > (float) GetRenderHeight()) m_position.x = (float) GetRenderHeight();
}
float Player::GetDirection() {

    return atan2(m_position.y - m_lastPosition.y, m_position.x - m_lastPosition.x) * 180 / PI;
}
