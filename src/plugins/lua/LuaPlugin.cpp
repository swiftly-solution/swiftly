#include "LuaPlugin.h"

#include "../../common.h"
#include "../../files/Files.h"

void SetupLuaEnvironment(LuaPlugin *plugin, lua_State *state);

bool LuaPlugin::LoadScriptingEnvironment()
{
    this->SetLoadError("");

    this->state = luaL_newstate();
    luaL_openlibs(this->state);

    SetupLuaEnvironment(this, this->state);

    std::vector<std::string> files = Files::FetchFileNames("addons/swiftly/plugins/" + this->GetName());
    for (std::string file : files)
    {
        if (ends_with(file, ".lua"))
        {
            int loadStatus = luaL_dofile(this->state, file.c_str());

            if (loadStatus != 0)
            {
                std::string error = lua_tostring(this->state, -1);
                PRINTF("Failed to load plugin file '%s'.\n", file.c_str());
                PRINTF("Error: %s\n", error.c_str());

                this->SetLoadError(error);

                lua_pop(this->state, 1);
                return false;
            }
        }
    }

    return true;
}

void LuaPlugin::DestroyScriptingEnvironment()
{
}

bool LuaPlugin::ExecuteStart()
{
    return true;
}

void LuaPlugin::ExecuteStop()
{
}
