#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"

namespace devices {
    extern pros::MotorGroup leftMotors;
    extern pros::MotorGroup rightMotors;

    extern pros::Imu imu;
    extern pros::Controller controller;

    extern lemlib::Drivetrain drivetrain;

    extern lemlib::ControllerSettings linearController;
    extern lemlib::ControllerSettings angularController;
    extern lemlib::OdomSensors sensors;
    extern lemlib::ExpoDriveCurve throttleCurve;
    extern lemlib::ExpoDriveCurve steerCurve;
    extern lemlib::Chassis chassis;

    extern pros::Motor conveyorMotor;
    extern pros::Motor intakeMotor;
    extern pros::Motor hailMaryMotor;

    extern pros::adi::Pneumatics mogoMech;
    extern pros::adi::Pneumatics doinker;
}

namespace configuredButtons{
}