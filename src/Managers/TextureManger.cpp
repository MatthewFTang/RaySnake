//
// Created by Matt on 5/07/2024.
//

#include "TextureManger.h"

#include <filesystem>
#include <iostream>

TextureManger *TextureManger::s_instance_ = nullptr;

void TextureManger::LoadText(std::string const &file_name, std::string const &id) {
    if (!texture_map_.contains(id)) {
        if (std::filesystem::exists(file_name)) {
            Texture temp_text = LoadTexture(file_name.c_str());
            texture_map_[id] = temp_text;
        } else
            std::cout << "TextureManger :: File (" << file_name << ") does not exist" << std::endl;
    }
}
void TextureManger::DrawImage(const std::string &id) {

    Rectangle src_rect;
    Rectangle dest_rect;
    src_rect.x = src_rect.y = 0;
    src_rect.width = (float) texture_map_[id].width;
    src_rect.height = (float) texture_map_[id].height;
    dest_rect.x = dest_rect.y = 0;
    dest_rect.width = (float) GetRenderWidth();
    dest_rect.height = (float) GetRenderHeight();
    DrawTexturePro(texture_map_[id], src_rect, dest_rect, {0, 0}, 0, WHITE);
}

void TextureManger::DrawImageWithSize(const std::string &id, float x_location, float y_location, float height, float width) {

    Rectangle src_rect;
    Rectangle dest_rect;
    src_rect.x = src_rect.y = 0;
    src_rect.width = (float) texture_map_[id].width;
    src_rect.height = (float) texture_map_[id].height;

    dest_rect.x = x_location;
    dest_rect.y = y_location;
    dest_rect.width = height;
    dest_rect.height = width;
    DrawTexturePro(texture_map_[id], src_rect, dest_rect, {0, 0}, 0, WHITE);
}

void TextureManger::CleanAll() {
    for (auto const &[kId, kText]: texture_map_) {
        UnloadTexture(texture_map_[kId]);
    }
    texture_map_.clear();
}
void TextureManger::DrawFrame(const std::string &id, float x_offset, float y_offset,
                              int width, int height, int items_per_row,
                              int current_frame, float rotation, int dest_height, int dest_width) {

    Rectangle dest_rect;
    Rectangle src_rect;

    src_rect.x = (float) (width * (current_frame % items_per_row));
    src_rect.y = (float) (height * (current_frame / items_per_row));


    src_rect.height = (float) height;
    src_rect.width = (float) width;

    dest_rect.height = (float) dest_height;
    dest_rect.width = (float) dest_width;
    dest_rect.x = x_offset;
    dest_rect.y = y_offset;

    Vector2 o{(float) dest_height / 2, (float) dest_width / 2};

    if (rotation > 90 && rotation < 270) {
        src_rect.height = -src_rect.height;
    }
    DrawTexturePro(texture_map_[id], src_rect, dest_rect, o, rotation, WHITE);
}
void TextureManger::DeleteTexture(const std::string &id) {

    UnloadTexture(texture_map_[id]);
    texture_map_.erase(id);
}
Vector2 TextureManger::GetTextureDimensions(const std::string &id) const {

    try {
        auto temp = texture_map_.at(id);
        return Vector2{(float) temp.height, (float) temp.width};

    } catch (std::out_of_range &e) {
        std::cerr << "Key not found: " << e.what() << '\n';
        return Vector2{0.0, 0.0};
    }
}
