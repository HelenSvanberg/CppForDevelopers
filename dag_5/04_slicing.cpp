#include <iostream>
#include <string>

class Device {
public:
    virtual ~Device() = default;

    virtual std::string name() const {
        return "device";
    }
};

class Sensor : public Device {
public:
    std::string name() const override {
        return "sensor";
    }
};

void by_value(Device device) {
    std::cout << device.name() << '\n';
}

void by_reference(const Device& device) {
    std::cout << device.name() << '\n';
}

int main() {
    Sensor sensor;

    by_value(sensor);
    by_reference(sensor);

    return 0;
}
