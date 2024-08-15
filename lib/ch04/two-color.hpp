#pragma once

#include "lib/ch04/graph.hpp"

struct TwoColor
{
    // preprocessing constructor
    TwoColor(const Graph& g)
        : marked_(g.V())
        , color_(g.V())
    {
        for (auto s = 0ul; s < g.V(); s++) {
            if (!marked_[s]) dfs(g, s);
        }
    }

    bool is_bipartite() const { return is_two_colorable_; }

private:

    void dfs(const Graph& g, const Vertice v)
    {
        marked_[v] = true;
        for (const auto w: g.adj(v)) {
            if (!marked_[w]) {
                color_[w] = !color_[v];
                dfs(g, w);
            } else if (color_[w] == color_[v]) {
                is_two_colorable_ = false;
            }
        }
    }

    std::vector<bool> marked_;
    std::vector<bool> color_;
    bool is_two_colorable_ = true;
};