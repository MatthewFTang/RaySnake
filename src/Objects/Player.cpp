//
// Created by Matt on 3/07/2024.
//

#include "Player.h"
#include <cmath>
#include <iostream>
Player::Player() {
    imageTexture = LoadTexture("res/assets/Bird.png");
    m_numFrames = 8;
    m_currentRow = 0;
    m_height = imageTexture.height;
    m_width = (float) imageTexture.width;
    m_position = Vector2({0, 0});

    textureSrc.height = (float) imageTexture.height / 2;
    textureSrc.width = (float) imageTexture.width / 4;
    textureSrc.x = textureDest.x = 0;
    textureSrc.y = textureDest.y = 0;
    textureDest.height = 75;
    textureDest.width = 75;
}
Player::~Player() {
    UnloadTexture(imageTexture);
}

void Player::Render() {
    DrawTexturePro(imageTexture, textureSrc, textureDest, Vector2({0, 0}), 0.0f, WHITE);
}
void Player::Update() {
    if (frameCounter >= 8) {

        textureSrc.x = textureSrc.width * (float) m_currentFrame;
        textureSrc.y = textureSrc.height * (float) (m_currentFrame % 3);
        m_currentFrame++;
        if (m_currentFrame == m_numFrames) m_currentFrame = 0;

        frameCounter = 0;
    }
    frameCounter++;
}
void Player::Clean() {
}
