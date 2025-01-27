#include "precacher.h"
#include "../../memory/signatures/Signatures.h"
#include "../../common.h"
#include "../../entrypoint.h"
#include "../../memory/hooks/FuncHook.h"
#include "game_system.h"
#include "../../utils/virtual.h"

#include <algorithm>

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
    int addResourceOffset = g_Offsets->GetOffset("CEntityResourceManifest_AddResource");
    for (auto it = this->cacheItems.begin(); it != this->cacheItems.end(); ++it)
    {
        std::string model = *it;
        CALL_VIRTUAL(void, addResourceOffset, manifest, model.c_str());
        this->precachedItems.insert(model);
        PLUGIN_PRINTF("Precacher", "Precached '%s'.\n", model.c_str());
    }
}