#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <future>
#include <iostream>
#include <vector>

using InputIterator = std::vector<unsigned>::const_iterator;

std::uint64_t summarize(InputIterator first, InputIterator last) {
    std::uint64_t total{};

    for (auto it = first; it != last; ++it) {
        const unsigned value = *it;
        total += std::uint64_t{value} * value;
    }

    return total;
}

std::uint64_t summarize_parallel(const std::vector<unsigned>& values) {
    const auto middle = values.cbegin() + values.size() / 2;
    auto left = std::async(std::launch::async, summarize, values.cbegin(), middle);

    const auto right = summarize(middle, values.cend());
    return left.get() + right;
}

template<class Operation>
double time_ms(Operation operation, std::uint64_t& output) {
    const auto start = std::chrono::steady_clock::now();
    output = operation();
    const auto elapsed = std::chrono::steady_clock::now() - start;
    return std::chrono::duration<double, std::milli>{elapsed}.count();
}

int main() {
    std::vector<unsigned> values(1'000'000);

    for (std::size_t index{}; index < values.size(); ++index) {
        values[index] = static_cast<unsigned>(index % 101);
    }

    std::array<double, 7> sequential{};
    std::array<double, 7> parallel{};
    std::uint64_t expected{};
    std::uint64_t actual{};

    for (std::size_t run{}; run < sequential.size(); ++run) {
        auto measure_sequential = [&] {
            sequential[run] = time_ms([&] { return summarize(values.cbegin(), values.cend()); }, expected);
        };
        auto measure_parallel = [&] {
            parallel[run] = time_ms([&] { return summarize_parallel(values); }, actual);
        };

        if (run % 2 == 0) {
            measure_sequential();
            measure_parallel();
        } else {
            measure_parallel();
            measure_sequential();
        }

        if (expected != actual) {
            std::cerr << "Different results\n";
            return 1;
        }
    }

    std::sort(sequential.begin(), sequential.end());
    std::sort(parallel.begin(), parallel.end());

    std::cout << "Result: " << expected << '\n';
    std::cout << "Sequential median (ms): " << sequential[3] << '\n';
    std::cout << "Parallel median (ms): " << parallel[3] << '\n';
}
