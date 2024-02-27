#ifndef _addons_h
#define _addons_h

/**************************************************
 * This feature was taken from https://github.com/Source2ZE/CS2Fixes/commit/98cc65a8a10f03ef8a96003f2e23f74be48284bb
 * Thanks to CS2Fixes for providing this method.
 ***************************************************/

#include <string>
#include <vector>

class Addons
{
private:
    bool m_status = false;
    uint32_t timeout = 10;
    std::vector<std::string> addons;

public:
    Addons() {}

    void RegisterAddons();
    void ToggleStatus() { this->m_status = !this->m_status; }
    void SetStatus(bool status) { this->m_status = status; }
    bool GetStatus() { return this->m_status; }
    void SetTimeout(uint32_t timeout) { this->timeout = timeout; }
    uint32_t GetTimeout() { return this->timeout; }
    std::vector<std::string> GetAddons() { return this->addons; }
};

extern Addons *g_addons;

#endif