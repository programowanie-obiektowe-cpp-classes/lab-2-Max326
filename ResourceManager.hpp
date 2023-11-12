#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    // stealing a constructor from the resource class
    ResourceManager() : resource(new Resource()){};

    ResourceManager(const ResourceManager& resourceManager)
        : resource(new Resource(*resourceManager.resource)){
              // std::cout << "Resource manager copied." << std::endl;
          };

    ResourceManager& operator=(const ResourceManager& resourceManager)
    {
        // std::cout << "Resource manager copied by assignment operator." << std::endl;

        if (this != &resourceManager) {
            delete resource;
            resource = new Resource(*resourceManager.resource);
        }
        return *this;
    };

    ResourceManager(ResourceManager&& resourceManager) : resource(resourceManager.resource)
    {
        resourceManager.resource = nullptr;
        // std::cout << "Moving constructor ran." << std::endl;
    }

    ResourceManager& operator=(ResourceManager&& resourceManager)
    {
        // std::cout << "Moving assignment operator ran." << std::endl;
        if (this != &resourceManager) {
            delete resource;
            resource                 = resourceManager.resource;
            resourceManager.resource = nullptr;
        }
        return *this;
    }

    ~ResourceManager()
    {
        delete resource;
        /*std::cout << "Resource manager object destroyed." << std::endl;*/
    };

    double get() const { return resource->get(); }

private:
    Resource* resource;
};
