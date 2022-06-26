#pragma once

#include <memory>

#include "ch05/depth-first-order.hpp"
#include "ch05/digraph.hpp"
#include "ch05/directed-cycle.hpp"

// topological-sorting
struct Topological
{
    Topological(const Digraph& g)
    {
        DirectedCycle cicle_finder{g};
        if (!cicle_finder.has_cycle()) {
            dfs_ = std::make_unique<DepthFirstOrder>(g);
        }
    }

    // is g a dag?
    bool is_dag() const noexcept { return dfs_ != nullptr; }

    // vertices in topological order
    const std::list<Vertice>& order() const
    {
        if (dfs_ == nullptr) throw std::runtime_error{""};
        return dfs_->reverse_post();
    }

private:

    std::unique_ptr<DepthFirstOrder> dfs_;
};