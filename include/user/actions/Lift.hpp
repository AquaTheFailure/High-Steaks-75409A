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
            /* Moves lift up to score rings. */
            void onPress();
            /* Stops lift from scoreing rings. */
            void onRelease();
    };

    class LiftDown : public button::BaseButton {
        public:
            LiftDown(pros::controller_digital_e_t button) : BaseButton(button) {}
            /* Moves lift down to eject rings. */
            void onPress();
            /* Stop lift from ejecting rings. */
            void onRelease();
    };
};