#include "../scripting.h"

#include <module.h>
#include "../../../utils/module.h"

void *FindSignature(const char *moduleName, const char *bytes);

PluginMemory::PluginMemory()
{
    m_ptr = nullptr;
}

void PluginMemory::LoadFromPtr(void *ptr)
{
    m_ptr = ptr;
}
void PluginMemory::LoadFromAddress(std::string addr)
{
    m_ptr = (void *)(strtol(addr.c_str(), nullptr, 16));
}

void PluginMemory::LoadFromSignatureName(std::string signature_name)
{
    m_ptr = g_Signatures->FetchRawSignature(signature_name);
}

void PluginMemory::LoadFromSignature(std::string library, std::string signature)
{
    void *sig = nullptr;
    if (signature.find("?") == std::string::npos)
    {
        std::string finalSig = (signature.at(0) == '@') ? signature : ("\\x" + replace(signature, " ", "\\x"));
        sig = FindSignature(library.c_str(), finalSig.c_str());
        if (sig == nullptr)
            return;
    }
    else
    {
        DynLibUtils::CModule module(library == "server" ? server : nullptr);
        DynLibUtils::CMemory sg = module.FindPattern(signature);
        if (!sg)
            return;

        sig = sg.RCast<void *>();
    }

    m_ptr = sig;
}

void PluginMemory::AddOffset(int64_t offset)
{
    m_ptr = m_ptr + offset;
}
void PluginMemory::RemoveOffset(int64_t offset)
{
    m_ptr = m_ptr - offset;
}

void PluginMemory::Clear()
{
    m_ptr = nullptr;
}

std::string PluginMemory::GetPtr()
{
    return string_format("%p", m_ptr);
}

bool PluginMemory::IsValid()
{
    return (m_ptr != nullptr);
}

void *PluginMemory::GetRawPtr()
{
    return m_ptr;
}