#include "../../../core/scripting/generated/classes/GCFilterModel.h"
#include "../core.h"

void SetupLuaClassGCFilterModel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFilterModel>("CFilterModel")
        .addProperty("FilterModel", &GCFilterModel::GetFilterModel, &GCFilterModel::SetFilterModel)
        .endClass();
}