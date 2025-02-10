#include "user/BaseButton.hpp"
#include "pros/misc.h"
#include "user/Devices.hpp"

namespace button {
    bool tgEnterIntake = false;
    bool tgExitIntake = false;

    std::vector<BaseButton*> BaseButton::buttonActions;

    BaseButton::BaseButton(pros::controller_digital_e_t button, bool setDebug) : button(button), debug(setDebug) {
        buttonActions.push_back(this);
    }

    void BaseButton::run() {
        for (BaseButton* action : buttonActions) {
            action->update();
            pros::delay(10);
        }
    }

    void BaseButton::update() {
        bool isPressed = devices::controller.get_digital(button);

        if (isPressed && !wasPressed) {
            onPress();
        } else if (!isPressed && wasPressed) {
            onRelease();
        }

        wasPressed = isPressed;
        if (debug) {
            std::cout << isPressed << ", " << wasPressed << std::endl;
        }
    }
}