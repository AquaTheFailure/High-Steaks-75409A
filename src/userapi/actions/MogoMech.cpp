#include "user/actions/MogoMech.hpp"
#include "user/Devices.hpp"

namespace buttonActions {
    void MogoMech::onPress() {
        devices::mogoMech.toggle();
    }
}