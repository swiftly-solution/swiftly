#include "../../../core/scripting/generated/classes/GC_OP_HSVShiftToCP.h"
#include "../core.h"

void SetupLuaClassGC_OP_HSVShiftToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_HSVShiftToCP>("C_OP_HSVShiftToCP")
        .addProperty("ColorCP", &GC_OP_HSVShiftToCP::GetColorCP, &GC_OP_HSVShiftToCP::SetColorCP)
        .addProperty("ColorGemEnableCP", &GC_OP_HSVShiftToCP::GetColorGemEnableCP, &GC_OP_HSVShiftToCP::SetColorGemEnableCP)
        .addProperty("OutputCP", &GC_OP_HSVShiftToCP::GetOutputCP, &GC_OP_HSVShiftToCP::SetOutputCP)
        .addProperty("DefaultHSVColor", &GC_OP_HSVShiftToCP::GetDefaultHSVColor, &GC_OP_HSVShiftToCP::SetDefaultHSVColor)
        .endClass();
}