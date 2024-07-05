//
// Created by Matt on 3/07/2024.
//

#include "Food.h"

void Food::Update() {
    if (m_frameCount == getAnimationSpeed()) {
        int frame = getCurrentFrame();
        frame++;
        if (frame == getNumFrames()) frame = 0;
        setCurrentFrame(frame);
        m_frameCount = 0;
    }
    m_frameCount++;
}
