#include <iostream>

namespace course {

    bool is_alarm(int value, int threshold) {
        return value >= threshold;
    }

    bool is_alarm(int value) {
        return is_alarm(value, 80);
    }

}

int main() {
    std::cout << std::boolalpha;

    std::cout << "Default threshold: " << course::is_alarm(85) << '\n';
    std::cout << "Custom threshold: " << course::is_alarm(85, 90) << '\n';

    // Samma namn, olika parameterlistor. Ingen global tröskel behövs.
    return 0;
}
