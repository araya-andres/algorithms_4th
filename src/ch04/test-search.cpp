#include <fstream>
#include <iostream>
#include <string>

#include "ch04/dfs.hpp"

int main(int argc, char* argv[])
{
    if (argc < 3) return EXIT_FAILURE;
    auto g = Graph::read_from_stream(std::fstream{argv[1]});
    auto s = std::stoul(argv[2]);
    auto search = DepthFirstSearch(g, s);

    for (auto v = 0ul; v < g.V(); v++) {
        if (search.marked(v)) {
            std::cout << v << " ";
        }
    }
    std::cout << '\n';
    if (search.count() != g.V()) std::cout << "NOT ";
    std::cout << "connected\n";
}