#pragma once

#include <string>

namespace automSelector {
    extern bool isComp;

    /**
     * @brief Get the selected Autom Value
     * 
     * @return int 
     */
    int get_selected();

    /**
     * @brief Get the selected autom name
     * 
     * @return std::string 
     */
    std::string get_selected_name();

    /**
     * @brief Runs the selected autom
     * 
     */
    void run_autom();
    
    void RedNegative();
    void RedPositive();
    void MoveLittle();
    void BlueNegative();
    void BluePositive();
    void Skills();
}