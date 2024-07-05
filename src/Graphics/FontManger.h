//
// Created by Matt on 5/07/2024.
//

#ifndef RAYSNAKE_FONTMANGER_H
#define RAYSNAKE_FONTMANGER_H

#include <map>
#include <string>

#include "raylib.h"

class FontManger {
public:
    static FontManger *s_Instance;

    static FontManger *Instance() {
        if (s_Instance == nullptr) {
            s_Instance = new FontManger();
            return s_Instance;
        }
        return s_Instance;
    }
    void renderText(const char *text, int fontSize, Color col, int posX, int posY);

    ~FontManger();

private:
    FontManger() = default;
    std::map<int, Font> fontMap;
};


#endif//RAYSNAKE_FONTMANGER_H
