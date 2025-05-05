#pragma once

#include <AUI/Common/AVector.h>
#include <AUI/Util/AImageDrawable.h>
#include "Song.h"

struct State {
    AProperty<AVector<_<Song>>> songs;
    APath path = APath::getDefaultPath(APath::HOME) / "Music";
    AProperty<_<Song>> currentSong;

    APropertyPrecomputed<_<IDrawable>> currentThumbnail = [&]() -> _<IDrawable> {
        if (*currentSong == nullptr) {
            return nullptr;
        }
        auto thumbnail = *(*currentSong)->thumbnail;
        if (thumbnail == nullptr) {
            return nullptr;
        }
        return _new<AImageDrawable>(std::move(thumbnail));
    };
};
