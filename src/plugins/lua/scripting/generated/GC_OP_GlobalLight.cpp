#include "../../../core/scripting/generated/classes/GC_OP_GlobalLight.h"
#include "../core.h"

void SetupLuaClassGC_OP_GlobalLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_GlobalLight>("C_OP_GlobalLight")
        .addProperty("Scale", &GC_OP_GlobalLight::GetScale, &GC_OP_GlobalLight::SetScale)
        .addProperty("ClampLowerRange", &GC_OP_GlobalLight::GetClampLowerRange, &GC_OP_GlobalLight::SetClampLowerRange)
        .addProperty("ClampUpperRange", &GC_OP_GlobalLight::GetClampUpperRange, &GC_OP_GlobalLight::SetClampUpperRange)
        .endClass();
}