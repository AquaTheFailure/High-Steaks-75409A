#pragma once

#include <vector>
#include "pros/colors.h"
#include <string>

namespace userscreen{
    class ScreenButton{
        private:
            static std::vector<ScreenButton*> registeredButton;
            pros::c::color_e color;
            std::string text;
            int cords1[2];
            int cords2[2];
        public:
            bool inbounds(int pos[2]);
            ScreenButton(int x, int y, int width, int height, pros::c::color_e color, std::string text = "");
            void draw();
            virtual void onclick() {}
    };
}