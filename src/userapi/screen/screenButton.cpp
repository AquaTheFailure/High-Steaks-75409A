#include "user/screen/screenButton.hpp"
#include "user/Devices.hpp"
#include "pros/screen.hpp"

namespace userscreen {
    bool ScreenButton::inbounds(int x, int y) {
        return (cords1[0] <= x && x <= cords2[0]) && (cords1[1] <= y && y <= cords2[1]);
    }

    std::vector<ScreenButton*> userscreen::ScreenButton::registeredButton;

    ScreenButton::ScreenButton(int x, int y, int width, int height, pros::c::color_e color, std::string text) {
        this->cords1[0] = x;
        this->cords1[1] = y;
        this->cords2[0] = x + width;
        this->cords2[1] = y + height;
        this->color = color;
        this->text = text;
        registeredButton.push_back(this);
    }

    void ScreenButton::draw() {
        pros::screen::set_pen(color);
        pros::screen::draw_rect(cords1[0], cords1[1], cords2[0], cords2[1]);
    }

    void ScreenButton::run(int x, int y) {
        for (ScreenButton* action : registeredButton) {
            if (action->inbounds(x, y)) {
                action->onclick();
            }
        }
    }
}