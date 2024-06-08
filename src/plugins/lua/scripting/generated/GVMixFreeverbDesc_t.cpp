#include "../../../core/scripting/generated/classes/GVMixFreeverbDesc_t.h"
#include "../core.h"

void SetupLuaClassGVMixFreeverbDesc_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GVMixFreeverbDesc_t>("VMixFreeverbDesc_t")
        .addProperty("RoomSize", &GVMixFreeverbDesc_t::GetRoomSize, &GVMixFreeverbDesc_t::SetRoomSize)
        .addProperty("Damp", &GVMixFreeverbDesc_t::GetDamp, &GVMixFreeverbDesc_t::SetDamp)
        .addProperty("Width", &GVMixFreeverbDesc_t::GetWidth, &GVMixFreeverbDesc_t::SetWidth)
        .addProperty("LateReflections", &GVMixFreeverbDesc_t::GetLateReflections, &GVMixFreeverbDesc_t::SetLateReflections)
        .endClass();
}