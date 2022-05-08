#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>

#include "math/point_2d.hpp"
#include "math/random.hpp"

using points = std::vector<math::Point2D<double>>;

auto initialize_list(size_t n)
{
    points lst;
    lst.reserve(n);
    math::set_seed();
    for (size_t i = 0; i < n; i++) {
        lst.emplace_back(math::random(), math::random());
    }
    return lst;
}

auto find_min_distance(const points& lst)
{
    const auto n = lst.size();
    auto min = std::numeric_limits<double>::max();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            auto d = math::squared_distance(lst[i], lst[j]);
            if (d < min) min = d;
        }
    }
    return min;
}

int main(int argc, char* argv[])
{
    if (argc == 1) return EXIT_FAILURE;
    auto lst = initialize_list(std::stoul(argv[1]));
    auto min = find_min_distance(lst);
    std::cout << min << '\n';
}