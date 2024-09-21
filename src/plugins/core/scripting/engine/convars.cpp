#include "../../scripting.h"
#include "../../../../entrypoint.h"
#include "../../../../convars/convars.h"

PluginConvars::PluginConvars(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

void PluginConvars::CreateFake(std::string cvarname, int32_t type, std::any defaultValue, bool prot)
{
    if (type < 0 || type > 14) return;
    if (FakeConvarExists(cvarname)) return;
    if (FetchCVar(cvarname)) return;

    auto cvar = new FakeConVar(cvarname, (EConVarType)type, defaultValue, prot);
    InsertFakeConvar(cvarname, cvar);
}

void PluginConvars::DeleteFake(std::string cvarname)
{
    if (!FakeConvarExists(cvarname)) return;

    auto cvar = GetFakeConvar(cvarname);
    delete cvar;
    DeleteFakeConvar(cvarname);
}

void PluginConvars::AddFlags(std::string cvarname, int64_t flags)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::AddFlags(cvarname=\"%s\",flags=%lld)", cvarname.c_str(), flags));
    auto cvar = FetchCVar(cvarname);
    if(cvar == nullptr) return;

    cvar->flags |= flags;
}

void PluginConvars::RemoveFlags(std::string cvarname, int64_t flags)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::RemoveFlags(cvarname=\"%s\",flags=%lld)", cvarname.c_str(), flags));
    auto cvar = FetchCVar(cvarname);
    if(cvar == nullptr) return;

    cvar->flags &= ~flags;
}

int64_t PluginConvars::GetFlags(std::string cvarname)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::GetFlags(cvarname=\"%s\")", cvarname.c_str()));
    auto cvar = FetchCVar(cvarname);
    if(cvar == nullptr) return 0;

    return cvar->flags;
}

bool PluginConvars::HasFlags(std::string cvarname, int64_t flags)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::HasFlags(cvarname=\"%s\",flags=%lld)", cvarname.c_str(), flags));
    auto cvar = FetchCVar(cvarname);
    if(cvar == nullptr) return false;

    return ((cvar->flags & flags) != 0);
}

bool PluginConvars::Exists(std::string cvarname)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::ExistsFake(cvarname=\"%s\")", cvarname.c_str()));

    return (FetchCVar(cvarname) != nullptr);
}

bool PluginConvars::ExistsFake(std::string cvarname)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::ExistsFake(cvarname=\"%s\")", cvarname.c_str()));

    return FakeConvarExists(cvarname);
}

std::any PluginConvars::GetConvarValue(std::string cvarname)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::GetConvarValue(cvarname=\"%s\")", cvarname.c_str()));

    return FetchCVarValue(cvarname);
}

int16_t PluginConvars::GetConvarType(std::string cvarname)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::GetConvarType(cvarname=\"%s\")", cvarname.c_str()));

    return (int16_t)FetchCVarType(cvarname);
}

void PluginConvars::SetConvar(std::string cvarname, std::string value)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::SetConvar(cvarname=\"%s\", value=\"%s\")", cvarname.c_str(), value.c_str()));

    auto cvartype = FetchCVarType(cvarname);

    if (cvartype == EConVarType_String)
        engine->ServerCommand(string_format("%s \"%s\"", cvarname.c_str(), value.c_str()).c_str());
    else if (cvartype != EConVarType_Invalid)
        engine->ServerCommand(string_format("%s %s", cvarname.c_str(), value.c_str()).c_str());
}