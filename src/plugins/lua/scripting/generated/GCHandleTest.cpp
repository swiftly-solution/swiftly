#include "../../../core/scripting/generated/classes/GCHandleTest.h"
#include "../core.h"

void SetupLuaClassGCHandleTest(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHandleTest>("CHandleTest")
        .addProperty("Handle", &GCHandleTest::GetHandle, &GCHandleTest::SetHandle)
        .addProperty("SendHandle", &GCHandleTest::GetSendHandle, &GCHandleTest::SetSendHandle)
        .endClass();
}