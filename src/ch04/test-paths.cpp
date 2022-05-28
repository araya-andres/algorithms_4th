#include <fstream>
#include <iostream>
#include <string>

#include "ch04/dfp.hpp"

int main(int argc, char* argv[])
{
    if (argc < 3) return EXIT_FAILURE;
    auto g = Graph::read_from_stream(std::fstream{argv[1]});
    auto s = std::stoul(argv[2]);
    auto search = DepthFirstPaths(g, s);
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