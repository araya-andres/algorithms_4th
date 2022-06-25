#pragma once

#include "ch05/digraph.hpp"

struct DirectedCycle
{
    DirectedCycle(const Digraph& g)
        : on_stack_(g.V())
        , edge_to_(g.V())
        , marked_(g.V())
    {
        for (const auto v: g) {
            if (!marked_[v]) dfs(g, v);
        }
    }

    bool has_cycle() const { return !cycle_.empty(); }

    const Edges& cycle() const { return cycle_; }

private:

    void dfs(const Digraph& g, Vertice v)
    {
        on_stack_[v] = true;
        marked_[v] = true;
        for (const auto w: g.adj(v)) {
            if (has_cycle()) {
                return;
            } else if (!marked_[w]) {
                edge_to_[w] = v;
                dfs(g, w);
            } else if (on_stack_[w]) {
                for (auto x = v; x != w; x = edge_to_[x]) {
                    cycle_.push_front(x);
                }
                cycle_.push_front(w);
                cycle_.push_front(v);
            }
        }
        on_stack_[v] = false;
    }

    std::vector<bool> on_stack_;
    std::vector<Vertice> edge_to_;
    std::vector<bool> marked_;
    Edges cycle_;
};
