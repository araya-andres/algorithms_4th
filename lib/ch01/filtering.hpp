#pragma once

#include <algorithm>
#include <functional>
#include <numeric>
#include <optional>
#include <vector>
#include <utility>

namespace filtering
{
    // See https://devblogs.microsoft.com/oldnewthing/20190619-00/?p=102599
    template <typename C, typename Cmp, typename T = C::value_type>
    auto minmax_helper(const C &container, const Cmp &cmp) -> T
    {
        T retval = container[0];
        for (const T &val : container)
            if (cmp(val, retval))
                retval = val;
        return retval;
    }

    template <typename C, typename T = C::value_type>
    auto max(const C &container) -> std::optional<T>
    {
        return container.size() == 0
            ? std::nullopt
            : std::optional{ minmax_helper(container, std::greater<T>{}) };
    }

    template <typename C, typename T = C::value_type>
    auto min(const C &container) -> std::optional<T>
    {
        return container.size() == 0
            ? std::nullopt
            : std::optional{ minmax_helper(container, std::less<T>{}) };
    }

    template <typename C, typename T = C::value_type>
    auto minmax(const C &container) -> std::optional<std::pair<T, T>>
    {
        return container.size() == 0
            ? std::nullopt
            : std::optional{ std::make_pair(
                    minmax_helper(container, std::less<T>{}),
                    minmax_helper(container, std::greater<T>{})
                ) };
    }

    template <typename C, typename T = C::value_type>
    auto median(const C& container) -> std::optional<double>
    {
        const auto sz = container.size();
        if (sz == 0)
            return std::nullopt;
        std::vector v(begin(container), end(container));
        std::sort(begin(v), end(v));
        const auto mid = sz / 2;
        return sz % 2 == 0
            ? .5 * (v[mid - 1] + v[mid])
            : v[mid];
    }

    template <typename C, typename T = C::value_type>
    auto average(const C& container) -> std::optional<double>
    {
        const auto sz = container.size();
        return sz == 0
            ? std::nullopt
            : std::optional{ std::accumulate(begin(container), end(container), 0.0) / sz };
    }
}