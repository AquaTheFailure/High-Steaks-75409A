#pragma once

#include "user/BaseButton.hpp"

namespace buttonActions {
    class IntakeIn : public button::BaseButton {
        public:
            IntakeIn(pros::controller_digital_e_t button, bool enabledTask = false) : BaseButton(button, enabledTask) {}
            void onPress();
            void onRelease();
    };

    class IntakeOut : public button::BaseButton {
        public:
            IntakeOut(pros::controller_digital_e_t button, bool enabledTask = false) : BaseButton(button, enabledTask) {}
            void onPress();
            void onRelease();
    };
};