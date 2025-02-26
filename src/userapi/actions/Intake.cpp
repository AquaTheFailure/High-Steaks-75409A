#include "user/actions/Intake.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void IntakeIn::onPress() {
        devices::intakeMotor.move(127);
        buttonActions::turnOffSort();
    }

    void IntakeIn::onRelease() {
        devices::intakeMotor.move(0);
        buttonActions::turnOffSort();
    }

    void IntakeOut::onPress() {
        devices::intakeMotor.move(-127);
        buttonActions::turnOffSort();
    }
    void IntakeOut::onRelease() {
        devices::intakeMotor.move(0);
        buttonActions::turnOffSort();
    }
}