#include "user/screen/automButton.hpp"
#include "pros/llemu.hpp"

namespace screenAction {
    void RedNegative::onclick() {
        pros::lcd::print(3, "Red Negative");
    }

    void RedPositive::onclick() {
        pros::lcd::print(3, "Red Positive");
    }

    void BlueNegative::onclick() {
        pros::lcd::print(3, "Blue Negative");
    }

    void BluePositive::onclick() {
        pros::lcd::print(3, "Blue Positive");
    }
}