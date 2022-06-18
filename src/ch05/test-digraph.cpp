#include <fstream>
#include <iostream>
#include "ch05/digraph.hpp"
#include "ch05/directed-dfs.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2) return EXIT_FAILURE;
    auto g = Digraph::read_from_stream(std::fstream{argv[1]});
    auto r = g.reverse();
    std::cout << g.str() << '\n'
              << r.str() << '\n';
    if (argc == 2) return EXIT_SUCCESS;
    std::vector<size_t> sources;
    sources.reserve(static_cast<size_t>(argc - 2));
    std::transform(
        argv + 2, argv + argc,
        std::back_inserter(sources),
        [](const char* arg){ return std::stoul(arg); });
    auto reachable = DirectedDFS(g, sources);
    for (auto v = 0ul; v < g.V(); v++) {
        if (reachable.marked(v)) std::cout << v << ' ';
    }
    std::cout << '\n';
}