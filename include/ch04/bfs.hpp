#pragma once

#include <queue>
#include "ch04/paths.hpp"

struct BreadthFirstPaths: Paths
{
    BreadthFirstPaths(const Graph& g, const Vertice s)
        : marked_(g.V())
        , edge_to_(g.V())
        , s_{s}
    {
        gfs(g, s);
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
    void gfs(const Graph& g, const Vertice s)
    {
        std::queue<Vertice> q;
        marked_[s] = true;
        q.push(s);
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            for (auto w: g.adj(v)) {
                if (!marked_[w]) {
                    edge_to_[w] = v;
                    marked_[w] = true;
                    q.push(w);
                }
            }
        }
    }

    std::vector<bool> marked_;
    std::vector<Vertice> edge_to_;
    Vertice s_;
};