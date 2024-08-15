#pragma once

#include <vector>
#include "lib/ch04/search.hpp"

struct DepthFirstSearch: Search
{
    DepthFirstSearch(const Graph& g, const Vertice s)
        : marked_(g.V())
    {
        dfs(g, s);
    }

    bool marked(const Vertice w) const override { return marked_[w]; }

    size_t count() const override { return count_; }

private:

    void dfs(const Graph& g, const Vertice v)
    {
        marked_[v] = true;
        count_++;
        for (auto w: g.adj(v)) {
            if (!marked_[w])
            {
                dfs(g, w);
            }
        }
    }

    std::vector<bool> marked_;
    size_t count_ = 0;
};