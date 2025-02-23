#include "user/actions/HailMary.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void HailMaryUp::onPress() {
        devices::hailMaryMotor.move(127);
        devices::liftMotor.move(-75);
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

    void HailMaryMacro::onPress() {
        int degree = 320;
        if (devices::hailMaryMotor.get_position() < degree) {
            devices::hailMaryMotor.move_absolute(degree, 127);
        } else {
            devices::hailMaryMotor.move_absolute(degree, -127);
        }
    }
}