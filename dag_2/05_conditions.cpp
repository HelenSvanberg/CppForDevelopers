#include <iostream>
#include <string>

int main() {
    int value{80};

    // if / else if / else och logiska operatorer.
    if (value < 0 || value > 100) {
        std::cout << "Outside 0..100\n";
    } else if (value >= 80) {
        std::cout << "Alarm\n";
    } else {
        std::cout << "Normal\n";
    }

    bool accepted = value >= 0 && value <= 100;

    if (!accepted) {
        std::cout << "Rejected\n";
    }

    // Villkorsoperatorn väljer ett av två värden.
    const std::string message = accepted ? "Accepted" : "Rejected";
    std::cout << message << '\n';

    // switch väljer mellan diskreta alternativ.
    char command{'s'};

    switch (command) {
        case 's':
            std::cout << "Start\n";
            break;

        case 'q':
            std::cout << "Quit\n";
            break;

        default:
            std::cout << "Unknown command\n";
            break;
    }

    return 0;
}
