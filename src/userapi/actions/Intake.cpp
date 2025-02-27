#include "user/actions/Intake.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void IntakeIn::onPress() {
        buttonActions::turnOffSort();
        devices::intakeMotor.move(127);
    }

    void IntakeIn::onRelease() {
        buttonActions::turnOffSort();
        devices::intakeMotor.move(0);
    }

    void IntakeOut::onPress() {
        buttonActions::turnOffSort();
        devices::intakeMotor.move(-127);
    }
    void IntakeOut::onRelease() {
        buttonActions::turnOffSort();
        devices::intakeMotor.move(0);
    }
}