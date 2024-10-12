#include <algorithm>
#include <fstream>
#include <iostream>
#include "lib/ch01/binary_search.hpp"
#include "lib/util/in.hpp"

int main(int argc, char* argv[])
{
    if (argc == 1) return EXIT_FAILURE;
    auto whitelist = in::read<int>(std::fstream{argv[1]});
    std::sort(whitelist.begin(), whitelist.end());
    // Read key, print if not in whitelist.
    int key;
    while (std::cin >> key) {
        if (binary_search::rank(key, whitelist) == -1) {
            std::cout << key << '\n';
        }
    }
}
