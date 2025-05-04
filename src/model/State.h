#pragma once

#include <AUI/Common/AVector.h>

struct Song {
    APath location;
    AString title;
};

struct State {
    AVector<_<Song>> songs;
    APath path = APath::getDefaultPath(APath::HOME) / "Music";
};
