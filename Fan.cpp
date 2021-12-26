#include "Fan.hpp"
#include <stdexcept>
#include <cmath>

// Fan::Fan() {
//     rpm = 0;
// }

// Fan::Fan(Fan&& other) : rpm(other.rpm) {}

// Fan::Fan(const Fan& other) : rpm(other.rpm) {}

void Fan::setSpeed(int newRpm) {
    if ((newRpm < 1000 and newRpm != 0) or newRpm > 3000) {
        throw std::invalid_argument("Invalid speed");
    }
    auto difference = std::abs(newRpm - rpm);
    for (auto i = 0; i < difference; ++i) {
        if (newRpm - rpm > 0) {
            rpm++;
        } else {
            rpm--;
        }
    }
}

int Fan::getSpeed() const {
    return rpm;
}

bool Fan::disable() {
    rpm = 0;
    return true;
}

bool Fan::enable() {
    rpm = 1000;
    return true;
}
