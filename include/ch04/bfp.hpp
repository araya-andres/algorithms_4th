#pragma once

#include <queue>
#include "ch04/graph.hpp"

struct BreadthFirstPaths
{
    BreadthFirstPaths(const Graph& g, const Vertice s)
        : marked_(g.V())
        , edge_to_(g.V())
    {
        bfs(g, s);
    }

    bool marked(const Vertice v) const { return marked_[v]; }

    Vertice edge_to(const Vertice v) const { return edge_to_[v]; }

    const char* description() const { return "Breadth-first search"; }

private:

    void bfs(const Graph& g, const Vertice s)
    {
        std::queue<Vertice> q;
        marked_[s] = true;
        for (q.push(s); q.size(); q.pop()) {
            auto v = q.front();
            for (auto w : g.adj(v)) {
                if (marked_[w]) continue;
                edge_to_[w] = v;
                marked_[w] = true;
                q.push(w);
            }
        }
    }

    std::vector<bool> marked_;
    std::vector<Vertice> edge_to_;
};