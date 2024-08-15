#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include "lib/util/in.hpp"

template <typename T>
int rank(const T key, const std::vector<T>& a)
{
    // Array must be sorted.
    size_t lo = 0;
    size_t hi = a.size() - 1;
    while (lo <= hi) {
        // Key is in a[lo..hi] or not present.
        size_t mid = lo + (hi - lo) / 2;
        if (key < a[mid]) hi = mid - 1;
        else if (key > a[mid]) lo = mid + 1;
        else return a[mid];
    }
    return -1;
}

int main(int argc, char* argv[])
{
    if (argc == 1) return EXIT_FAILURE;
    auto whitelist = in::read<int>(std::fstream{argv[1]});
    std::sort(whitelist.begin(), whitelist.end());
    // Read key, print if not in whitelist.
    int key;
    while (std::cin >> key) {
        if (rank(key, whitelist) == -1) {
            std::cout << key << '\n';
        }
    }
}
