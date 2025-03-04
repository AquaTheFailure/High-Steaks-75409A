#include "lemlib-tarball/api.hpp"
#include "user/AutomSelector.hpp"
#include "pros/misc.hpp"
#include "user/Devices.hpp"
#include "user/actions/Lift.hpp"
#include <cmath>

using namespace devices;

ASSET(MoveLittle_txt);
ASSET(Automs_txt);

lemlib_tarball::Decoder decoder(Automs_txt);

namespace automSelector{
    int get_selected() {
        return (int) round(devices::potentiometerAutom.get_value() / 1023.75) + 1;
    }

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

    void run_autom() {
        if ((int) round(potentiometerMatchSkills.get_value() / 2047.5) == 0) {
            buttonActions::getRingColor = true;
            Skills();
            return;
        }
        
        switch (get_selected()) {
            case 1:
                buttonActions::getRingColor = true;
                RedNegative();
                break;
            case 2:
                buttonActions::getRingColor = true;
                RedPositive();
                break;
            case 3:
                MoveLittle();
                break;
            case 4:
                buttonActions::getRingColor = false;
                BluePositive();
                break;
            case 5:
                buttonActions::getRingColor = false;
                BlueNegative();
                break;
        }
    }

    void RedNegative() {
        chassis.setPose(-61, 47.5, 270);
        chassis.follow(decoder["RN1"], 15, 3000, false, true);
        chassis.waitUntil(39);
        mogoMech.toggle();
        pros::delay(250);
        buttonActions::turnOnSort();

        chassis.follow(decoder["RN2"], 15, 5000, true, true);
    }

    void RedPositive() {
        chassis.setPose(-61, -24.5, 90);
        intakeMotor.move(127);
        chassis.follow(decoder["RP1"], 10, 3000, true, true);
        chassis.waitUntil(56);
        intakeMotor.move(30);
        doinker.toggle();

        chassis.follow(decoder["RP2"], 10, 4000, false, false);
        doinker.toggle();
        pros::delay(400);
        liftMotor.move_relative(200, 127);
        pros::delay(100);

        chassis.follow(decoder["RP3"], 10, 4000, true, false);

        chassis.follow(decoder["RP4"], 10, 3000, false, false);
        mogoMech.toggle();
        pros::delay(200);
        liftMotor.move_relative(600, 127);
        pros::delay(500);
        mogoMech.toggle();
        
        chassis.follow(decoder["RP5"], 10, 3000, true, false);

        chassis.follow(decoder["RP6"], 10, 3000, false, false);
        mogoMech.toggle();
        pros::delay(200);
        liftMotor.move(127);
        
        chassis.follow(decoder["RP7"], 10, 3000, true, false);
    }

    void MoveLittle() {
        chassis.setPose(-60, 23, 90);
        chassis.follow(MoveLittle_txt, 10, 2000, true);
    }

    void BluePositive() {
        chassis.setPose(61, -24.5, 225);
        intakeMotor.move(127);
        chassis.follow(decoder["BP1"], 10, 3000, true, true);
        chassis.waitUntil(56);
        intakeMotor.move(30);
        doinker.toggle();
        liftMotor.move_relative(200, 127);
        intakeMotor.move(-10);

        chassis.follow(decoder["BP2"], 10, 4000, false, false);
        doinker.toggle();
        pros::delay(400);

        chassis.follow(decoder["BP3"], 10, 4000, true, false);

        chassis.follow(decoder["BP4"], 10, 3000, false, false);
        mogoMech.toggle();
        pros::delay(200);
        liftMotor.move_relative(600, 127);
        pros::delay(500);
        mogoMech.toggle();

        chassis.follow(decoder["BP5"], 10, 2500, true, false);


        chassis.follow(decoder["BP6"], 10, 3000, false, false);
        mogoMech.toggle();
        pros::delay(200);
        liftMotor.move_relative(800, 127);

        chassis.follow(decoder["BP7"], 10, 3000, true, false);
    }

    void BlueNegative() {
        chassis.setPose(61, 47.5, 90);
        chassis.follow(decoder["BN1"], 15, 3000, false, true);
        chassis.waitUntil(39);
        mogoMech.toggle();
        pros::delay(250);
        buttonActions::turnOnSort();

        chassis.follow(decoder["BN2"], 15, 5000, true, true);
    }

    void Skills() {
        chassis.setPose(-59, -1, 90);
        chassis.follow(decoder["Skills1"], 10, 2000, true, false);
        pros::delay(100);
        liftMotor.move(127);
        pros::delay(500);
        liftMotor.move(-75);
        pros::delay(100);

        chassis.follow(decoder["Skills2"], 10, 3000, true, false);
        liftMotor.move(0);
        pros::delay(100);

        chassis.follow(decoder["Skills3"], 10, 3000, false, false);
        mogoMech.toggle();
        pros::delay(200);
        buttonActions::turnOnSort();

        chassis.follow(decoder["Skills4"], 15, 6000, true, true);
        chassis.waitUntil(82);
        pros::delay(100);
        chassis.turnToHeading(245, 1500, {}, false);
        pros::delay(100);

        chassis.follow(decoder["Skills5"], 15, 7000, true, false);
        pros::delay(100);

        chassis.follow(decoder["Skills6"], 15, 5000, false, false);
        pros::delay(100);
        chassis.turnToHeading(45, 2000, {}, false);
        pros::delay(500);
        buttonActions::turnOffSort();
        liftMotor.move(-50);
        
        chassis.follow(decoder["Skills7"], 15, 2000, false, false);
        pros::delay(100);
        mogoMech.toggle();
        pros::delay(200);
        liftMotor.move(0);

        chassis.follow(decoder["Skills8"], 15, 7000, true, false);
        pros::delay(100);
        chassis.turnToHeading(180, 2000, {.maxSpeed=75}, false);
        pros::delay(100);

        chassis.follow(decoder["Skills9"], 10, 3000, false, false);
        pros::delay(100);
        mogoMech.toggle();
        chassis.setPose(-47.5, 23.5, 174);
    }
}