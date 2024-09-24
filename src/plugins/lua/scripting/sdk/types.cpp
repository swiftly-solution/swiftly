#include "../core.h"
#include "../../../../sdk/access/sdkaccess.h"

LoadLuaScriptingComponent(
    types,
    [](LuaPlugin* plugin, lua_State* state)
    {
        auto types = g_sdk->GetSDKTypes();

        for(auto it = types.begin(); it != types.end(); ++it)
        {
            auto typ = luabridge::getGlobalNamespace(state).beginNamespace(it->first.c_str());
            
            for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
                typ.addConstant(it2->first.c_str(), it2->second);

            typ.endNamespace();
        }
    }
)