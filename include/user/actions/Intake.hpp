#pragma once

#include "user/BaseButton.hpp"

namespace buttonActions {
    class IntakeIn : public button::BaseButton {
        public:
            IntakeIn(pros::controller_digital_e_t button) : BaseButton(button) {}
            void onPress();
            void onRelease();
    };

    class IntakeOut : public button::BaseButton {
        public:
            IntakeOut(pros::controller_digital_e_t button) : BaseButton(button) {}
            void onPress();
            void onRelease();
    };
};