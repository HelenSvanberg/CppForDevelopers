#include <iostream>

int main() {
    int count{};                 // Initierat till 0.
    auto limit = 100;             // Härleds till int.
    const int saved{count};       // Får inte tilldelas ett nytt värde.
    constexpr int maxValue{100};  // Konstant uttryck.

    count = 5;
    limit = 90;

    std::cout << "Count: " << count << '\n';
    std::cout << "Saved: " << saved << '\n';
    std::cout << "Limit: " << limit << '\n';
    std::cout << "Maximum: " << maxValue << '\n';

    // Avkommentera en rad i taget för ett avsiktligt kompileringsfel.
    // int narrowed{3.5};
    // maxValue = 7;

    return 0;
}
