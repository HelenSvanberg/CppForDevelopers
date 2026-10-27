#include <iostream>

int next_id() {
    static int counter{};
    return ++counter;
}

int main() {
    int local{10};
    int* dynamic = new int{20};

    const int first = next_id();
    const int second = next_id();

    std::cout << local << ' ' << *dynamic << ' ' << first << ' ' << second << '\n';

    delete dynamic;
    dynamic = nullptr;

    return 0;
}
