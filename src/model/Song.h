#pragma once

#include <AUI/Common/AVector.h>
#include <AUI/IO/APath.h>
#include <AUI/Image/AImage.h>
#include <AUI/Common/AProperty.h>

struct Song {
    APath location;
    AString title;
    AProperty<_<AImage>> thumbnail;
};
