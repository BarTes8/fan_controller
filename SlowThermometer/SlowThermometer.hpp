#pragma once

#include "../IThermometer.hpp"

class SlowThermometer : public IThermometer {
public:
    SlowThermometer() {};
    double getTemperature() const;
};