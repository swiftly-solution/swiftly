#ifndef _core_scripting_h
#define _core_scripting_h

#include "scripting_schema.h"
#include "public/iservernetworkable.h"
#include "../../tools/resourcemonitor/ResourceMonitor.h"
#include "../../sdk/entity/CCSWeaponBase.h"
#include "../../tools/crashreporter/CallStack.h"
#include "../../memory/encoders/msgpack.h"
#include "../../sdk/entity/CTakeDamageInfo.h"
#include "../../network/database/IQueryBuilder.h"

#include "cstrike15_usermessages.pb.h"
#include <google/protobuf/message.h>

#include <dynohook/platform.h>
#include <dynohook/core.h>
#include <dynohook/manager.h>
#ifdef _WIN32
#include <dynohook/conventions/x64/x64MsFastcall.h>
#else
#include <dynohook/conventions/x64/x64SystemVcall.h>
#endif

#include <any>
#include <set>

#define INVALID_MESSAGE_ID -1

class PluginMemory;

//////////////////////////////////////////////////////////////
/////////////////          Entity IO           //////////////
////////////////////////////////////////////////////////////

struct EntityIOConnectionDesc_t
{
    string_t m_targetDesc;
    string_t m_targetInput;
    string_t m_valueOverride;
    CEntityHandle m_hTarget;
    EntityIOTargetType_t m_nTargetType;
    int32 m_nTimesToFire;
    float m_flDelay;
};

struct EntityIOConnection_t : EntityIOConnectionDesc_t
{
    bool m_bMarkedForRemoval;
    EntityIOConnection_t* m_pNext;
};

struct EntityIOOutputDesc_t
{
    const char* m_pName;
    uint32 m_nFlags;
    uint32 m_nOutputOffset;
};

class CEntityIOOutput
{
public:
    void* vtable;
    EntityIOConnection_t* m_pConnections;
    EntityIOOutputDesc_t* m_pDesc;
};

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
/////////////////        Check Transmit        //////////////
///////////////// May God rest our CPU usage  //////////////
///////////////////////////////////////////////////////////

class PluginCCheckTransmitInfo
{
private:
    CCheckTransmitInfo* m_ptr;
public:
    PluginCCheckTransmitInfo(std::string ptr);

    std::map<int, int> GetPlayers();
    std::vector<int> GetEntities();
    void SetEntities(std::vector<int> tbl);
};

//////////////////////////////////////////////////////////////
/////////////////         Event System         //////////////
////////////////////////////////////////////////////////////

class PluginEvent
{
private:
    std::string plugin_name;
    IGameEvent* gameEvent;
    dyno::Hook* hookPtr;

    std::any returnValue;
    bool shouldFree = false;

public:
    PluginEvent(std::string m_plugin_name, IGameEvent* m_gameEvent, dyno::Hook* m_hookPtr);
    PluginEvent(std::string gameEventName, lua_State* state);
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
    std::any GetHookReturn();
};

//////////////////////////////////////////////////////////////
/////////////////          Key Values          //////////////
////////////////////////////////////////////////////////////

class PluginCEntityKeyValues
{
private:
    CEntityKeyValues* keyVals = nullptr;

public:
    PluginCEntityKeyValues();

    CEntityKeyValues* GetKeyVals();
    bool			GetBool(std::string key);
    int				GetInt(std::string key);
    uint			GetUint(std::string key);
    int64			GetInt64(std::string key);
    uint64			GetUint64(std::string key);
    float			GetFloat(std::string key);
    double			GetDouble(std::string key);
    std::string		GetString(std::string key);
    std::string		GetPtr(std::string key);
    unsigned int 	GetStringToken(std::string key);
    Color			GetColor(std::string key);
    Vector			GetVector(std::string key);
    Vector2D		GetVector2D(std::string key);
    Vector4D		GetVector4D(std::string key);
    QAngle			GetQAngle(std::string key);

    void            SetBool(std::string key, bool value);
    void            SetInt(std::string key, int value);
    void            SetUint(std::string key, uint value);
    void            SetInt64(std::string key, int64 value);
    void            SetUint64(std::string key, uint64 value);
    void            SetFloat(std::string key, float value);
    void            SetDouble(std::string key, double value);
    void            SetString(std::string key, std::string value);
    void            SetPtr(std::string key, std::string value);
    void            SetStringToken(std::string key, unsigned int value);
    void            SetColor(std::string key, Color value);
    void            SetVector(std::string key, Vector value);
    void            SetVector2D(std::string key, Vector2D value);
    void            SetVector4D(std::string key, Vector4D value);
    void            SetQAngle(std::string key, QAngle value);
};

//////////////////////////////////////////////////////////////
/////////////////          SDK Access          //////////////
////////////////////////////////////////////////////////////

class SDKBaseClass
{
private:
    void* m_ptr;
    std::string m_className;
    uint64_t classOffset;

public:
    SDKBaseClass(std::string ptr, lua_State* state);
    SDKBaseClass(void* ptr, std::string className);
    SDKBaseClass(std::string ptr, std::string className);

    luabridge::LuaRef AccessSDKLua(std::string fieldName, uint64_t path, lua_State* state);
    void UpdateSDKLua(std::string fieldName, luabridge::LuaRef value, lua_State* state);

    int CBasePlayerController_EntityIndex();
    void CAttributeList_SetOrAddAttributeValueByName(std::string str, float value);
    void CBaseModelEntity_SetModel(std::string model);
    void CBaseModelEntity_SetSolidType(int64_t solidType);
    void CBaseModelEntity_SetBodygroup(std::string str, int64_t val);
    SDKBaseClass CBaseEntity_EHandle();
    void CBaseEntity_Spawn(PluginCEntityKeyValues* kv);
    void CBaseEntity_SpawnLua(lua_State* state);
    void CBaseEntity_Despawn();
    void CBaseEntity_AcceptInput(std::string input, SDKBaseClass activator, SDKBaseClass caller, std::string value, int outputID);
    std::string CBaseEntity_GetClassname();
    SDKBaseClass CBaseEntity_GetVData();
    void CBaseEntity_Teleport(Vector value, QAngle angle, Vector velocity);
    void CBaseEntity_TeleportLua(lua_State *L);
    void CBaseEntity_EmitSound(std::string sound_name, float pitch, float volume);
    void CBaseEntity_CollisionRulesChanged();
    SDKBaseClass CGameSceneNode_GetSkeletonInstance();
    SDKBaseClass CPlayerPawnComponent_GetPawn();

    int GetProp(lua_State* state);
    int SetProp(lua_State* state);
    int CallProp(lua_State* state);

    std::string GetClassName();
    void* GetPtr();
    void SetPtr(void* ptr);
    std::string ToPtr();
    bool IsValid();
};

//////////////////////////////////////////////////////////////
/////////////////         User Message         //////////////
////////////////////////////////////////////////////////////

class PluginUserMessage;

class PluginUserMessage
{
private:
    int msgid = INVALID_MESSAGE_ID;
    INetworkMessageInternal* internalMsg = nullptr;
    uint64* clients = nullptr;

public:
    CNetMessagePB<google::protobuf::Message>* msgBuffer = nullptr;

    PluginUserMessage(std::string msgname);
    PluginUserMessage(INetworkMessageInternal* msg, CNetMessage* data, uint64* cls);
    PluginUserMessage(google::protobuf::Message* msg);
    ~PluginUserMessage();

    bool IsValidMessage();
    std::string GetMessageName();
    int GetMessageID();

    bool HasField(std::string pszFieldName);

    int32 GetInt32(std::string pszFieldName);
    void SetInt32(std::string pszFieldName, int32 value);
    int32 GetRepeatedInt32(std::string pszFieldName, int index);
    void SetRepeatedInt32(std::string pszFieldName, int index, int32 value);
    void AddInt32(std::string pszFieldName, int32 value);

    int64 GetInt64(std::string pszFieldName);
    void SetInt64(std::string pszFieldName, int64 value);
    int64 GetRepeatedInt64(std::string pszFieldName, int index);
    void SetRepeatedInt64(std::string pszFieldName, int index, int64 value);
    void AddInt64(std::string pszFieldName, int64 value);

    uint32 GetUInt32(std::string pszFieldName);
    void SetUInt32(std::string pszFieldName, uint32 value);
    uint32 GetRepeatedUInt32(std::string pszFieldName, int index);
    void SetRepeatedUInt32(std::string pszFieldName, int index, uint32 value);
    void AddUInt32(std::string pszFieldName, uint32 value);

    uint64 GetUInt64(std::string pszFieldName);
    void SetUInt64(std::string pszFieldName, uint64 value);
    uint64 GetRepeatedUInt64(std::string pszFieldName, int index);
    void SetRepeatedUInt64(std::string pszFieldName, int index, uint64 value);
    void AddUInt64(std::string pszFieldName, uint64 value);

    int64 GetInt64OrUnsigned(std::string pszFieldName);
    void SetInt64OrUnsigned(std::string pszFieldName, int64 value);
    int64 GetRepeatedInt64OrUnsigned(std::string pszFieldName, int index);
    void SetRepeatedInt64OrUnsigned(std::string pszFieldName, int index, int64 value);
    void AddInt64OrUnsigned(std::string pszFieldName, int64 value);

    bool GetBool(std::string pszFieldName);
    void SetBool(std::string pszFieldName, bool value);
    bool GetRepeatedBool(std::string pszFieldName, int index);
    void SetRepeatedBool(std::string pszFieldName, int index, bool value);
    void AddBool(std::string pszFieldName, bool value);

    float GetFloat(std::string pszFieldName);
    void SetFloat(std::string pszFieldName, float value);
    float GetRepeatedFloat(std::string pszFieldName, int index);
    void SetRepeatedFloat(std::string pszFieldName, int index, float value);
    void AddFloat(std::string pszFieldName, float value);

    double GetDouble(std::string pszFieldName);
    void SetDouble(std::string pszFieldName, double value);
    double GetRepeatedDouble(std::string pszFieldName, int index);
    void SetRepeatedDouble(std::string pszFieldName, int index, double value);
    void AddDouble(std::string pszFieldName, double value);

    float GetFloatOrDouble(std::string pszFieldName);
    void SetFloatOrDouble(std::string pszFieldName, float value);
    float GetRepeatedFloatOrDouble(std::string pszFieldName, int index);
    void SetRepeatedFloatOrDouble(std::string pszFieldName, int index, float value);
    void AddFloatOrDouble(std::string pszFieldName, float value);

    std::string GetString(std::string pszFieldName);
    void SetString(std::string pszFieldName, const char* value);
    std::string GetRepeatedString(std::string pszFieldName, int index);
    void SetRepeatedString(std::string pszFieldName, int index, const char* value);
    void AddString(std::string pszFieldName, const char* value);

    Color GetColor(std::string pszFieldName);
    void SetColor(std::string pszFieldName, const Color& value);
    Color GetRepeatedColor(std::string pszFieldName, int index);
    void SetRepeatedColor(std::string pszFieldName, int index, const Color& value);
    void AddColor(std::string pszFieldName, const Color& value);

    Vector2D GetVector2D(std::string pszFieldName);
    void SetVector2D(std::string pszFieldName, Vector2D& vec);
    Vector2D GetRepeatedVector2D(std::string pszFieldName, int index);
    void SetRepeatedVector2D(std::string pszFieldName, int index, Vector2D& vec);
    void AddVector2D(std::string pszFieldName, Vector2D& vec);

    Vector GetVector(std::string pszFieldName);
    void SetVector(std::string pszFieldName, Vector& vec);
    Vector GetRepeatedVector(std::string pszFieldName, int index);
    void SetRepeatedVector(std::string pszFieldName, int index, Vector& vec);
    void AddVector(std::string pszFieldName, Vector& vec);

    QAngle GetQAngle(std::string pszFieldName);
    void SetQAngle(std::string pszFieldName, QAngle& vec);
    QAngle GetRepeatedQAngle(std::string pszFieldName, int index);
    void SetRepeatedQAngle(std::string pszFieldName, int index, QAngle& vec);
    void AddQAngle(std::string pszFieldName, QAngle& vec);

    PluginUserMessage GetUMessage(std::string pszFieldName);
    PluginUserMessage GetRepeatedMessage(std::string pszFieldName, int index);
    PluginUserMessage AddMessage(std::string pszFieldName);

    void RemoveRepeatedFieldValue(std::string pszFieldName, int index);
    int GetRepeatedFieldCount(std::string pszFieldName);

    void AddClient(int playerId);
    void RemoveClient(int playerId);
    void ClearClients();
    void AddClients();
    std::vector<int> GetClients();

    void SendToPlayer(int playerId);
    void SendToAllPlayers();
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

    void RegisterCommand(std::string commandName, void* callback);
    void UnregisterCommand(std::string commandName);

    void RegisterRawAlias(std::string commandName, std::string aliasName);
    void RegisterAlias(std::string commandName, std::string aliasName);
    void UnregisterAlias(std::string aliasName);

    void RegisterCommandLua(std::string commandName, luabridge::LuaRef callback);

    std::vector<std::string> GetAllCommands();
    std::vector<std::string> GetCommands();
};

//////////////////////////////////////////////////////////////
/////////////////           Database           //////////////
////////////////////////////////////////////////////////////
class PluginDatabaseQueryBuilder;

class PluginDatabase
{
private:
    std::string connection_name;
    IDatabase* db;
    bool dbConnected;

public:
    PluginDatabase(std::string m_connection_name);

    bool IsConnected();
    std::string EscapeString(std::string str);

    void QueryLua(std::string query, luabridge::LuaRef callback, lua_State* L);
    void QueryParamsLua(std::string query, std::map<luabridge::LuaRef, luabridge::LuaRef> params, luabridge::LuaRef callback, lua_State* L);

    PluginDatabaseQueryBuilder QueryBuilderLua();
};

class PluginDatabaseQueryBuilder
{
private:
    IQueryBuilder* qb;
    IDatabase* db;

    std::string FormatValue(const luabridge::LuaRef& luaValue, lua_State* L);
    
public:
    PluginDatabaseQueryBuilder(IQueryBuilder* mqb, IDatabase* mdb);
    ~PluginDatabaseQueryBuilder();

    PluginDatabaseQueryBuilder* Table(const std::string& tableName);
    PluginDatabaseQueryBuilder* Create(const std::unordered_map<std::string, std::string>& columns);
    PluginDatabaseQueryBuilder* Alter(const std::map<std::string, std::string>& columns);
    PluginDatabaseQueryBuilder* Drop();

    PluginDatabaseQueryBuilder* Select(const std::vector<std::string>& columns);
    PluginDatabaseQueryBuilder* Insert(const std::map<std::string, luabridge::LuaRef>& data, lua_State* L);
    PluginDatabaseQueryBuilder* Update(const std::map<std::string, luabridge::LuaRef>& data, lua_State* L);
    PluginDatabaseQueryBuilder* Delete();

    PluginDatabaseQueryBuilder* Where(const std::string& column, const std::string& operator_, const luabridge::LuaRef& value, lua_State* L);
    PluginDatabaseQueryBuilder* OrWhere(const std::string& column, const std::string& operator_, const luabridge::LuaRef& value, lua_State* L);
    PluginDatabaseQueryBuilder* Join(const std::string& table, const std::string& onCondition, const std::string& joinType = "INNER");
    PluginDatabaseQueryBuilder* OrderBy(const std::vector<std::pair<std::string, std::string>>& columns);
    PluginDatabaseQueryBuilder* Limit(int count);
    PluginDatabaseQueryBuilder* GroupBy(const std::vector<std::string>& columns);
    PluginDatabaseQueryBuilder* OnDuplicate(const std::map<std::string, luabridge::LuaRef>& data, lua_State* L);
    PluginDatabaseQueryBuilder* Having(const std::string& condition);
    PluginDatabaseQueryBuilder* Distinct();
    PluginDatabaseQueryBuilder* Offset(int count);
    PluginDatabaseQueryBuilder* Union(const std::string& query, bool all);

    void Execute(luabridge::LuaRef callback, lua_State* L);

private:
    template<typename T>
    std::string join(const std::vector<T>& vec, const std::string& delimiter);
};

//////////////////////////////////////////////////////////////
/////////////////            CHandle           //////////////
////////////////////////////////////////////////////////////

class PluginCHandle
{
private:
    CHandle<CEntityInstance>* m_Handle;

public:
    PluginCHandle(std::string ptr);
    PluginCHandle(void* ptr);

    std::string GetPtr();
    void SetPtr(std::string ptr);

    std::string GetHandlePtr();
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

    void CreateLua(std::string configurationKey, luabridge::LuaRef table, lua_State* L);
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

    void CreateFake(std::string cvarname, int32_t type, std::any defaultValue, bool prot);
    void CreateFakeLua(std::string cvarname, int32_t type, luabridge::LuaRef defaultValue, bool prot);
    void DeleteFake(std::string cvarname);

    std::any GetConvarValue(std::string cvarname);

    int16_t GetConvarType(std::string cvarname);
    void SetConvar(std::string cvarname, std::string value);

    bool Exists(std::string cvarname);
    bool ExistsFake(std::string cvarname);

    void AddFlags(std::string cvarname, int64_t flags);
    void RemoveFlags(std::string cvarname, int64_t flags);
    int64_t GetFlags(std::string cvarname);
    bool HasFlags(std::string cvarname, int64_t flags);
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

    bool Compress(std::string path, std::string output);
    bool Decompress(std::string path, std::string output);
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

    void TerminateRound(float delay, uint32_t reason);
    std::string GetIP();
};

//////////////////////////////////////////////////////////////
/////////////////            Weapon            //////////////
////////////////////////////////////////////////////////////

class PluginWeapon
{
private:
    int m_playerId;
    CBasePlayerWeapon* m_ptr;

public:
    PluginWeapon(int playerId, CBasePlayerWeapon* ptr);
    PluginWeapon(int playerId, std::string ptr);

    SDKBaseClass GetCBasePlayerWeapon();
    SDKBaseClass GetCCSWeaponBase();
    SDKBaseClass GetCBasePlayerWeaponVData();
    SDKBaseClass GetCCSWeaponBaseVData();

    void Drop();
    void Remove();
    void SetDefaultAttributes();
};

//////////////////////////////////////////////////////////////
/////////////////        Weapon Manager        //////////////
////////////////////////////////////////////////////////////

class PluginWeaponManager
{
private:
    int m_playerId;

public:
    PluginWeaponManager(int playerId);

    void GiveWeapon(std::string weapon_name);
    void RemoveWeapons();
    void DropWeapons();
    std::vector<PluginWeapon> GetWeapons();

    void RemoveByClassname(std::string classname);
    void RemoveBySlot(int slot);
    PluginWeapon GetFirstInSlot(int slot);
    std::vector<PluginWeapon> GetInSlot(int slot);
    void RemoveByItemDefinition(int idx);
};

//////////////////////////////////////////////////////////////
/////////////////            Player            //////////////
////////////////////////////////////////////////////////////

class PluginPlayer
{
private:
    std::string plugin_name;
    int playerId;

    SDKBaseClass* pCBaseEntity = nullptr;
    SDKBaseClass* pCBasePlayerController = nullptr;
    SDKBaseClass* pCBasePlayerPawn = nullptr;
    SDKBaseClass* pCCSPlayerController = nullptr;
    SDKBaseClass* pCCSPlayerPawn = nullptr;
    SDKBaseClass* pCCSPlayerPawnBase = nullptr;

public:
    PluginPlayer(std::string m_plugin_name, int m_playerId);
    ~PluginPlayer();

    SDKBaseClass* GetCBaseEntity();
    SDKBaseClass* GetCBasePlayerController();
    SDKBaseClass* GetCBasePlayerPawn();
    SDKBaseClass* GetCCSPlayerController();
    SDKBaseClass* GetCCSPlayerPawn();
    SDKBaseClass* GetCCSPlayerPawnBase();
    void Drop(int reason);
    uint32_t GetConnectedTime();
    PluginWeaponManager GetWeaponManager();

    std::string GetChatTag();
    void SetChatTag(std::string tag);

    std::string GetChatTagColor();
    void SetChatTagColor(std::string color);

    std::string GetNameColor();
    void SetNameColor(std::string color);

    std::string GetChatColor();
    void SetChatColor(std::string color);

    void ExecuteCommand(std::string cmd);
    std::string GetConvarValue(std::string name);
    void SetConvar(std::string name, std::string value);
    std::string GetIPAddress();
    int GetSlot();
    uint64_t GetSteamID();
    std::string GetSteamID2();
    void SwitchTeam(int team);
    void ChangeTeam(int team);
    void HideMenu();
    bool IsFakeClient();
    bool IsFirstSpawn();
    void Kill();
    void Respawn();
    void SendMsg(int dest, std::string msg);
    void ShowMenu(std::string menuid);

    std::any GetVarValue(std::string key);
    void SetVarValue(std::string key, std::any value);

    void SetListening(int playerid, int listenOverride);
    int GetListening(int playerid);

    void SetVoiceFlags(int flags);
    int GetVoiceFlags();

    void SetBunnyhop(bool state);
    bool GetBunnyhop();

    void QueryConvar(std::string cvar_name);
    bool IsListeningToGameEvent(std::string game_event);

    bool IsValid();
};

//////////////////////////////////////////////////////////////
/////////////////         Translations         //////////////
////////////////////////////////////////////////////////////

std::string scripting_FetchTranslation(std::string key, int playerid);

//////////////////////////////////////////////////////////////
/////////////////            Memory            //////////////
////////////////////////////////////////////////////////////

class PluginMemory
{
private:
    void* m_ptr;
    bool accessedVTable = false;
    bool allocatedMem = false;

public:
    PluginMemory();
    ~PluginMemory();

    void LoadFromPtr(void* ptr);
    void LoadFromAddress(std::string addr);
    void LoadFromSignatureName(std::string signature_name);
    void LoadFromSignature(std::string library, std::string signature);

    void AddOffsetByName(std::string offsetName);
    void RemoveOffsetByName(std::string offsetName);

    void AddOffset(int64_t offset);
    void RemoveOffset(int64_t offset);

    void AccessIndex(int64_t idx);

    void AccessVTableFromOffset(std::string offsetName);
    void AccessVTable(int64_t offset);
    bool AccessedVTable();

    void Allocate(uint64_t size);
    void Deallocate();

    void Clear();

    void SetBool(bool value);
    void SetInt(int value);
    void SetInt64(int64_t value);
    void SetUint(uint32_t value);
    void SetUint64(uint64_t value);
    void SetFloat(float value);
    void SetDouble(double value);
    void SetVector(Vector value);
    void SetVector2D(Vector2D value);
    void SetVector4D(Vector4D value);
    void SetColor(Color value);
    void SetQAngle(QAngle value);

    bool GetBool();
    int GetInt();
    int64_t GetInt64();
    uint32_t GetUint();
    uint64_t GetUint64();
    float GetFloat();
    double GetDouble();
    Vector GetVector();
    Vector2D GetVector2D();
    Vector4D GetVector4D();
    Color GetColor();
    QAngle GetQAngle();

    void* GetRawPtr();
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
    void* ptr;
    std::string argsList;
    std::string retType;
    std::string id;
    bool vTable;
};

class PluginHooks
{
private:
    std::string m_plugin_name;

public:
    PluginHooks(std::string plugin_name);

    std::string AddHook(PluginMemory mem, std::string args_list, std::string ret_type);
    std::string AddEntityOutputHook(std::string classname, std::string output);

    std::any CallHook(std::string hookId, std::string hookPayload);
};

//////////////////////////////////////////////////////////////
/////////////////           Entities           //////////////
////////////////////////////////////////////////////////////

std::vector<SDKBaseClass> UTIL_FindEntitiesByClassname(const char* name);
SDKBaseClass CreateEntityByName(const char* name);

//////////////////////////////////////////////////////////////
/////////////////             Utils            //////////////
////////////////////////////////////////////////////////////

bool scripting_IsWindows();
bool scripting_IsLinux();
std::string scripting_GetOS();
SDKBaseClass scripting_GetCCSGameRules();
std::string scripting_GetPluginPath(std::string plugin_name);
void scripting_StateUpdate(std::string ptr, std::string classname, std::string field);
PluginUserMessage scripting_GetUserMessage(std::string uuid);
std::string scripting_CreateTextTable(std::vector<std::vector<std::string>> data);
int scripting_GetPluginState(std::string plugin_name);

#endif