#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

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
            if (value < 0 || value > 100) {
                throw std::out_of_range{"Value must be in 0..100"};
            }
            std::cout << (value >= 80 ? "Alarm\n" : "Normal\n");
        } catch (const std::out_of_range& error) {
            std::cerr << error.what() << '\n';
        }
    }

    return 0;
}
