#pragma once

#include "pros/optical.h"
#include "pros/rtos.hpp"
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
            /* Toggle between sort and not sorting rings. */
            RingSort(pros::controller_digital_e_t button) : BaseButton(button) {}
            void onPress();
    };

    class ChangeRingSortColor : public button::BaseButton {
        public:
            ChangeRingSortColor(pros::controller_digital_e_t button) : BaseButton(button) {}
            /* Flips the color wanted to sort. */
            void onPress();
    };
    
    /* Turns on ring sorting and related motors. */
    void turnOnSort();

    /* Tuns off ring sorting and related motors. */
    void turnOffSort();

    /* Calculates the diffrence of the 2 numbers based on the bigger number on bottom and larger on top*/
    double calculatePercentageDiffrence(double a, double b);

    /* Checks if hue is red range and checks if red is bigger than blue with the percentage being high enought diffrence. */
    bool isRedRing(double hue, pros::c::optical_rgb_s_t rgb, int PERCENTAGE_DIFFRENCE);

    /* Checks if hue is blue range and checks if blue is bigger than red with the percentage being high enought diffrence. */
    bool isBlueRing(double hue, pros::c::optical_rgb_s_t rgb, int PERCENTAGE_DIFFRENCE);
    
    /* Runs a seperate task to detect a ring infront of optical sensor and eject it if its not the right color. */
    extern pros::Task ejectRings;
}