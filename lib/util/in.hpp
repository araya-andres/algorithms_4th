#pragma once

#include <vector>

namespace in
{
template <typename T>
std::vector<T> read(std::istream&& is)
{
    std::vector<T> v;
    T value;
    while (is >> value) v.push_back(value);
    return v;
}
}