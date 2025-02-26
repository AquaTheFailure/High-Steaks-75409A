#pragma once

#include "user/BaseButton.hpp"

namespace buttonActions {
    /**
     * @brief Toggle scoring on mobile goal
     * 
     */
    extern bool toggleScore;
    /**
     * @brief Decides which rings to pick up.
     * 
     * \b True -> Red Rings
     * 
     * \b False -> Blue Rings
     */
    extern bool getRingColor;

    class LiftUp : public button::BaseButton {
        public:
            LiftUp(pros::controller_digital_e_t button) : BaseButton(button) {}
            void onPress();
            void onRelease();
    };

    class LiftDown : public button::BaseButton {
        public:
            LiftDown(pros::controller_digital_e_t button) : BaseButton(button) {}
            void onPress();
            void onRelease();
    };

    class ToggleLift : public button::BaseButton {
        public:
            ToggleLift(pros::controller_digital_e_t button) : BaseButton(button) {}
            void onPress();
    };
};