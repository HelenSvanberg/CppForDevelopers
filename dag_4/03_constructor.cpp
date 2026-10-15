#include <iostream>
#include <stdexcept>

#include "Sensor.hpp"

int main() {
    try {
        Sensor valid{80};

        std::cout << "Valid object: " << valid.threshold() << '\n';

        Sensor invalid{-1};

        // Raden nås inte när konstruktorn kastar.
        std::cout << invalid.threshold() << '\n';
    } catch (const std::out_of_range& error) {
        std::cerr << "Construction failed: " << error.what() << '\n';
    }

    return 0;
}
