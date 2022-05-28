#pragma once

#include "ch04/graph.hpp"

struct Paths
{

    // is there a path from s to v
    virtual bool has_path_to(const Vertice v) const = 0;

    // path from s to v; empty if no such path
    virtual Edges path_to(const Vertice v) const = 0;
};