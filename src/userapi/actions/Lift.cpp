#include "user/actions/Lift.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void LiftUp::onPress() {
        buttonActions::turnOffSort();
        devices::liftMotor.move(127);
    }

    void LiftUp::onRelease() {
        buttonActions::turnOffSort();
        devices::liftMotor.move(0);
    }

    void LiftDown::onPress() {
        buttonActions::turnOffSort();
        devices::liftMotor.move(-127);
    }
    void LiftDown::onRelease() {
        buttonActions::turnOffSort();
        devices::liftMotor.move(0);
    }
}