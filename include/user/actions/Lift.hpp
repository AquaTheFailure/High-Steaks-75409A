#pragma once

#include "user/BaseButton.hpp"

namespace buttonActions {
    class LiftUp : public button::BaseButton {
        public:
            LiftUp(pros::controller_digital_e_t button, bool enabledTask = false) : BaseButton(button, enabledTask) {}
            void onPress();
            void onRelease();
    };

    class LiftDown : public button::BaseButton {
        public:
            LiftDown(pros::controller_digital_e_t button, bool enabledTask = false) : BaseButton(button, enabledTask) {}
            void onPress();
            void onRelease();
    };
};