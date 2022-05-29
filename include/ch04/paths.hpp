#pragma once

#include "ch04/graph.hpp"

template<typename T>
struct Paths
{
    Paths(const Graph& g, const Vertice s)
        : impl_{g, s}
        , s_{s}
    {}

    // is there a path from s to v
    bool has_path_to(const Vertice v) const { return impl_.marked(v); }

    // path from s to v; empty if no such path
    Edges path_to(const Vertice v) const
    {
        Edges path;
        if (has_path_to(v)) {
            for (auto x = v; x != s_; x = impl_.edge_to(x)) {
                path.push_front(x);
            }
            path.push_front(s_);
        }
        return path;
    }

    const char* description() const { return impl_.description(); }
private:
    T impl_;
    Vertice s_;
};