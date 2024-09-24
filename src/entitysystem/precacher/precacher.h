#ifndef _precacher_h
#define _precacher_h

#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

void Hook_PrecacheResource(const char *, int64_t);

class Precacher
{
private:
    int64_t precacheContext = 0;
    std::vector<std::string> cacheModels;
    std::vector<std::string> cacheSounds;
    std::vector<std::string> precachedModels;
    std::vector<std::string> precachedSounds;
    bool soundsPrecached = false;

public:
    Precacher(){};

    void SetContext(int64_t context) { this->precacheContext = context; }
    int64_t GetContext() { return this->precacheContext; }

    void Reset()
    {
        this->precacheContext = 0;
        this->precachedModels.clear();
        this->precachedSounds.clear();
        this->soundsPrecached = false;
    }

    void SetSoundsPrecached(bool toggle) { this->soundsPrecached = toggle; }
    bool GetSoundsPrecached() { return this->soundsPrecached; }

    void AddModel(std::string model);
    void AddSound(std::string sound);

    void CacheModels();
    void CacheSounds();

    bool HasModelInList(std::string model)
    {
        return (std::find(this->precachedModels.begin(), this->precachedModels.end(), model) != this->precachedModels.end());
    }

    bool HasSoundInList(std::string model)
    {
        return (std::find(this->precachedSounds.begin(), this->precachedSounds.end(), model) != this->precachedSounds.end());
    }

    void CacheModel(const char *model);
    void CacheSound(const char *model);
};

extern Precacher *g_precacher;

#endif