#include "../../../core/scripting/generated/classes/GFootFixedData_t.h"
#include "../core.h"

void SetupLuaClassGFootFixedData_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GFootFixedData_t>("FootFixedData_t")
        .addProperty("ToeOffset", &GFootFixedData_t::GetToeOffset, &GFootFixedData_t::SetToeOffset)
        .addProperty("HeelOffset", &GFootFixedData_t::GetHeelOffset, &GFootFixedData_t::SetHeelOffset)
        .addProperty("TargetBoneIndex", &GFootFixedData_t::GetTargetBoneIndex, &GFootFixedData_t::SetTargetBoneIndex)
        .addProperty("AnkleBoneIndex", &GFootFixedData_t::GetAnkleBoneIndex, &GFootFixedData_t::SetAnkleBoneIndex)
        .addProperty("IKAnchorBoneIndex", &GFootFixedData_t::GetIKAnchorBoneIndex, &GFootFixedData_t::SetIKAnchorBoneIndex)
        .addProperty("IkChainIndex", &GFootFixedData_t::GetIkChainIndex, &GFootFixedData_t::SetIkChainIndex)
        .addProperty("MaxIKLength", &GFootFixedData_t::GetMaxIKLength, &GFootFixedData_t::SetMaxIKLength)
        .addProperty("FootIndex", &GFootFixedData_t::GetFootIndex, &GFootFixedData_t::SetFootIndex)
        .addProperty("TagIndex", &GFootFixedData_t::GetTagIndex, &GFootFixedData_t::SetTagIndex)
        .addProperty("MaxRotationLeft", &GFootFixedData_t::GetMaxRotationLeft, &GFootFixedData_t::SetMaxRotationLeft)
        .addProperty("MaxRotationRight", &GFootFixedData_t::GetMaxRotationRight, &GFootFixedData_t::SetMaxRotationRight)
        .endClass();
}