#include "Controller.hpp"

#include <cmath>

constexpr int kMaxSpeed = 3000;

Controller::Controller(IThermometer& thermo,
                       Fan& f,
                       double temp,
                       double tolerance,
                       std::shared_ptr<LcdDisplay>)
                       : thermometer_(thermo)
                       , fan_(f)
                       , targetTemperature_(temp)
                       , tolerance_(tolerance)
{}

bool Controller::inMiddleRange(double currentTemp) {
    return currentTemp >= targetTemperature_ - tolerance_ && currentTemp <= targetTemperature_ + tolerance_;
}

bool Controller::inUpperRange(double currentTemp) {
    return currentTemp > targetTemperature_ + tolerance_;
}

void Controller::updateRpm() {
    double currentTemp = thermometer_.getTemperature();
    if (inMiddleRange(currentTemp)) {
        fan_.setSpeed(1000);
    }
    else if (inUpperRange(currentTemp)) {
        double temperatureDifference = std::abs(currentTemp - targetTemperature_ + tolerance_);
        int newSpeed = std::min(kMaxSpeed, static_cast<int>(temperatureDifference * 1000));
        fan_.setSpeed(newSpeed);
    }
    else {
        fan_.setSpeed(0);
    }
}

void Controller::displayInfo() {}
