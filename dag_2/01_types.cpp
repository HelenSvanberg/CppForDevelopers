#include <iostream>
#include <string>

int main() {
    int count{3};
    double temperature{21.5};
    bool alarm{false};
    char command{'q'};
    std::string label{"sensor A"};

    std::cout << "Count: " << count << '\n';
    std::cout << "Temperature: " << temperature << '\n';
    std::cout << std::boolalpha << "Alarm: " << alarm << '\n';
    std::cout << "Command: " << command << '\n';
    std::cout << "Label: " << label << '\n';

    // Resultaten beror på plattformen. sizeof räknar byte.
    std::cout << "sizeof(int): " << sizeof(int) << '\n';
    std::cout << "sizeof(double): " << sizeof(double) << '\n';

    return 0;
}
