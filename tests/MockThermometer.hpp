#pragma once

#include "IThermometer.hpp"

class MockThermometer : public IThermometer {
public:
    double getTemperature() const {
        return tmp_;
    };
    ~MockThermometer() {};    
    void setTemperature(double tmp) {
        tmp_ = tmp;
    }

private: 
    double tmp_;
};
