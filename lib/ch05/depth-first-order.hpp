#pragma once

#include "lib/ch05/digraph.hpp"

struct DepthFirstOrder
{
    DepthFirstOrder(const Digraph& g)
        : marked_(g.V())
    {
        pre_.reserve(g.V());
        post_.reserve(g.V());
        for (const auto v: g) {
            if (!marked_[v]) dfs(g, v);
        }
    }

    const std::vector<Vertice>& pre() const noexcept { return pre_; }

    const std::vector<Vertice>& post() const noexcept { return post_; }

    const std::list<Vertice>& reverse_post() const noexcept { return reverse_post_; }

private:

    void dfs(const Digraph& g, const Vertice v)
    {
        pre_.push_back(v);
        marked_[v] = true;
        for (const auto w: g.adj(v)) {
            if (!marked_[w]) dfs(g, w);
        }
        post_.push_back(v);
        reverse_post_.push_front(v);
    }

    std::vector<bool> marked_;
    std::vector<Vertice> pre_;
    std::vector<Vertice> post_;
    std::list<Vertice> reverse_post_;
};