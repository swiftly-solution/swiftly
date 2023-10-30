#pragma once

#include "../common.h"
#include <vector>

struct Logging
{
    bool enabled;
    std::string mode; // "daily" / "map"
};

struct CoreConfig
{
    Logging logging;
    std::vector<std::string> commandPrefixes;
    std::vector<std::string> commandSilentPrefixes;
};

struct Config
{
    CoreConfig core;
};