#include <fstream>
#include <iostream>

#include "ch04/graph.hpp"
#include "ch04/symbol.hpp"

// ./build/src/ch04/test-symbol-graph ./data/routes.txt ' '
int main(int argc, const char* argv[])
{
    if (argc < 3) return EXIT_FAILURE;
    auto sg = Symbol<Graph>(std::fstream{argv[1]}, argv[2]);
    auto g = sg.g();
    std::cout << g.str() << '\n';
}