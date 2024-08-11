#include "../scripting.h"

PluginCHandle::PluginCHandle(void* ptr)
{
    m_Handle = (CHandle<CEntityInstance>*)ptr;
}

PluginCHandle::PluginCHandle(std::string ptr)
{
    if (!starts_with(ptr, "0x")) return;

    m_Handle = (CHandle<CEntityInstance>*)strtol(ptr.c_str(), nullptr, 16);
}

std::string PluginCHandle::GetPtr()
{
    return string_format("%p", (void*)m_Handle->Get());
}

void PluginCHandle::SetPtr(std::string ptr)
{
    if (!starts_with(ptr, "0x")) return;

    m_Handle->Set((CEntityInstance*)strtol(ptr.c_str(), nullptr, 16));
}

std::string PluginCHandle::GetHandlePtr()
{
    return string_format("%p", (void*)m_Handle);
}