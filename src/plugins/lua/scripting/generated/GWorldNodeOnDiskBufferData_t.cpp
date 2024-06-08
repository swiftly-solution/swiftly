#include "../../../core/scripting/generated/classes/GWorldNodeOnDiskBufferData_t.h"
#include "../core.h"

void SetupLuaClassGWorldNodeOnDiskBufferData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GWorldNodeOnDiskBufferData_t>("WorldNodeOnDiskBufferData_t")
        .addProperty("ElementCount", &GWorldNodeOnDiskBufferData_t::GetElementCount, &GWorldNodeOnDiskBufferData_t::SetElementCount)
        .addProperty("ElementSizeInBytes", &GWorldNodeOnDiskBufferData_t::GetElementSizeInBytes, &GWorldNodeOnDiskBufferData_t::SetElementSizeInBytes)
        .addProperty("InputLayoutFields", &GWorldNodeOnDiskBufferData_t::GetInputLayoutFields, &GWorldNodeOnDiskBufferData_t::SetInputLayoutFields)
        .addProperty("Data", &GWorldNodeOnDiskBufferData_t::GetData, &GWorldNodeOnDiskBufferData_t::SetData)
        .endClass();
}