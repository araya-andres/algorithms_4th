#pragma once

#include <istream>
#include <list>
#include <string>
#include <vector>

using Edges = std::list<size_t>;

struct Graph
{
    // create a V-vertex graph with no edges
    Graph(size_t V)
        : adj_(V)
    {
    }

    static Graph read_from_stream(std::istream& is)
    {
        size_t e, v, w;
        is >> v >> e;
        Graph g{v};
        while (e-- > 0) {
            is >> v >> w;
            g.add_edge(v, w);
        }
        return g;
    }

    // number of vertices
    size_t V() const { return adj_.size(); }

    // number of edges
    size_t E() const { return edges_; };

    // add edge v - w
    bool add_edge(size_t v, size_t w)
    {
        const auto sz = V();
        if (sz <= v || sz <= w)
            return false;
        adj_[v].push_front(w);
        adj_[w].push_front(v);
        edges_++;
        return true;
    }

    // vertices adjacent to v
    const Edges& adj(size_t v) const
    {
        return adj_.at(v);
    }

private:
    size_t edges_ = 0;
    std::vector<Edges> adj_;
};