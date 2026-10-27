#include <iostream>

int main() {
    int first{10};
    int second{20};

    const int* readable = &first;
    readable = &second;
    // *readable = 30; // Avvisas: värdet får inte ändras genom pekaren.

    int* const fixed = &first;
    *fixed = 15;
    // fixed = &second; // Avvisas: pekaren får inte byta mål.

    std::cout << *readable << ' ' << first << '\n';

    return 0;
}
