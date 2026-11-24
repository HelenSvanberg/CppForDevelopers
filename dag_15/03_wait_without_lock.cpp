#include <future>
#include <iostream>
#include <mutex>

int main() {
    std::mutex mutex;
    int value{21};
    std::future<int> result;

    {
        std::lock_guard<std::mutex> lock{mutex};

        result = std::async(std::launch::async, [&mutex, &value] {
            std::lock_guard<std::mutex> worker_lock{mutex};

            value *= 2;
            return value;
        });

        // Calling result.get() here would deadlock:
        // main holds mutex and waits for a worker that needs mutex.
    } // Release mutex before waiting for the worker.

    std::cout << "Result: " << result.get() << '\n';
}
