#include <iostream>

void increment_if_present(int* value) {
    if (value != nullptr) {
        ++*value;
    }
}

int main() {
    int value{10};
    int* pointer = &value;

    increment_if_present(pointer);
    increment_if_present(nullptr);
    *pointer = 20;

    std::cout << value << '\n';

    return 0;
}
