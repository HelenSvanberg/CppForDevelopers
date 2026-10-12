#include <iostream>
#include <string>

int next_value(int value) {
    return value + 1;
}

void increment(int& value) {
    ++value;
}

void increment_without_reference(int value) {
    // Eftersom vi inte har en referens till originalvariabeln kommer detta inte ändra något
    ++value;
}

void print_label(const std::string& label) {
    std::cout << "Label: " << label << '\n';
}

int main() {
    int count{5};

    int next = next_value(count);
    std::cout << "Original: " << count << "; result: " << next << '\n';

    increment(count);
    std::cout << "After reference parameter: " << count << '\n';

    increment_without_reference(count);
    std::cout << "After not using a reference, the value will still be the same: " << count << '\n';

    const std::string label{"sensor A"};
    print_label(label);

    return 0;
}
