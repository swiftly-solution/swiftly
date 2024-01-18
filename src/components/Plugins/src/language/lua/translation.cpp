#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

void SetupLuaTranslation(luacpp::LuaState *state, Plugin *plugin)
{
    state->CreateFunction(scripting_Translations_Fetch, "FetchTranslation");
}