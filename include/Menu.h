//
// Created by Matt on 2/07/2024.
//

#ifndef RAYSNAKE_SRC_MENU_MENU_H_
#define RAYSNAKE_SRC_MENU_MENU_H_
#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"

class Menu {
public:
    virtual ~Menu() = default;
    virtual void Render() = 0;
    virtual void Update() = 0;
};


#endif//RAYSNAKE_SRC_MENU_MENU_H_
