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

void SetupLuaLogger(luacpp::LuaState *state, Plugin *plugin)
{
    state->CreateInteger(1, "LOGLEVEL_DEBUG");
    state->CreateInteger(2, "LOGLEVEL_WARNING");
    state->CreateInteger(3, "LOGLEVEL_ERROR");
    state->CreateInteger(4, "LOGLEVEL_COMMON");

    auto loggerClass = state->CreateClass<LuaLoggerClass>("Logger").DefConstructor<const char *>();

    loggerClass.DefMember("Write", [plugin](LuaLoggerClass *base, int level, const char *message)
                          { scripting_Logger_WriteLog(plugin->GetName().c_str(), (ELogType)level, message); });

    state->DoString("logger = Logger(PluginName())");

    PRINT("Scripting - Lua", "Logger loaded.\n");
}