#include <stdexcept>

#include "Sensor.hpp"

Sensor::Sensor(int threshold) : threshold_{threshold} {
    if (threshold < 0 || threshold > 100) {
        throw std::out_of_range{"Threshold must be in 0..100"};
    }
}

int Sensor::threshold() const {
    return threshold_;
}

void Sensor::set_threshold(int threshold) {
    if (threshold < 0 || threshold > 100) {
        throw std::out_of_range{"Threshold must be in 0..100"};
    }
    threshold_ = threshold;
}

bool Sensor::is_alarm(int value) const {
    if (value < 0 || value > 100) {
        throw std::out_of_range{"Value must be in 0..100"};
    }

    return value >= threshold_;
}
