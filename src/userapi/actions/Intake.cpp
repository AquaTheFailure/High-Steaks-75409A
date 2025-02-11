#include "user/actions/Intake.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void IntakeIn::onPress() {
        devices::intakeMotor.move(127);
    }

    void IntakeIn::onRelease() {
        devices::intakeMotor.move(0);
    }

    void IntakeOut::onPress() {
        devices::intakeMotor.move(-127);
    }
    void IntakeOut::onRelease() {
        devices::intakeMotor.move(0);
    }
}