#ifndef COURSE_ACCOUNT_HPP
#define COURSE_ACCOUNT_HPP

#include <stdexcept>

#include "Money.hpp"

class Account {
public:
    explicit Account(Money opening_balance) : balance_{opening_balance} {
        if (opening_balance < Money{0}) {
            throw std::invalid_argument{"Opening balance must not be negative"};
        }
    }

    Money balance() const {
        return balance_;
    }

    void deposit(const Money& amount) {
        require_positive(amount);

        // Money kontrollerar sin maxgräns innan saldot ändras.
        balance_ += amount;
    }

    void withdraw(const Money& amount) {
        require_positive(amount);

        if (balance_ < amount) {
            throw std::out_of_range{"Insufficient funds"};
        }

        // Beräkna och validera det nya värdet före tilldelningen.
        const Money remaining{balance_.cents() - amount.cents()};
        balance_ = remaining;
    }

private:
    void require_positive(const Money& amount) const {
        if (amount < Money{0}) {
            throw std::invalid_argument{"Amount must be positive"};
        }
    }

    Money balance_;
};

#endif
