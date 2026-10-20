#include <iostream>

#include "Source.hpp"

int main() {
    // Source source; // Avvisas: abstrakt klass.
    ConstantSource source{80};
    const Source& interface = source;

    std::cout << interface.name() << ": " << interface.read() << '\n';

    return 0;
}
