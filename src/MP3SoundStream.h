#pragma once

#include <AUI/Audio/ISoundInputStream.h>
#include <AUI/Util/APimpl.h>
#include <dr_mp3.h>
#include "IFiniteMedia.h"

class MP3SoundStream: public ISoundInputStream, public IFiniteMedia {
public:
    MP3SoundStream(aui::non_null<_unique<IInputStream>> stream);
    ~MP3SoundStream() override;

    AAudioFormat info();

    size_t read(char* dst, size_t size);

    void seek(std::chrono::milliseconds offset) override;

private:
    std::unique_ptr<IInputStream> mStream;
    drmp3 mMP3;

};
