#include "user/actions/Lift.hpp"
#include "user/Devices.hpp"
#include "pros/misc.h"

namespace buttonActions {
    bool toggleScore = false;
    bool getRingColor = true;

    void LiftUp::onPress() {
        devices::liftMotor.move(127);
        toggleScore = false;
    }

    void LiftUp::onRelease() {
        devices::liftMotor.move(0);
        toggleScore = false;
    }

    void LiftDown::onPress() {
        devices::liftMotor.move(-127);
        toggleScore = false;
    }
    void LiftDown::onRelease() {
        devices::liftMotor.move(0);
        toggleScore = false;
    }

    void ToggleLift::onPress() {
        if (toggleScore) {
            devices::intakeMotor.move(0);
            devices::liftMotor.move(0);
            toggleScore = false;
        } else {
            devices::intakeMotor.move(0);
            devices::liftMotor.move(127);
            toggleScore = true;
        }
    }

    // pros::Task ejectRings([] {
    //     while (true) {
    //         pros::delay(25);

    //         if (toggleScore == false) {
    //             continue;
    //         }

    //         double hue = devices::opticalSensor.get_hue();
            
    //         if (hue >= 0 && hue <= 50 && getRingColor == true) { // Hue range for red
    //             continue;
    //         }

    //         if (hue >= 200 && hue <= 250 && getRingColor == false) { // Hue range for blue
    //             continue;
    //         }

    //         pros::delay(500);
    //         devices::liftMotor.move(-127);
    //         pros::delay(200);
    //         devices::liftMotor.move(127);
    //     }
    // });
}