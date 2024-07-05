//
// Created by Matt on 5/07/2024.
//

#include "FontManger.h"
FontManger *FontManger::s_Instance = nullptr;
void FontManger::renderText(const char *text, int fontSize, Color col, int posX, int posY) {

    if (!fontMap.contains(fontSize)) {

        fontMap[fontSize] = LoadFontEx("res/fonts/Lato-Bold.ttf", fontSize, nullptr, 0);
    }
    Vector2 pos{(float) posX, (float) posY};
    SetTextLineSpacing(fontSize);

    DrawTextEx(fontMap[fontSize], text, pos, fontSize, 0, col);
}
FontManger::~FontManger() {
    for (auto const &[size, font]: fontMap) {
        UnloadFont(font);
    }
    fontMap.clear();
}
