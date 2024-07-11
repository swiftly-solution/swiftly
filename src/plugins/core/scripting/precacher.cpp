#include "../scripting.h"
#include "../../../precacher/precacher.h"

PluginPrecacher::PluginPrecacher(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

void PluginPrecacher::PrecacheModel(std::string model)
{
    g_precacher->AddModel(model);
}

void PluginPrecacher::PrecacheSound(std::string path)
{
    g_precacher->AddSound(path);
}
