#ifndef _components_plugins_scripting_h
#define _components_plugins_scripting_h

#include "../../../common.h"
#include "../../../hooks/Hooks.h"
#include "../../../player/Player.h"
#include "../../../player/PlayerManager.h"
#include "../../../logs/Log.h"
#include "../../../http/ContentTypes.h"
#include "PluginsComponent.h"
#include "Plugin.h"

typedef void (*OnProgramLoadFunction)(const char *, const char *);

typedef void (*Plugin_WrapperVoid)(...);
typedef bool (*Plugin_WrapperBool)(...);

enum PlayerStat : int
{
    KILLS = 0,
    DEATHS = 1,
    ASSISTS = 2,
    DAMAGE = 3
};

enum PluginState : int
{
    STOPPED = 0,
    STARTED = 1
};

SMM_API void scripting_Commands_RegisterCommand(const char *pluginName, const char *name, void *funcPtr);
SMM_API void scripting_Commands_UnregisterCommand(const char *name);

SMM_API const char *scripting_Configuration_Fetch(const char *key);
SMM_API uint32 scripting_Configuration_FetchArraySize(const char *key);
SMM_API bool scripting_Configuration_Exists(const char *key);
SMM_API void scripting_Configuration_ReloadConfiguration(const char *key);

SMM_API int scripting_Server_GetConvarInt(const char *name);
SMM_API unsigned int scripting_Server_GetConvarUint(const char *name);
SMM_API bool scripting_Server_GetConvarBool(const char *name);
SMM_API float scripting_Server_GetConvarFloat(const char *name);
SMM_API const char *scripting_Server_GetConvarString(const char *name);
SMM_API EConVarType scripting_Server_GetConvarType(const char *name);
SMM_API void scripting_Server_SetConvar(const char *name, ...);

SMM_API bool scripting_Database_Connect(const char *connectionName);
SMM_API const char *scripting_Database_EscapeString(const char *connectionName, const char *value);
std::vector<std::map<const char *, std::any>> scripting_Database_QueryRaw(const char *connectionName, const char *query);
SMM_API const char *scripting_Database_Query(const char *connectionName, const char *query);

SMM_API uint32_t scripting_Entity_Create(const char *classname);
SMM_API void scripting_Entity_Spawn(uint32_t entityID);
SMM_API void scripting_Entity_Destroy(uint32_t entityID);
SMM_API void scripting_Entity_SetModel(uint32_t entityID, const char *model);
SMM_API void scripting_Entity_AcceptInput(uint32_t entityID, const char *input, const char *activator, const char *caller, double *value);
Vector scripting_Entity_GetCoordsRaw(uint32_t entityID);
SMM_API const char *scripting_Entity_GetCoords(uint32_t entityID);
SMM_API void scripting_Entity_SetCoords(uint32_t entityID, float x, float y, float z);
QAngle scripting_Entity_GetAnglesRaw(uint32_t entityID);
SMM_API const char *scripting_Entity_GetAngles(uint32_t entityID);
SMM_API void scripting_Entity_SetAngles(uint32_t entityID, float x, float y, float z);
Color scripting_Entity_GetColorsRaw(uint32_t entityID);
SMM_API const char *scripting_Entity_GetColors(uint32_t entityID);
SMM_API void scripting_Entity_SetColors(uint32_t entityID, int r, int g, int b, int a);
SMM_API void scripting_Entity_SetCollisionGroup(uint32_t entityID, Collision_Group_t collisionGroup);

SMM_API bool scripting_OnClientChat(CBasePlayerController *controller, const char *text, bool teamonly);
SMM_API bool scripting_OnClientGameMessage(CBasePlayerController *controller, int destination, const char *text);
SMM_API bool scripting_ShouldHearVoice(Player *player);

SMM_API void scripting_Precacher_AddSound(const char *path);

SMM_API const char *scripting_Files_Read(const char *path);
SMM_API void scripting_Files_Append(const char *path, const char *content, bool hasdate);
SMM_API void scripting_Files_Write(const char *path, const char *content, bool hasdate);
SMM_API void scripting_Files_Delete(const char *path);
SMM_API const char *scripting_Files_GetBase(const char *path);
SMM_API bool scripting_Files_ExistsPath(const char *path);
SMM_API bool scripting_Files_IsDirectory(const char *path);
SMM_API const char **scripting_Files_FetchFileNames(const char *path);
SMM_API const char **scripting_Files_FetchDirectories(const char *path);
SMM_API bool scripting_Files_CreateDirectory(const char *path);

SMM_API uint64_t scripting_HTTP_CreateRequest(const char *domain);
SMM_API void scripting_HTTP_SetBody(uint64_t requestID, const char *body);
SMM_API void scripting_HTTP_AddHeader(uint64_t requestID, const char *key, const char *value);
SMM_API void scripting_HTTP_DeleteHeader(uint64_t requestID, const char *key);
SMM_API void scripting_HTTP_AddMultipartFile(uint64_t requestID, const char *field, const char *content, const char *filename, const char *file_content_type);
SMM_API void scripting_HTTP_SetContentType(uint64_t requestID, ContentType content_type);
SMM_API void scripting_HTTP_SetBasicAuthentication(uint64_t requestID, const char *username, const char *password);
SMM_API void scripting_HTTP_SetBearerAuthenticationToken(uint64_t requestID, const char *token);
SMM_API void scripting_HTTP_SetFollowRedirect(uint64_t requestID, bool follow);
SMM_API const char *scripting_HTTP_GetBody(uint64_t requestID);
SMM_API int scripting_HTTP_GetStatusCode(uint64_t requestID);
SMM_API const char *scripting_HTTP_GetError(uint64_t requestID);
SMM_API void scripting_HTTP_Get(uint64_t requestID, const char *path);
SMM_API void scripting_HTTP_Delete(uint64_t requestID, const char *path);
SMM_API void scripting_HTTP_Post(uint64_t requestID, const char *path);
SMM_API void scripting_HTTP_Put(uint64_t requestID, const char *path);
SMM_API void scripting_HTTP_Patch(uint64_t requestID, const char *path);
SMM_API void scripting_HTTP_Close(uint64_t requestID);

SMM_API void scripting_Logger_CreateLogger(const char *plugin_name);
SMM_API void scripting_Logger_WriteLog(const char *plugin_name, ELogType log_type, const char *text);

SMM_API const char *scripting_Player_GetName(uint32 playerId);
SMM_API void scripting_Player_SetName(uint32 playerId, const char *name);
SMM_API uint64 scripting_Player_GetSteamID(uint32 playerId);
SMM_API float scripting_Player_GetGravity(uint32 playerId);
SMM_API bool scripting_Player_IsFirstSpawn(uint32 playerId);
SMM_API void scripting_Player_SetGravity(uint32 playerId, float gravity);
SMM_API float scripting_Player_GetSpeed(uint32 playerId);
SMM_API void scripting_Player_SetSpeed(uint32 playerId, float speed);
SMM_API const char *scripting_Player_GetSteamID2(uint32 playerId);
SMM_API void scripting_Player_SetFlashDuration(uint32 playerId, float duration);
SMM_API void scripting_Player_Drop(uint32 playerId, int reason);
SMM_API bool scripting_Player_IsAuthenticated(uint32 playerId);
SMM_API const char *scripting_Player_GetConvar(uint32 playerId, const char *name);
SMM_API void scripting_Player_SendMessage(uint32 playerId, int dest, const char *text);
SMM_API uint8 scripting_Player_GetTeam(uint32 playerId);
SMM_API void scripting_Player_SetTeam(uint32 playerId, int team);
SMM_API int scripting_Player_GetHealth(uint32 playerId);
SMM_API void scripting_Player_SetHealth(uint32 playerId, int health);
SMM_API int scripting_Player_GetMaxHealth(uint32 playerId);
SMM_API void scripting_Player_SetMaxHealth(uint32 playerId, int health);
SMM_API void scripting_Player_TakeHealth(uint32 playerId, int health);
SMM_API void scripting_Player_Kill(uint32 playerId);
SMM_API void scripting_Players_SendMessage(int dest, const char *text);
SMM_API int scripting_Player_GetArmor(uint32 playerId);
SMM_API void scripting_Player_SetArmor(uint32 playerId, int armor);
SMM_API void scripting_Player_TakeArmor(uint32 playerId, int armor);
SMM_API const char *scripting_Player_GetClanTag(uint32 playerId);
SMM_API void scripting_Player_SetClanTag(uint32 playerId, const char *tag);
SMM_API void scripting_Player_SetVar(uint32 playerId, const char *name, int type, ...);
SMM_API const char *scripting_Player_GetVar(uint32 playerId, const char *name);
SMM_API uint32 scripting_Player_GetConnectedTime(uint32 playerId);
SMM_API int scripting_Player_FetchMatchStat(uint32 playerId, PlayerStat stat);
SMM_API void scripting_Player_SetMatchStat(uint32 playerId, PlayerStat stat, int value);
SMM_API const char *scripting_Player_GetIPAddress(uint32 playerId);
SMM_API const char *scripting_Player_GetCoords(uint32 playerId);
SMM_API void scripting_Player_SetCoords(uint32 playerId, float x, float y, float z);
SMM_API const char *scripting_Player_GetVelocity(uint32 playerId);
SMM_API void scripting_Player_SetVelocity(uint32 playerId, float x, float y, float z);
SMM_API int scripting_Player_GetMoney(uint32 playerId);
SMM_API void scripting_Player_SetMoney(uint32 playerId, int money);
SMM_API void scripting_Player_TakeMoney(uint32 playerId, int money);
SMM_API void scripting_Player_SetHealthShotBoostEffectExpirationTime(uint32 playerId, float expireTime);
SMM_API void scripting_Player_ShowMenu(uint32 playerId, const char *menuid);
SMM_API void scripting_Player_HideMenu(uint32 playerId);
SMM_API int scripting_Player_GetLatency(uint32 playerId);
SMM_API void scripting_Player_SetConvar(uint32 playerId, const char *cvarname, const char *cvarvalue);
SMM_API void scripting_Player_ExecuteCommand(uint32 playerId, const char *cmd);
SMM_API void scripting_Player_SetCompetitiveRanking(uint32 playerId, int ranking);
SMM_API void scripting_Player_SetCompetitiveRankType(uint32 playerId, int type);
SMM_API void scripting_Player_Weapons_SetActiveWeapon(uint32 playerId, uint32 slot);
SMM_API void scripting_Player_Weapons_Drop(uint32 playerId);
SMM_API void scripting_Player_Weapons_Remove(uint32 playerId);
SMM_API void scripting_Player_Weapons_Give(uint32 playerId, const char *name);
SMM_API uint32_t scripting_Player_Weapons_GetWeaponID(uint32 playerId, uint32 slot);

QAngle scripting_Player_GetEyeAnglesRaw(uint32 playerId);
SMM_API const char *scripting_Player_GetEyeAngles(uint32 playerId);
SMM_API void scripting_Player_SetEyeAngles(uint32 playerId, float x, float y, float z);

SMM_API void scripting_Player_Respawn(uint32 playerId);

SMM_API void scripting_Player_Weapon_Remove(uint32 playerId, uint32 slot);
SMM_API void scripting_Player_Weapon_Drop(uint32 playerId, uint32 slot);

SMM_API void scripting_Player_Weapon_SetClipAmmo(uint32 playerId, uint32 slot, int ammo);
SMM_API void scripting_Player_Weapon_SetClip2Ammo(uint32 playerId, uint32 slot, int ammo);
SMM_API void scripting_Player_Weapon_SetReserveAmmo(uint32 playerId, uint32 slot, int ammo);
SMM_API uint32_t scripting_Player_Weapon_GetSilencerType(uint32 playerId, uint32 slot);
SMM_API int32_t scripting_Player_Weapon_GetNextPrimaryAttackTick(uint32 playerId, uint32 slot);
SMM_API int32_t scripting_Player_Weapon_GetNextSecondaryAttackTick(uint32 playerId, uint32 slot);
SMM_API void scripting_Player_Weapon_SetNextPrimaryAttackTick(uint32 playerId, uint32 slot, int32_t tick);
SMM_API void scripting_Player_Weapon_SetNextSecondaryAttackTick(uint32 playerId, uint32 slot, int32_t tick);
SMM_API float scripting_Player_Weapon_GetNextPrimaryAttackTickRatio(uint32 playerId, uint32 slot);
SMM_API float scripting_Player_Weapon_GetNextSecondaryAttackTickRatio(uint32 playerId, uint32 slot);
SMM_API void scripting_Player_Weapon_SetNextPrimaryAttackTickRatio(uint32 playerId, uint32 slot, float ratio);
SMM_API void scripting_Player_Weapon_SetNextSecondaryAttackTickRatio(uint32 playerId, uint32 slot, float ratio);

SMM_API void scripting_Player_Weapon_SetStatTrack(uint32 playerId, uint32 slot, bool stattrack);
SMM_API void scripting_Player_Weapon_SetWear(uint32 playerId, uint32 slot, float wear);
SMM_API void scripting_Player_Weapon_SetPaintKit(uint32 playerId, uint32 slot, int paintkit);
SMM_API void scripting_Player_Weapon_SetSeed(uint32 playerId, uint32 slot, int seed);

SMM_API bool scripting_Player_Weapon_GetStatTrack(uint32 playerId, uint32 slot);
SMM_API float scripting_Player_Weapon_GetWear(uint32 playerId, uint32 slot);
SMM_API int scripting_Player_Weapon_GetPaintKit(uint32 playerId, uint32 slot);
SMM_API int scripting_Player_Weapon_GetSeed(uint32 playerId, uint32 slot);
SMM_API void scripting_Player_Weapon_SetDefaultChangeSkinAttributes(uint32 playerId, uint32 slot);
SMM_API void scripting_Player_Weapon_SetNametag(uint32 playerId, uint32 slot, const char *text);

SMM_API bool scripting_Player_Weapon_Exists(uint32 playerId, uint32 slot);

SMM_API uint32 scripting_Player_Weapon_GetType(uint32 playerId, uint32 slot);
SMM_API const char *scripting_Player_Weapon_GetName(uint32 playerId, uint32 slot);

SMM_API void scripting_Player_SetDesiredFOV(uint32 playerId, uint32_t fov);
SMM_API uint32_t scripting_Player_GetDesiredFOV(uint32 playerId);

SMM_API uint32_t scripting_Player_GetHighestGeneratedServerViewAngleChangeIndex(uint32 playerId);
SMM_API void scripting_Player_SetHighestGeneratedServerViewAngleChangeIndex(uint32 playerId, uint32_t val);
SMM_API uint32_t scripting_Player_GetHideHUD(uint32 playerId);
SMM_API void scripting_Player_SetHideHUD(uint32 playerId, uint32_t val);
SMM_API bool scripting_Player_GetInitHUD(uint32 playerId);
SMM_API void scripting_Player_SetInitHUD(uint32 playerId, bool val);
SMM_API float scripting_Player_GetHltvReplayDelay(uint32 playerId);
SMM_API void scripting_Player_SetHltvReplayDelay(uint32 playerId, float val);
SMM_API float scripting_Player_GetHltvReplayEnd(uint32 playerId);
SMM_API void scripting_Player_SetHltvReplayEnd(uint32 playerId, float val);

SMM_API bool scripting_Player_GetAutoKickDisabled(uint32 playerId);
SMM_API void scripting_Player_SetAutoKickDisabled(uint32 playerId, bool val);
SMM_API int32_t scripting_Player_GetAvailableEntitySteadyState(uint32 playerId);
SMM_API void scripting_Player_SetAvailableEntitySteadyState(uint32 playerId, int32_t val);
SMM_API bool scripting_Player_GetPredict(uint32 playerId);
SMM_API void scripting_Player_SetPredict(uint32 playerId, bool val);
SMM_API uint32_t scripting_Player_GetTickBase(uint32 playerId);
SMM_API void scripting_Player_SetTickBase(uint32 playerId, uint32_t val);
SMM_API bool scripting_Player_GetGamePaused(uint32 playerId);
SMM_API void scripting_Player_SetGamePaused(uint32 playerId, bool val);
SMM_API bool scripting_Player_GetHasAnySteadyStateEnts(uint32 playerId);
SMM_API void scripting_Player_SetHasAnySteadyStateEnts(uint32 playerId, bool val);
SMM_API bool scripting_Player_GetIsHLTV(uint32 playerId);
SMM_API void scripting_Player_SetIsHLTV(uint32 playerId, bool val);
SMM_API bool scripting_Player_GetIsLowViolence(uint32 playerId);
SMM_API void scripting_Player_SetIsLowViolence(uint32 playerId, bool val);
SMM_API bool scripting_Player_GetLagCompensation(uint32 playerId);
SMM_API void scripting_Player_SetLagCompensation(uint32 playerId, bool val);
SMM_API float scripting_Player_GetLastEntitySteadyState(uint32 playerId);
SMM_API void scripting_Player_SetLastEntitySteadyState(uint32 playerId, float val);
SMM_API int32_t scripting_Player_GetLastLateCommandExecuted(uint32 playerId);
SMM_API void scripting_Player_SetLastLateCommandExecuted(uint32 playerId, int32_t val);
SMM_API float scripting_Player_GetLastPlayerTalkTime(uint32 playerId);
SMM_API void scripting_Player_SetLastPlayerTalkTime(uint32 playerId, float val);
SMM_API int32_t scripting_Player_GetLastRealCommandNumberExecuted(uint32 playerId);
SMM_API void scripting_Player_SetLastRealCommandNumberExecuted(uint32 playerId, int32_t val);
SMM_API float scripting_Player_GetLerpTime(uint32 playerId);
SMM_API void scripting_Player_SetLerpTime(uint32 playerId, float val);

SMM_API void scripting_Player_SetGloves(uint32 playerId, uint16_t defindex, int paintkit, int seed, float wear);
SMM_API void scripting_Player_SetModel(uint32 playerId, const char *model);
SMM_API void scripting_Player_SetMusicKit(uint32 playerId, int musicid);

SMM_API const char *scripting_Player_GetChatTag(uint32 playerId);
SMM_API void scripting_Player_SetChatTag(uint32 playerId, const char *tag);
SMM_API void scripting_Player_SetChatTagColor(uint32 playerId, const char *tagcolor);
SMM_API void scripting_Player_SetNameColor(uint32 playerId, const char *namecolor);
SMM_API void scripting_Player_SetChatColor(uint32 playerId, const char *chatcolor);

SMM_API void scripting_Precacher_AddModel(const char *model);

SMM_API void scripting_Server_ExecuteCommand(const char *str);
SMM_API uint16 scripting_Server_GetMaxPlayers();
SMM_API const char *scripting_Server_GetMapName();
SMM_API bool scripting_Server_IsMapValid(const char *map);
SMM_API bool scripting_Server_IsPistolRound();
SMM_API int32_t scripting_server_GetTotalRounds();
SMM_API float scripting_Server_GetCurrentTime();
SMM_API int scripting_Server_GetTickCount();
SMM_API void scripting_Server_SetQueuedMatchmaking(bool status);
SMM_API bool scripting_Server_GetQueuedMatchmaking();

SMM_API const char *scripting_Translations_Fetch(const char *key);

SMM_API const char *scripting_Exports_Call(const char *plugin_name, const char *export_name, const char *jsonData);
SMM_API void scripting_Exports_Register(const char *plugin_name, const char *export_name, void *functionPtr);
SMM_API void scripting_Exports_Unregister(const char *plugin_name, const char *export_name);

SMM_API void scripting_Menus_Register(const char *plugin_name, const char *id, const char *title, const char *color, const char *items);
SMM_API void scripting_Menus_Unregister(const char *plugin_name, const char *id);

SMM_API void scripting_Print(const char *str);
SMM_API PluginState scripting_GetPluginState(const char *plugin_name);

void SetupLuaCommands(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaConfiguration(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaConvars(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaDatabase(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaEntities(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaExports(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaFiles(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaGameEvents(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaHTTP(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaLogger(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaMenus(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaPlayer(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaPlayerManager(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaPrecacher(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaServer(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaTimers(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaTranslation(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaTypes(luacpp::LuaState *state, Plugin *plugin);
void SetupLuaUtils(luacpp::LuaState *state, Plugin *plugin);

template <typename T, typename... Args>
void CallCPPFunctionNoReturn(std::string function, Args... args);
template <typename... Args>
void CallLuaFunctionNoReturn(std::string function, Args... args);

#endif