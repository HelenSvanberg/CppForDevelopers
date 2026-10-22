#include <compare>
#include <iostream>

struct Reading {
    int sensor_id;
    int value;

    auto operator<=>(const Reading&) const = default;
};

int main() {
    Reading first{1, 80};
    Reading same{1, 80};
    Reading later{2, 10};

    std::cout << std::boolalpha << (first == same) << ' ' << (first < later) << '\n';

    return 0;
}
