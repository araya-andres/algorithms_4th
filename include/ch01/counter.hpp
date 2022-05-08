#pragma once

#include <string>
#include <sstream>

struct Counter
{
    // Create a counter named id
    Counter(const std::string& id): id_{id} {}

    // Increment the counter by 1
    void increment() { counter_++; }

    // Number of increments since creation
    int tally() const { return counter_; }

    // String representation
    const std::string toString() const
    {
        std::ostringstream oss;
        oss << counter_ << " " << id_;
        return oss.str();
    }

private:
    std::string id_;
    int counter_ = 0;
};