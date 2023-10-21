#pragma once

#include "../../BaseComponent.h"

class BasicComponent : public BaseComponent
{
public:
    void LoadComponent();
    inline const char *GetName() { return "Basic Component"; };
};