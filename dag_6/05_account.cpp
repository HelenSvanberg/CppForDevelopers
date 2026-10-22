#include <iostream>
#include <stdexcept>

#include "Account.hpp"

int main() {
    Account account{Money{10'000}};

    std::cout << "Start: " << account.balance() << '\n';

    account.deposit(Money{2'500});
    std::cout << "Deposited: " << account.balance() << '\n';

    account.withdraw(Money{3'000});
    std::cout << "Withdrawn: " << account.balance() << '\n';

    try {
        account.withdraw(Money{10'000});
    } catch (const std::out_of_range&) {
        std::cout << "Rejected: " << account.balance() << '\n';
    }

    // En kopia av saldot ger inte tillgång till kontots privata tillstånd.
    Money copy = account.balance();
    copy += Money{100};

    std::cout << "Copy: " << copy << '\n';
    std::cout << "Account: " << account.balance() << '\n';

    return 0;
}
