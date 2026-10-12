#include <iostream>
#include <limits>
#include <string>

int main() {
    // Formaterad läsning: >> läser ett tal och lämnar radslutet kvar.
    int age{};

    std::cout << "Age: ";

    if (!(std::cin >> age)) {
        std::cerr << "Could not read an integer.\n";
        return 1;
    }

    // Ta bort resten av åldersraden innan vi läser en hel ny rad.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string fullName;

    std::cout << "Full name: ";

    if (!std::getline(std::cin, fullName)) {
        std::cerr << "No name was supplied before EOF.\n";
        return 1;
    }

    std::cout << "Hello, " << fullName << "!\n";
    std::cout << "Age: " << age << '\n';

    // >> accepterar här en heltalsprefix, t.ex. 12 i "12abc".
    // Exempel 07 visar strikt kontroll av hela raden.
    return 0;
}
