#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

void SetupLuaUtils(luacpp::LuaState *state, Plugin *plugin)
{
    state->CreateFunction([]() -> const char *
                          { return WIN_LINUX("Windows", "Linux"); },
                          "GetOS");
    state->CreateFunction([]() -> bool
                          { return WIN_LINUX(true, false); },
                          "IsWindows");
    state->CreateFunction([]() -> bool
                          { return WIN_LINUX(true, false); },
                          "IsLinux");
    state->CreateFunction([]() -> uint64_t
                          { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); },
                          "GetTime");

    PRINT("Scripting - Lua", "Utils loaded.\n");
}