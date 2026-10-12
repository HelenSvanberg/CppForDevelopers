#include <string>

#include <iostream>

// Deklaration: definitionen ligger i greeting.cpp.
std::string greeting();

int main() {
    std::cout << greeting() << '\n';

    return 0;
}
