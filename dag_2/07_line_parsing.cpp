#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;

    std::cout << "Enter one integer per line; q quits.\n";

    // EOF gör villkoret falskt och avslutar loopen.
    while (std::getline(std::cin, line)) {
        if (line == "q") {
            break;
        }

        std::istringstream input{line};
        int value{};
        char extra{};

        if (!(input >> value) || (input >> extra)) {
            std::cerr << "Enter exactly one integer.\n";
            continue;
        }

        std::cout << "Parsed: " << value << '\n';
    }

    // Detta exempel kontrollerar formen, inte intervallet 0..100.
    return 0;
}
