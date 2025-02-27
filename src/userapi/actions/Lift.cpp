#include "user/actions/Lift.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void LiftUp::onPress() {
        buttonActions::toggleScore = false;
        devices::liftMotor.move(127);
    }

    void LiftUp::onRelease() {
        buttonActions::toggleScore = false;
        devices::liftMotor.move(0);
    }

    void LiftDown::onPress() {
        buttonActions::toggleScore = false;
        devices::liftMotor.move(-127);
    }
    void LiftDown::onRelease() {
        buttonActions::toggleScore = false;
        devices::liftMotor.move(0);
    }
}