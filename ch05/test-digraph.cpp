#include <fstream>
#include <iomanip>
#include <iostream>

#include "lib/ch05/digraph.hpp"
#include "lib/ch05/directed-cycle.hpp"
#include "lib/ch05/directed-dfs.hpp"

// ./bazel-bin/ch05/test-digraph ./data/tinyDG.txt
// # To test DirectedDFS
// ./bazel-bin/ch05/test-digraph ./data/tinyDG.txt 1
// ./bazel-bin/ch05/test-digraph ./data/tinyDG.txt 2
// ./bazel-bin/ch05/test-digraph ./data/tinyDG.txt 1 2 6
int main(int argc, char* argv[])
{
    if (argc < 2) return EXIT_FAILURE;
    auto g = Graph::read_from_stream<Digraph>(std::fstream{argv[1]});
    auto r = g.reverse();
    std::cout << g.str() << '\n'
              << r.str() << '\n';
    if (argc > 2) {
        std::vector<size_t> sources;
        sources.reserve(static_cast<size_t>(argc - 2));
        std::transform(
            argv + 2, argv + argc,
            std::back_inserter(sources),
            [](const char *arg) { return std::stoul(arg); });
        auto reachable = DirectedDFS(g, sources);
        for (const auto v: g) {
            if (reachable.marked(v)) std::cout << v << ' ';
        }
        std::cout << '\n';
    }
    DirectedCycle dc{g};
    std::cout << std::boolalpha << dc.has_cycle() << '\n';
    std::copy(
        dc.cycle().cbegin(), dc.cycle().cend(),
        std::ostream_iterator<Vertice>(std::cout, " "));
    std::cout << '\n';
}