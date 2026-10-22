#include <iostream>
#include <stdexcept>

#include "Money.hpp"

int main() {
    Money first{1250};
    Money second{375};
    Money total = first + second;

    std::cout << "Total: " << total << '\n';
    std::cout << std::boolalpha << "Equal: " << (total == Money{1625}) << '\n';
    std::cout << "Less: " << (first < total) << '\n';

    total += Money{5};
    std::cout << "Updated: " << total << '\n';

    try {
        total += Money{Money::limit};
    } catch (const std::out_of_range&) {
        std::cout << "Rejected: " << total << '\n';
    }

    return 0;
}
