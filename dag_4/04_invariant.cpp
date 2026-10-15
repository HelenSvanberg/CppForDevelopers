#include <iostream>
#include <stdexcept>

#include "Sensor.hpp"

int main() {
    Sensor sensor{80};

    sensor.set_threshold(90);
    std::cout << "Before rejected update: " << sensor.threshold() << '\n';

    try {
        sensor.set_threshold(101);
    } catch (const std::out_of_range& error) {
        std::cerr << "Update failed: " << error.what() << '\n';
    }

    std::cout << "After rejected update: " << sensor.threshold() << '\n';

    return 0;
}
