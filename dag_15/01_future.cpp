#include <future>
#include <iostream>

int main() {
    auto result = std::async(std::launch::async, [] {
        return 20 + 22;
    });

    std::cout << "Result: " << result.get() << '\n';
}
