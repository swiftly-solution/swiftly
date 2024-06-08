#include "../../../core/scripting/generated/classes/GCSosGroupActionSoundeventPrioritySchema.h"
#include "../core.h"

void SetupLuaClassGCSosGroupActionSoundeventPrioritySchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionSoundeventPrioritySchema>("CSosGroupActionSoundeventPrioritySchema")
        .addProperty("PriorityValue", &GCSosGroupActionSoundeventPrioritySchema::GetPriorityValue, &GCSosGroupActionSoundeventPrioritySchema::SetPriorityValue)
        .addProperty("PriorityVolumeScalar", &GCSosGroupActionSoundeventPrioritySchema::GetPriorityVolumeScalar, &GCSosGroupActionSoundeventPrioritySchema::SetPriorityVolumeScalar)
        .addProperty("PriorityContributeButDontRead", &GCSosGroupActionSoundeventPrioritySchema::GetPriorityContributeButDontRead, &GCSosGroupActionSoundeventPrioritySchema::SetPriorityContributeButDontRead)
        .addProperty("PriorityReadButDontContribute", &GCSosGroupActionSoundeventPrioritySchema::GetPriorityReadButDontContribute, &GCSosGroupActionSoundeventPrioritySchema::SetPriorityReadButDontContribute)
        .endClass();
}