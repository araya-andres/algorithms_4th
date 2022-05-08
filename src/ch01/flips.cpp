#include <cstdlib>
#include <iostream>
#include <string>
#include "ch01/counter.hpp"

std::ostream& operator<<(std::ostream& os, const Counter& counter)
{
    return os << counter.toString();
}

int main(int argc, char* argv[])
{
    if (argc == 1) return EXIT_FAILURE;
    auto n = std::stoi(argv[1]);
    Counter heads{"heads"};
    Counter tails{"tails"};
    for (int i = 0; i < n; i++) {
        if (1.0 * rand() / RAND_MAX < 0.5) heads.increment();
        else tails.increment();
    }
    auto d = heads.tally() - tails.tally();
    std::cout
        << heads << '\n'
        << tails << '\n'
        << "delta: " << abs(d) << '\n';
}