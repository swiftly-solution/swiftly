#include "../../../core/scripting/generated/classes/GMotionBlendItem.h"
#include "../core.h"

void SetupLuaClassGMotionBlendItem(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GMotionBlendItem>("MotionBlendItem")
        .addProperty("KeyValue", &GMotionBlendItem::GetKeyValue, &GMotionBlendItem::SetKeyValue)
        .endClass();
}