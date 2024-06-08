class GCBaseIssue;

#ifndef _gccbaseissue_h
#define _gccbaseissue_h

#include "../../../scripting.h"




class GCBaseIssue
{
private:
    void *m_ptr;

public:
    GCBaseIssue() {}
    GCBaseIssue(void *ptr) : m_ptr(ptr) {}

    std::string GetTypeString() const { return GetSchemaValue<char*>(m_ptr, "CBaseIssue", "m_szTypeString"); }
    void SetTypeString(std::string value) { SetSchemaValue(m_ptr, "CBaseIssue", "m_szTypeString", false, value); }
    std::string GetDetailsString() const { return GetSchemaValue<char*>(m_ptr, "CBaseIssue", "m_szDetailsString"); }
    void SetDetailsString(std::string value) { SetSchemaValue(m_ptr, "CBaseIssue", "m_szDetailsString", false, value); }
    int32_t GetNumYesVotes() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseIssue", "m_iNumYesVotes"); }
    void SetNumYesVotes(int32_t value) { SetSchemaValue(m_ptr, "CBaseIssue", "m_iNumYesVotes", false, value); }
    int32_t GetNumNoVotes() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseIssue", "m_iNumNoVotes"); }
    void SetNumNoVotes(int32_t value) { SetSchemaValue(m_ptr, "CBaseIssue", "m_iNumNoVotes", false, value); }
    int32_t GetNumPotentialVotes() const { return GetSchemaValue<int32_t>(m_ptr, "CBaseIssue", "m_iNumPotentialVotes"); }
    void SetNumPotentialVotes(int32_t value) { SetSchemaValue(m_ptr, "CBaseIssue", "m_iNumPotentialVotes", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif