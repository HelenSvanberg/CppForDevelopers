#include <iostream>

void increment_if_present(int* value) {
    if (value != nullptr) {
        ++*value;
    }
}

int main() {
    int value{10};
    /*
    int* pointer => 11, 20
    const int* => kommer inte gå att kompilera. Ändrar vi funktionen får vi
        att rad 5 måste vara modifyable left value.
    int* const => 11, 20, men om vi försöker få pointer att peka på ett annat
        värde kommer vi inte få kompilera.
    */
    int* pointer = &value;

    increment_if_present(pointer);
    increment_if_present(nullptr);

    std::cout << value << '\n';

    *pointer = 20;

    std::cout << value << '\n';

    return 0;
}
