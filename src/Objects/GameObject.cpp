//
// Created by Matt on 3/07/2024.
//

#include "include/GameObject.h"

#include "include/TextureManger.h"

void GameObject::Render() {
    TextureManger::Instance()->DrawFrame(texture_id_, position_.x, position_.y, width_, height_, items_per_row_, current_frame_, rotation_, dest_height_, dest_width_);
}

void GameObject::Clean() {
    TextureManger::Instance()->DeleteTexture(texture_id_);
}
GameObject::GameObject(LoaderParams const &params) {
    position_ = {(float) params.GetX(), (float) params.GetY()};
    velocity_ = {0.0f, 0.0f};
    acceleration_ = {0.0f, 0.0f};
    texture_id_ = params.GetTextureId();
    frame_count_ = 0;
    width_ = params.GetWidth();
    height_ = params.GetHeight();
    num_frames_ = params.GetNumFrames();
    dest_height_ = params.GetDestHeight();
    dest_width_ = params.GetDestWidth();
    animation_speed_ = params.GetAnimateSpeed();
    current_frame_ = 0;
    items_per_row_ = params.GetItemsPerRow();
    rotation_ = 0.0f;
    bounding_box_.height = (float) dest_height_;
    bounding_box_.width = (float) dest_width_;
    TextureManger::Instance()->LoadText(params.GetFilePath(), texture_id_);
}

Rectangle GameObject::GetBoundingBox() {
    bounding_box_.x = position_.x;
    bounding_box_.y = position_.y;
    return bounding_box_;
}
