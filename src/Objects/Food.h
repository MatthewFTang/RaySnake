//
// Created by Matt on 3/07/2024.
//

#pragma once
#include "GameObject.h"
#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"

class Food : public GameObject {
public:
    explicit Food(const LoaderParams& params) : GameObject(params){};

    std::string GetGameObjectType() override { return "Food"; }
    void Update() override;

private:
    int m_frame_count_ = 0;
};
