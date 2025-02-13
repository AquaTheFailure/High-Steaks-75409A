#include "user/BaseButton.hpp"
#include "pros/rtos.hpp"
#include "user/Devices.hpp"

namespace button {
    std::vector<BaseButton*> BaseButton::buttonActions;

    BaseButton::BaseButton(pros::controller_digital_e_t button, bool enabledTask) {
        this->button = button;
        this->enabledTask = enabledTask;
        buttonActions.push_back(this);
    }

    void BaseButton::run() {
        pros::Task buttonTask([&]() {
            while (true) {
                for (BaseButton* action : buttonActions) {
                    action->update();
                }
                pros::delay(10);
            }
        });
    }

    void BaseButton::update() {
        bool isPressed = devices::controller.get_digital(button);

        if (isPressed && !wasPressed) {
            onPress();
        } else if (!isPressed && wasPressed) {
            onRelease();
        }

        wasPressed = isPressed;
    }

    void BaseButton::reset() {
        buttonActions.clear();
    }
}