#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    // stealing a constructor from the resource class
    ResourceManager() : resource(){};

    ResourceManager(const ResourceManager& resourceManager)
        : resource(resourceManager.resource){
              // std::cout << "Resource manager copied." << std::endl;
          };

    ResourceManager& operator=(const ResourceManager& resourceManager)
    {
        // std::cout << "Resource manager copied by assignment operator." << std::endl;

        if (this != &resourceManager) {
            resource = resourceManager.resource;
        }
        return *this;
    };

    ResourceManager(ResourceManager&& resourceManager)
        : resource(std::move(resourceManager.resource))
    {
        // std::cout << "Moving constructor ran." << std::endl;
    }

    ResourceManager& operator=(ResourceManager&& resourceManager)
    {
        // std::cout << "Moving assignment operator ran." << std::endl;
        if (this != &resourceManager) {
            resource = std::move(resourceManager.resource);
        }
        return *this;
    }

    ~ResourceManager(){/*std::cout << "Resource manager object destroyed." << std::endl;*/};

    double get() { return resource.get(); }

private:
    Resource resource;
};
