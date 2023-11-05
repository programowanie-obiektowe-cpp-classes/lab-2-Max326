#pragma once

#include <cstdint>

struct ConstructionTracker
{
    ConstructionTracker()
    {
        ++defaults;
        ++live;
    }
    ConstructionTracker(const ConstructionTracker&)
    {
        ++copies;
        ++live;
    }
    ConstructionTracker(ConstructionTracker&&) noexcept
    {
        ++moves;
        ++live;
    }
    ConstructionTracker& operator=(const ConstructionTracker&)
    {
        ++cp_asgn;
        return *this;
    }
    ConstructionTracker& operator=(ConstructionTracker&&) noexcept
    {
        ++mv_asgn;
        return *this;
    }
    ~ConstructionTracker()
    {
        ++destr;
        --live;
    }

    static size_t defaults, copies, moves, cp_asgn, mv_asgn, destr, live;

    static void resetCount()
    {
        defaults = 0;
        copies   = 0;
        moves    = 0;
        cp_asgn  = 0;
        mv_asgn  = 0;
        destr    = 0;
        live     = 0;
    }
};

size_t ConstructionTracker::defaults = 0;
size_t ConstructionTracker::copies   = 0;
size_t ConstructionTracker::moves    = 0;
size_t ConstructionTracker::cp_asgn  = 0;
size_t ConstructionTracker::mv_asgn  = 0;
size_t ConstructionTracker::destr    = 0;
size_t ConstructionTracker::live     = 0;
