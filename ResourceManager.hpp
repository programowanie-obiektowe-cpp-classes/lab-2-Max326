#pragma once

#include "Resource.hpp"

class ResourceManager : public Resource
{
    // Twoja implementacja tutaj
    double get(Resource resource){
        return resource.get();
    }
};
