#ifndef _configuration_h
#define _configuration_h

#include "Config.h"

class Configuration
{
private:
    Config *config = NULL;

public:
    bool LoadConfiguration();
    bool SaveConfiguration();
    inline bool IsConfigurationLoaded() { return config != NULL; };

    inline Config *GetConfig() { return config; };
};

extern Configuration g_Config;

#endif