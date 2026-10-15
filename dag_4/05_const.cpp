#include <iostream>

#include "Sensor.hpp"

int main() {
    const Sensor sensor{80};

    std::cout << "Threshold: " << sensor.threshold() << '\n';
    std::cout << std::boolalpha << "Alarm for 85: " << sensor.is_alarm(85) << '\n';

    // Const objekt får använda const-metoder, men inte denna setter.
    // sensor.set_threshold(90);

    return 0;
}
