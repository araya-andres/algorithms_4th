#pragma once

struct Range
{
    Range(size_t n = 0ul): n_{n} {}

    Range& operator++() { n_++; return *this; }

    Range operator++(int)
    {
        auto rv = *this;
        ++(*this);
        return rv;
    }

    bool operator==(Range other) const { return n_ == other.n_; }

    bool operator!=(Range other) const { return !(*this == other); }

    size_t operator*() const { return n_; }

private:

    size_t n_;
};

