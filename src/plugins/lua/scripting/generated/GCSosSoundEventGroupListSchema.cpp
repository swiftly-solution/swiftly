#include "../../../core/scripting/generated/classes/GCSosSoundEventGroupListSchema.h"
#include "../core.h"

void SetupLuaClassGCSosSoundEventGroupListSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosSoundEventGroupListSchema>("CSosSoundEventGroupListSchema")
        .addProperty("GroupList", &GCSosSoundEventGroupListSchema::GetGroupList, &GCSosSoundEventGroupListSchema::SetGroupList)
        .endClass();
}