#pragma once

#include "../../BaseComponent.h"

class PluginsComponent : public BaseComponent
{
public:
    void LoadComponent();
    void StartPlugins();
    void RegisterGameEvents();
    inline const char *GetName() { return "Plugins Component"; };
};