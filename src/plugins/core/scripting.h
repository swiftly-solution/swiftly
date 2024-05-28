#pragma once

#include "../../common.h"
#include "../../entrypoint.h"
#include "../Plugin.h"
#include "../PluginManager.h"
#include "../../types/LogType.h"
#include "../../logs/Logger.h"

//////////////////////////////////////////////////////////////
/////////////////         Translations         //////////////
////////////////////////////////////////////////////////////

class PluginLogger
{
private:
    std::string plugin_name;
public:
    PluginLogger(std::string m_plugin_name);

    void Write(int level, std::string message);
};

//////////////////////////////////////////////////////////////
/////////////////         Translations         //////////////
////////////////////////////////////////////////////////////

std::string scripting_FetchTranslation(Plugin *plugin, std::string key);