#include "../scripting.h"

#include "../../../signatures/Signatures.h"

typedef IGameEventListener2 *(*GetLegacyGameEventListener)(CPlayerSlot slot);

PluginEvent::PluginEvent(std::string m_plugin_name, IGameEvent *m_gameEvent, void *m_hookPtr)
{
    this->plugin_name = m_plugin_name;
    this->gameEvent = m_gameEvent;
    this->hookPtr = m_hookPtr;
}

PluginEvent::~PluginEvent()
{
}

std::string PluginEvent::GetInvokingPlugin()
{
    return this->plugin_name;
}

bool PluginEvent::IsGameEvent()
{
    return (this->gameEvent != nullptr);
}

bool PluginEvent::IsHook()
{
    return (this->hookPtr != nullptr);
}

void PluginEvent::SetReturn(std::any value)
{
    this->returnValue = value;
}

void PluginEvent::SetReturnLua(luabridge::LuaRef value)
{
    std::any returnValue;

    if (value.isBool())
        returnValue = value.cast<bool>();
    else if (value.isNil())
        returnValue = nullptr;
    else if (value.isNumber())
        returnValue = value.cast<int64_t>();
    else if (value.isString())
        returnValue = value.cast<std::string>();
    else
        returnValue = nullptr;

    SetReturn(returnValue);
}

std::any PluginEvent::GetReturnValue()
{
    return this->returnValue;
}

void PluginEvent::SetBool(std::string key, bool value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetBool(key.c_str(), value);
}

void PluginEvent::SetInt(std::string key, int value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetInt(key.c_str(), value);
}

void PluginEvent::SetUint64(std::string key, uint64_t value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetUint64(key.c_str(), value);
}

void PluginEvent::SetFloat(std::string key, float value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetFloat(key.c_str(), value);
}

void PluginEvent::SetString(std::string key, std::string value)
{
    if (!this->gameEvent)
        return;

    this->gameEvent->SetString(key.c_str(), value.c_str());
}

bool PluginEvent::GetBool(std::string key)
{
    if (!this->gameEvent)
        return false;

    return this->gameEvent->GetBool(key.c_str());
}

int PluginEvent::GetInt(std::string key)
{
    if (!this->gameEvent)
        return 0;

    return this->gameEvent->GetInt(key.c_str());
}

uint64_t PluginEvent::GetUint64(std::string key)
{
    if (!this->gameEvent)
        return 0;

    return this->gameEvent->GetUint64(key.c_str());
}

float PluginEvent::GetFloat(std::string key)
{
    if (!this->gameEvent)
        return 0.0f;

    return this->gameEvent->GetFloat(key.c_str());
}

std::string PluginEvent::GetString(std::string key)
{
    if (!this->gameEvent)
        return "";

    return this->gameEvent->GetString(key.c_str());
}

void PluginEvent::FireEvent(bool dontBroadcast)
{
    if (!this->gameEvent)
        return;

    g_gameEventManager->FireEvent(this->gameEvent, dontBroadcast);
}

void PluginEvent::FireEventToClient(int slot)
{
    if (!this->gameEvent)
        return;

    IGameEventListener2 *playerListener = g_Signatures->FetchSignature<GetLegacyGameEventListener>("LegacyGameEventListener")(slot);
    playerListener->FireGameEvent(this->gameEvent);
}