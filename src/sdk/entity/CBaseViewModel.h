#ifndef _cbaseviewmodel_h
#define _cbaseviewmodel_h

#include "CBaseModelEntity.h"
#include "services.h"

class CBaseViewModel;

class CBaseViewModel : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBaseViewModel)

    SCHEMA_FIELD_OFFSET(int, m_nViewModelIndex, 0);
};

class CCSGOViewModel : public CBaseViewModel
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSGOViewModel)
};

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
        pViewModel->m_nViewModelIndex = iIndex;
        this->m_pPawn->NetworkStateChanged();
    }
};

#endif