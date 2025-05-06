#pragma once

#include <AUI/Platform/AWindow.h>
#include <AUI/Thread/AAsyncHolder.h>
#include <AUI/Audio/IAudioPlayer.h>
#include "model/State.h"

class MainWindow: public AWindow {
public:
    MainWindow();

private:
    State mState;
    AAsyncHolder mAsync;

    void present(_<AView> view);

    void loadPlaylist();

    _<ISoundInputStream> open(const AUrl& url);

    _<AView> playlistView();
    _<AView> playerView();

    void togglePlay();
};
