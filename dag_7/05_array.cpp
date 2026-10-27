#include <iostream>

int main() {
    int* values = new int[3]{};

    for (int index{}; index < 3; ++index) {
        values[index] = (index + 1) * 10;
    }

    std::cout << values[0] << ' ' << values[1] << ' ' << values[2] << '\n';

    delete[] values;
    values = nullptr;

    return 0;
}
