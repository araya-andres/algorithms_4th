#pragma once

#include "ch04/paths.hpp"

struct DepthFirstPaths: Paths
{
    DepthFirstPaths(const Graph& g, Vertice s)
        : marked_(g.V())
        , edge_to_(g.V())
        , s_{s}
    {
        dfs(g, s);
    }

    bool has_path_to(const Vertice v) const override
    {
        return marked_[v];
    }

    Edges path_to(const Vertice v) const override
    {
        if (!has_path_to(v)) return {};
        Edges path;
        for (auto x = v; x != s_; x = edge_to_[x]) {
            path.push_front(x);
        }
        path.push_front(s_);
        return path;
    }

private:
    void dfs(const Graph& g, Vertice v)
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
    Vertice s_;
};