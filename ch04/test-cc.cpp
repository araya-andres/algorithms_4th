#include <fstream>
#include <iostream>
#include <queue>
#include "lib/ch04/cc.hpp"

// ./bazel-bin/ch04/test-cc ./data/tinyG.txt
int main(int argc, const char* argv[])
{
    if (argc < 2) return EXIT_FAILURE;
    auto g = Graph::read_from_stream<Graph>(std::fstream{argv[1]});
    auto cc = CC{g};

    auto m = cc.count();
    std::cout << m << " components\n";
    std::vector<std::vector<Vertice>> components(m);
    for (const auto v: g) {
        components[cc.id(v)].push_back(v);
    }
    for (const auto& c: components) {
        for (const auto v: c) {
            std::cout << v << " ";
        }
        std::cout << '\n';
    }
}