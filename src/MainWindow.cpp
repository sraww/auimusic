#include <AUI/View/AForEachUI.h>
#include "MainWindow.h"
#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/View/ALabel.h>
#include <AUI/View/AButton.h>
#include <AUI/Platform/APlatform.h>
#include <AUI/View/ADrawableView.h>
#include <AUI/View/AProgressBar.h>
#include <AUI/View/ASlider.h>
#include <AUI/View/ASpacerFixed.h>
#include <AUI/View/AScrollArea.h>
#include "fluent_icons.h"
#include "model/State.h"

using namespace declarative;


static _<AView> playlistView(State& state) {
    return AScrollArea::Builder().withContents(
        AUI_DECLARATIVE_FOR(i, state.songs, AVerticalLayout) {
            return Label { i->title };
        }
    ).build() with_style {
        FixedSize { 200_dp, {} },
        BackgroundSolid { AColor::BLACK.transparentize(0.7f) },
    };
}

static _<AView> playerView() {
    return Centered::Expanding {
        Vertical {
          Centered {
            _new<AView>() with_style {
              FixedSize { 128_dp },
              BackgroundSolid { AColor::GRAY },
              BorderRadius { 4_dp },
              BoxShadow { 0, 4_dp, 32_dp, AColor::BLACK.transparentize(0.7f) },
            },
          },

          SpacerFixed { 32_dp },

          _new<ASlider>(),
          Horizontal {
            Label { "00:00" } with_style { ATextAlign::CENTER },
            SpacerExpanding {},
            Label { "00:00" } with_style { ATextAlign::CENTER },
          },

          SpacerFixed { 16_dp },

          Label { "Title" } with_style { ATextAlign::CENTER, FontSize(14_pt) },
          Label { "Artist" } with_style { ATextAlign::CENTER },
          Label { "Album" } with_style { ATextAlign::CENTER },

          SpacerFixed { 16_dp },

          Centered {
            Horizontal {
              Label { fluent_icons::ic_fluent_previous_48_filled } with_style {
                Font { ":img/FluentSystemIcons-Filled.ttf" },
                FontSize { 32_dp },
              },
              Label { fluent_icons::ic_fluent_play_circle_48_filled } with_style {
                Font { ":img/FluentSystemIcons-Filled.ttf" },
                FontSize { 48_dp },
              },
              Label { fluent_icons::ic_fluent_next_48_filled } with_style {
                Font { ":img/FluentSystemIcons-Filled.ttf" },
                FontSize { 32_dp },
              },
            } with_style { LayoutSpacing { 8_dp } },
          },
        } with_style { MinSize { 200_dp }, Padding { 32_dp, 64_dp } },
    };
}

MainWindow::MainWindow() : AWindow("Project template app", 400_dp, 600_dp) {
    setExtraStylesheet(AStylesheet {
      {
        t<AView>(),
        TextColor { AColor::WHITE },
      },
    });

    mState.songs << _new<Song>("Test");
    mState.songs << _new<Song>("Test1");
    mState.songs << _new<Song>("stariy Perdoon");
    mState.songs << _new<Song>("XyeCoC");
    mState.songs << _new<Song>("XyeCoC kura perdoli");

    setContents(Centered {
        Horizontal::Expanding { playlistView(mState), playerView(), }
    } with_style {
      BackgroundSolid { 0x2c2c2c_rgb },
      Padding { 0 },
      Margin { 0 },
    });
}
