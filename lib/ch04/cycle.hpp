#pragma once

#include "lib/ch04/graph.hpp"

struct Cycle
{
    // preprocessing constructor
    Cycle(const Graph& g)
        : marked_(g.V())
    {
        for (const auto s: g) {
            if (!marked_[s]) dfs(g, s, s);
        }
    }

    bool has_cycle() const { return has_cycle_; }

private:

    void dfs(const Graph& g, const Vertice v, const Vertice u)
    {
        marked_[v] = true;
        for (const auto w: g.adj(v)) {
            if (!marked_[w]) dfs(g, w, v);
            else if (w != u) has_cycle_ = true;
        }
    }

    std::vector<bool> marked_;
    bool has_cycle_ = false;
};