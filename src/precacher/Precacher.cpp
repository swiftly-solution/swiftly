#include "Precacher.h"
#include "../sig/Signatures.h"
#include "../common.h"

#include <algorithm>

void Precacher::CacheModel(const char *model)
{
    g_Signatures->FetchSignature<PrecacheResource>("PrecacheResource")(model, this->precacheContext);
    PRINTF("Precacher", "Precached model '%s'.\n", model);
}

void Precacher::AddModel(std::string model)
{
    if (std::find(this->cacheModels.begin(), this->cacheModels.end(), model) != this->cacheModels.end())
        return;
    if (std::find(this->precachedModels.begin(), this->precachedModels.end(), model) != this->precachedModels.end())
        return;
    if (model.size() <= 0)
        return;

    this->cacheModels.push_back(model);
}

void Precacher::CacheModels()
{
    for (std::string model : this->cacheModels)
    {
        if (std::find(this->precachedModels.begin(), this->precachedModels.end(), model) != this->precachedModels.end())
            continue;

        this->CacheModel(model.c_str());
        this->precachedModels.push_back(model);
    }
}