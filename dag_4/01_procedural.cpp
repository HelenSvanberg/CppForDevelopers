#include <iostream>

struct SensorData {
    int threshold{80};
};

bool is_alarm(const SensorData& sensor, int value) {
    return value >= sensor.threshold;
}

int main() {
    SensorData sensor;

    std::cout << std::boolalpha << is_alarm(sensor, 85) << '\n';

    // Publik data gör det möjligt att bryta domänregeln.
    sensor.threshold = -1;
    std::cout << "Invalid threshold is possible: " << sensor.threshold << '\n';

    return 0;
}
