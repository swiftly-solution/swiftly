#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaPrecacherClass
{
public:
    LuaPrecacherClass() {}
};

void SetupLuaPrecacher(luacpp::LuaState *state, Plugin *plugin)
{
    auto precacherClass = state->CreateClass<LuaPrecacherClass>("Precacher").DefConstructor();

    precacherClass.DefMember("PrecacheModel", [](LuaPrecacherClass *base, const char *model) -> void
                             { scripting_Precacher_AddModel(model); });

    state->DoString("precacher = Precacher()");
}