#include <stdexcept>

#include "sensor.hpp"

namespace course {
    Status classify(int value, int threshold) {
        if (value < 0 || value > 100 || threshold < 0 || threshold > 100) {
            throw std::out_of_range{"Expected 0..100"};
        }

        return value >= threshold ? Status::alarm : Status::normal;
    }

    Status classify(int value) {
        return classify(value, 80);
    }

    std::string to_text(Status status) {
        return status == Status::alarm ? "Alarm" : "Normal";
    }
}
