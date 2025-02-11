#include "user/actions/Doinker.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void Doinker::onPress() {
        devices::doinker.toggle();
    }
}