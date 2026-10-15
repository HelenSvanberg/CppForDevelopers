#ifndef COURSE_SENSOR_CLASS_HPP
#define COURSE_SENSOR_CLASS_HPP

class Sensor {
public:
    explicit Sensor(int threshold);

    int threshold() const;

    void set_threshold(int threshold);

    bool is_alarm(int value) const;

private:
    int threshold_;
};

#endif
