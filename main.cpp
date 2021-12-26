#include "Controller.hpp"
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include "LcdDisplay.hpp"
#include <memory>
#include <iostream>

int main()
try {
    SlowThermometer t;
    Fan f;
    double targetTemperature = 36.6;
    double tolerance = .5;
    Controller oldController{t, f, targetTemperature, tolerance, nullptr};
    oldController.updateRpm();
    oldController.displayInfo();

    Controller newController{t, f, targetTemperature, tolerance, std::shared_ptr<LcdDisplay>()};
    newController.updateRpm();
    newController.displayInfo();

    return 0;
} catch (const std::invalid_argument & e) {
    std::cerr << e.what() << '\n';
    return -1;
}

