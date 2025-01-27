#include "precacher.h"
#include "../../memory/signatures/Signatures.h"
#include "../../common.h"
#include "../../entrypoint.h"
#include "../../memory/hooks/FuncHook.h"

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
    if (this->cacheModels.find(model) != this->cacheModels.end())
        return;
    if (this->precachedModels.find(model) != this->precachedModels.end())
        return;
    if (model.size() <= 0)
        return;

    this->cacheModels.insert(model);
}

void Precacher::CacheModels()
{
    for (auto it = this->cacheModels.begin(); it != this->cacheModels.end(); ++it)
    {
        std::string model = *it;
        if (this->precachedModels.find(model) != this->precachedModels.end())
            continue;

        this->CacheModel(model.c_str());
        this->precachedModels.insert(model);
    }
}

void Precacher::AddSound(std::string sound)
{
    if (this->cacheSounds.find(sound) != this->cacheSounds.end())
        return;
    if (this->precachedSounds.find(sound) != this->precachedSounds.end())
        return;
    if (sound.size() <= 0)
        return;

    this->cacheSounds.insert(sound);
}

void Precacher::CacheSounds()
{
    for (auto it = this->cacheSounds.begin(); it != this->cacheSounds.end(); ++it)
    {
        std::string sound = *it;
        if (this->precachedSounds.find(sound) != this->precachedSounds.end())
            continue;

        this->CacheSound(sound.c_str());
        this->precachedSounds.insert(sound);
    }
}

void Precacher::CacheSound(const char *model)
{
    engine->PrecacheDecal(model, true);
    PLUGIN_PRINTF("Precacher", "Precached sound '%s'.\n", model);
}
