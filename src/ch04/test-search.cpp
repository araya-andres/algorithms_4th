#include <fstream>
#include <iostream>
#include <string>

#include "ch04/dfs.hpp"

// ./build/src/ch04/test-search ./data/tinyG.txt 0
// ./build/src/ch04/test-search ./data/tinyG.txt 9
int main(int argc, char* argv[])
{
    if (argc < 3) return EXIT_FAILURE;
    auto g = Graph::read_from_stream(std::fstream{argv[1]});
    auto s = std::stoul(argv[2]);
    auto search = DepthFirstSearch(g, s);

    for (const auto v: g) {
        if (search.marked(v)) {
            std::cout << v << " ";
        }
    }
    std::cout << '\n';
    if (search.count() != g.V()) std::cout << "NOT ";
    std::cout << "connected\n";
}