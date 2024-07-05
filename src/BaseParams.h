//
// Created by Matt on 5/07/2024.
//

#ifndef RAYSNAKE_BASEPARAMS_H
#define RAYSNAKE_BASEPARAMS_H
#include <string>
struct PlayerInfo {
    std::string filePath = "res/Assets/Bird.png";
    std::string id = "player";
    int animationSpeed = 8;
    int x = 200;
    int y = 200;
    int SpriteHeight = 622;
    int SpriteWidth = 716;
    int ItemsPerRow = 4;
    int numFrames = 8;
    int destHeight = 100;
    int destWidth = 100;
};

struct FoodInfo {
    std::string filePath = "res/Assets/Apple.png";
    std::string id = "food";
    int animationSpeed = 8;
    int x = 400;
    int y = 800;
    int SpriteHeight = 32;
    int SpriteWidth = 32;
    int ItemsPerRow = 17;
    int numFrames = 17;
    int destHeight = 50;
    int destWidth = 50;
};


#endif//RAYSNAKE_BASEPARAMS_H
