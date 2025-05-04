#pragma once

#include <AUI/Platform/AWindow.h>
#include "model/State.h"

class MainWindow: public AWindow {
public:
    MainWindow();

private:
    State mState;
};
