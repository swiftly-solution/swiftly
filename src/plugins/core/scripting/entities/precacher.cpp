#include "../../scripting.h"
#include "../../../../entitysystem/precacher/precacher.h"

PluginPrecacher::PluginPrecacher(std::string m_plugin_name)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginPrecacher::PluginPrecacher(m_plugin_name=\"%s\")", m_plugin_name.c_str()));

    this->plugin_name = m_plugin_name;
}

void PluginPrecacher::PrecacheModel(std::string model)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginPrecacher::PrecacheModel(model=\"%s\")", model.c_str()));

    g_precacher->AddModel(model);
}

void PluginPrecacher::PrecacheSound(std::string path)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginPrecacher::PrecacheSound(model=\"%s\")", path.c_str()));

    g_precacher->AddSound(path);
}
