#include "../../../core/scripting/generated/classes/GCAnimMotorUpdaterBase.h"
#include "../core.h"

void SetupLuaClassGCAnimMotorUpdaterBase(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCAnimMotorUpdaterBase>("CAnimMotorUpdaterBase")
        .addProperty("Name", &GCAnimMotorUpdaterBase::GetName, &GCAnimMotorUpdaterBase::SetName)
        .addProperty("Default", &GCAnimMotorUpdaterBase::GetDefault, &GCAnimMotorUpdaterBase::SetDefault)
        .endClass();
}