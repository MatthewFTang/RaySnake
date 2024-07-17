//
// Created by Matt on 5/07/2024.
//

#pragma once
#include <raylib.h>

#include <map>
#include <string>

class TextureManger {

public:
    static TextureManger *s_instance_;

    static TextureManger *Instance() {
        if (s_instance_ == nullptr) {
            s_instance_ = new TextureManger();
            return s_instance_;
        }
        return s_instance_;
    }

    void LoadText(std::string const &file_name, std::string const &id);

    void DrawImage(const std::string &id);

    void DrawImageWithSize(const std::string &id, float x_location, float y_location, float height, float width);

    void DrawFrame(const std::string &id, float x_offset, float y_offset,
                   int width, int height, int items_per_row,
                   int current_frame, float rotation, int dest_height, int dest_width);

    void DeleteTexture(const std::string &id);

    void CleanAll();

    [[nodiscard]] Vector2 GetTextureDimensions(const std::string &id) const;

private:
    TextureManger() = default;

    std::unordered_map<std::string, Texture2D> texture_map_;
};
