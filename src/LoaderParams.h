//
// Created by Matt on 5/07/2024.
//

#ifndef RAYSNAKE_LOADERPARAMS_H
#define RAYSNAKE_LOADERPARAMS_H

#include <string>
#include <utility>

class LoaderParams {
public:
    LoaderParams(std::string filePath, int x, int y, int spriteWidth,
                 int spriteHeight, std::string id, int numFrames,
                 int animationSpeed, int destWidth, int destHeight, int itemsPerRow)

        : m_filePath(std::move(filePath)),
          m_x(x),
          m_y(y),
          m_width(spriteWidth),
          m_height(spriteHeight),
          m_numFrames(numFrames),
          m_animSpeed(animationSpeed),
          m_destHeight(destHeight),
          m_destWidth(destWidth),
          m_textureID(std::move(id)),
          m_itemsPerRow(itemsPerRow) {}

    int getX() const {
        return m_x;
    }
    int getY() const {
        return m_y;
    }
    int getWidth() const {
        return m_width;
    }
    int getHeight() const {
        return m_height;
    }
    int getNumFrames() const {
        return m_numFrames;
    }
    int getAnimateSpeed() const {
        return m_animSpeed;
    }
    std::string getTextureID() const {
        return m_textureID;
    }
    std::string getFilePath() const {
        return m_filePath;
    }
    int getItemsPerRow() const { return m_itemsPerRow; }
    int getDestHeight() const { return m_destHeight; }
    int getDestWidth() const { return m_destWidth; }

private:
    std::string m_filePath;
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    int m_numFrames;
    int m_animSpeed;
    int m_destHeight;
    int m_destWidth;
    int m_itemsPerRow;
    std::string m_textureID;
};

#endif//RAYSNAKE_LOADERPARAMS_H
