#include "user/AutomSelector.hpp"
#include "user/Devices.hpp"
#include <cmath>

using namespace devices;

ASSET(MoveLittle_txt);
ASSET(RedNegative_txt);

namespace automSelector{
    std::string get_selected_name() {
        switch (get_selected()) {
            case 1:
                return "Red Negative";
            case 2:
                return "Red Positive";
            case 3:
                return "Move Little";
            case 4:
                return "Blue Positive";
            case 5:
                return "Blue Negative";
            }
        return "None";
    }

    int get_selected() {
        return (int) round(devices::potentiometer.get_value() / 1023.75) + 1;
    }

    void run_autom() {
        switch (get_selected()) {
            case 1:
                RedNegative();
                break;
            case 2:
                RedPositive();
                break;
            case 3:
                MoveLittle();
                break;
            case 4:
                BluePositive();
                break;
            case 5:
                BlueNegative();
                break;
        }
    }

    void RedNegative() {
        chassis.setPose(-60, 23.5, 270);
        chassis.follow(RedNegative_txt, 10, 5000, false);
        chassis.waitUntil(23);
        mogoMech.toggle();
        liftMotor.move(127);
        pros::delay(1500);
        liftMotor.move(0);
    }

    void RedPositive() {

    }

    void MoveLittle() {
        chassis.setPose(-60, 23, 90);
        chassis.follow(MoveLittle_txt, 10, 2000, true);
    }

    void BluePositive() {

    }

    void BlueNegative() {

    }

}