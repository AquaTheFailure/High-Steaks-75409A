#include "user/actions/Lift.hpp"
#include "user/Devices.hpp"
#include "pros/misc.h"

namespace buttonActions {
    bool toggleScore = true;
    bool getRingColor = false;

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
            devices::intakeMotor.move(127);
            devices::liftMotor.move(127);
            toggleScore = true;
        }
    }

    pros::Task ejectRings([] {
        while (true) {
            pros::delay(25);
            
            if (toggleScore == false) {
                continue;
            }

            double hue = devices::opticalSensor.get_hue();
            int firstDelay = 175;
            int secondDelay = 300;
            
            if (hue >= 0 && hue <= 30 && getRingColor == true) { // Hue range for red
                pros::delay(firstDelay);
                devices::liftMotor.move(-127);
                pros::delay(secondDelay);
                devices::liftMotor.move(127);
            }

            if (180 <= hue && hue <= 230 && getRingColor == false) { // Hue range for blue
                pros::delay(firstDelay);
                devices::liftMotor.move(-127);
                pros::delay(secondDelay);
                devices::liftMotor.move(127);
            }

            std::cout << "Hue: " << hue << ", getRingColor: " << getRingColor << std::endl;
        }
    });
}