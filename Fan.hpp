#pragma once

class Fan {
    int rpm = 0;

public:
    //Fan() = default;
    //Fan(const Fan&) = default;
    //Fan(Fan&&) = default;

    void setSpeed(int newRpm);
    int getSpeed() const;
    //bool disable();
    //bool enable();
};