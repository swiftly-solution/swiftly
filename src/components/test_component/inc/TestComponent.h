#pragma once

#include "../../BaseComponent.h"

class TestComponent : public BaseComponent
{
public:
    void LoadComponent();
    inline const char *GetName() { return "Test Component"; };
};