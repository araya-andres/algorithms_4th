#pragma once

#include <algorithm>
#include <istream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

#include "lib/ch04/iterator.hpp"

using Vertice = size_t;
using Edges = std::list<Vertice>;

struct Graph
{
    // create a V-vertex graph with no edges
    Graph(const size_t V)
        : adj_(V)
    {
    }

    template <typename G>
    static G read_from_stream(std::istream&& is)
    {
        size_t e, v, w;
        is >> v >> e;
        G g{v};
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
    virtual void add_edge(const Vertice v, const Vertice w)
    {
        const auto sz = V();
        if (sz <= v || sz <= w) throw std::out_of_range{""};
        adj_[v].push_front(w);
        adj_[w].push_front(v);
        edges_++;
    }

    // vertices adjacent to v
    const Edges& adj(const Vertice v) const
    {
        return adj_.at(v);
    }

    Iterator<Vertice> begin() const { return {}; }

    Iterator<Vertice> end() const { return {V()}; }

    std::string str() const
    {
        std::ostringstream oss;
        for (const auto i: *this) {
            oss << i << ": ";
            std::copy(
                adj_[i].cbegin(), adj_[i].cend(),
                std::ostream_iterator<size_t>(oss, " ")
            );
            oss << '\n';
        }
        return oss.str();
    }

protected:

    size_t edges_ = 0;
    std::vector<Edges> adj_;
};