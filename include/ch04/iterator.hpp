#pragma once

template <typename T>
struct Iterator
{
    using iterator_category = std::input_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T const*;
    using reference = T const&;

    Iterator(T n = {}): n_{n} {}

    Iterator& operator++()
    {
        n_++;
        return *this;
    }

    Iterator operator++(int) = delete;

    bool operator==(const Iterator& other) const { return n_ == other.n_; }

    bool operator!=(const Iterator& other) const { return !(*this == other); }

    T operator*() const { return n_; }

private:

    T n_;
};

