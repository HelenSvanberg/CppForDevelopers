#include <iostream>

#include "Sensor.hpp"

int main() {
    Sensor room{80};
    Sensor storage{90};

    std::cout << std::boolalpha;

    std::cout << "Room threshold: " << room.threshold() << '\n';
    std::cout << "Storage threshold: " << storage.threshold() << '\n';

    std::cout << "Room alarm for 85: " << room.is_alarm(85) << '\n';
    std::cout << "Storage alarm for 85: " << storage.is_alarm(85) << '\n';

    // Privat data kan inte ändras direkt av anroparen.
    // room.threshold_ = -1;

    return 0;
}
