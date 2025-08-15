#include "../schema.h"

class CEntityInstance;

class CPlayerPawnComponent
{
    virtual ~CPlayerPawnComponent() = 0;
    virtual void unk_01() = 0;
    virtual void unk_02() = 0;
    virtual void unk_03() = 0;
    virtual void unk_04() = 0;
    virtual void unk_05() = 0;
    virtual void unk_06() = 0;
    virtual void unk_07() = 0;
    virtual void unk_08() = 0;
    virtual void unk_09() = 0;
    virtual void unk_10() = 0;
    virtual void unk_11() = 0;
    virtual void unk_12() = 0;
    virtual void unk_13() = 0;
    virtual void unk_14() = 0;
    virtual void unk_15() = 0;
    virtual void unk_16() = 0;
    virtual void unk_17() = 0;

public:
    CEntityInstance* GetPawn() { return reinterpret_cast<CEntityInstance*>(schema::GetProp<CNetworkVarChainer>(this, "CPlayerPawnComponent", "__m_pChainEntity").m_pEntity); }
};