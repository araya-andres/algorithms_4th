#include <fstream>
#include <iostream>
#include <string>

#include "lib/ch04/paths.hpp"
#include "lib/ch04/dfp.hpp"
#include "lib/ch04/bfp.hpp"

template<typename T>
void test(const Graph& g, const Vertice s)
{
    auto search = Paths<T>(g, s);
    std::cout << search.description() << '\n';
    for (const auto v: g) {
        std::cout << s << " to " << v << ": ";
        if (search.has_path_to(v)) {
            for (const auto x: search.path_to(v)) {
                if (x == s) std::cout << x;
                else std::cout << '-' << x;
            }
        }
        std::cout << '\n';
    }
}

// ./build/src/ch04/test-paths ./data/tinyCG.txt 0
int main(int argc, char* argv[])
{
    if (argc < 3) return EXIT_FAILURE;
    auto g = Graph::read_from_stream<Graph>(std::fstream{argv[1]});
    auto s = std::stoul(argv[2]);
    test<DepthFirstPaths>(g, s);
    test<BreadthFirstPaths>(g, s);
}