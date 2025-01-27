#include "../../scripting.h"
#include "../../../../entrypoint.h"
#include "../../../../engine/convars/convars.h"

PluginConvars::PluginConvars(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
}

PluginConvars::~PluginConvars()
{
    for(auto it = created_cvars.begin(); it != created_cvars.end(); ++it)
        DeleteFakeConvar(*it);
}

void PluginConvars::CreateFake(std::string cvarname, int32_t type, std::any defaultValue, bool prot)
{
    if (type < 0 || type > 14) return;
    if (FakeConvarExists(cvarname)) return;
    if (FetchCVar(cvarname)) return;

    if (type == EConVarType_Int16) {
        if (defaultValue.type() == typeid(int64_t))
            defaultValue = (int16_t)std::any_cast<int64_t>(defaultValue);
        else
            defaultValue = (int16_t)0;
    }
    else if (type == EConVarType_UInt16) {
        if (defaultValue.type() == typeid(int64_t))
            defaultValue = (uint16_t)std::any_cast<int64_t>(defaultValue);
        else
            defaultValue = (uint16_t)0;
    }
    else if (type == EConVarType_UInt32) {
        if (defaultValue.type() == typeid(int64_t))
            defaultValue = (uint32_t)std::any_cast<int64_t>(defaultValue);
        else
            defaultValue = (uint32_t)0;
    }
    else if (type == EConVarType_Int32) {
        if (defaultValue.type() == typeid(int64_t))
            defaultValue = (int32_t)std::any_cast<int64_t>(defaultValue);
        else
            defaultValue = (int32_t)0;
    }
    else if (type == EConVarType_UInt64) {
        if (defaultValue.type() == typeid(int64_t))
            defaultValue = (uint64_t)std::any_cast<int64_t>(defaultValue);
        else
            defaultValue = (uint64_t)0;
    }
    else if (type == EConVarType_Int64) {
        if (defaultValue.type() == typeid(int64_t))
            defaultValue = (int64_t)std::any_cast<int64_t>(defaultValue);
        else
            defaultValue = (int64_t)0;
    }
    else if (type == EConVarType_Bool) {
        if (defaultValue.type() != typeid(bool))
            defaultValue = false;
    }
    else if (type == EConVarType_Float32) {
        if (defaultValue.type() != typeid(float))
            defaultValue = (float)0.0f;
    }
    else if (type == EConVarType_Float64) {
        if (defaultValue.type() != typeid(double))
            defaultValue = (double)0.0f;
    }
    else if (type == EConVarType_String) {
        if (defaultValue.type() != typeid(std::string)) {
            if (defaultValue.type() == typeid(char*))
                defaultValue = std::string(std::any_cast<char*>(defaultValue));
            else if (defaultValue.type() == typeid(const char*))
                defaultValue = std::string(std::any_cast<const char*>(defaultValue));
            else
                defaultValue = std::string("");
        }
    }
    else if (type == EConVarType_Color) {
        if (defaultValue.type() != typeid(Color))
            defaultValue = Color(0, 0, 0);
    }
    else if (type == EConVarType_Vector2) {
        if (defaultValue.type() != typeid(Vector2D))
            defaultValue = Vector2D(0.0f, 0.0f);
    }
    else if (type == EConVarType_Vector3) {
        if (defaultValue.type() != typeid(Vector))
            defaultValue = Vector(0.0f, 0.0f, 0.0f);
    }
    else if (type == EConVarType_Vector4) {
        if (defaultValue.type() != typeid(Vector4D))
            defaultValue = Vector4D(0.0f, 0.0f, 0.0f, 0.0f);
    }
    else if (type == EConVarType_Qangle) {
        if (defaultValue.type() != typeid(QAngle))
            defaultValue = QAngle(0.0f, 0.0f, 0.0f);
    }

    InsertFakeConvar(cvarname, (EConVarType)type, defaultValue, prot);
    if(created_cvars.find(cvarname) == created_cvars.end()) created_cvars.insert(cvarname);
}

void PluginConvars::DeleteFake(std::string cvarname)
{
    if (!FakeConvarExists(cvarname)) return;

    DeleteFakeConvar(cvarname);
    if(created_cvars.find(cvarname) != created_cvars.end()) created_cvars.erase(cvarname);
}

void PluginConvars::AddFlags(std::string cvarname, int64_t flags)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::AddFlags(cvarname=\"%s\",flags=%lld)", cvarname.c_str(), flags));
    auto cvar = FetchCVar(cvarname);
    if (cvar == nullptr) return;

    cvar->flags |= flags;
}

void PluginConvars::RemoveFlags(std::string cvarname, int64_t flags)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::RemoveFlags(cvarname=\"%s\",flags=%lld)", cvarname.c_str(), flags));
    auto cvar = FetchCVar(cvarname);
    if (cvar == nullptr) return;

    cvar->flags &= ~flags;
}

int64_t PluginConvars::GetFlags(std::string cvarname)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::GetFlags(cvarname=\"%s\")", cvarname.c_str()));
    auto cvar = FetchCVar(cvarname);
    if (cvar == nullptr) return 0;

    return cvar->flags;
}

bool PluginConvars::HasFlags(std::string cvarname, int64_t flags)
{
    REGISTER_CALLSTACK(this->plugin_name, string_format("PluginConvars::HasFlags(cvarname=\"%s\",flags=%lld)", cvarname.c_str(), flags));
    auto cvar = FetchCVar(cvarname);
    if (cvar == nullptr) return false;

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