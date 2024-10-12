#pragma once

#include <vector>

namespace
{
    template <typename T>
    int rank_r(const T key, const std::vector<T> &a, const int lo, const int hi)
    {
        if (lo > hi)
            return -1;
        const auto mid = lo + (hi - lo) / 2;
        if (key < a[mid])
            return rank_r(key, a, lo, mid - 1);
        if (key > a[mid])
            return rank_r(key, a, mid + 1, hi);
        return mid;
    }
}

namespace binary_search
{
    template <typename T>
    int rank(const T key, const std::vector<T> &a)
    {
        // Array must be sorted.
        int lo = 0;
        int hi = a.size() - 1;
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

    template <typename T>
    int rank_r(const T key, const std::vector<T> &a)
    {
        return ::rank_r(key, a, 0, a.size() - 1);
    }
};