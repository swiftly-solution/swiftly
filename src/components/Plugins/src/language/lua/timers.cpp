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
                              newTimerTable.Set("func", function);
                              state->GetTable("timersTbl").Set(state->GetTable("timersTbl").GetSize() + 1, newTimerTable);

                              state->DoString(string_format("timersTbl[%llu].timeoutfunc = function() if timersTbl[%llu] then timersTbl[%llu].func(); SetTimeout(%d, timersTbl[%llu].timeoutfunc) end end; SetTimeout(%d, timersTbl[%llu].timeoutfunc)", timerID, timerID, timerID, milliseconds, timerID, milliseconds, timerID).c_str());

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
                    } });

    state->DoString("timers = Timers()");
}