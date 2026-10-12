#include <iostream>

// Deklaration: anroparen får veta funktionens kontrakt.
int add(int left, int right);
int max(int a, int b);
void print_result(int value);

int main() {
    int result = add(3, 4);

    print_result(result);

    result = max(3, 4);

    print_result(result);

    return 0;
}

// Definition: här finns själva implementationen.
int add(int left, int right) {
    return left + right;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void print_result(int value) {
    std::cout << "Result: " << value << '\n';
}
