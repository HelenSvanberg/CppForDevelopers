#include <iostream>

int main() {
    int value{10};

    {
        int adjustment{5};

        std::cout << "Inside block: " << value + adjustment << '\n';
    }

    std::cout << "Outside block: " << value << '\n';

    // adjustment finns inte i detta scope.
    // std::cout << adjustment << '\n';

    return 0;
}
