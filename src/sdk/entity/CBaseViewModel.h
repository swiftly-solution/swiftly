#ifndef _cbaseviewmodel_h
#define _cbaseviewmodel_h

#include "CBaseModelEntity.h"
#include "services.h"

class CBaseViewModel;

class CCSPlayer_ViewModelServices : public CPlayerPawnComponent
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayer_ViewModelServices)

    SCHEMA_FIELD_POINTER_OFFSET(CHandle<CBaseViewModel>, m_hViewModel, 0);

    CBaseViewModel* GetViewModel(int iIndex = 0)
    {
        return m_hViewModel()[iIndex].Get();
    }

    void SetViewModel(int iIndex, CBaseViewModel* pViewModel)
    {
        m_hViewModel()[iIndex].Set(pViewModel);
        this->m_pPawn->NetworkStateChanged();
    }
};

class CBaseViewModel : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBaseViewModel)
};

class CCSGOViewModel : public CBaseViewModel
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSGOViewModel)
};

#endif