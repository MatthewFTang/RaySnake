//
// Created by Matt on 3/07/2024.
//

#include "GameObject.h"

#include "src/Graphics/TextureManger.h"

void GameObject::Render() {
    TextureManger::Instance()->drawFrame(m_textureID, m_position.x, m_position.y, m_width, m_height, m_itemsPerRow, m_currentFrame, m_rotation, m_destHeight, m_destWidth);
}

void GameObject::Clean() {
    TextureManger::Instance()->UnLoadTextures(m_textureID);
}
GameObject::GameObject(LoaderParams const &params) {
    m_position = {(float) params.getX(), (float) params.getY()};
    m_velocity = {0.0f, 0.0f};
    m_acceleration = {0.0f, 0.0f};
    m_textureID = params.getTextureID();
    m_frameCount = 0;
    m_width = params.getWidth();
    m_height = params.getHeight();
    m_numFrames = params.getNumFrames();
    m_destHeight = params.getDestHeight();
    m_destWidth = params.getDestWidth();
    m_animationSpeed = params.getAnimateSpeed();
    m_currentFrame = 0;
    m_itemsPerRow = params.getItemsPerRow();
    m_rotation = 0.0f;
    m_boundingBox.height = m_destHeight;
    m_boundingBox.width = m_destWidth;
    TextureManger::Instance()->loadTexture(params.getFilePath(), m_textureID);
}
GameObject::GameObject() {}
Rectangle GameObject::getBoundingBox() {
    m_boundingBox.x = m_position.x;
    m_boundingBox.y = m_position.y;
    return m_boundingBox;
}
