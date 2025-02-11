#pragma once

#include "user/BaseButton.hpp"

namespace buttonActions {
    class Doinker : public button::BaseButton {
        public:
            Doinker(pros::controller_digital_e_t button, bool enabledTask = false) : BaseButton(button, enabledTask) {}
            void onPress();
    };
};