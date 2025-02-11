#include "user/actions/Lift.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void LiftUp::onPress() {
        devices::liftMotor.move(127);
    }

    void LiftUp::onRelease() {
        devices::liftMotor.move(0);
    }

    void LiftDown::onPress() {
        devices::liftMotor.move(-127);
    }
    void LiftDown::onRelease() {
        devices::liftMotor.move(0);
    }
}