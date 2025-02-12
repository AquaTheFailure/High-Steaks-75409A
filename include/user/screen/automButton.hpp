#pragma once

#include "user/screen/screenButton.hpp"

namespace screenAction {
    class RedNegative: public userscreen::ScreenButton {
        public:
            RedNegative(int x, int y, int width, int height, pros::c::color_e color, std::string text = "") : userscreen::ScreenButton(x, y, width, height, color, text) {}
            void onclick();
    };

    class RedPositive: public userscreen::ScreenButton {
        public:
            RedPositive(int x, int y, int width, int height, pros::c::color_e color, std::string text = "") : userscreen::ScreenButton(x, y, width, height, color, text) {}
            void onclick();
    };

    class BlueNegative: public userscreen::ScreenButton {
        public:
            BlueNegative(int x, int y, int width, int height, pros::c::color_e color, std::string text = "") : userscreen::ScreenButton(x, y, width, height, color, text) {}
            void onclick();
    };

    class BluePositive: public userscreen::ScreenButton {
        public:
            BluePositive(int x, int y, int width, int height, pros::c::color_e color, std::string text = "") : userscreen::ScreenButton(x, y, width, height, color, text) {}
            void onclick();
    };
};