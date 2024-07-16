//
// Created by Matt on 5/07/2024.
//

#include "FontManger.h"
FontManger *FontManger::s_instance_ = nullptr;

void FontManger::RenderText(const char *text, int font_size, Color col, int pos_x, int pos_y, bool centered) {

    if (!font_map_.contains(font_size)) {

        font_map_[font_size] = LoadFontEx("res/fonts/Lato-Bold.ttf", font_size, nullptr, 0);
    }
    Vector2 pos{(float) pos_x, (float) pos_y};

    if (centered) {
        Vector2 text_size = MeasureTextEx(font_map_[font_size], text, (float) font_size, 0);
        pos.x -= text_size.x / 2;
        pos.y -= -text_size.y / 2;
    }

    Vector2 pos_shadow = pos;
    pos_shadow.y += 3;
    SetTextLineSpacing(font_size);


    DrawTextEx(font_map_[font_size], text, pos_shadow, (float) font_size, 0, BLACK);
    DrawTextEx(font_map_[font_size], text, pos, (float) font_size, 0, col);
}
FontManger::~FontManger() {
    for (auto const &[kSize, kFont]: font_map_) {
        UnloadFont(kFont);
    }
    font_map_.clear();
}
