#include "pros/optical.h"
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

    double calculatePercentageDiffrence(double a, double b) {
        double larger = std::max(a, b);
        double smaller = std::min(a, b);

        if (larger == 0) return 0;

        return (smaller / larger);
    }

    bool isRedRing(double hue, pros::c::optical_rgb_s_t rgb, int PERCENTAGE_DIFFRENCE) {
        return (
            (0 <= hue && hue <= 30) || 
            (rgb.blue < rgb.red && PERCENTAGE_DIFFRENCE <= calculatePercentageDiffrence(rgb.red, rgb.blue))
        );
    }

    bool isBlueRing(double hue, pros::c::optical_rgb_s_t rgb, int PERCENTAGE_DIFFRENCE) {
        return (
            (150 <= hue && hue <= 230 && getRingColor == true) ||
            (rgb.red < rgb.blue && PERCENTAGE_DIFFRENCE <= calculatePercentageDiffrence(rgb.red, rgb.blue) && getRingColor == true)
        );
    }

    pros::Task ejectRings([] {
        constexpr int PROXIMITY_THRESHOLD = 200;
        constexpr double PERCENTAGE_DIFFRENCE = 0.30;

        constexpr int RED_FIRST_DELAY = 65;
        constexpr int RED_SECOND_DELAY = 300;
        constexpr int RED_AFTER_DELAY = 200;

        constexpr int BLUE_FIRST_DELAY = 85;
        constexpr int BLUE_SECOND_DELAY = 300;
        constexpr int BLUE_AFTER_DELAY = 200;

        while (true) {
            pros::delay(3);
            
            if (toggleScore == false) {
                continue;
            }

            if (devices::opticalSensor.get_proximity() <= 75) {
                continue;
            }

            double hue = devices::opticalSensor.get_hue();
            pros::c::optical_rgb_s_t rgb = devices::opticalSensor.get_rgb();
            double colorDiffrence = calculatePercentageDiffrence(rgb.red, rgb.blue);
            std::cout << colorDiffrence << std::endl;

            if (isRedRing(hue, rgb, PERCENTAGE_DIFFRENCE) && getRingColor == false) {
                pros::delay(RED_FIRST_DELAY);
                devices::liftMotor.move(-50);
                pros::delay(RED_SECOND_DELAY);
                devices::liftMotor.move(127);
                pros::delay(RED_AFTER_DELAY);
            }

            if (isBlueRing(hue, rgb, PERCENTAGE_DIFFRENCE) && getRingColor == true) {
                pros::delay(BLUE_FIRST_DELAY);
                devices::liftMotor.move(-50);
                pros::delay(BLUE_SECOND_DELAY);
                devices::liftMotor.move(127);
                pros::delay(BLUE_AFTER_DELAY);
            }

        }
    });
}