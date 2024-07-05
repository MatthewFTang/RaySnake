//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_GAMEOBJECT_H
#define RAYSNAKE_GAMEOBJECT_H

#include <raylib.h>

#include <string>

#include "src/LoaderParams.h"
class GameObject {

public:
    explicit GameObject(LoaderParams const &params);
    GameObject();
    virtual ~GameObject() = default;

    virtual void Render();
    virtual void Clean();

    virtual void Update() = 0;
    virtual std::string getGameObjectType() = 0;


    Vector2 getPosition() const { return m_position; }
    Vector2 getVelocity() const { return m_velocity; }
    Vector2 getAcceleration() const { return m_acceleration; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    int getNumFrames() const { return m_numFrames; }
    int getFrameCount() const { return m_frameCount; }
    int getCurrentFrame() const { return m_currentFrame; }
    int getDestWidth() const { return m_destWidth; }
    int getDestHeight() const { return m_destHeight; }
    void setPosition(Vector2 _position) { m_position = _position; }
    void setVelocity(Vector2 _velocity) { m_velocity = _velocity; }
    void setAcceleration(Vector2 _acceleration) { m_acceleration = _acceleration; }
    Rectangle getBoundingBox();
    void setRotation(float _rot) { m_rotation = _rot; }
    void setCurrentFrame(int _frame) { m_currentFrame = _frame; }
    int getAnimationSpeed() const { return m_animationSpeed; }

private:
    Vector2 m_position;
    Vector2 m_velocity;
    Vector2 m_acceleration;
    Rectangle m_boundingBox;
    float m_rotation;
    int m_width;
    int m_height;
    int m_currentRow;
    int m_itemsPerRow;
    int m_numFrames;
    int m_currentFrame;
    int m_frameCount;
    int m_destHeight;
    int m_destWidth;
    int m_animationSpeed;
    std::string m_textureID;
};


#endif//RAYSNAKE_GAMEOBJECT_H
