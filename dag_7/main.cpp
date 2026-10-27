#include <iostream>

void increase(int& value) {
    ++value;
}

void print_if_present(const int* value) {
    if (value == nullptr) {
        std::cout << "No value\n";
        return;
    }

    std::cout << "Observed: " << *value << '\n';
}

int main() {
    int local{20};
    increase(local);
    print_if_present(&local);
    print_if_present(nullptr);

    int* values = new int[3]{};
    values[0] = 10;
    values[1] = 20;
    values[2] = 30;

    const int sum = values[0] + values[1] + values[2];
    std::cout << "Sum: " << sum << '\n';

    delete[] values;
    values = nullptr;

    return 0;
}
