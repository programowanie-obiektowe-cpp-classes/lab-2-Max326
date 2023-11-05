#include "catch.hpp"

#include "ResourceManager.hpp"

TEST_CASE("Move semantics", "[]")
{
    {
        ResourceManager rm1;
        const auto      getv = rm1.get();
        ResourceManager rm2{std::move(rm1)};

        REQUIRE(getv == rm2.get());

        ResourceManager rm3;
        rm3 = std::move(rm2);
        REQUIRE(ConstructionTracker::live == 1);
        REQUIRE(getv == rm3.get());
    }
    REQUIRE(ConstructionTracker::live == 0);
}
