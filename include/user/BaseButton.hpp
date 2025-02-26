#pragma once

#include "pros/misc.h"
#include <vector>

namespace button{
    class BaseButton {
        private:
            static std::vector<BaseButton*> buttonActions;
            pros::controller_digital_e_t button;
            bool wasPressed = false;
            bool enabledTask = false;

        public:
            BaseButton(pros::controller_digital_e_t button);
            virtual ~BaseButton() = default;

            static void run();
            static void reset();
            void update();
            virtual void onPress() {}
            virtual void onRelease() {}
    };

}