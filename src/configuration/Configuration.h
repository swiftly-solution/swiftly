#ifndef _configuration_h
#define _configuration_h

#include "Config.h"

class Configuration
{
private:
    Config *config = nullptr;

public:
    bool LoadConfiguration();
    bool SaveConfiguration();
    inline bool IsConfigurationLoaded() { return config != nullptr; };

    inline Config *GetConfig() { return config; };
};

extern Configuration g_Config;

#endif