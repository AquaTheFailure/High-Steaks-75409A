#pragma once

#include "user/BaseButton.hpp"

namespace buttonActions {
    /**
    * @brief Toggle ring sorting.
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

    class RingSort : public button::BaseButton {
        public:
            RingSort(pros::controller_digital_e_t button) : BaseButton(button) {}
            void onPress();
    };

    class ChangeRingSortColor : public button::BaseButton {
        public:
            ChangeRingSortColor(pros::controller_digital_e_t button) : BaseButton(button) {}
            void onPress();
    };
}