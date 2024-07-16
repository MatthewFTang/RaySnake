//
// Created by Matt on 5/07/2024.
//

#pragma once
#include <map>
#include <string>

#include "raylib.h"

class FontManger {
public:
    static FontManger *s_instance_;

    static FontManger *Instance() {
        if (s_instance_ == nullptr) {
            s_instance_ = new FontManger();
            return s_instance_;
        }
        return s_instance_;
    }
    void RenderText(const char *text, int font_size, Color col, int pos_x, int pos_y, bool centered = false);

    ~FontManger();

private:
    FontManger() = default;
    std::map<int, Font> font_map_;
};
