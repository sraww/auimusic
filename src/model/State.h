#pragma once

#include <AUI/Common/AVector.h>

struct Song {
    APath location;
    AString title;
};

struct State {
    AProperty<AVector<_<Song>>> songs;
    APath path = APath::getDefaultPath(APath::HOME) / "Music";
    AProperty<_<Song>> currentSong;
};
