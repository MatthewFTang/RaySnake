//
// Created by Matt on 15/07/2024.
//

#include "SoundManger.h"


SoundManger *SoundManger::s_instance_ = nullptr;

void SoundManger::LoadSounds(const std::string &file_path, const std::string &id) {
    if (!sound_map_.contains(id)) {
        Sound sound = LoadSound(file_path.c_str());
        sound_map_[id] = {SoundType::SOUND, sound};
    }
}
void SoundManger::LoadMusic(const std::string &file_path, const std::string &id) {
    if (!sound_map_.contains(id)) {
        Music music = LoadMusicStream(file_path.c_str());
        sound_map_[id] = {SoundType::MUSIC, music};
    }
}
void SoundManger::Play(const std::string &id) {

    if (sound_map_[id].type == SoundType::MUSIC) {
        Music temp = std::get<Music>(sound_map_[id].data);
        PlayMusicStream(temp);
    } else if (sound_map_[id].type == SoundType::SOUND) {
        Sound temp = std::get<Sound>(sound_map_[id].data);
        PlaySound(temp);
    }
    is_playing_[id] = true;
}
void SoundManger::Pause(const std::string &id) {

    if (sound_map_[id].type == SoundType::MUSIC) {
        Music temp = std::get<Music>(sound_map_[id].data);
        PauseMusicStream(temp);
    } else if (sound_map_[id].type == SoundType::SOUND) {
        Sound temp = std::get<Sound>(sound_map_[id].data);
        PauseSound(temp);
    }
    is_playing_[id] = false;
}
void SoundManger::Render() {
    for (auto const &[kId, kFlag]: is_playing_) {
        if (kFlag && sound_map_[kId].type == SoundType::MUSIC) {
            Music temp = std::get<Music>(sound_map_[kId].data);
            UpdateMusicStream(temp);
        }
    }
}
