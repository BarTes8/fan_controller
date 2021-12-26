#pragma once

class IThermometer {
public:
    virtual double getTemperature() const = 0;
    virtual ~IThermometer() {};
};
