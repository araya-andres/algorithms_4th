#include <fstream>
#include <iostream>

#include "ch04/symbol.hpp"
#include "ch05/digraph.hpp"
#include "ch05/topological.hpp"

// ./build/src/ch04/test-symbol-digraph ./data/jobs.txt '/'
int main(int argc, const char* argv[])
{
    if (argc < 3) return EXIT_FAILURE;
    auto sg = Symbol<Digraph>(std::fstream{argv[1]}, argv[2]);
    Topological top{sg.g()};
    if (!top.is_dag()) return EXIT_FAILURE;
    for (const auto v: top.order()) {
        std::cout << sg.name(v) << '\n';
    }
}