#include <iostream>
#include <stdexcept>

#include "Source.hpp"

void report(const Source& source) {
    const int value = source.read();

    std::cout << source.name() << ": " << value
              << (value >= 80 ? " Alarm\n" : " Normal\n");
}

int main() {
    ConstantSource constant{20};
    OffsetSource offset{30};

    report(constant);
    report(offset);

    try {
        ConstantSource invalid{101};
        report(invalid);
    } catch (const std::out_of_range&) {
        std::cout << "Rejected\n";
    }

    return 0;
}
