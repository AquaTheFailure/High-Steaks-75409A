#include "user/actions/Lift.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void LiftUp::onPress() {
        devices::liftMotor.move(127);
        buttonActions::turnOffSort();
    }

    void LiftUp::onRelease() {
        devices::liftMotor.move(0);
        buttonActions::turnOffSort();
    }

    void LiftDown::onPress() {
        devices::liftMotor.move(-127);
        buttonActions::turnOffSort();
    }
    void LiftDown::onRelease() {
        devices::liftMotor.move(0);
        buttonActions::turnOffSort();
    }
}