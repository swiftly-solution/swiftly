#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

class LuaTimersClass
{
private:
    int timerIDs = 0;

public:
    LuaTimersClass() {}

    int GetNextTimerID()
    {
        return (++this->timerIDs);
    }
};

void SetupLuaTimers(luacpp::LuaState *state, Plugin *plugin)
{
    luacpp::LuaTable timersTable = state->CreateTable("timersTbl");

    auto timersClass = state->CreateClass<LuaTimersClass>("Timers").DefConstructor();

    timersClass.DefMember("create", [state](LuaTimersClass *base, int milliseconds, const luacpp::LuaObject &function) -> uint64_t
                          {
                              if (milliseconds < 500)
                              {
                                  PRINT("Runtime", "Timer delay time needs to be more than 500ms between calls.\n");
                                  return 0;
                              }
                              if (function.GetType() != LUA_TFUNCTION)
                              {
                                  PRINT("Runtime", "The second argument needs to be a function.\n");
                                  return 0;
                              }

                              luacpp::LuaTable newTimerTable = state->CreateTable();

                              newTimerTable.SetInteger("delay", milliseconds);
                              newTimerTable.Set("func", function);
                              newTimerTable.SetInteger("last_called", 0);
                              newTimerTable.SetInteger("paused", false);

                              int timerID = base->GetNextTimerID();
                        
                              state->GetTable("timersTbl").Set(timerID, newTimerTable);
                              
                              return timerID; })

        .DefMember("delete", [state](LuaTimersClass *base, int timerId) -> void
                   {
                    luacpp::LuaTable timersTbl = state->GetTable("timersTbl");

                    if(timersTbl.Get(timerId).GetType() != LUA_TTABLE) {
                        PRINT("Runtime", "The timer with the specified ID doesn't exists.\n");
                        return;
                    }

                    timersTbl.Set(timerId, state->CreateNil()); })

        .DefMember("pause", [state](LuaTimersClass *base, int timerId) -> void
                   {
            luacpp::LuaTable timersTbl = state->GetTable("timersTbl");

                    if(timersTbl.Get(timerId).GetType() != LUA_TTABLE) {
                        PRINT("Runtime", "The timer with the specified ID doesn't exists.\n");
                        return;
                    }

                    luacpp::LuaTable tbl = luacpp::LuaTable(timersTbl.Get(timerId));

                    if(tbl.Get("paused").GetType() != LUA_TBOOLEAN) {
                        PRINT("Runtime", "The timer paused typed is not a boolean.\n");
                        return;
                    }

                    if(tbl.GetInteger("paused") == 1) {
                        PRINT("Runtime", "The timer is already paused.\n");
                        return;
                    }

                    tbl.SetInteger("paused", true); })
        .DefMember("unpause", [state](LuaTimersClass *base, int timerId) -> void
                   {
            luacpp::LuaTable timersTbl = state->GetTable("timersTbl");

                    if(timersTbl.Get(timerId).GetType() != LUA_TTABLE) {
                        PRINT("Runtime", "The timer with the specified ID doesn't exists.\n");
                        return;
                    }

                    luacpp::LuaTable tbl = luacpp::LuaTable(timersTbl.Get(timerId));

                    if(tbl.Get("paused").GetType() != LUA_TBOOLEAN) {
                        PRINT("Runtime", "The timer paused typed is not a boolean.\n");
                        return;
                    }

                    if(tbl.GetInteger("paused") == 0) {
                        PRINT("Runtime", "The timer is not paused.\n");
                        return;
                    }

                    tbl.SetInteger("paused", false); });

    state->DoString("timers = Timers()");

    state->DoString("events:on(\"OnGameTick\", function(simulating, first, last) for _, timerTbl in next,timersTbl,nil do if timerTbl.paused ~= 0 then goto continue end if (GetTime() - timerTbl.last_called) < timerTbl.delay then goto continue end timerTbl.func();timerTbl.last_called = GetTime(); ::continue:: end end)");

    PRINT("Scripting - Lua", "Timers loaded.\n");
}