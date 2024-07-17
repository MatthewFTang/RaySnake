//
// Created by Matt on 15/07/2024.
//

#pragma once

#include <raylib.h>

#include <map>
#include <string>
#include <variant>


enum class SoundType {
    MUSIC,
    SOUND
};

struct SoundOrMusic {
    SoundType type;
    std::variant<Music, Sound> data;
};


class SoundManger {

public:
    static SoundManger *s_instance_;

    static SoundManger *Instance() {
        if (s_instance_ == nullptr) {
            s_instance_ = new SoundManger();
        }
        return s_instance_;
    }

    void LoadSounds(const std::string &file_path, const std::string &id);

    void LoadMusic(const std::string &file_path, const std::string &id);
    void Play(const std::string &id);
    void Pause(const std::string &id);
    void Render();
    void Clean();

private:
    SoundManger() = default;
    std::unordered_map<std::string, SoundOrMusic> sound_map_;
    std::unordered_map<std::string, bool> is_playing_;
};
