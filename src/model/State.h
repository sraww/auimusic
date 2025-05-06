#pragma once

#include <AUI/Common/AVector.h>
#include <AUI/Util/AImageDrawable.h>
#include "Song.h"
#include "IFiniteMedia.h"

struct State {
    AProperty<AVector<_<Song>>> songs;
    APath path = APath::getDefaultPath(APath::HOME) / "Music";
    AProperty<_<Song>> currentSong;
    _<IAudioPlayer> currentPlayer;
    AProperty<_<IFiniteMedia>> currentStream;
    AProperty<bool> isPlaying = false;

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

    APropertyPrecomputed<std::chrono::milliseconds> currentPosition = [&]() -> std::chrono::milliseconds {
        if (currentStream == nullptr) {
            return std::chrono::milliseconds(0);
        }
        return (*currentStream)->position;
    };

    APropertyPrecomputed<std::chrono::milliseconds> currentDuration = [&]() -> std::chrono::milliseconds {
      if (currentStream == nullptr) {
          return std::chrono::milliseconds(0);
      }
      return (*currentStream)->duration;
    };
};
