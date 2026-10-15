#include <iostream>

#include "Sensor.hpp"

int main() {
    Sensor original{80};

    {
    
    Sensor copy{original};
        copy.set_threshold(90);

        std::cout << "Original: " << original.threshold() << '\n';
        std::cout << "Copy: " << copy.threshold() << '\n';
    }

    // Kopians automatiska livstid har avslutats; originalet finns kvar.
    std::cout << "After block: " << original.threshold() << '\n';

    return 0;
}
