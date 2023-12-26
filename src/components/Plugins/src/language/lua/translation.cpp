#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaLoggerClass
{
public:
    LuaLoggerClass(const char *plugin_name) { scripting_Logger_CreateLogger(plugin_name); }
};

void SetupLuaTranslation(luacpp::LuaState *state, Plugin *plugin)
{
    state->CreateFunction([](const char *key) -> const char *
                          { return scripting_Translations_Fetch(key); },
                          "FetchTranslation");

    PRINT("Scripting - Lua", "Translation loaded.\n");
}