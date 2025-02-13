#include "user/AutomSelector.hpp"
#include "user/Devices.hpp"
#include <cmath>

namespace automSelector{
    std::string get_selected_name() {
        switch (get_selected()) {
            case 1:
                return "Red Negative";
            case 2:
                return "Red Positive";
            case 3:
                return "Blue Negative";
            case 4:
                return "Blue Positive";
        }
        return "";
    }

    int get_selected() {
        return round(devices::potentiometer.get_value() / 1365) + 1;
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
                BlueNegative();
            case 4:
                BluePositive();
        }
    }

    void RedNegative() {

    }

    void RedPositive() {

    }

    void BlueNegative() {

    }

    void BluePositive() {

    }
}