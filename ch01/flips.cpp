#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

#include "lib/ch01/counter.hpp"

int main(int argc, char* argv[])
{
    if (argc == 1) return EXIT_FAILURE;
    auto n = std::stoi(argv[1]);
    auto heads = Counter{"heads"};
    auto tails = Counter{"tails"};
    srand(static_cast<unsigned>(time(nullptr)));
    for (auto i = 0; i < n; i++) {
        if (1.0 * rand() / RAND_MAX < 0.5) heads.increment();
        else tails.increment();
    }
    auto d = heads.tally() - tails.tally();
    std::cout
        << heads << '\n'
        << tails << '\n'
        << "delta: " << abs(d) << '\n';
}