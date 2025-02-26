#pragma once

#include "user/BaseButton.hpp"

namespace buttonActions {
    class HailMaryUp : public button::BaseButton {
        public:
            HailMaryUp(pros::controller_digital_e_t button) : BaseButton(button) {}
            /* Moves HailMary up. */
            void onPress();
            /* Stops HailMary moving up. */
            void onRelease();
    };

    class HailMaryDown : public button::BaseButton {
        public:
            HailMaryDown(pros::controller_digital_e_t button) : BaseButton(button) {}
            /* Moves HailMary down. */
            void onPress();
            /* Stops HailMary moving down. */
            void onRelease();
    };

    class HailMaryMacro : public button::BaseButton {
        public:
            HailMaryMacro(pros::controller_digital_e_t button) : BaseButton(button) {}
            /* Moves HailMarry to position to grab ring. */
            void onPress();
    };
};