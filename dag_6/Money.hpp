#ifndef COURSE_MONEY_HPP
#define COURSE_MONEY_HPP

#include <iomanip>
#include <ostream>
#include <stdexcept>

class Money {
public:
    explicit Money(long long cents) : cents_{cents} {
        if (cents < -limit || cents > limit) {
            throw std::out_of_range{"Money exceeds supported range"};
        }
    }

    long long cents() const {
        return cents_;
    }

    Money& operator+=(const Money& other) {
        // Två redan begränsade värden ryms i long long före valideringen.
        const Money candidate{cents_ + other.cents_};
        cents_ = candidate.cents_;

        return *this;
    }

    friend Money operator+(Money left, const Money& right) {
        left += right;

        return left;
    }

    friend bool operator==(const Money& left, const Money& right) {
        return left.cents_ == right.cents_;
    }

    friend bool operator<(const Money& left, const Money& right) {
        return left.cents_ < right.cents_;
    }

    friend std::ostream& operator<<(std::ostream& output, const Money& money) {
        const long long magnitude = money.cents_ < 0 ? -money.cents_ : money.cents_;
        const char old_fill = output.fill();

        if (money.cents_ < 0) {
            output << '-';
        }

        output << magnitude / 100 << '.'
               << std::setfill('0') << std::setw(2) << magnitude % 100;
        output.fill(old_fill);

        return output;
    }

    static constexpr long long limit{1'000'000'000};

private:
    long long cents_;
};

#endif
