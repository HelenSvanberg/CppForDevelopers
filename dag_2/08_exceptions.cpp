#include <iostream>
#include <stdexcept>

int main() {
    const int values[]{80, 101, 20};

    for (int value : values) {
        try {
            std::cout << "Checking: " << value << '\n';

            if (value < 0 || value > 100) {
                throw std::out_of_range{"Value must be in 0..100"};
            }

            std::cout << "Accepted\n";
        } catch (const std::out_of_range& error) {
            std::cerr << "Rejected: " << error.what() << '\n';
        }
    }

    // Efter felet för 101 behandlas även 20.
    return 0;
}
