//
// Created by Matt on 5/07/2024.
//

#ifndef RAYSNAKE_TEXTUREMANGER_H
#define RAYSNAKE_TEXTUREMANGER_H

#include <raylib.h>

#include <map>
#include <string>


class TextureManger {

public:
    static TextureManger *s_Instance;

    static TextureManger *Instance() {
        if (s_Instance == nullptr) {
            s_Instance = new TextureManger();
            return s_Instance;
        }
        return s_Instance;
    }

    void loadTexture(std::string const &fileName, std::string const &id);
   void drawImage(std::string &id);
    void drawFrame(const std::string &id, float xOffset, float yOffset,
                   int width, int height, int itemsPerRow,
                   int currentFrame, float rotation, int destHeight, int destWidth);
    void Clean();

private:
    TextureManger() = default;
    Vector2 origin = {0, 0};
    std::map<std::string, Texture2D> textureMap;
};


#endif//RAYSNAKE_TEXTUREMANGER_H
