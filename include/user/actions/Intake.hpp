#pragma once

#include "user/BaseButton.hpp"

namespace buttonActions {
    class IntakeIn : public button::BaseButton {
        public:
            IntakeIn(pros::controller_digital_e_t button) : BaseButton(button) {}
            /* Moves Intake inward to grab rings. */
            void onPress();
            /* Stops Intake from grabing rings. */
            void onRelease();
    };

    class IntakeOut : public button::BaseButton {
        public:
            IntakeOut(pros::controller_digital_e_t button) : BaseButton(button) {}
            /* Moves Intake outward to eject rings. */
            void onPress();
            /* Stops Intake from ejecting rings. */
            void onRelease();
    };
};