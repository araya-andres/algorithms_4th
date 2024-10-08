#pragma once

#include <vector>

#include "lib/ch05/digraph.hpp"

struct DirectedDFS
{
    // find vertices in g that are reachable from s
    DirectedDFS(const Digraph& g, const Vertice s)
        : DirectedDFS{g, std::vector<Vertice>{s}}
    {}

    // find vertices in g that are reachable from sources
    DirectedDFS(const Digraph& g, const std::vector<Vertice>& sources)
        : marked_(g.V())
    {
        for (const auto s: sources) {
            if (!marked_[s]) dfs(g, s);
        }
    }

    // is v reachable?
    bool marked(const Vertice w) const { return marked_.at(w); }

private:

    void dfs(const Digraph& g, const Vertice v) noexcept
    {
        marked_[v] = true;
        for (const auto w: g.adj(v)) {
            if (!marked_[w]) dfs(g, w);
        }
    }

    std::vector<bool> marked_;
};