#include "../../scripting.h"

#include "../../../../../vendor/dynlib/module.h"

void* FindSignature(const char* moduleName, const char* bytes);

PluginMemory::PluginMemory()
{
    m_ptr = nullptr;
}

void PluginMemory::LoadFromPtr(void* ptr)
{
    m_ptr = ptr;
}
void PluginMemory::LoadFromAddress(std::string addr)
{
    if (!starts_with(addr, "0x")) return;

    m_ptr = (void*)(strtol(addr.c_str(), nullptr, 16));
}

void PluginMemory::LoadFromSignatureName(std::string signature_name)
{
    m_ptr = g_Signatures->FetchRawSignature(signature_name);
}

void PluginMemory::LoadFromSignature(std::string library, std::string signature)
{
    void* sig = nullptr;
    DynLibUtils::CModule module = DetermineModuleByLibrary(library);
    if (signature.at(0) == '@') sig = module.GetFunctionByName((signature.c_str() + 1)).RCast<void*>();
    else sig = module.FindPattern(signature).RCast<void*>();
    if (sig == nullptr) return;

    m_ptr = sig;
}

void PluginMemory::AddOffsetByName(std::string offsetName)
{
    int64_t offset = g_Offsets->GetOffset(offsetName);
    if (offset == -1) return;
    m_ptr = ((char*)m_ptr) + offset;
}

void PluginMemory::RemoveOffsetByName(std::string offsetName)
{
    int64_t offset = g_Offsets->GetOffset(offsetName);
    if (offset == -1) return;
    m_ptr = ((char*)m_ptr) - offset;
}

void PluginMemory::AddOffset(int64_t offset)
{
    m_ptr = ((char*)m_ptr) + offset;
}
void PluginMemory::RemoveOffset(int64_t offset)
{
    m_ptr = ((char*)m_ptr) - offset;
}

void PluginMemory::AccessVTableFromOffset(std::string offsetName)
{
    int64_t offset = g_Offsets->GetOffset(offsetName);
    if (offset == -1) return;

    void* pt = m_ptr;
    m_ptr = reinterpret_cast<void***>(pt)[0][offset];
    accessedVTable = true;
}

void PluginMemory::AccessIndex(int64_t idx)
{
    if(idx < 0) return;

    void* pt = m_ptr;
    m_ptr = reinterpret_cast<void**>(pt)[idx];
}

void PluginMemory::AccessVTable(int64_t offset)
{
    void* pt = m_ptr;
    m_ptr = reinterpret_cast<void***>(pt)[0][offset];
    accessedVTable = true;
}

bool PluginMemory::AccessedVTable()
{
    return accessedVTable;
}

void PluginMemory::Clear()
{
    m_ptr = nullptr;
}

void PluginMemory::SetBool(bool value)
{
    *((bool*)(m_ptr)) = value;
}
void PluginMemory::SetInt(int value)
{
    *((int*)(m_ptr)) = value;
}
void PluginMemory::SetInt64(int64_t value)
{
    *((int64_t*)(m_ptr)) = value;
}
void PluginMemory::SetUint(uint32_t value)
{
    *((uint32_t*)(m_ptr)) = value;
}
void PluginMemory::SetUint64(uint64_t value)
{
    *((uint64_t*)(m_ptr)) = value;
}
void PluginMemory::SetFloat(float value)
{
    *((float*)(m_ptr)) = value;
}
void PluginMemory::SetDouble(double value)
{
    *((double*)(m_ptr)) = value;
}
void PluginMemory::SetVector(Vector value)
{
    *((Vector*)(m_ptr)) = value;
}
void PluginMemory::SetVector2D(Vector2D value)
{
    *((Vector2D*)(m_ptr)) = value;
}
void PluginMemory::SetVector4D(Vector4D value)
{
    *((Vector4D*)(m_ptr)) = value;
}
void PluginMemory::SetColor(Color value)
{
    *((Color*)(m_ptr)) = value;
}
void PluginMemory::SetQAngle(QAngle value)
{
    *((QAngle*)(m_ptr)) = value;
}

bool PluginMemory::GetBool()
{
    return *((bool*)(m_ptr));
}
int PluginMemory::GetInt()
{
    return *((int*)(m_ptr));
}
int64_t PluginMemory::GetInt64()
{
    return *((int64_t*)(m_ptr));
}
uint32_t PluginMemory::GetUint()
{
    return *((uint32_t*)(m_ptr));
}
uint64_t PluginMemory::GetUint64()
{
    return *((uint64_t*)(m_ptr));
}
float PluginMemory::GetFloat()
{
    return *((float*)(m_ptr));
}
double PluginMemory::GetDouble()
{
    return *((double*)(m_ptr));
}
Vector PluginMemory::GetVector()
{
    return *((Vector*)(m_ptr));
}
Vector2D PluginMemory::GetVector2D()
{
    return *((Vector2D*)(m_ptr));
}
Vector4D PluginMemory::GetVector4D()
{
    return *((Vector4D*)(m_ptr));
}
Color PluginMemory::GetColor()
{
    return *((Color*)(m_ptr));
}
QAngle PluginMemory::GetQAngle()
{
    return *((QAngle*)(m_ptr));
}

std::string PluginMemory::GetPtr()
{
    return string_format("%p", m_ptr);
}

bool PluginMemory::IsValid()
{
    return (m_ptr != nullptr);
}

void* PluginMemory::GetRawPtr()
{
    return m_ptr;
}