#pragma once

#include "pros/misc.h"
#include <vector>

namespace button{
    class BaseButton {
        private:
            /* The list of registerd buttons. */
            static std::vector<BaseButton*> buttonActions;
            /* The button registerd to run a certain action. */
            pros::controller_digital_e_t button;
            bool wasPressed = false;
            bool enabledTask = false;

        public:
            BaseButton(pros::controller_digital_e_t button);
            virtual ~BaseButton() = default;

            /* Runs all the button actions on it's own task. */
            static void run();
            /* Deletes all registered buttons. */
            static void reset();
            /* Runs the onPress and onRelease functions. */
            void update();
            /* Runs button task on press the button registered. */
            virtual void onPress() {}
            /* Runs button task on release the button registered. */
            virtual void onRelease() {}
    };

}