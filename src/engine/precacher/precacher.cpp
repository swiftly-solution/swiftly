#include "precacher.h"

#include <memory/gamedata/gamedata.h>
#include <memory/virtual/virtual.h>
#include <utils/common.h>

void Precacher::AddItem(std::string model)
{
    if (this->cacheItems.find(model) != this->cacheItems.end())
        return;
    if (this->precachedItems.find(model) != this->precachedItems.end())
        return;
    if (model.size() <= 0)
        return;

    this->cacheItems.insert(model);
}

void Precacher::CacheItems(IEntityResourceManifest* manifest)
{
    int addResourceOffset = g_GameData.GetOffset("CEntityResourceManifest_AddResource");
    for (auto it = this->cacheItems.begin(); it != this->cacheItems.end(); ++it)
    {
        std::string model = *it;
        CALL_VIRTUAL(void, addResourceOffset, manifest, model.c_str());
        this->precachedItems.insert(model);
        PLUGIN_PRINTF("Precacher", "Precached '%s'.\n", model.c_str());
    }
}

bool Precacher::HasModelInList(std::string model)
{
    return (this->precachedItems.find(model) != this->precachedItems.end());
}