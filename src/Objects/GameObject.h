//
// Created by Matt on 3/07/2024.
//

#ifndef RAYSNAKE_GAMEOBJECT_H
#define RAYSNAKE_GAMEOBJECT_H

#include <raylib.h>
class GameObject {

public:
    virtual void Render() = 0;
    virtual void Update() = 0;
    virtual void Clean() = 0;


private:
};


#endif//RAYSNAKE_GAMEOBJECT_H
