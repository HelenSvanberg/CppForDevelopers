#include <iostream>

int main() {
    int value{42};
    const int* observer = &value;

    {
        int temporary{7};
        std::cout << temporary << '\n';

        // observer = &temporary; // Då skulle observer bli hängande efter blocket.
    }

    std::cout << *observer << '\n';

    return 0;
}
