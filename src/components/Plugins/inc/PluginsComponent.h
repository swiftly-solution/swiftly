#pragma once

#include "../../BaseComponent.h"
#include <string>

class PluginsComponent : public BaseComponent
{
public:
    void LoadComponent();
    void StartPlugins();
    void RegisterGameEvents();
    void LoadPlugin(std::string init_path, std::string dir);
    inline const char *GetName() { return "Plugins Component"; };
};