#include "../../../core/scripting/generated/classes/GCTestDomainDerived_Cursor.h"
#include "../core.h"

void SetupLuaClassGCTestDomainDerived_Cursor(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCTestDomainDerived_Cursor>("CTestDomainDerived_Cursor")
        .addProperty("CursorValueA", &GCTestDomainDerived_Cursor::GetCursorValueA, &GCTestDomainDerived_Cursor::SetCursorValueA)
        .addProperty("CursorValueB", &GCTestDomainDerived_Cursor::GetCursorValueB, &GCTestDomainDerived_Cursor::SetCursorValueB)
        .endClass();
}