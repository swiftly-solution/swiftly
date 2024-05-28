#include "precacher.h"
#include "../signatures/Signatures.h"
#include "../common.h"
#include "../entrypoint.h"
#include "../hooks/FuncHook.h"

#include <algorithm>

typedef void (*PrecacheResource)(const char *, int64_t);

FuncHook<decltype(Hook_PrecacheResource)> TPrecacheResource(Hook_PrecacheResource, "PrecacheResource");

void Hook_PrecacheResource(const char *model_path, int64_t context)
{
    if (g_precacher->GetContext() == 0 && starts_with(std::string(model_path), "models/"))
    {
        g_precacher->SetContext(context);
        g_precacher->CacheModels();
    }

    TPrecacheResource(model_path, context);
}

void Precacher::CacheModel(const char *model)
{
    g_Signatures->FetchSignature<PrecacheResource>("PrecacheResource")(model, this->precacheContext);
    PLUGIN_PRINTF("Precacher", "Precached model '%s'.\n", model);
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
