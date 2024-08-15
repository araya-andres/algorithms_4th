#pragma once

#include <ostream>
#include <string>

struct Accumulator
{
    void add_value(double val)
    {
        n++;
        total += val;
    }

    double mean() const { return total / n; }

    std::string str() const
    {
        std::ostringstream oss;
        oss << "Mean (" << n << " value): " << mean;
        return oss.str();
    }

private:
    int n = 0;
    double total = .0;
};