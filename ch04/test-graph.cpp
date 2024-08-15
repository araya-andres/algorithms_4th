#include <fstream>
#include <iostream>
#include "lib/ch04/graph.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2) return EXIT_FAILURE;
    auto g = Graph::read_from_stream<Graph>(std::fstream{argv[1]});
    std::cout << g.str() << '\n';
}