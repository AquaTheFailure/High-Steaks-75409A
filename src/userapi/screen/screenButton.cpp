#include "user/screen/screenButton.hpp"
#include <screen.hpp>

namespace userscreen {
    bool ScreenButton::inbounds(int pos[2]) {
        return (cords1[0] <= pos[0] && pos[0] <= cords2[0]) && (cords1[1] <= pos[1] && pos[1] <= cords2[1]);
    }

    std::vector<ScreenButton*> ScreenButton::registeredButton;

    ScreenButton::ScreenButton(int x, int y, int width, int height, pros::c::color_e color, std::string text) {
        this->cords1[x, y];
        this->cords2[x + width, y + height];
        this->color = color;
        this->text = text;
        registeredButton.push_back(this);
    }

    void ScreenButton::draw() {
        pros::screen::set_pen(color);
        pros::screen::draw_rect(cords1[0], cords1[1], cords2[0], cords2[1]);
        
    }

    void onclick() {}
}