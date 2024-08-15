#pragma once

#include "ch05/digraph.hpp"

// cycle-finding
struct DirectedCycle
{
    DirectedCycle(const Digraph& g)
        : marked_(g.V())
        , on_stack_(g.V())
        , edge_to_(g.V())
    {
        for (const auto v: g) {
            if (!marked_[v]) dfs(g, v);
        }
    }

    // does g have a directed cycle?
    bool has_cycle() const noexcept { return !cycle_.empty(); }

    // vertices on a cycle (if one exists)
    const Edges& cycle() const noexcept { return cycle_; }

private:

    void dfs(const Digraph& g, const Vertice v)
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

    std::vector<bool> marked_;
    std::vector<bool> on_stack_;
    std::vector<Vertice> edge_to_;
    Edges cycle_;
};
