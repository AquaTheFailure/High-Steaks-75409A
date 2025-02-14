#pragma once

#include <string>

namespace automSelector {
    std::string get_selected_name();
    int get_selected();
    void run_autom();
    
    void RedNegative();
    void RedPositive();
    void MoveLittle();
    void BlueNegative();
    void BluePositive();
}