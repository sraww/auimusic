#pragma once

#include <AUI/Common/AVector.h>

struct Song {
    AString title;
};

struct State {
    AVector<_<Song>> songs;
};
