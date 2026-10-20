#include <iostream>
#include <string>

class Device {
public:
    explicit Device(std::string label) : label_{label} {}

    const std::string& label() const {
        return label_;
    }

private:
    std::string label_;
};

class Sensor : public Device {
public:
    Sensor(std::string label, int value) : Device{label}, value_{value} {}

    int read() const {
        return value_;
    }

private:
    int value_;
};

int main() {
    Sensor sensor{"room", 25};

    std::cout << sensor.label() << ": " << sensor.read() << '\n';

    return 0;
}
