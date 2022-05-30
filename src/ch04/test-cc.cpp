#include <fstream>
#include <iostream>
#include <queue>
#include "ch04/cc.hpp"

int main(int argc, const char* argv[])
{
    if (argc < 2) return EXIT_FAILURE;
    auto g = Graph::read_from_stream(std::fstream{argv[1]});
    auto cc = CC{g};

    auto m = cc.count();
    std::cout << m << " components\n";
    std::vector<std::vector<Vertice>> components(m);
    for (auto v = 0ul; v < g.V(); v++) {
        components[cc.id(v)].push_back(v);
    }
    for (const auto& c: components) {
        for (auto v: c) {
            std::cout << v << " ";
        }
        std::cout << '\n';
    }
}