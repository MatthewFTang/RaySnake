//
// Created by Matt on 5/07/2024.
//

#include "TextureManger.h"

#include <filesystem>
#include <iostream>
TextureManger *TextureManger::s_Instance = nullptr;

void TextureManger::loadTexture(std::string const &fileName, std::string const &id) {
    if (!textureMap.contains(id)) {
        if (std::filesystem::exists(fileName)) {
            Texture tempText = LoadTexture(fileName.c_str());
            textureMap[id] = tempText;
        } else
            std::cout << "TextureManger :: File (" << fileName << ") does not exist" << std::endl;
    }
}
void TextureManger::drawImage(std::string    &id) {

    Rectangle srcRect;
    Rectangle destRect;
    srcRect.x = srcRect.y = 0;
    srcRect.width = (float) textureMap[id].width;
    srcRect.height = (float) textureMap[id].height;
    destRect.x = destRect.y = 0;
    destRect.width = (float) GetRenderWidth();
    destRect.height = (float) GetRenderHeight();

    DrawTexturePro(textureMap[id], srcRect, destRect, {0, 0}, 0, WHITE);
}
void TextureManger::Clean() {
    for ( auto const &[id, text]: textureMap) {
        UnloadTexture(text);
    }
    textureMap.clear();
}
void TextureManger::drawFrame(const std::string &id, float xOffset, float yOffset,
                              int width, int height, int itemsPerRow,
                              int currentFrame, float rotation, int destHeight, int destWidth) {

    Rectangle destRect;
    Rectangle srcRect;

    srcRect.x = (float) (width * (currentFrame % itemsPerRow));
    srcRect.y = (float) (height * (currentFrame / itemsPerRow));


    srcRect.height = (float) height;
    srcRect.width = (float) width;

    destRect.height = destHeight;
    destRect.width = destWidth;
    destRect.x = xOffset;
    destRect.y = yOffset;

    Vector2 o{(float) destHeight / 2, (float) destWidth / 2};

    if (rotation > 90 && rotation < 270) {
        srcRect.height = -srcRect.height;
    }
    DrawTexturePro(textureMap[id], srcRect, destRect, o, rotation, WHITE);
}
