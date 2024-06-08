class GResponseFollowup;

#ifndef _gcresponsefollowup_h
#define _gcresponsefollowup_h

#include "../../../scripting.h"




class GResponseFollowup
{
private:
    void *m_ptr;

public:
    GResponseFollowup() {}
    GResponseFollowup(void *ptr) : m_ptr(ptr) {}

    std::string GetFollowup_concept() const { return GetSchemaValue<char*>(m_ptr, "ResponseFollowup", "followup_concept"); }
    void SetFollowup_concept(std::string value) { WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_concept", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    std::string GetFollowup_contexts() const { return GetSchemaValue<char*>(m_ptr, "ResponseFollowup", "followup_contexts"); }
    void SetFollowup_contexts(std::string value) { WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_contexts", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    float GetFollowup_delay() const { return GetSchemaValue<float>(m_ptr, "ResponseFollowup", "followup_delay"); }
    void SetFollowup_delay(float value) { SetSchemaValue(m_ptr, "ResponseFollowup", "followup_delay", false, value); }
    std::string GetFollowup_target() const { return GetSchemaValue<char*>(m_ptr, "ResponseFollowup", "followup_target"); }
    void SetFollowup_target(std::string value) { WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_target", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    std::string GetFollowup_entityiotarget() const { return GetSchemaValue<char*>(m_ptr, "ResponseFollowup", "followup_entityiotarget"); }
    void SetFollowup_entityiotarget(std::string value) { WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_entityiotarget", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    std::string GetFollowup_entityioinput() const { return GetSchemaValue<char*>(m_ptr, "ResponseFollowup", "followup_entityioinput"); }
    void SetFollowup_entityioinput(std::string value) { WriteSchemaPtrValue(m_ptr, "ResponseFollowup", "followup_entityioinput", false, reinterpret_cast<byte*>(const_cast<char*>(value.c_str())), value.size()); }
    float GetFollowup_entityiodelay() const { return GetSchemaValue<float>(m_ptr, "ResponseFollowup", "followup_entityiodelay"); }
    void SetFollowup_entityiodelay(float value) { SetSchemaValue(m_ptr, "ResponseFollowup", "followup_entityiodelay", false, value); }
    bool GetFired() const { return GetSchemaValue<bool>(m_ptr, "ResponseFollowup", "bFired"); }
    void SetFired(bool value) { SetSchemaValue(m_ptr, "ResponseFollowup", "bFired", false, value); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif