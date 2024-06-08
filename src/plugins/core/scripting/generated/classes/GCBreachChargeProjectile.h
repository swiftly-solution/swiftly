class GCBreachChargeProjectile;

#ifndef _gccbreachchargeprojectile_h
#define _gccbreachchargeprojectile_h

#include "../../../scripting.h"




class GCBreachChargeProjectile
{
private:
    void *m_ptr;

public:
    GCBreachChargeProjectile() {}
    GCBreachChargeProjectile(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif