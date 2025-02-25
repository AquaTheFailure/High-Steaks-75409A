#include "user/Devices.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/misc.h"

namespace devices {
    pros::MotorGroup leftMotors({-14, -13, -12}, pros::MotorGearset::blue);
    pros::MotorGroup rightMotors({18, 17, 16}, pros::MotorGearset::blue);

    pros::Imu imu(15);

    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                                &rightMotors, // right motor group
                                12.75, // 10 inch track width
                                lemlib::Omniwheel::NEW_275, // using new 4" omnis
                                600, // drivetrain rpm is 360
                                8 // horizontal drift is 2. If we had traction wheels, it would have been 8
    );

    // lateral motion controller
    lemlib::ControllerSettings linearController(5, // proportional gain (kP)
        0, // integral gain (kI)
        10, // derivative gain (kD)
        0, // anti windup
        1, // small error range, in inches
        100, // small error range timeout, in milliseconds
        3, // large error range, in inches
        500, // large error range timeout, in milliseconds
        20 // maximum acceleration (slew)
    );

    // angular motion controller
    lemlib::ControllerSettings angularController(1.35, // proportional gain (kP)
                                        0, // integral gain (kI)
                                        9.9, // derivative gain (kD)
                                        0, // anti windup
                                        1, // small error range, in inches
                                        100, // small error range timeout, in milliseconds
                                        3, // large error range, in inches
                                        500, // large error range timeout, in milliseconds
                                        0 // maximum acceleration (slew)
    );
    
    // sensors for odometry
    lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel
                                nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                                nullptr, // horizontal tracking wheel
                                nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                                &imu // inertial sensor
    );

    // input curve for throttle input during driver control
    lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                        10, // minimum output where drivetrain will move out of 127
                                        1.019 // expo curve gain
    );

    // input curve for steer input during driver control
    lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                    10, // minimum output where drivetrain will move out of 127
                                    1.019 // expo curve gain
    );

    // create the chassis
    lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);

    pros::Motor liftMotor(19);
    pros::Motor intakeMotor(20);
    pros::Motor hailMaryMotor(10);

    pros::adi::Pneumatics mogoMech(1, false);
    pros::adi::Pneumatics doinker(2, false);

    pros::adi::Potentiometer potentiometer(3);
}

// Button Controll setup
namespace configuredButtons {
    // buttonActions::Doinker doinkerButton(pros::E_CONTROLLER_DIGITAL_LEFT);
    buttonActions::Doinker doinkerButton(pros::E_CONTROLLER_DIGITAL_Y);

    // buttonActions::MogoMech mogoMechButton(pros::E_CONTROLLER_DIGITAL_A);
    buttonActions::MogoMech mogoMechButton(pros::E_CONTROLLER_DIGITAL_B);
    
    buttonActions::HailMaryUp hailMaryUpButton(pros::E_CONTROLLER_DIGITAL_UP);
    buttonActions::HailMaryDown hailMaryDownButton(pros::E_CONTROLLER_DIGITAL_DOWN);
    buttonActions::HailMaryMacro hailMaryMacro(pros::E_CONTROLLER_DIGITAL_X);

    buttonActions::LiftUp liftUpButton(pros::E_CONTROLLER_DIGITAL_L1);
    buttonActions::LiftDown liftDownButton(pros::E_CONTROLLER_DIGITAL_L2);

    buttonActions::IntakeIn intakeInButton(pros::E_CONTROLLER_DIGITAL_R1);
    buttonActions::IntakeOut intakeOutButton(pros::E_CONTROLLER_DIGITAL_R2);
}