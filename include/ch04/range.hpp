#pragma once

template <typename T>
struct Range
{
    Range(T n = {}): n_{n} {}

    Range& operator++()
    {
        n_++;
        return *this;
    }

    Range operator++(int)
    {
        auto rv = *this;
        ++(*this);
        return rv;
    }

    bool operator==(Range other) const { return n_ == other.n_; }

    bool operator!=(Range other) const { return !(*this == other); }

    T operator*() const { return n_; }

private:

    T n_;
};

