#include "core.h"

#include "../../../types/EventResult.h"
#include "../../../types/LogType.h"
#include "../../../player/Player.h"

void SetupLuaTypes(LuaPlugin *plugin, lua_State *state)
{

    luabridge::getGlobalNamespace(state)

        .beginNamespace("PluginState_t")
        .addConstant("Started", (uint64_t)PluginState_t::Started)
        .addConstant("Stopped", (uint64_t)PluginState_t::Stopped)
        .endNamespace()

        .beginNamespace("EventResult")
        .addConstant("Continue", (uint64_t)EventResult::Continue)
        .addConstant("Stop", (uint64_t)EventResult::Stop)
        .addConstant("Handled", (uint64_t)EventResult::Handled)
        .endNamespace()

        .beginNamespace("MessageType")
        .addConstant("Notify", HUD_PRINTNOTIFY)
        .addConstant("Console", HUD_PRINTCONSOLE)
        .addConstant("Chat", HUD_PRINTTALK)
        .addConstant("Center", HUD_PRINTCENTER)
        .endNamespace()

        .beginNamespace("EConVarType")
        .addConstant("EConVarType_Invalid", (uint64_t)EConVarType::EConVarType_Invalid)
        .addConstant("EConVarType_Bool", (uint64_t)EConVarType::EConVarType_Bool)
        .addConstant("EConVarType_Int16", (uint64_t)EConVarType::EConVarType_Int16)
        .addConstant("EConVarType_UInt16", (uint64_t)EConVarType::EConVarType_UInt16)
        .addConstant("EConVarType_Int32", (uint64_t)EConVarType::EConVarType_Int32)
        .addConstant("EConVarType_UInt32", (uint64_t)EConVarType::EConVarType_UInt32)
        .addConstant("EConVarType_Int64", (uint64_t)EConVarType::EConVarType_Int64)
        .addConstant("EConVarType_UInt64", (uint64_t)EConVarType::EConVarType_UInt64)
        .addConstant("EConVarType_Float32", (uint64_t)EConVarType::EConVarType_Float32)
        .addConstant("EConVarType_Float64", (uint64_t)EConVarType::EConVarType_Float64)
        .addConstant("EConVarType_String", (uint64_t)EConVarType::EConVarType_String)

        .addConstant("EConVarType_Color", (uint64_t)EConVarType::EConVarType_Color)
        .addConstant("EConVarType_Vector2", (uint64_t)EConVarType::EConVarType_Vector2)
        .addConstant("EConVarType_Vector3", (uint64_t)EConVarType::EConVarType_Vector3)
        .addConstant("EConVarType_Vector4", (uint64_t)EConVarType::EConVarType_Vector4)
        .addConstant("EConVarType_Qangle", (uint64_t)EConVarType::EConVarType_Qangle)

        .endNamespace()

        .beginNamespace("LogType_t")
        .addConstant("Debug", (uint64_t)LogType_t::Debug)
        .addConstant("Warning", (uint64_t)LogType_t::Warning)
        .addConstant("Error", (uint64_t)LogType_t::Error)
        .addConstant("Common", (uint64_t)LogType_t::Common)
        .endNamespace();
}