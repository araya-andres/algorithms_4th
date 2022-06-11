#include <fstream>
#include <iomanip>
#include <iostream>
#include "ch04/cycle.hpp"
#include "ch04/two-color.hpp"

int main(int argc, const char* argv[])
{
    if (argc < 2) return EXIT_FAILURE;
    auto g = Graph::read_from_stream(std::fstream{argv[1]});
    std::cout << std::boolalpha;

    auto cycle = Cycle{g};
    std::cout << cycle.has_cycle() << '\n';

    auto two_color = TwoColor{g};
    std::cout << two_color.is_bipartite() << '\n';
}