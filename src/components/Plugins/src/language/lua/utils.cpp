#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>
#include <thread>

void SetupLuaUtils(luacpp::LuaState *state, Plugin *plugin)
{
    state->CreateTable("NextTicksFuncToCall");
    state->CreateTable("timeoutsTbl");

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

    state->CreateFunction([plugin](luacpp::LuaObject obj) -> void
                          {
        if(obj.GetType() != LUA_TFUNCTION) return;

        std::thread th([plugin, obj]() -> void {
            LuaFuncWrapper func(obj);
            func.PrepForExec();
            func.ExecuteNoReturn("thread", 0);
        });
        th.detach(); },
                          "CreateThread");

    state->CreateFunction([](uint64_t waitms) -> void
                          {
        uint64_t time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - time < waitms) {} },
                          "Wait");

    state->DoString("function NextTick(func) if type(func) ~= \"function\" then return print(\"[Swiftly] The callback needs to be a function.\") end table.insert(NextTicksFuncToCall, func); end");
    state->DoString("events:on(\"OnGameTick\", function(simulating, first, last) if simulating == 0 then return end; for i=1,#NextTicksFuncToCall do NextTicksFuncToCall[i](); end NextTicksFuncToCall = {}; end)");

    state->DoString("function SetTimeout(delay, cb) if type(func) ~= \"function\" then return print(\"[Swiftly] The callback needs to be a function.\") end table.insert(timeoutsTbl, { call = GetTime() + delay, cb = cb }); end");
    state->DoString("events:on(\"OnGameTick\", function(simulating, first, last) if simulating == 0 then return end for k,v in next,timeoutsTbl,nil do if v.call - GetTime() <= 0 then v.cb(); timeoutsTbl[k] = nil; end end end)")
}