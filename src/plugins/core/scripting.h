#ifndef _core_scripting_h
#define _core_scripting_h

#include "scripting_includes.h"
#include "../../resourcemonitor/ResourceMonitor.h"

#include <dynohook/core.h>
#include <dynohook/manager.h>
#include <dynohook/conventions/x64_systemV_call.h>

#include <any>

class GCBaseEntity;
class GCBasePlayerController;
class GCBasePlayerPawn;
class GCCSPlayerController;
class GCCSPlayerPawn;
class GCCSPlayerPawnBase;
class GCEntityInstance;
class PluginMemory;

//////////////////////////////////////////////////////////////
/////////////////            Logger            //////////////
////////////////////////////////////////////////////////////

class PluginLogger
{
private:
    std::string plugin_name;

public:
    PluginLogger(std::string m_plugin_name);

    void Write(int level, std::string message);
};

//////////////////////////////////////////////////////////////
/////////////////        Player Manager        //////////////
////////////////////////////////////////////////////////////

class PluginPlayerManager
{
private:
    std::string plugin_name;

public:
    PluginPlayerManager(std::string m_plugin_name);

    uint16_t GetPlayerCount();
    uint16_t GetPlayerCap();
    void SendMsg(int destination, std::string text);
};

//////////////////////////////////////////////////////////////
/////////////////         HTTP Client          //////////////
////////////////////////////////////////////////////////////

class PluginHTTP
{
private:
    std::string plugin_name;

public:
    PluginHTTP(std::string m_plugin_name);

    std::string PerformHTTP(std::string receivedData);
};

//////////////////////////////////////////////////////////////
/////////////////         Event System         //////////////
////////////////////////////////////////////////////////////

class PluginEvent
{
private:
    std::string plugin_name;
    IGameEvent *gameEvent;
    dyno::IHook *hookPtr;

    std::any returnValue;

public:
    PluginEvent(std::string m_plugin_name, IGameEvent *m_gameEvent, dyno::IHook *m_hookPtr);
    ~PluginEvent();

    std::string GetInvokingPlugin();

    // Game Event Section
    bool IsGameEvent();

    void SetBool(std::string key, bool value);
    void SetInt(std::string key, int value);
    void SetUint64(std::string key, uint64_t value);
    void SetFloat(std::string key, float value);
    void SetString(std::string key, std::string value);

    bool GetBool(std::string key);
    int GetInt(std::string key);
    uint64_t GetUint64(std::string key);
    float GetFloat(std::string key);
    std::string GetString(std::string key);

    void FireEvent(bool dontBroadcast);
    void FireEventToClient(int slot);

    void SetReturn(std::any value);
    void SetReturnLua(luabridge::LuaRef value);
    std::any GetReturnValue();

    // Hooks section
    bool IsHook();

    bool GetHookBool(int index);
    int GetHookInt(int index);
    uint64_t GetHookUint64(int index);
    float GetHookFloat(int index);
    std::string GetHookString(int index);
    PluginMemory GetHookPointer(int index);
    double GetHookDouble(int index);
    uint32_t GetHookUInt(int index);
    int64_t GetHookInt64(int index);

    void SetHookBool(int index, bool value);
    void SetHookInt(int index, int value);
    void SetHookUint64(int index, uint64_t value);
    void SetHookFloat(int index, float value);
    void SetHookString(int index, std::string value);
    void SetHookPointer(int index, PluginMemory value);
    void SetHookDouble(int index, double value);
    void SetHookUInt(int index, uint32_t value);
    void SetHookInt64(int index, int64_t value);

    void SetHookReturn(std::any value);
    void SetHookReturnLua(luabridge::LuaRef value);
    std::any GetHookReturn();
};

//////////////////////////////////////////////////////////////
/////////////////            Commands          //////////////
////////////////////////////////////////////////////////////

class PluginCommands
{
private:
    std::string plugin_name;

public:
    PluginCommands(std::string m_plugin_name);

    void RegisterCommand(std::string commandName, void *callback);
    void UnregisterCommand(std::string commandName);

    void RegisterAlias(std::string commandName, std::string aliasName);
    void UnregisterAlias(std::string aliasName);

    void RegisterCommandLua(std::string commandName, luabridge::LuaRef callback);
};

//////////////////////////////////////////////////////////////
/////////////////           Database           //////////////
////////////////////////////////////////////////////////////

class PluginDatabase
{
private:
    std::string connection_name;
    Database *db;
    bool dbConnected;

public:
    PluginDatabase(std::string m_connection_name);

    bool IsConnected();
    std::string EscapeString(std::string str);

    void QueryLua(std::string query, luabridge::LuaRef callback, lua_State *L);
};

//////////////////////////////////////////////////////////////
/////////////////         Configuration        //////////////
////////////////////////////////////////////////////////////

class PluginConfiguration
{
private:
    std::string plugin_name;

public:
    PluginConfiguration(std::string m_plugin_name);

    bool Exists(std::string key);
    void Reload(std::string key);
    uint64_t FetchArraySize(std::string key);
    std::any Fetch(std::string key);

    luabridge::LuaRef FetchLua(std::string key, lua_State *L);
};

//////////////////////////////////////////////////////////////
/////////////////            Convars           //////////////
////////////////////////////////////////////////////////////

class PluginConvars
{
private:
    std::string plugin_name;

public:
    PluginConvars(std::string m_plugin_name);

    std::any GetConvarValue(std::string cvarname);
    luabridge::LuaRef GetConvarValueLua(std::string cvarname, lua_State *L);

    int16_t GetConvarType(std::string cvarname);
    void SetConvar(std::string cvarname, std::string value);
};

//////////////////////////////////////////////////////////////
/////////////////             Menus            //////////////
////////////////////////////////////////////////////////////

class PluginMenus
{
private:
    std::string plugin_name;

public:
    PluginMenus(std::string m_plugin_name);

    void Register(std::string custom_id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options);
    void RegisterTemporary(std::string custom_id, std::string title, std::string color, std::vector<std::pair<std::string, std::string>> options);
    void Unregister(std::string id);
};

//////////////////////////////////////////////////////////////
/////////////////             Files            //////////////
////////////////////////////////////////////////////////////

class PluginFiles
{
private:
    std::string plugin_name;

public:
    PluginFiles(std::string m_plugin_name);

    void Append(std::string path, std::string content, bool hasdate);
    bool CreateDirectory(std::string path);
    void Delete(std::string path);
    bool ExistsPath(std::string path);
    std::vector<std::string> FetchDirectories(std::string path);
    std::vector<std::string> FetchFileNames(std::string path);
    std::string GetBase(std::string path);
    bool IsDirectory(std::string path);
    std::string Read(std::string path);
    void Write(std::string path, std::string content, bool hasdate);
};

//////////////////////////////////////////////////////////////
/////////////////           Precacher          //////////////
////////////////////////////////////////////////////////////

class PluginPrecacher
{
private:
    std::string plugin_name;

public:
    PluginPrecacher(std::string m_plugin_name);

    void PrecacheModel(std::string model);
    void PrecacheSound(std::string path);
};

//////////////////////////////////////////////////////////////
/////////////////            Server            //////////////
////////////////////////////////////////////////////////////

class PluginServer
{
private:
    std::string plugin_name;

public:
    PluginServer(std::string m_plugin_name);

    std::string GetMap();
    bool IsMapValid(std::string map);
    void ChangeMap(std::string map, bool workshop);

    uint16_t GetMaxPlayers();

    void Execute(std::string cmd);

    float GetCurrentTime();
    int GetTickCount();
};

//////////////////////////////////////////////////////////////
/////////////////            Player            //////////////
////////////////////////////////////////////////////////////

class PluginPlayer
{
private:
    std::string plugin_name;
    int playerId;

    std::map<std::string, void *> ptrs;

public:
    PluginPlayer(std::string m_plugin_name, int m_playerId);
    ~PluginPlayer();

    GCBaseEntity *GetCBaseEntity();
    GCBasePlayerController *GetCBasePlayerController();
    GCBasePlayerPawn *GetCBasePlayerPawn();
    GCCSPlayerController *GetCCSPlayerController();
    GCCSPlayerPawn *GetCCSPlayerPawn();
    GCCSPlayerPawnBase *GetCCSPlayerPawnBase();
    void Drop(int reason);
    std::string GetChatTag();
    void SetChatTag(std::string tag);
    void SetChatTagColor(std::string color);
    void SetNameColor(std::string color);
    void SetChatColor(std::string color);
    void ExecuteCommand(std::string cmd);
    std::string GetConvarValue(std::string name);
    void SetConvar(std::string name, std::string value);
    std::string GetIPAddress();
    int GetSlot();
    uint64_t GetSteamID();
    std::string GetSteamID2();
    void SwitchTeam(int team);
    void HideMenu();
    bool IsFakeClient();
    bool IsFirstSpawn();
    void Kill();
    void Respawn();
    void SendMsg(int dest, std::string msg);
    void SetModel(std::string model);
    void ShowMenu(std::string menuid);

    std::any GetVarValue(std::string key);
    luabridge::LuaRef GetVarValueLua(std::string key, lua_State *L);

    void SetVarValue(std::string key, std::any value);
    void SetVarValueLua(std::string key, luabridge::LuaRef value);
};

//////////////////////////////////////////////////////////////
/////////////////         Translations         //////////////
////////////////////////////////////////////////////////////

std::string scripting_FetchTranslation(Plugin *plugin, std::string key);

//////////////////////////////////////////////////////////////
/////////////////            Memory            //////////////
////////////////////////////////////////////////////////////

class PluginMemory
{
private:
    void *m_ptr;

public:
    PluginMemory();

    void LoadFromPtr(void *ptr);
    void LoadFromAddress(std::string addr);
    void LoadFromSignatureName(std::string signature_name);
    void LoadFromSignature(std::string library, std::string signature);

    void AddOffset(int64_t offset);
    void RemoveOffset(int64_t offset);

    void Clear();

    void *GetRawPtr();
    std::string GetPtr();
    bool IsValid();
};

//////////////////////////////////////////////////////////////
/////////////////           DynHook            //////////////
////////////////////////////////////////////////////////////

enum class DataType_t
{
    VOID,
    BOOL,
    CHAR,
    UCHAR,
    SHORT,
    USHORT,
    INT,
    UINT,
    LONG,
    ULONG,
    LONG_LONG,
    ULONG_LONG,
    FLOAT,
    DOUBLE,
    POINTER,
    STRING,
    VARIANT
};

/*
    Args List Convention
        - p -> Pointer
        - b -> Boolean
        - f -> Float
        - d -> Double
        - i -> Integer 32-bit
        - u -> Unsigned Integer 32-bit
        - s -> const char*
        - I -> Integer 64-bit
        - U -> Unsigned Integer 64-bit
        - v -> Void
*/

struct Hook
{
    void *ptr;
    std::string argsList;
    std::string retType;
    std::string id;
};

class PluginHooks
{
private:
    std::string m_plugin_name;

public:
    PluginHooks(std::string plugin_name);

    std::string AddHook(PluginMemory mem, std::string args_list, std::string ret_type);

    luabridge::LuaRef CallHookLua(std::string hookId, std::string hookPayload, lua_State *L);
};

//////////////////////////////////////////////////////////////
/////////////////           Entities           //////////////
////////////////////////////////////////////////////////////

std::vector<GCEntityInstance *> UTIL_FindEntitiesByClassname(const char *name);
GCEntityInstance *CreateEntityByName(const char *name);

//////////////////////////////////////////////////////////////
/////////////////             Utils            //////////////
////////////////////////////////////////////////////////////

bool scripting_IsWindows();
bool scripting_IsLinux();
std::string scripting_GetOS();

#endif