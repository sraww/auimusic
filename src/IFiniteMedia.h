#pragma once

#include <chrono>
#include <AUI/Common/AProperty.h>

class IFiniteMedia {
public:
    virtual ~IFiniteMedia() = default;
    virtual void seek(std::chrono::milliseconds offset) = 0;

    AProperty<std::chrono::milliseconds> position;
    std::chrono::milliseconds duration;
};
