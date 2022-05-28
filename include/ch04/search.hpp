#pragma once

#include "graph.hpp"

struct Search
{
    // is v connected to s?
    virtual bool marked(size_t v) const;

    // how many vertices are connected to s?
    virtual size_t count() const;
};