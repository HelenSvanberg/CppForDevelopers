#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

int main() {
    std::string line;
    long long sum{};
    int count{};

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
            if (count >= 1'000'000) {
                throw std::out_of_range{"Maximum number of readings reached"};
            }

            sum += value;
            ++count;
            std::cout << (value >= 80 ? "Alarm\n" : "Normal\n");
        } catch (const std::out_of_range& error) {
            std::cerr << error.what() << '\n';
        }
    }

    if (count == 0) {
        std::cout << "No measurements\n";
    } else {
        const double mean = static_cast<double>(sum) / count;
        std::cout << "Count: " << count << "; mean: " << mean << '\n';
    }

    return 0;
}
