#include "../../../core/scripting/generated/classes/GCSosGroupActionMemberCountEnvelopeSchema.h"
#include "../core.h"

void SetupLuaClassGCSosGroupActionMemberCountEnvelopeSchema(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCSosGroupActionMemberCountEnvelopeSchema>("CSosGroupActionMemberCountEnvelopeSchema")
        .addProperty("BaseCount", &GCSosGroupActionMemberCountEnvelopeSchema::GetBaseCount, &GCSosGroupActionMemberCountEnvelopeSchema::SetBaseCount)
        .addProperty("TargetCount", &GCSosGroupActionMemberCountEnvelopeSchema::GetTargetCount, &GCSosGroupActionMemberCountEnvelopeSchema::SetTargetCount)
        .addProperty("BaseValue", &GCSosGroupActionMemberCountEnvelopeSchema::GetBaseValue, &GCSosGroupActionMemberCountEnvelopeSchema::SetBaseValue)
        .addProperty("TargetValue", &GCSosGroupActionMemberCountEnvelopeSchema::GetTargetValue, &GCSosGroupActionMemberCountEnvelopeSchema::SetTargetValue)
        .addProperty("Attack", &GCSosGroupActionMemberCountEnvelopeSchema::GetAttack, &GCSosGroupActionMemberCountEnvelopeSchema::SetAttack)
        .addProperty("Decay", &GCSosGroupActionMemberCountEnvelopeSchema::GetDecay, &GCSosGroupActionMemberCountEnvelopeSchema::SetDecay)
        .addProperty("ResultVarName", &GCSosGroupActionMemberCountEnvelopeSchema::GetResultVarName, &GCSosGroupActionMemberCountEnvelopeSchema::SetResultVarName)
        .addProperty("SaveToGroup", &GCSosGroupActionMemberCountEnvelopeSchema::GetSaveToGroup, &GCSosGroupActionMemberCountEnvelopeSchema::SetSaveToGroup)
        .endClass();
}