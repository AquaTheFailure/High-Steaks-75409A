#include "user/actions/HailMary.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void HailMaryUp::onPress() {
        devices::hailMaryMotor.move(127);
        devices::liftMotor.move(-100);
    }

    void HailMaryUp::onRelease() {
        devices::hailMaryMotor.brake();
        devices::liftMotor.brake();
    }

    void HailMaryDown::onPress() {
        devices::hailMaryMotor.move(-127);
    }

    void HailMaryDown::onRelease() {
        devices::hailMaryMotor.brake();
    }
}