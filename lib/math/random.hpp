#pragma once

#include <cstdlib>
#include <ctime>

namespace math
{
// initialize
static inline void set_seed(
    unsigned seed=static_cast<unsigned>(time(nullptr))
)
{
    srand(seed);
}

// Real between 0 and 1
static inline double random()
{
    return 1.0 * rand() / RAND_MAX;
}

// Interger between 0 and n - 1
static inline int uniform(int n)
{
    return rand() % n;
}

// Interger between lo and hi - 1
static inline int uniform(int lo, int hi)
{
    return uniform(hi - lo) + lo;
}
}