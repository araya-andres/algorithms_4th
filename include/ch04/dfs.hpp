#pragma once

#include <vector>
#include "ch04/graph.hpp"

struct DepthFirstSearch
{
    DepthFirstSearch(const Graph& g, size_t s)
        : marked_(g.V())
    {
        dfs(g, s);
    }

    bool marked(size_t w) const { return marked_[w]; }

    size_t count() const { return count_; }

private:
    void dfs(const Graph& g, size_t v)
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