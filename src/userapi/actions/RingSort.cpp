#include "user/actions/RingSorter.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    bool toggleScore = false;
    bool getRingColor = true;

    void RingSort::onPress() {
        if (toggleScore) {
            turnOffSort();
            
        } else {
            turnOnSort();
        }
    }

    void ChangeRingSortColor::onPress() {
        getRingColor = !getRingColor;
    }
    
    void turnOnSort() {
        toggleScore = true;
        devices::intakeMotor.move(127);
        devices::liftMotor.move(127);
    }
    
    void turnOffSort() {
        toggleScore = false;
        devices::intakeMotor.move(0);
        devices::liftMotor.move(0);
    }

    pros::Task ejectRings([] {
        constexpr int PROXIMITY_THRESHOLD = 200;
        constexpr int FIRST_DELAY = 30;
        constexpr int SECOND_DELAY = 300;
        constexpr int AFTER_DELAY = 200;

        while (true) {
            pros::delay(3);
            
            if (toggleScore == false) {
                continue;
            }

            if (devices::opticalSensor.get_proximity() <= 125) {
                continue;
            }

            double hue = devices::opticalSensor.get_hue();
            pros::c::optical_rgb_s_t rgb = devices::opticalSensor.get_rgb();
            
            // First Part is checking for is Red Ring, Second Part is checking for Blue Ring.
            if (!(
                // Hue: if red 
                (0 <= hue && hue <= 30 && getRingColor == false) ||
                (150 <= hue && hue <= 230 && getRingColor == true) ||
                (200 <= rgb.red && getRingColor == false) ||
                (500 <= rgb.blue && getRingColor == true)
            )) {
                continue;
            }
            
            pros::delay(FIRST_DELAY);
            devices::liftMotor.move(-75);
            pros::delay(SECOND_DELAY);
            devices::liftMotor.move(127);
            pros::delay(AFTER_DELAY);
        }
    });
}