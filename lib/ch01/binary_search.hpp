#pragma once

#include <vector>

namespace binary_search
{
    template <typename C, typename T = C::value_type>
    auto rank(const T key, const C &a) -> int
    {
        // Array must be sorted.
        int lo = 0;
        int hi = a.size() - 1;
        while (lo <= hi)
        {
            // Key is in a[lo..hi] or not present.
            int mid = lo + (hi - lo) / 2;
            if (key < a[mid])
                hi = mid - 1;
            else if (key > a[mid])
                lo = mid + 1;
            else
                return a[mid];
        }
        return -1;
    }

    template <typename C, typename T = C::value_type>
    auto rank_r(const T key, const C &a, const int lo, const int hi) -> int
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

    template <typename C, typename T = C::value_type>
    auto rank_r(const T key, const C &a) -> int
    {
        return rank_r(key, a, 0, a.size() - 1);
    }
};