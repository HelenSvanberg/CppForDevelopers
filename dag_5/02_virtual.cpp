#include <iostream>

#include "Source.hpp"

void show(const Source& source) {
    std::cout << source.name() << ": " << source.read() << '\n';
}

int main() {
    ConstantSource constant{20};
    OffsetSource offset{30};

    show(constant);
    show(offset);

    return 0;
}
