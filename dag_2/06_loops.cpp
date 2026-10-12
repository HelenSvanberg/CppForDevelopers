#include <iostream>

int main() {
    std::cout << "for: ";

    for (int index{0}; index < 3; ++index) {
        std::cout << index << ' ';
    }

    std::cout << "\nwhile: ";
    int remaining{3};

    while (--remaining > 0) {
        std::cout << remaining << ' ';
    }

    // do-while kör kroppen minst en gång.
    std::cout << "\ndo-while: ";
    int attempts{};

    do {
        ++attempts;
        std::cout << attempts << ' ';
    } while (attempts < 2);

    // Range-for över en liten fast samling.
    std::cout << "\nrange-for: ";
    const int values[]{10, 20, 30};

    for (int value : values) {
        std::cout << value << ' ';
    }

    // continue hoppar till nästa iteration; break lämnar loopen.
    std::cout << "\ncontinue/break: ";

    for (int value{0}; value < 6; ++value) {
        if (value == 1) {
            continue;
        }

        if (value == 4) {
            break;
        }

        std::cout << value << ' ';
    }

    std::cout << '\n';

    return 0;
}
