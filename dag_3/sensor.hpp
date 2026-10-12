#ifndef COURSE_SENSOR_HPP
#define COURSE_SENSOR_HPP

#include <string>

namespace course {
    enum class Status {
        normal,
        alarm
    };

    Status classify(int value, int threshold);

    Status classify(int value);

    std::string to_text(Status status);
}

#endif
