#include <iostream>

#include "counter.hpp"

std::ostream& operator<<(std::ostream& os, const Counter& c)
{
    return os << c.str();
}