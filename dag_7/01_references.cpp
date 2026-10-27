#include <iostream>

void increment(int& value) {
    ++value;
}

int main() {
    int value{10};
    int& alias = value;

    alias = 20;
    increment(value);

    std::cout << value << ' ' << alias << '\n';

    return 0;
}
