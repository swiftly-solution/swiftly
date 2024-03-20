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
    luacpp::LuaTable timersTable = (state->Get("timersTbl").GetType() == LUA_TNIL ? state->CreateTable("timersTbl") : state->GetTable("timersTbl"));

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
                              int timerID = base->GetNextTimerID();

                              newTimerTable.SetInteger("id", timerID);
                              newTimerTable.SetInteger("delay", milliseconds);
                              newTimerTable.Set("func", function);
                              newTimerTable.SetInteger("last_called", 0);
                              newTimerTable.SetInteger("paused", false);

                              state->GetTable("timersTbl").Set(state->GetTable("timersTbl").GetSize() + 1, newTimerTable);
                              
                              return timerID; })

        .DefMember("delete", [state](LuaTimersClass *base, int timerId) -> void
                   {
                    luacpp::LuaTable timersTbl = state->GetTable("timersTbl");
                    uint64_t tblSize = timersTbl.GetSize();

                    for(uint64_t i = 0; i < tblSize; i++) {
                        if(timersTbl.GetTable(i + 1).GetInteger("id") == timerId) {
                            state->DoString(string_format("table.remove(timersTbl, %llu)", i+1).c_str());
                            break;
                        }
                    } })
        .DefMember("pause", [state](LuaTimersClass *base, int timerId) -> void
                   {
            luacpp::LuaTable timersTbl = state->GetTable("timersTbl");
                    uint64_t tblSize = timersTbl.GetSize();

                    for(uint64_t i = 0; i < tblSize; i++) {
                        if(timersTbl.GetTable(i + 1).GetInteger("id") == timerId) {
                            timersTbl.GetTable(i + 1).SetInteger("paused", 1);
                            break;
                        }
                    } })
        .DefMember("unpause", [state](LuaTimersClass *base, int timerId) -> void
                   {
            luacpp::LuaTable timersTbl = state->GetTable("timersTbl");
                    uint64_t tblSize = timersTbl.GetSize();

                    for(uint64_t i = 0; i < tblSize; i++) {
                        if(timersTbl.GetTable(i + 1).GetInteger("id") == timerId) {
                            timersTbl.GetTable(i + 1).SetInteger("paused", 0);
                            break;
                        }
                    } });

    state->DoString("timers = Timers()");

    if (plugin->HasTimers)
        state->DoString("events:on(\"OnGameTick\", function(simulating, first, last) local sz = #timersTbl; local t = GetTime(); for i=1,sz do if timersTbl[i].paused ~= 0 then goto continue end if (t - timersTbl[i].last_called) < timersTbl[i].delay then goto continue end timersTbl[i].func(); timersTbl[i].last_called = t; ::continue:: end end)");
}