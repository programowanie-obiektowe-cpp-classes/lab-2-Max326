#pragma once

#include <algorithm>
#include <array>
#include <random>

#include "ConstructionTracker.hpp"

struct Resource : ConstructionTracker
{
    static constexpr size_t size = 1'000'000'0u;
    static const size_t     get_index;

    Resource()
    {
        std::random_device                       rd;
        std::mt19937                             gen(rd());
        std::uniform_real_distribution< double > dist(0, 1);
        std::generate(tab.begin(), tab.end(), [&]() { return dist(gen); });
    }

    double get() { return tab.at(get_index); }

    std::array< double, size > tab;
};

const size_t Resource::get_index = []() {
    std::random_device                      rd;
    std::mt19937                            gen(rd());
    std::uniform_int_distribution< size_t > dist(0, size - 1);
    return dist(gen);
}();
