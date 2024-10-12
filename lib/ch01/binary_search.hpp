#pragma once

#include <vector>

namespace binary_search
{
    template <typename T>
    int rank(const T key, const std::vector<T> &a)
    {
        // Array must be sorted.
        size_t lo = 0;
        size_t hi = a.size() - 1;
        while (lo <= hi)
        {
            // Key is in a[lo..hi] or not present.
            size_t mid = lo + (hi - lo) / 2;
            if (key < a[mid])
                hi = mid - 1;
            else if (key > a[mid])
                lo = mid + 1;
            else
                return a[mid];
        }
        return -1;
    }
}