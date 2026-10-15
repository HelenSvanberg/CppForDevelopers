#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>

class Rectangle {
public:
    Rectangle(double width, double height) {
        set_dimensions(width, height);
    }

    void set_dimensions(double width, double height) {
        if (!std::isfinite(width) || !std::isfinite(height)
            || width <= 0 || height <= 0) {
            throw std::out_of_range{"Dimensions must be positive and finite"};
        }

        width_ = width;
        height_ = height;
    }

    double area() const {
        return width_ * height_;
    }

    double width() const {
        return width_;
    }

    double height() const {
        return height_;
    }

private:
    double width_{};
    double height_{};
};

int main() {
    Rectangle rectangle{3, 4};
    std::cout << "Area: " << rectangle.area() << '\n';

    for (double width : {0.0, -1.0, std::numeric_limits<double>::infinity()}) {
        try {
            rectangle.set_dimensions(width, 5);
            std::cout << "Updated: " << rectangle.area() << '\n';
        } catch (const std::out_of_range&) {
            std::cout << "Rejected: " << rectangle.width()
                      << ' ' << rectangle.height() << '\n';
        }
    }

    std::cout << "After rejected updates: " << rectangle.area() << '\n';

    return 0;
}
