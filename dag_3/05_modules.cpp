#include <iostream>

#include "sensor.hpp"

int main() {
    course::Status status = course::classify(85);

    std::cout << course::to_text(status) << '\n';

    // Deklaration i sensor.hpp, definition i sensor.cpp.
    return 0;
}
