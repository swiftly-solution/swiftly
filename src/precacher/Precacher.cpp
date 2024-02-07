#include "Precacher.h"
#include "../sig/Signatures.h"
#include "../common.h"

#include <algorithm>

typedef void (*PrecacheResource)(const char *, int64_t);

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

void Precacher::AddSound(std::string sound)
{
    if (std::find(this->cacheSounds.begin(), this->cacheSounds.end(), sound) != this->cacheSounds.end())
        return;
    if (std::find(this->precachedSounds.begin(), this->precachedSounds.end(), sound) != this->precachedSounds.end())
        return;
    if (sound.size() <= 0)
        return;

    this->cacheSounds.push_back(sound);
}

void Precacher::CacheSounds()
{
    for (std::string sound : this->cacheSounds)
    {
        if (std::find(this->precachedSounds.begin(), this->precachedSounds.end(), sound) != this->precachedSounds.end())
            continue;

        this->CacheSound(sound.c_str());
        this->precachedSounds.push_back(sound);
    }
}

void Precacher::CacheSound(const char *model)
{
    engine->PrecacheDecal(model, true);
    PRINTF("Precacher", "Precached sound '%s'.\n", model);
}
