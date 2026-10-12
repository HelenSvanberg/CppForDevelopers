#include <iostream>

int main() {
    int total{5};
    int count{2};

    if (count == 0) {
        std::cerr << "Cannot divide by zero.\n";
        return 1;
    }

    int integerResult = total / count;
    double tooLate = total / count;
    double average = static_cast<double>(total) / count;

    std::cout << "Integer division: " << integerResult << '\n';
    std::cout << "Conversion after division: " << tooLate << '\n';
    std::cout << "Conversion before division: " << average << '\n';

    return 0;
}
