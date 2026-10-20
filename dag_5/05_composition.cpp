#include <iostream>

class AlarmRule {
public:
    bool matches(int value) const {
        return value >= 80;
    }
};

class Monitor {
public:
    bool is_alarm(int value) const {
        return rule_.matches(value);
    }

private:
    AlarmRule rule_;
};

int main() {
    Monitor monitor;

    std::cout << std::boolalpha << monitor.is_alarm(85) << '\n';

    return 0;
}
