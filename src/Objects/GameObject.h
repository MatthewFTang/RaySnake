//
// Created by Matt on 3/07/2024.
//

#pragma once
#include <string>

#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"
#include "src/Core/LoaderParams.h"

class GameObject {

public:
    explicit GameObject(LoaderParams const &params);

    virtual ~GameObject() = default;

    virtual void Render();
    virtual void Clean();

    virtual void Update() = 0;
    virtual std::string GetGameObjectType() = 0;

    [[nodiscard]] Vector2 GetPosition() const { return position_; }
    [[nodiscard]] Vector2 GetAcceleration() const { return acceleration_; }
    [[nodiscard]] int GetWidth() const { return width_; }
    [[nodiscard]] int GetHeight() const { return height_; }
    [[nodiscard]] int GetNumFrames() const { return num_frames_; }
    [[nodiscard]] int GetFrameCount() const { return frame_count_; }
    [[nodiscard]] int GetCurrentFrame() const { return current_frame_; }
    [[nodiscard]] int GetDestWidth() const { return dest_width_; }
    [[nodiscard]] int GetDestHeight() const { return dest_height_; }
    std::string GetTextureId() { return &texture_id_[0]; }
    [[nodiscard]] int GetItemsPerRow() const { return items_per_row_; }
    [[nodiscard]] float GetRotation() const { return rotation_; }
    [[nodiscard]] int GetAnimationSpeed() const { return animation_speed_; }

    void SetPosition(Vector2 position) { position_ = position; }
    void SetVelocity(Vector2 velocity) { velocity_ = velocity; }
    void SetAcceleration(Vector2 acceleration) { acceleration_ = acceleration; }
    Rectangle GetBoundingBox();
    void SetRotation(float rot) { rotation_ = rot; }
    void SetCurrentFrame(int frame) { current_frame_ = frame; }

private:
    Vector2 position_{};
    Vector2 velocity_{};
    Vector2 acceleration_{};
    Rectangle bounding_box_{};
    float rotation_;

    int width_;
    int height_;
    int items_per_row_;
    int num_frames_;
    int current_frame_;
    int frame_count_;
    int dest_height_;
    int dest_width_;
    int animation_speed_;
    std::string texture_id_;
};
