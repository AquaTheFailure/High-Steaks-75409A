#include "user/actions/Intake.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void IntakeIn::onPress() {
        devices::intakeMotor.move(127);
        buttonActions::toggleScore = false;
    }

    void IntakeIn::onRelease() {
        devices::intakeMotor.move(0);
        buttonActions::toggleScore = false;
    }

    void IntakeOut::onPress() {
        devices::intakeMotor.move(-127);
        buttonActions::toggleScore = false;
    }
    void IntakeOut::onRelease() {
        devices::intakeMotor.move(0);
        buttonActions::toggleScore = false;
    }
}