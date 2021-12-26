#pragma once
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include "IThermometer.hpp"
#include <memory>

class LcdDisplay;

class Controller {
public:
    Controller(IThermometer&, Fan&, double temp, double tolerance, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
private:
    bool inMiddleRange(double currentTemp);
    bool inUpperRange(double currentTemp);
    IThermometer& thermometer_;
    Fan& fan_;
    double targetTemperature_;
    double tolerance_;
};