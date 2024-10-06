#ifndef _cbaseviewmodel_h
#define _cbaseviewmodel_h

#include "CBaseModelEntity.h"

class CBaseViewModel;

class CCSPlayer_ViewModelServices
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSPlayer_ViewModelServices)

    SCHEMA_FIELD_POINTER_OFFSET(CHandle<CBaseViewModel>, m_hViewModel, 0)
};

class CBaseViewModel : public CBaseModelEntity
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBaseViewModel)
};

#endif