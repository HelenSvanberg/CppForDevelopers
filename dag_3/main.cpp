#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "sensor.hpp"

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line == "q") {
            break;
        }

        std::istringstream input{line};
        int value{};
        char extra{};

        if (!(input >> value) || (input >> extra)) {
            std::cerr << "Enter one integer\n";
            continue;
        }

        try {
            std::cout << course::to_text(course::classify(value)) << '\n';
        } catch (const std::out_of_range& error) {
            std::cerr << error.what() << '\n';
        }
    }
}
