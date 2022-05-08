#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>

#include "ch01/point_2d.hpp"

inline double rnd()
{
    return 1.0 * rand() / RAND_MAX;
}

int main(int argc, char* argv[])
{
    if (argc == 1) return EXIT_FAILURE;
    size_t n = std::stoul(argv[1]);
    std::vector<Point2D<double>> point;
    srand(static_cast<unsigned>(time(nullptr)));
    for (size_t i = 0; i < n; i++) {
        point.emplace_back(rnd(), rnd());
    }
    double min = std::numeric_limits<double>::max();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            auto d = squared_distance(point[i], point[j]);
            if (d < min) min = d;
        }
    }
    std::cout << min << '\n';
}