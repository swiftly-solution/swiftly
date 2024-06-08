#include "../../../core/scripting/generated/classes/GC_INIT_Orient2DRelToCP.h"
#include "../core.h"

void SetupLuaClassGC_INIT_Orient2DRelToCP(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_INIT_Orient2DRelToCP>("C_INIT_Orient2DRelToCP")
        .addProperty("CP", &GC_INIT_Orient2DRelToCP::GetCP, &GC_INIT_Orient2DRelToCP::SetCP)
        .addProperty("FieldOutput", &GC_INIT_Orient2DRelToCP::GetFieldOutput, &GC_INIT_Orient2DRelToCP::SetFieldOutput)
        .addProperty("RotOffset", &GC_INIT_Orient2DRelToCP::GetRotOffset, &GC_INIT_Orient2DRelToCP::SetRotOffset)
        .endClass();
}