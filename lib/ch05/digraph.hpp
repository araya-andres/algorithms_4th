#pragma once

#include "ch04/graph.hpp"

struct Digraph: Graph
{
    Digraph(size_t v): Graph{v} {}

    // add edge v -> w
    void add_edge(Vertice v, Vertice w) override
    {
        if (V() <= w) throw std::out_of_range{""};
        adj_.at(v).push_front(w);
        edges_++;
    }

    // reverse of this digraph
    Digraph reverse()
    {
        Digraph r{V()};
        for (const auto v: *this) {
            for (const auto w: adj(v)) {
                r.add_edge(w, v);
            }
        }
        return r;
    }
};