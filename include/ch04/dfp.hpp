#pragma once

#include "ch04/graph.hpp"

struct DepthFirstPaths
{
    DepthFirstPaths(const Graph& g, const Vertice s)
        : marked_(g.V())
        , edge_to_(g.V())
    {
        dfs(g, s);
    }

    bool marked(const Vertice v) const { return marked_[v]; }

    Vertice edge_to(const Vertice v) const { return edge_to_[v]; }

    const char* description() const { return "Depth-first search"; }

private:
    void dfs(const Graph& g, const Vertice v)
    {
        marked_[v] = true;
        for (auto w: g.adj(v)) {
            if (!marked_[w]) {
                edge_to_[w] = v;
                dfs(g, w);
            }
        }
    }

    std::vector<bool> marked_;
    std::vector<Vertice> edge_to_;
};