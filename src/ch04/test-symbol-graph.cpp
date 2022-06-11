#include <fstream>
#include <iostream>
#include <queue>
#include "ch04/symbol-graph.hpp"

int main(int argc, const char* argv[])
{
    if (argc < 2) return EXIT_FAILURE;
    auto sg = SymbolGraph(std::fstream{argv[1]}, " ");
}