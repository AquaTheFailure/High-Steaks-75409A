#pragma once

#include "pros/misc.h"
#include <vector>

namespace button{
    extern bool tgEnterIntake;
    extern bool tgExitIntake;

    class BaseButton {
        private:
            static std::vector<BaseButton*> buttonActions;
            pros::controller_digital_e_t button;
            bool wasPressed = false;
            bool debug = false;

        public:
            BaseButton(pros::controller_digital_e_t button, bool setDebug = false);
            virtual ~BaseButton() = default;

            static void run();
            void update();

            virtual void onPress() {}
            virtual void onRelease() {}
    };

}