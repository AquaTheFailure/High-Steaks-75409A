#pragma once

#include "user/BaseButton.hpp"

namespace buttonActions {
    class Doinker : public button::BaseButton {
        public:
            Doinker(pros::controller_digital_e_t button) : BaseButton(button) {}
            /* Toggle Doinker Extend And Rectracted */
            void onPress();
    };
};