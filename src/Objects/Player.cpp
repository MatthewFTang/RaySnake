//
// Created by Matt on 3/07/2024.
//

#include "Player.h"

#include <raymath.h>

#include <cmath>
#include <iostream>


void Player::Update() {


    if (IsKeyDown(KEY_DOWN)) {
        m_PosAccum.y += 1.0f;
        inputThisFrame = true;
    }

    if (IsKeyDown(KEY_UP)) {
        m_PosAccum.y -= 1.0f;
        inputThisFrame = true;
    }
    if (IsKeyDown(KEY_LEFT)) {
        m_PosAccum.x -= 1.0f;
        inputThisFrame = true;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        m_PosAccum.x += 1.0f;
        inputThisFrame = true;
    }
    frameCounter++;
    updatePosition();
    int curFrame = getCurrentFrame();
    if (frameCounter == getAnimationSpeed()) {
        frameCounter = 0;
        curFrame++;
        if (curFrame == getNumFrames()) curFrame = 0;
        setCurrentFrame(curFrame);
    }
}
void Player::updatePosition() {

    if (inputThisFrame) {
        m_currentAngle = atan2(m_PosAccum.y, m_PosAccum.x);
        m_currentAngleDeg = m_currentAngle * 180 / PI;
        m_currentAngleDeg = Wrap(m_currentAngleDeg, 0, 360);
        setRotation(m_currentAngleDeg);
    }
    inputThisFrame = false;

    float dx = movementSpeed * std::cos(m_currentAngle);
    float dy = movementSpeed * std::sin(m_currentAngle);

    m_PosAccum.x = m_PosAccum.y = 0.0f;
    Vector2 pos = getPosition();
    pos.x += dx;
    pos.y += dy;

    //    pos = CheckBounds(pos);
    setPosition(pos);
}


Vector2 Player::CheckBounds(Vector2 pos) {
    int width = getWidth();
    int height = getHeight();
    if (pos.x < width) pos.x = width;
    if (pos.y < height) pos.y = height;
    if (pos.x > (float) GetRenderWidth() - width) pos.x = (float) GetRenderWidth() - width;
    if (pos.y > (float) GetRenderHeight() - height) pos.x = (float) GetRenderHeight() - height;
    return pos;
}
