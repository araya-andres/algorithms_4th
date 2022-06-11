#pragma once

#include <istream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

#include "graph.hpp"

struct SymbolGraph
{
    using Edge = std::tuple<std::string, std::string>;

    SymbolGraph(std::istream&& is, std::string_view delimiter)
    {
        std::vector<Edge> edges;
        std::string line;
        while (getline(is, line)) {
            auto pos = line.find(delimiter);
            auto u = line.substr(0, pos);
            auto v = line.substr(pos + delimiter.size());
            if (!st_.contains(u)) st_[u] = st_.size();
            if (!st_.contains(v)) st_[v] = st_.size();
            edges.push_back({u, v});
        }
        keys_ = std::vector<std::string>(st_.size());
        for (auto& [key, index]: st_) {
            keys_[index] = key;
        }
        g_ = Graph(st_.size());
        for (auto& [u, v]: edges) {
            g_.add_edge(st_[u], st_[v]);
        }
    }

    // is key a vertex?
    bool contains(const std::string& key) const { return st_.contains(key); }

    // index associated with key
    Vertice index(const std::string& key) const { return st_.at(key); };

    // key associated with index
    const std::string& name(Vertice v) const { return keys_[v]; };

    // underlying graph
    const Graph& g() const { return g_; }

private:

    std::map<std::string, Vertice> st_;
    std::vector<std::string> keys_;
    Graph g_{0};
};