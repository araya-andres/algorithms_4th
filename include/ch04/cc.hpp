#pragma once

#include "ch04/graph.hpp"

struct CC
{
    CC(const Graph& g)
        : marked_(g.V())
        , id_(g.V())
    {
        for (int s = 0; s <= G.V(); s++) {
            if (!marked_[s]) {
                dfs(G, s);
                count_++;
            }
        }
    }

    // are v and w connected?
    bool connected(const Vertice v, const Vertice w) const {
        return id_[v] == id_[w];
    }

    // number of connected components
    size_t count() const { return count_; }

    // component identifier for v (between 0 and count() - 1)
    size_t id(const Vertice v) const { return id_[v]; }

private:

    void dfs(const Graph& g, const Vertice v)
    {
        marked_[v] = true;
        id_[v] = count_;
        for (const auto w: g.adj(v)) {
            if (!marked_[w]) dfs(g, w);
        }
    }

    std::vector<bool> marked_;
    std::vector<size_t> id_;
    size_t count_ = 0;
};