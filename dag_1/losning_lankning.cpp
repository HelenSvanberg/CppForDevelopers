#include <iostream>

void initialize_cout();

int main() {
    initialize_cout();
    std::cout << "Hello World!\n";

    return 0;
}

// Anropet behöver en definition, inte bara en deklaration.
void initialize_cout() {
    std::cout << std::boolalpha;
}
