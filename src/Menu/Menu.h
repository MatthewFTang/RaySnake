//
// Created by Matt on 2/07/2024.
//

#ifndef RAYSNAKE_MENU_H
#define RAYSNAKE_MENU_H
#include <raylib.h>

class Menu {
public:
    virtual ~Menu() = default;
    virtual void Render() = 0;
    virtual void Update() = 0;
};


#endif//RAYSNAKE_MENU_H
