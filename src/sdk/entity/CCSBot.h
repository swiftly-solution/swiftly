#pragma once

#include "services.h"
class CCSPlayerController;

class CBot
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CBot)

    SCHEMA_FIELD_POINTER_OFFSET(CCSPlayerController, m_pController, 0);
};

class CCSBot : public CBot
{
public:
    DECLARE_SCHEMA_CLASS_BASE(CCSBot)

    SCHEMA_FIELD_POINTER_OFFSET(char, m_name, 0);
};