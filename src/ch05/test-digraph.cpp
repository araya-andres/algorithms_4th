#include <fstream>
#include <iostream>
#include "ch05/digraph.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2) return EXIT_FAILURE;
    auto g = Digraph::read_from_stream(std::fstream{argv[1]});
    auto r = g.reverse();
    std::cout << g.str() << '\n'
              << r.str() << '\n';
}