#include "../../../core/scripting/generated/classes/GCFuseSymbolTable.h"
#include "../core.h"

void SetupLuaClassGCFuseSymbolTable(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuseSymbolTable>("CFuseSymbolTable")
        .addProperty("Constants", &GCFuseSymbolTable::GetConstants, &GCFuseSymbolTable::SetConstants)
        .addProperty("Variables", &GCFuseSymbolTable::GetVariables, &GCFuseSymbolTable::SetVariables)
        .addProperty("Functions", &GCFuseSymbolTable::GetFunctions, &GCFuseSymbolTable::SetFunctions)
        .endClass();
}