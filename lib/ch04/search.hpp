#pragma once

#include "lib/ch04/graph.hpp"

struct Search
{
    // is v connected to s?
    virtual bool marked(const Vertice v) const = 0;

    // how many vertices are connected to s?
    virtual size_t count() const = 0;
};