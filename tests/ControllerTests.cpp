#include "external/catch.hpp"
#include "external/hippomocks.h"
#include "Controller.hpp"
#include "MockThermometer.hpp"

TEST_CASE("Controller - setSpeed() behavior", "[Controller]") {

    MockThermometer t;
    Fan f;
    constexpr double targetTemperature = 36.6;
    constexpr double tolerance = .5;
    Controller c{t, f, targetTemperature, tolerance, nullptr};
    // oldController.updateRpm();
    // oldController.displayInfo();

    constexpr int disabledRpm = 0;
    constexpr int minRpm = 1000;
    constexpr int maxRpm = 3000;

    SECTION("is update of speed working for 0 C") {
        CHECK(f.getSpeed() == disabledRpm);
    }

    SECTION("Given temperature target fan controller should set rpm to 1000") {
        t.setTemperature(targetTemperature);
        c.updateRpm();
        CHECK(f.getSpeed() == minRpm);
    }

    SECTION("Given temperature range fan controller should set rpm to 1000") {
        t.setTemperature(targetTemperature - tolerance);
        c.updateRpm();
        CHECK(f.getSpeed() == minRpm);
    }

    SECTION("Given temperature below temp tolerance fan controller should set rpm to 0") {
        t.setTemperature(targetTemperature - tolerance - 1);
        c.updateRpm();
        CHECK(f.getSpeed() == disabledRpm);
    }

    SECTION("Given temperature above temp tolerance fan controller should set rpm to 0") {
        int currentSpeed = f.getSpeed();
        t.setTemperature(targetTemperature + tolerance + 1);
        c.updateRpm();
        CHECK(f.getSpeed() == 2000);
    }

    
    // SECTION("setting proper values") {
    //     f.setSpeed(minRpm);
    //     CHECK(f.getSpeed() == minRpm);

    //     f.setSpeed(maxRpm);
    //     CHECK(f.getSpeed() == maxRpm);

    //     f.setSpeed(disabledRpm);
    //     CHECK(f.getSpeed() == disabledRpm);
    // }

    // SECTION("setting invalid values") {
    //     auto before = f.getSpeed();
        
    //     REQUIRE_THROWS_AS(f.setSpeed(minRpm - 1), std::invalid_argument);
    //     CHECK(f.getSpeed() == before);

    //     REQUIRE_THROWS_AS(f.setSpeed(maxRpm + 1), std::invalid_argument);
    //     CHECK(f.getSpeed() == before);
    // }
}
