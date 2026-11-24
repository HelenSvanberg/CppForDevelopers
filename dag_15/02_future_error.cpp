#include <future>
#include <iostream>
#include <stdexcept>

int main() {
    auto result = std::async(std::launch::async, []() -> int {
        throw std::runtime_error{"Invalid input"};
    });

    try {
        (void)result.get();
    } catch (const std::runtime_error& error) {
        std::cout << "Caught: " << error.what() << '\n';
    }
}
