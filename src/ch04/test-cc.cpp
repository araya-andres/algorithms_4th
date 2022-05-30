#include <fstream>
#include <iostream>
#include "ch04/cc.hpp"

int main(int argc, const char* argv[])
{
    if (argc < 2) return EXIT_FAILURE;
    auto g = Graph::read_from_stream(std::fstream{argv[1]});
    auto cc = CC{g};

    std::cout << cc.count() << " components\n";
}