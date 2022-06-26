#pragma once

#include <istream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

#include "ch04/graph.hpp"

template <typename G>
struct Symbol
{
    using Edge = std::tuple<std::string, std::string>;
    using Keys = std::vector<std::string>;

    Symbol(std::istream&& is, std::string_view delimiter)
    {
        std::vector<Edge> edges;
        std::string line;
        while (getline(is, line)) {
            const auto symbols = split(line, delimiter);
            const auto& u = symbols[0];
            if (!st_.contains(u)) st_[u] = st_.size();
            for (size_t i = 1; i < symbols.size(); i++) {
                const auto& v = symbols[i];
                if (!st_.contains(v)) st_[v] = st_.size();
                edges.push_back({u, v});
            }
        }
        keys_ = Keys(st_.size());
        for (const auto& [key, index]: st_) {
            keys_[index] = key;
        }
        g_ = G{st_.size()};
        for (const auto& [u, v]: edges) {
            g_.add_edge(st_[u], st_[v]);
        }
    }

    // is key a vertex?
    bool contains(const std::string& key) const noexcept { return st_.contains(key); }

    // index associated with key
    Vertice index(const std::string& key) const { return st_.at(key); };

    // key associated with index
    const std::string& name(Vertice v) const { return keys_.at(v); };

    // underlying graph
    const G& g() const noexcept { return g_; }

private:

    auto split(std::string& s, std::string_view delimiter)
    {
        std::vector<std::string> v;
        auto pos = s.find(delimiter);
        while (pos != std::string::npos) {
            v.push_back(s.substr(0, pos));
            s.erase(0, pos + delimiter.length());
            pos = s.find(delimiter);
        }
        v.push_back(s);
        return v;
    }

    std::map<std::string, Vertice> st_; // string -> index
    Keys keys_; // index -> string
    G g_{0}; // the graph
};