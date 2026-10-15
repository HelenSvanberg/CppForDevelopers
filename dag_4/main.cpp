#include <iostream>
#include <stdexcept>

#include "Sensor.hpp"

int main() {
    Sensor a{80};
    Sensor b{90};

    std::cout << std::boolalpha
              << a.is_alarm(85) << ' '
              << b.is_alarm(85) << '\n';

    a.set_threshold(90);

    try {
        a.set_threshold(101);
    }
    catch (const std::out_of_range& error) {
        std::cerr << error.what() << '\n';
    }

    std::cout << "Threshold after rejected update: " << a.threshold() << '\n';

    Sensor copy{a};
    copy.set_threshold(70);
    std::cout << "Original: " << a.threshold() << "; copy: " << copy.threshold() << '\n';
}
