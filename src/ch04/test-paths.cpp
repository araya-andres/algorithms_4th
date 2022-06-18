#include <fstream>
#include <iostream>
#include <string>

#include "ch04/paths.hpp"
#include "ch04/dfp.hpp"
#include "ch04/bfp.hpp"

template<typename T>
void test(const Graph& g, const Vertice s)
{
    auto search = Paths<T>(g, s);
    std::cout << search.description() << '\n';
    for (auto v = 0ul; v < g.V(); v++) {
        std::cout << s << " to " << v << ": ";
        if (search.has_path_to(v)) {
            for (auto x: search.path_to(v)) {
                if (x == s) std::cout << x;
                else std::cout << '-' << x;
            }
        }
        std::cout << '\n';
    }
}

int main(int argc, char* argv[])
{
    if (argc < 3) return EXIT_FAILURE;
    auto g = Graph::read_from_stream(std::fstream{argv[1]});
    auto s = std::stoul(argv[2]);
    test<DepthFirstPaths<Graph>>(g, s);
    test<BreadthFirstPaths<Graph>>(g, s);
}