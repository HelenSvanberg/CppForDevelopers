#ifndef COURSE_SOURCE_HPP
#define COURSE_SOURCE_HPP

#include <stdexcept>
#include <string>

class Source {
public:
    virtual ~Source() = default;

    virtual int read() const = 0;
    virtual std::string name() const = 0;
};

class ConstantSource final : public Source {
public:
    explicit ConstantSource(int value) : value_{value} {
        if (value < 0 || value > 100) {
            throw std::out_of_range{"Value must be 0..100"};
        }
    }

    int read() const override {
        return value_;
    }

    std::string name() const override {
        return "constant";
    }

private:
    int value_;
};

class OffsetSource final : public Source {
public:
    explicit OffsetSource(int value) : value_{value} {
        if (value < -50 || value > 50) {
            throw std::out_of_range{"Value must be -50..50"};
        }
    }

    int read() const override {
        return 50 + value_;
    }

    std::string name() const override {
        return "offset";
    }

private:
    int value_;
};

#endif
