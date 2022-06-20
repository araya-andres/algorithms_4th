#pragma once

#include "ch04/graph.hpp"

struct Digraph
{
    Digraph(size_t v): adj_(v) {}

    // build a digraph from input stream is
    static Digraph read_from_stream(std::istream&& is)
    {
        size_t e, v, w;
        is >> v >> e;
        Digraph g{v};
        while (e--) {
            is >> v >> w;
            g.add_edge(v, w);
        }
        return g;
    }

    // number of vertices
    size_t V() const noexcept { return adj_.size(); }

    // number of edges
    size_t E() const noexcept { return edges_; }

    // add edge v -> w
    void add_edge(Vertice v, Vertice w)
    {
        if (V() <= w) throw std::out_of_range{""};
        adj_.at(v).push_front(w);
        edges_++;
    }

    // vertices adjacent to v by edges pointing from v
    const Edges& adj(const Vertice v) const { return adj_.at(v); }

    // reverse of this digraph
    Digraph reverse()
    {
        auto r = Digraph(V());
        for (auto v = 0ul; v < V(); v++) {
            for (auto w: adj(v)) {
                r.add_edge(w, v);
            }
        }
        return r;
    }

    // string representation
    std::string str() const
    {
        std::ostringstream oss;
        for (size_t i = 0; i < V(); i++) {
            oss << i << ": ";
            std::copy(
                adj_[i].cbegin(), adj_[i].cend(),
                std::ostream_iterator<size_t>(oss, " ")
            );
            oss << '\n';
        }
        return oss.str();
    }

    Range<Vertice> begin() const { return {}; }

    Range<Vertice> end() const { return {V()}; }

private:

    size_t edges_ = 0;
    std::vector<Edges> adj_;
};