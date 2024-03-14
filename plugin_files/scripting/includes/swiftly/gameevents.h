#ifndef _swiftly_gameevents_h
#define _swiftly_gameevents_h

#include "playermanager.h"

class Player;

void ThreadFunction() __attribute__((weak));
void NextFrameHandler() __attribute__((weak));

void print(const char *str, ...);

void OnPluginStart() __attribute__((weak));
void OnPluginStop() __attribute__((weak));
void OnProgramLoad(const char *pluginName, const char *mainFilePath);
bool OnClientConnect(Player *player) __attribute__((weak));
void OnClientDisconnect(Player *player) __attribute__((weak));
void OnClientFullConnected(Player *player) __attribute__((weak));
void OnPlayerPostThink(Player *player) __attribute__((weak));
bool OnPlayerPrePostThink(Player *player) __attribute__((weak));
void OnPlayerSpawn(Player *player) __attribute__((weak));
bool OnPlayerDamagePlayer(Player *player, Player *attacker, float damage, DamageTypes damagetype, uint8_t ammotype, DamageFlags damageflags) __attribute__((weak));
void OnGameTick(bool simulating, bool bFirstTick, bool bLastTick) __attribute__((weak));
bool OnPlayerChat(Player *player, const char *text, bool teamonly) __attribute__((weak));
void OnRoundStart(long timelimit, long fraglimit, const char *objective) __attribute__((weak));
void OnRoundEnd(unsigned char winner, unsigned char reason, const char *message, unsigned char legacy, short player_count, unsigned char nomusic) __attribute__((weak));
void OnRoundMVP(Player *player, short reason, long value, long musickitmvps, unsigned char nomusic, long musickitid) __attribute__((weak));
void OnRoundPrestart() __attribute__((weak));
void OnBombBeginPlant(Player *player, unsigned short site) __attribute__((weak));
void OnBombAbortPlant(Player *player, unsigned short site) __attribute__((weak));
void OnBombPlanted(Player *player, unsigned short site) __attribute__((weak));
void OnBombBeginDefuse(Player *player, unsigned short site) __attribute__((weak));
void OnBombAbortDefuse(Player *player, unsigned short site) __attribute__((weak));
void OnBombDefused(Player *player, unsigned short site) __attribute__((weak));
void OnBombExploded(Player *player, unsigned short site) __attribute__((weak));
void OnBombDropped(Player *player) __attribute__((weak));
void OnBombPickup(Player *player) __attribute__((weak));
bool OnClientCommand(Player *player, const char *command) __attribute__((weak));
void BombBeginPlant(Player *player, unsigned short site) __attribute__((weak));
void BombAbortPlant(Player *player, unsigned short site) __attribute__((weak));
void BombPlanted(Player *player, unsigned short site) __attribute__((weak));
void BombBeginDefuse(Player *player, unsigned short site) __attribute__((weak));
void BombAbortDefuse(Player *player, unsigned short site) __attribute__((weak));
void BombDefused(Player *player, unsigned short site) __attribute__((weak));
void BombExploded(Player *player, unsigned short site) __attribute__((weak));
void BombDropped(Player *player) __attribute__((weak));
void BombPickup(Player *player) __attribute__((weak));
void AllPluginsLoaded() __attribute__((weak));
void OnMapLoad(const char *mapName) __attribute__((weak));
void OnMapUnload(const char *mapName) __attribute__((weak));
bool OnClientGameMessage(Player *player, int destination, const char *message) __attribute__((weak));
void OnPlayerDeath(Player *player, Player *attacker, Player *assister, bool assistedflash, const char *weapon, bool headshot, short dominated, short revenge, short wipe, short penetrated, bool noreplay, bool noscope, bool thrusmoke, bool attackerblind, float distance, short dmg_health, short dmg_armor, short hitgroup) __attribute__((weak));
void OnPlayerHurt(Player *player, Player *attacker, short dmgHealth, short dmgArmor, short hitgroup, const char *weapon) __attribute__((weak));
void OnPlayerBlind(Player *player, Player *attacker, short entityid, float duration) __attribute__((weak));
void OnPlayerChangeName(Player *player, const char *oldname, const char *newname) __attribute__((weak));
void OnPlayerInfo(const char *name, Player *player, uint64_t steamid, bool bot) __attribute__((weak));
void OnPlayerFullUpdate(Player *player, short count) __attribute__((weak));
void OnItemPickup(Player *player, const char *item, bool silent, long defindex) __attribute__((weak));
void OnPlayerTeam(Player *player, unsigned char team, unsigned char oldteam, bool disconnect, bool silent, bool isbot) __attribute__((weak));
void OnEnterBuyzone(Player *player, bool canbuy) __attribute__((weak));
void OnExitBuyzone(Player *player, bool canbuy) __attribute__((weak));
void OnRoundPostStart() __attribute__((weak));
void OnEnterBombzone(Player *player, bool hasbomb, bool isplanted) __attribute__((weak));
void OnExitBombzone(Player *player, bool hasbomb, bool isplanted) __attribute__((weak));
void OnPlayerFallDamage(Player *player, float damage) __attribute__((weak));
void OnPlayerJump(Player *player) __attribute__((weak));
bool ShouldHearVoice(Player *player) __attribute__((weak));
bool OnWeaponSpawned(Player *player, Weapon *weapon) __attribute__((weak));
void OnClientKeyStateChange(Player *player, const char *button, bool pressed) __attribute__((weak));
void OnClientExecuteCommand(Player *player, const char *command) __attribute__((weak));
void OnServerCvarChange(const char *cvarname, const char *cvarvalue) __attribute__((weak));
void OnServerPreshutdown(const char *reason) __attribute__((weak));
void OnServerShutdown(const char *reason) __attribute__((weak));
void OnServerMesssage(const char *text) __attribute__((weak));
void OnPlayerActivate(Player *player) __attribute__((weak));
void OnLocalPlayerTeam() __attribute__((weak));
void OnLocalPlayerControllerTeam() __attribute__((weak));
void OnLocalPlayerPawnChanged() __attribute__((weak));
void OnTeamplayBroadcastAudio(unsigned char team, const char *sound) __attribute__((weak));
void OnFinaleStart(short rushes) __attribute__((weak));
void OnPlayerStatsUpdated(bool forceupload) __attribute__((weak));
void OnUserDataDownloaded() __attribute__((weak));
void OnRagdollDissolved(long entindex) __attribute__((weak));
void OnTeamInfo(unsigned char teamid, const char *teamname) __attribute__((weak));
void OnTeamScore(unsigned char teamid, short score) __attribute__((weak));
void OnHLTVCameraman(Player *player) __attribute__((weak));
void OnHLTVChase(Player *target1, Player *target2, short distance, short theta, short phi, unsigned char inertia, unsigned char ineye) __attribute__((weak));
void OnHLTVRankCamera(unsigned char index, float rank, Player *target) __attribute__((weak));
void OnHLTVRankEntity(Player *player, float rank, Player *target) __attribute__((weak));
void OnHLTVFixed(long posx, long posy, long posz, short theta, short phi, short offset, float fov, Player *target) __attribute__((weak));
void OnHLTVMessage(const char *text) __attribute__((weak));
void OnHLTVStatus(long clients, long slots, short proxies, const char *master) __attribute__((weak));
void OnHLTVTitle(const char *text) __attribute__((weak));
void OnHLTVChat(const char *text, uint64_t steamID) __attribute__((weak));
void OnHLTVVersioninfo(long version) __attribute__((weak));
void OnHLTVReplay(long delay, long reason) __attribute__((weak));
void OnMapShutdown() __attribute__((weak));
void OnMapTransition() __attribute__((weak));
void OnHostnameChanged(const char *hostname) __attribute__((weak));
void OnDifficultyChanged(short newDifficulty, short oldDifficulty, const char *strDifficulty) __attribute__((weak));
void OnGameMessage(unsigned char target, const char *text) __attribute__((weak));
void OnGameNewmap(const char *mapname) __attribute__((weak));
void OnRoundStartPreEntity() __attribute__((weak));
void OnRoundStartPostNav() __attribute__((weak));
void OnRoundFreezeEnd() __attribute__((weak));
void OnTeamplayRoundStart(bool full_reset) __attribute__((weak));
void OnPlayerFootstep(Player *player) __attribute__((weak));
void OnPlayerHintmessage(const char *hintmessage) __attribute__((weak));
void OnBreakBreakable(long entindex, Player *player, unsigned char material) __attribute__((weak));
void OnBreakProp(long entindex, Player *player) __attribute__((weak));
void OnEntityKilled(long entindex_killed, long entindex_attacker, long entindex_inflictor, long damagebits) __attribute__((weak));
void OnDoorClose(Player *player, bool checkpoint) __attribute__((weak));
void OnVoteStarted(const char *issue, const char *param1, unsigned char team, long initiator) __attribute__((weak));
void OnVoteFailed(unsigned char team) __attribute__((weak));
void OnVotePassed(const char *details, const char *param1, unsigned char team) __attribute__((weak));
void OnVoteChanged(unsigned char vote_option1, unsigned char vote_option2, unsigned char vote_option3, unsigned char vote_option4, unsigned char vote_option5, unsigned char potentialVotes) __attribute__((weak));
void OnVoteCastYes(unsigned char team, long entityid) __attribute__((weak));
void OnVoteCastNo(unsigned char team, long entityid) __attribute__((weak));
void OnAchievementEvent(const char *achievement_name, short cur_val, short max_val) __attribute__((weak));
void OnAchievementEarned(Player *player, short achievement) __attribute__((weak));
void OnAchievementWriteFailed() __attribute__((weak));
void OnBonusUpdated(short numadvanced, short numbronze, short numsilver, short numgold) __attribute__((weak));
void OnSpecTargetUpdated(Player *player, long target) __attribute__((weak));
void OnSpecModeUpdated(Player *player) __attribute__((weak));
void OnEntityVisible(Player *player, short subject, const char *classname, const char *entityname) __attribute__((weak));
void OnGameInstructorDraw() __attribute__((weak));
void OnGameInstructorNodraw() __attribute__((weak));
void OnFlareIgniteNCP(long entindex) __attribute__((weak));
void OnHelicoptedGrenadePuntMiss() __attribute__((weak));
void OnPhysgunPickup(long target) __attribute__((weak));
void OnInventoryUpdated() __attribute__((weak));
void OnCarUpdated() __attribute__((weak));
void OnStorePricesheetUpdated() __attribute__((weak));
void OnItemSchemaInitialized() __attribute__((weak));
void OnDropRateModified() __attribute__((weak));
void OnEventTicketModified() __attribute__((weak));
void OnGCConnected() __attribute__((weak));
void OnInstructorStartLesson(Player *player, const char *hint_name, long hint_target, unsigned char vr_movement_type, bool vr_single_controller, unsigned char vr_controller_type) __attribute__((weak));
void OnInstructorCloseLesson(Player *player, const char *hint_name) __attribute__((weak));
void OnInstructorServerHintCreate(Player *player, const char *hint_name, const char *hint_replace_key, long hint_target, Player *hint_activator_user, short hint_timeout, const char *hint_icon_onscreen, const char *hint_icon_offscreen, const char *hint_caption, const char *hint_activator_caption, const char *hint_color, float hint_icon_offset, float hint_range, long hint_flags, const char *hint_binding, const char *hint_gamepad_binding, bool hint_allow_nodraw_target, bool hint_nooffscreen, bool hint_forcecaption, bool hint_local_player_only) __attribute__((weak));
void OnClinetsideLessonClosed(const char *lesson_name) __attribute__((weak));
void OnDynamicShadowLightChanged() __attribute__((weak));
void OnGameuiHidden() __attribute__((weak));
void OnItemsGifted(Player *player, long itemdef, short numgifts, long giftidx, long accountid) __attribute__((weak));
void OnPlayerScore(Player *player, short kills, short deaths, short score) __attribute__((weak));
void OnPlayerShoot(Player *player, unsigned char weapon, unsigned char mode) __attribute__((weak));
void OnGameInit() __attribute__((weak));
void OnGameStart(long roundslimit, long timelimit, long fraglimit, const char *objective) __attribute__((weak));
void OnGameEnd(unsigned char winner) __attribute__((weak));
void OnRoundAnnounceMatchPoint() __attribute__((weak));
void OnRoundAnnounceFinal() __attribute__((weak));
void OnRoundAnnounceLastRoundHalf() __attribute__((weak));
void OnRoundAnnouceMatchStart() __attribute__((weak));
void OnRoundAnnounceWarmup() __attribute__((weak));
void OnRoundEndUploadStats() __attribute__((weak));
void OnRoundOfficiallyEnded() __attribute__((weak));
void OnRoundTimeWarning() __attribute__((weak));
void OnUGCMapInfoReceived(uint64_t published_file_id) __attribute__((weak));
void OnUGCMapUnsubscribed(uint64_t published_file_id) __attribute__((weak));
void OnUGCMapDownloadError(uint64_t published_file_id, long error_code) __attribute__((weak));
void OnUGCFileDownloadFinished(uint64_t hcontent) __attribute__((weak));
void OnUGCFileDownloadStart(uint64_t hcontent, uint64_t published_file_id) __attribute__((weak));
void OnBeginNewMatch() __attribute__((weak));
void OnDMBonusWeaponStart(short time, short Pos) __attribute__((weak));
void OnSurvivalAnnouncePhase(short phase) __attribute__((weak));
void OnBrokenBreakable(long entindex, Player *player, unsigned char material) __attribute__((weak));
void OnPlayerDecal(Player *player) __attribute__((weak));
void OnSetInstructorGroupEnabled(const char *group, short enabled) __attribute__((weak));
void OnInstructorServerHintStop(const char *hint_name) __attribute__((weak));
void OnReadGameTitledata(short controllerId) __attribute__((weak));
void OnWriteGameTitledata(short controllerId) __attribute__((weak));
void OnResetGameTitledata(short controllerId) __attribute__((weak));
void OnWeaponhudSelection(Player *player, unsigned char mode, long entindex) __attribute__((weak));
void OnVoteEnded() __attribute__((weak));
void OnVoteCast(unsigned char vote_option, short team, Player *player) __attribute__((weak));
void OnVoteOptions(unsigned char count, const char *option1, const char *option2, const char *option3, const char *option4, const char *option5) __attribute__((weak));
void OnEndmatchMapvoteSelectingMap(unsigned char count, unsigned char slot1, unsigned char slot2, unsigned char slot3, unsigned char slot4, unsigned char slot5, unsigned char slot6, unsigned char slot7, unsigned char slot8, unsigned char slot9, unsigned char slot10) __attribute__((weak));
void OnEndmatchCMMStartRevealItems() __attribute__((weak));
void OnClientLoadoutChanged() __attribute__((weak));
void OnAddPlayerSonarIcon(Player *player, float pos_x, float pos_y, float pos_z) __attribute__((weak));
void OnAddBulletHitMarker(Player *player, short bone, short pos_x, short pos_y, short pos_z, short ang_x, short ang_y, short ang_z, short start_x, short start_y, short start_z, bool hit) __attribute__((weak));
void OnOtherDeath(short otherid, const char *othertype, short attacker, const char *weapon, const char *weapon_itemid, const char *weapon_fauxitemid, const char *weapon_originalowner_xuid, bool headshot, short penetrated, bool noscope, bool thrusmoke, bool attackerblind) __attribute__((weak));
void OnItemPurchase(Player *player, short team, short loadout, const char *weapon) __attribute__((weak));
void OnDefuserDropped(long entityid) __attribute__((weak));
void OnDefuserPickup(long entityid, Player *player) __attribute__((weak));
void OnAnnouncePhaseEnd() __attribute__((weak));
void OnCSIntermission() __attribute__((weak));
void OnHostageFollows(Player *player, short hostage) __attribute__((weak));
void OnHostageHurt(Player *player, short hostage) __attribute__((weak));
void OnHostageKilled(Player *player, short hostage) __attribute__((weak));
void OnHostageRescued(Player *player, short hostage, short site) __attribute__((weak));
void OnHostageStopsFollowing(Player *player, short hostage) __attribute__((weak));
void OnHostageRescuedAll() __attribute__((weak));
void OnHostageCallForHelp(short hostage) __attribute__((weak));
void OnVIPEscaped(Player *player) __attribute__((weak));
void OnVIPKilled(Player *player, Player *attacker) __attribute__((weak));
void OnPlayerRadio(Player *player, short slot) __attribute__((weak));
void OnBombBeep(long entindex) __attribute__((weak));
void OnWeaponFire(Player *player, const char *weapon, bool silenced) __attribute__((weak));
void OnWeaponFireOnEmpty(Player *player, const char *weapon) __attribute__((weak));
void OnGrenadeThrown(Player *player, const char *weapon) __attribute__((weak));
void OnWeaponOutOfAmmo(Player *player) __attribute__((weak));
void OnWeaponReload(Player *player) __attribute__((weak));
void OnWeaponZoom(Player *player) __attribute__((weak));
void OnSilencerDetach(Player *player) __attribute__((weak));
void OnInspectWeapon(Player *player) __attribute__((weak));
void OnWeaponZoomRifle(Player *player) __attribute__((weak));
void OnPlayerSpawned(Player *player, bool inrestart) __attribute__((weak));
void OnItemPickupSlerp(Player *player, short index, short behavior) __attribute__((weak));
void OnItemPickupFailed(Player *player, const char *item, short reason, short limit) __attribute__((weak));
void OnItemRemove(Player *player, const char *item, long defindex) __attribute__((weak));
void OnAmmoPickup(Player *player, const char *item, long index) __attribute__((weak));
void OnItemEquip(Player *player, const char *item, long defindex, bool canzoom, bool hassilencer, bool issilenced, bool hastracers, short weptype, bool ispainted) __attribute__((weak));
void OnBuytimeEnded() __attribute__((weak));
void OnEnterRescueZone(Player *player) __attribute__((weak));
void OnExitRescueZone(Player *player) __attribute__((weak));
void OnSilencerOff(Player *player) __attribute__((weak));
void OnSilencerOn(Player *player) __attribute__((weak));
void OnBuyMenuOpen(Player *player) __attribute__((weak));
void OnBuyMenuClose(Player *player) __attribute__((weak));
void OnGrenadeBounce(Player *player) __attribute__((weak));
void OnHEGrenadeDetonate(Player *player, short entityid, float x, float y, float z) __attribute__((weak));
void OnFlashbangDetonate(Player *player, short entityid, float x, float y, float z) __attribute__((weak));
void OnSmokeGrenadeDetonate(Player *player, short entityid, float x, float y, float z) __attribute__((weak));
void OnSmokeGrenadeExpired(Player *player, short entityid, float x, float y, float z) __attribute__((weak));
void OnMolotovDetonate(Player *player, float x, float y, float z) __attribute__((weak));
void OnDecoyDetonate(Player *player, short entityid, float x, float y, float z) __attribute__((weak));
void OnDecoyStarted(Player *player, short entityid, float x, float y, float z) __attribute__((weak));
void OnTagrenadeDetonate(Player *player, short entityid, float x, float y, float z) __attribute__((weak));
void OnInfernoStartBurn(short entityid, float x, float y, float z) __attribute__((weak));
void OnInfernoExpire(short entityid, float x, float y, float z) __attribute__((weak));
void OnInfernoExtinguish(short entityid, float x, float y, float z) __attribute__((weak));
void OnDecoyFiring(Player *player, short entityid, float x, float y, float z) __attribute__((weak));
void OnBulletImpact(Player *player, float x, float y, float z) __attribute__((weak));
void OnDoorMoving(Player *player, long entindex) __attribute__((weak));
void OnMBInputLockSuccess() __attribute__((weak));
void OnMBInputLockCancel() __attribute__((weak));
void OnNavBlocked(long area, bool blocked) __attribute__((weak));
void OnNavGenerate() __attribute__((weak));
void OnAchievementInfoLoaded() __attribute__((weak));
void OnHLTVChangedMode(long oldmode, long newmode, long obs_target) __attribute__((weak));
void OnCSGameDisconnected() __attribute__((weak));
void OnCSRoundFinalBeep() __attribute__((weak));
void OnCSRoundStartBeep() __attribute__((weak));
void OnCSWinPanelRound(bool show_timer_defend, bool show_timer_attack, short timer_time, unsigned char final_event, const char *funfact_token, Player *funfact_player, long funfact_data1, long funfact_data2, long funfact_data3) __attribute__((weak));
void OnCSWinPanelMatch() __attribute__((weak));
void OnCSMatchEndRestart() __attribute__((weak));
void OnCSPreRestart() __attribute__((weak));
void OnShowDeathpanel(Player *victim, long killer, Player *killer_controller, short hits_taken, short damage_taken, short hits_given, short damage_given) __attribute__((weak));
void OnHideDeathpanel() __attribute__((weak));
void OnAchievementEarnedLocal(short achievement, short splitscreenplayer) __attribute__((weak));
void OnRepostXboxAchievements(short splitscreenplayer) __attribute__((weak));
void OnMatchEndConditions(long frags, long max_rounds, long win_rounds, long time) __attribute__((weak));
void OnShowSurvivalRespawnStatus(const char *loc_token, long duration, Player *player) __attribute__((weak));
void OnGGKilledEnemy(Player *victim, Player *attacker, short dominated, short revenge, bool bonus) __attribute__((weak));
void OnSwitchTeam(short numPlayers, short numSpectators, short avg_rank, short numTSlotsFree, short numCTSlotsFree) __attribute__((weak));
void OnWriteProfileData() __attribute__((weak));
void OnTrialTimeExpired(Player *player) __attribute__((weak));
void OnUpdateMatchmakingStats() __attribute__((weak));
void OnPlayerResetVote(Player *player, bool vote) __attribute__((weak));
void OnEnableRestartVoting(bool enable) __attribute__((weak));
void OnSfuievent(const char *action, const char *data, unsigned char slot) __attribute__((weak));
void OnStartVote(Player *player, unsigned char type, short vote_parameter) __attribute__((weak));
void OnPlayerGivenBomb(Player *player) __attribute__((weak));
void OnTRPlayerFlashbanged(Player *player) __attribute__((weak));
void OnTRMarkComplete(short complete) __attribute__((weak));
void OnTRMarkBestTime(long time) __attribute__((weak));
void OnTRExitHintTrigger() __attribute__((weak));
void OnBotTakeover(Player *player, Player *bot) __attribute__((weak));
void OnTRShowFinishMsgbox() __attribute__((weak));
void OnTRShowExitMsgbox() __attribute__((weak));
void OnJoinTeamFailed(Player *player, unsigned char reason) __attribute__((weak));
void OnTeamChangePending(Player *player, unsigned char toteam) __attribute__((weak));
void OnMaterialDefaultComplete() __attribute__((weak));
void OnCSPrevNextSpectator(bool next) __attribute__((weak));
void OnNextLevelChanged(const char *nextlevel, const char *mapgroup, const char *skirmishmode) __attribute__((weak));
void OnSeasoncoinLevelup(Player *player, short category, short rank) __attribute__((weak));
void OnTournamentReward(long defindex, long totalrewards, long accountid) __attribute__((weak));
void OnStartHalftime() __attribute__((weak));
void OnAmmoRefill(Player *player, bool success) __attribute__((weak));
void OnParachutePickup(Player *player) __attribute__((weak));
void OnParachuteDeploy(Player *player) __attribute__((weak));
void OnDronegunAttack(Player *player) __attribute__((weak));
void OnDroneDispatched(Player *player, short priority, short drone_dispatched) __attribute__((weak));
void OnLootCrateVisible(Player *player, short subject, const char *type) __attribute__((weak));
void OnLootCrateOpened(Player *player, const char *type) __attribute__((weak));
void OnOpenCrateInstructions(Player *player, short subject, const char *type) __attribute__((weak));
void OnSmokeBeaconParadrop(Player *player, short paradrop) __attribute__((weak));
void OnSurvivalParadropSpawn(short entityid) __attribute__((weak));
void OnSurvivalParadropBreak(short entityid) __attribute__((weak));
void OnDroneCargoDetached(Player *player, short cargo, bool delivered) __attribute__((weak));
void OnDroneAboveRoof(Player *player, short cargo) __attribute__((weak));
void OnChoppersIncomingWarning(bool global) __attribute__((weak));
void OnFirstbombsIncomingWarning(bool global) __attribute__((weak));
void OnDZItemInteraction(Player *player, short subject, const char *type) __attribute__((weak));
void OnSurvivalTeammateRespawn(Player *player) __attribute__((weak));
void OnSurvivalNoRespawnsWarning(Player *player) __attribute__((weak));
void OnSurvivalNoRespawnsFinal(Player *player) __attribute__((weak));
void OnPlayerPing(Player *player, short entityid, float x, float y, float z, bool urgent) __attribute__((weak));
void OnPlayerPingStop(short entityid) __attribute__((weak));
void OnPlayerSound(Player *player, long radius, float duration, bool step) __attribute__((weak));
void OnGuardianWaveRestart() __attribute__((weak));
void OnTeamIntroStart() __attribute__((weak));
void OnTeamIntroEnd() __attribute__((weak));
void OnBulletFlightResolution(Player *player, short pos_x, short pos_y, short pos_z, short ang_x, short ang_y, short ang_z, short start_x, short start_y, short start_z) __attribute__((weak));
void OnDoorBreak(long entindex, long dmgstate) __attribute__((weak));
void OnDoorClosed(Player *player, long entindex) __attribute__((weak));
void OnDoorOpen(Player *player, long entindex) __attribute__((weak));
void OnGamePhaseChanged(short new_phase) __attribute__((weak));
void OnHLTVReplayStatus(long reason) __attribute__((weak));

extern "C"
{
    void Internal_OnPluginStart()
    {
        print("");
        if (OnPluginStart)
            OnPluginStart();
    }
    void Internal_AllPluginsLoaded()
    {
        if (AllPluginsLoaded)
            AllPluginsLoaded();
    }
    void Internal_OnPluginStop()
    {
        if (OnPluginStop)
            OnPluginStop();
    }
    void Internal_OnProgramLoad(const char *pluginName, const char *mainFilePath)
    {
        OnProgramLoad(pluginName, mainFilePath);
    }
    void Internal_OnClientDisconnect(uint32_t slot)
    {
        if (!OnClientDisconnect)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnClientDisconnect(player);
    }
    bool Internal_OnClientConnect(uint32_t slot)
    {
        if (!OnClientConnect)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return false;

        return OnClientConnect(player);
    }
    void Internal_OnClientFullConnected(uint32_t slot)
    {
        if (OnClientFullConnected)
        {
            Player *player = g_playerManager->GetPlayer(slot);
            if (player == nullptr)
                return;

            OnClientFullConnected(player);
        }
    }
    void Internal_OnPlayerSpawn(uint32_t slot)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnPlayerSpawn)
            OnPlayerSpawn(player);
    }
    void Internal_OnPlayerPostThink(uint32_t slot)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnPlayerPostThink)
            OnPlayerPostThink(player);
    }
    bool Internal_OnPlayerPrePostThink(uint32_t slot)
    {
        if (!OnPlayerPrePostThink)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return true;

        return OnPlayerPrePostThink(player);
    }
    bool Internal_OnPlayerChat(uint32_t slot, const char *text, bool teamonly)
    {
        if (!OnPlayerChat)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return false;

        return OnPlayerChat(player, text, teamonly);
    }
    bool Internal_OnClientGameMessage(uint32_t slot, int destination, const char *message)
    {
        if (!OnClientGameMessage)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return true;

        return OnClientGameMessage(player, destination, message);
    }
    void Internal_RegisterPlayer(uint32_t slot, bool fakeClient)
    {
        g_playerManager->RegisterPlayer(new Player(slot, fakeClient));
    }
    void Internal_UnregisterPlayer(uint32_t slot)
    {
        g_playerManager->UnregisterPlayer(slot);
    }
    void Internal_OnItemPickup(uint32_t slot, const char *item, bool silent, long defindex)
    {
        if (!OnItemPickup)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnItemPickup(player, item, silent, defindex);
    }
    void Interval_OnEnterBuyzone(uint32_t slot, bool canbuy)
    {
        if (!OnEnterBuyzone)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnEnterBuyzone(player, canbuy);
    }
    void Interval_OnEnterBombzone(uint32_t slot, bool hasbomb, bool isplanted)
    {
        if (!OnEnterBombzone)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnEnterBombzone(player, hasbomb, isplanted);
    }
    void Interval_OnExitBombzone(uint32_t slot, bool hasbomb, bool isplanted)
    {
        if (!OnExitBombzone)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnExitBombzone(player, hasbomb, isplanted);
    }
    void Interval_OnExitBuyzone(uint32_t slot, bool canbuy)
    {
        if (!OnExitBuyzone)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnExitBuyzone(player, canbuy);
    }

    void Interval_OnRoundPostStart()
    {
        if (!OnRoundPostStart)
            return;

        OnRoundPostStart();
    }

    void Internal_OnGameTick(bool simulating, bool bFirstTick, bool bLastTick)
    {
        if (ThreadFunction)
            ThreadFunction();

        if (NextFrameHandler)
            NextFrameHandler();

        if (OnGameTick)
            OnGameTick(simulating, bFirstTick, bLastTick);
    }
    void Internal_OnPlayerFullUpdate(uint32_t slot, short count)
    {
        if (!OnPlayerFullUpdate)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnPlayerFullUpdate(player, count);
    }
    void Internal_OnRoundEnd(unsigned char winner, unsigned char reason, const char *message, unsigned char legacy, short player_count, unsigned char nomusic)
    {
        if (OnRoundEnd)
            OnRoundEnd(winner, reason, message, legacy, player_count, nomusic);
    }
    void Internal_OnRoundMVP(int slot, short reason, long value, long musickitmvps, unsigned char nomusic, long musickitid)
    {

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnRoundMVP)
            OnRoundMVP(player, reason, value, musickitmvps, nomusic, musickitid);
    }
    void Internal_OnRoundStart(long timelimit, long fraglimit, const char *objective)
    {
        if (OnRoundStart)
            OnRoundStart(timelimit, fraglimit, objective);
    }
    void Internal_OnRoundPrestart()
    {
        if (OnRoundPrestart)
            OnRoundPrestart();
    }

    void Internal_BombBeginPlant(uint32_t slot, uint16_t site)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnBombBeginPlant)
            OnBombBeginPlant(player, site);
        if (BombBeginPlant)
            BombBeginPlant(player, site);
    }

    void Internal_BombAbortPlant(uint32_t slot, uint16_t site)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnBombAbortPlant)
            OnBombAbortPlant(player, site);
        if (BombAbortPlant)
            BombAbortPlant(player, site);
    }

    void Internal_BombPlanted(uint32_t slot, uint16_t site)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnBombPlanted)
            OnBombPlanted(player, site);
        if (BombPlanted)
            BombPlanted(player, site);
    }

    void Internal_BombBeginDefuse(uint32_t slot, uint16_t site)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnBombBeginDefuse)
            OnBombBeginDefuse(player, site);
        if (BombBeginDefuse)
            BombBeginDefuse(player, site);
    }

    void Internal_BombAbortDefuse(uint32_t slot, uint16_t site)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnBombAbortDefuse)
            OnBombAbortDefuse(player, site);
        if (BombAbortDefuse)
            BombAbortDefuse(player, site);
    }

    void Internal_BombDefused(uint32_t slot, uint16_t site)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnBombDefused)
            OnBombDefused(player, site);
        if (BombDefused)
            BombDefused(player, site);
    }

    void Internal_BombExploded(uint32_t slot, uint16_t site)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnBombExploded)
            OnBombExploded(player, site);
        if (BombExploded)
            BombExploded(player, site);
    }

    void Internal_BombDropped(uint32_t slot)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnBombDropped)
            OnBombDropped(player);
        if (BombDropped)
            BombDropped(player);
    }

    void Internal_BombPickup(uint32_t slot)
    {
        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        if (OnBombPickup)
            OnBombPickup(player);
        if (BombPickup)
            BombPickup(player);
    }

    void Internal_OnMapLoad(const char *mapName)
    {
        if (OnMapLoad)
            OnMapLoad(mapName);
    }

    void Internal_OnMapUnload(const char *mapName)
    {
        if (OnMapUnload)
            OnMapUnload(mapName);
    }

    void Internal_OnPlayerDeath(int slot, int attacker, int assister, bool assistedflash, const char *weapon, bool headshot, short dominated, short revenge, short wipe, short penetrated, bool noreplay, bool noscope, bool thrusmoke, bool attackerblind, float distance, short dmg_health, short dmg_armor, short hitgroup)
    {
        if (!OnPlayerDeath)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        Player *attackerPlayer = nullptr, *assisterPlayer = nullptr;
        if (attacker != -1)
        {
            attackerPlayer = g_playerManager->GetPlayer(attacker);
            if (attackerPlayer == nullptr)
                return;
        }
        if (assister != -1)
        {
            assisterPlayer = g_playerManager->GetPlayer(assister);
            if (assisterPlayer == nullptr)
                return;
        }

        OnPlayerDeath(player, attackerPlayer, assisterPlayer, assistedflash, weapon, headshot, dominated, revenge, wipe, penetrated, noreplay, noscope, thrusmoke, attackerblind, distance, dmg_health, dmg_armor, hitgroup);
    }

    void Internal_OnPlayerBlind(int slot, int attacker, short entityid, float duration)
    {
        if (!OnPlayerBlind)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        Player *attackerPlayer = g_playerManager->GetPlayer(attacker);
        if (attackerPlayer == nullptr)
            return;

        OnPlayerBlind(player, attackerPlayer, entityid, duration);
    }

    void Internal_OnPlayerTeam(int slot, unsigned char team, unsigned char oldteam, bool disconnect, bool silent, bool isbot)
    {
        if (!OnPlayerTeam)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnPlayerTeam(player, team, oldteam, disconnect, silent, isbot);
    }

    void Interval_OnPlayerChangeName(int slot, const char *oldname, const char *newName)
    {
        if (!OnPlayerChangeName)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnPlayerChangeName(player, oldname, newName);
    }

    void Internal_OnPlayerInfo(const char *name, int slot, uint64_t steamid, bool bot)
    {
        if (!OnPlayerInfo)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnPlayerInfo(name, player, steamid, bot);
    }

    void Internal_OnPlayerFallDamage(int slot, float damage)
    {
        if (!OnPlayerFallDamage)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnPlayerFallDamage(player, damage);
    }

    void Internal_OnPlayerJump(int slot)
    {
        if (!OnPlayerJump)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        OnPlayerJump(player);
    }

    void Internal_OnPlayerHurt(int slot, int attacker, short dmgHealth, short dmgArmor, short hitgroup, const char *weapon)
    {
        if (!OnPlayerHurt)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return;

        Player *attackerPlayer = g_playerManager->GetPlayer(attacker);
        if (attackerPlayer == nullptr)
            return;

        OnPlayerHurt(player, attackerPlayer, dmgHealth, dmgArmor, hitgroup, weapon);
    }

    bool Internal_ShouldHearVoice(uint32_t slot)
    {
        if (!ShouldHearVoice)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return true;

        return ShouldHearVoice(player);
    }

    bool Internal_OnPlayerDamagePlayer(uint32_t slot, uint32_t attackerslot, float damage, uint32_t damagetype, uint8_t ammotype, uint32_t damageflags)
    {
        if (!OnPlayerDamagePlayer)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (player == nullptr)
            return true;

        Player *attacker = g_playerManager->GetPlayer(attackerslot);
        if (attacker == nullptr)
            return true;

        return OnPlayerDamagePlayer(player, attacker, damage, (DamageTypes)damagetype, ammotype, (DamageFlags)damageflags);
    }

    void Internal_OnWeaponSpawned(uint32_t slot, uint32_t weaponid)
    {
        if (!OnWeaponSpawned)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (!player)
            return;

        OnWeaponSpawned(player, player->weapons->GetWeapon(weaponid));
    }

    void Internal_OnClientKeyStateChange(uint32_t slot, const char *button, bool pressed)
    {
        if (!OnClientKeyStateChange)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (!player)
            return;

        OnClientKeyStateChange(player, button, pressed);
    }

    void Internal_OnClientExecuteCommand(uint32_t slot, const char *command)
    {
        if (!OnClientExecuteCommand)
            return;

        Player *player = g_playerManager->GetPlayer(slot);
        if (!player)
            return;

        OnClientExecuteCommand(player, command);
    }

    void Internal_OnServerCvarChange(const char *name, const char *value)
    {
        if (!OnServerCvarChange)
            return;

        OnServerCvarChange(name, value);
    }

    bool Internal_OnClientCommand(uint32_t slot, const char *command)
    {
        if (!OnClientCommand)
            return true;

        Player *player = g_playerManager->GetPlayer(slot);
        if (!player)
            return true;

        return OnClientCommand(player, command);
    }

    void Internal_OnServerPreshutdown(const char *reason)
    {
        if (!OnServerPreshutdown)
            return;
        OnServerPreshutdown(reason);
    }
    void Internal_OnServerShutdown(const char *reason)
    {
        if (!OnServerShutdown)
            return;
        OnServerShutdown(reason);
    }
    void Internal_OnServerMesssage(const char *text)
    {
        if (!OnServerMesssage)
            return;
        OnServerMesssage(text);
    }
    void Internal_OnPlayerActivate(int player_slot)
    {
        if (!OnPlayerActivate)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerActivate(player);
    }
    void Internal_OnLocalPlayerTeam()
    {
        if (!OnLocalPlayerTeam)
            return;
        OnLocalPlayerTeam();
    }
    void Internal_OnLocalPlayerControllerTeam()
    {
        if (!OnLocalPlayerControllerTeam)
            return;
        OnLocalPlayerControllerTeam();
    }
    void Internal_OnLocalPlayerPawnChanged()
    {
        if (!OnLocalPlayerPawnChanged)
            return;
        OnLocalPlayerPawnChanged();
    }
    void Internal_OnTeamplayBroadcastAudio(unsigned char team, const char *sound)
    {
        if (!OnTeamplayBroadcastAudio)
            return;
        OnTeamplayBroadcastAudio(team, sound);
    }
    void Internal_OnFinaleStart(short rushes)
    {
        if (!OnFinaleStart)
            return;
        OnFinaleStart(rushes);
    }
    void Internal_OnPlayerStatsUpdated(bool forceupload)
    {
        if (!OnPlayerStatsUpdated)
            return;
        OnPlayerStatsUpdated(forceupload);
    }
    void Internal_OnUserDataDownloaded()
    {
        if (!OnUserDataDownloaded)
            return;
        OnUserDataDownloaded();
    }
    void Internal_OnRagdollDissolved(long entindex)
    {
        if (!OnRagdollDissolved)
            return;
        OnRagdollDissolved(entindex);
    }
    void Internal_OnTeamInfo(unsigned char teamid, const char *teamname)
    {
        if (!OnTeamInfo)
            return;
        OnTeamInfo(teamid, teamname);
    }
    void Internal_OnTeamScore(unsigned char teamid, short score)
    {
        if (!OnTeamScore)
            return;
        OnTeamScore(teamid, score);
    }
    void Internal_OnHLTVCameraman(int player_slot)
    {
        if (!OnHLTVCameraman)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnHLTVCameraman(player);
    }
    void Internal_OnHLTVChase(int target1_slot, int target2_slot, short distance, short theta, short phi, unsigned char inertia, unsigned char ineye)
    {
        if (!OnHLTVChase)
            return;
        Player *target1 = g_playerManager->GetPlayer(target1_slot);
        if (target1 == nullptr)
            return;
        Player *target2 = g_playerManager->GetPlayer(target2_slot);
        if (target2 == nullptr)
            return;
        OnHLTVChase(target1, target2, distance, theta, phi, inertia, ineye);
    }
    void Internal_OnHLTVRankCamera(unsigned char index, float rank, int target_slot)
    {
        if (!OnHLTVRankCamera)
            return;
        Player *target = g_playerManager->GetPlayer(target_slot);
        if (target == nullptr)
            return;
        OnHLTVRankCamera(index, rank, target);
    }
    void Internal_OnHLTVRankEntity(int player_slot, float rank, int target_slot)
    {
        if (!OnHLTVRankEntity)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        Player *target = g_playerManager->GetPlayer(target_slot);
        if (target == nullptr)
            return;
        OnHLTVRankEntity(player, rank, target);
    }
    void Internal_OnHLTVFixed(long posx, long posy, long posz, short theta, short phi, short offset, float fov, int target_slot)
    {
        if (!OnHLTVFixed)
            return;
        Player *target = g_playerManager->GetPlayer(target_slot);
        if (target == nullptr)
            return;
        OnHLTVFixed(posx, posy, posz, theta, phi, offset, fov, target);
    }
    void Internal_OnHLTVMessage(const char *text)
    {
        if (!OnHLTVMessage)
            return;
        OnHLTVMessage(text);
    }
    void Internal_OnHLTVStatus(long clients, long slots, short proxies, const char *master)
    {
        if (!OnHLTVStatus)
            return;
        OnHLTVStatus(clients, slots, proxies, master);
    }
    void Internal_OnHLTVTitle(const char *text)
    {
        if (!OnHLTVTitle)
            return;
        OnHLTVTitle(text);
    }
    void Internal_OnHLTVChat(const char *text, uint64_t steamID)
    {
        if (!OnHLTVChat)
            return;
        OnHLTVChat(text, steamID);
    }
    void Internal_OnHLTVVersioninfo(long version)
    {
        if (!OnHLTVVersioninfo)
            return;
        OnHLTVVersioninfo(version);
    }
    void Internal_OnHLTVReplay(long delay, long reason)
    {
        if (!OnHLTVReplay)
            return;
        OnHLTVReplay(delay, reason);
    }
    void Internal_OnMapShutdown()
    {
        if (!OnMapShutdown)
            return;
        OnMapShutdown();
    }
    void Internal_OnMapTransition()
    {
        if (!OnMapTransition)
            return;
        OnMapTransition();
    }
    void Internal_OnHostnameChanged(const char *hostname)
    {
        if (!OnHostnameChanged)
            return;
        OnHostnameChanged(hostname);
    }
    void Internal_OnDifficultyChanged(short newDifficulty, short oldDifficulty, const char *strDifficulty)
    {
        if (!OnDifficultyChanged)
            return;
        OnDifficultyChanged(newDifficulty, oldDifficulty, strDifficulty);
    }
    void Internal_OnGameMessage(unsigned char target, const char *text)
    {
        if (!OnGameMessage)
            return;
        OnGameMessage(target, text);
    }
    void Internal_OnGameNewmap(const char *mapname)
    {
        if (!OnGameNewmap)
            return;
        OnGameNewmap(mapname);
    }
    void Internal_OnRoundStartPreEntity()
    {
        if (!OnRoundStartPreEntity)
            return;
        OnRoundStartPreEntity();
    }
    void Internal_OnRoundStartPostNav()
    {
        if (!OnRoundStartPostNav)
            return;
        OnRoundStartPostNav();
    }
    void Internal_OnRoundFreezeEnd()
    {
        if (!OnRoundFreezeEnd)
            return;
        OnRoundFreezeEnd();
    }
    void Internal_OnTeamplayRoundStart(bool full_reset)
    {
        if (!OnTeamplayRoundStart)
            return;
        OnTeamplayRoundStart(full_reset);
    }
    void Internal_OnPlayerFootstep(int player_slot)
    {
        if (!OnPlayerFootstep)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerFootstep(player);
    }
    void Internal_OnPlayerHintmessage(const char *hintmessage)
    {
        if (!OnPlayerHintmessage)
            return;
        OnPlayerHintmessage(hintmessage);
    }
    void Internal_OnBreakBreakable(long entindex, int player_slot, unsigned char material)
    {
        if (!OnBreakBreakable)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnBreakBreakable(entindex, player, material);
    }
    void Internal_OnBreakProp(long entindex, int player_slot)
    {
        if (!OnBreakProp)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnBreakProp(entindex, player);
    }
    void Internal_OnEntityKilled(long entindex_killed, long entindex_attacker, long entindex_inflictor, long damagebits)
    {
        if (!OnEntityKilled)
            return;
        OnEntityKilled(entindex_killed, entindex_attacker, entindex_inflictor, damagebits);
    }
    void Internal_OnDoorClose(int player_slot, bool checkpoint)
    {
        if (!OnDoorClose)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDoorClose(player, checkpoint);
    }
    void Internal_OnVoteStarted(const char *issue, const char *param1, unsigned char team, long initiator)
    {
        if (!OnVoteStarted)
            return;
        OnVoteStarted(issue, param1, team, initiator);
    }
    void Internal_OnVoteFailed(unsigned char team)
    {
        if (!OnVoteFailed)
            return;
        OnVoteFailed(team);
    }
    void Internal_OnVotePassed(const char *details, const char *param1, unsigned char team)
    {
        if (!OnVotePassed)
            return;
        OnVotePassed(details, param1, team);
    }
    void Internal_OnVoteChanged(unsigned char vote_option1, unsigned char vote_option2, unsigned char vote_option3, unsigned char vote_option4, unsigned char vote_option5, unsigned char potentialVotes)
    {
        if (!OnVoteChanged)
            return;
        OnVoteChanged(vote_option1, vote_option2, vote_option3, vote_option4, vote_option5, potentialVotes);
    }
    void Internal_OnVoteCastYes(unsigned char team, long entityid)
    {
        if (!OnVoteCastYes)
            return;
        OnVoteCastYes(team, entityid);
    }
    void Internal_OnVoteCastNo(unsigned char team, long entityid)
    {
        if (!OnVoteCastNo)
            return;
        OnVoteCastNo(team, entityid);
    }
    void Internal_OnAchievementEvent(const char *achievement_name, short cur_val, short max_val)
    {
        if (!OnAchievementEvent)
            return;
        OnAchievementEvent(achievement_name, cur_val, max_val);
    }
    void Internal_OnAchievementEarned(int player_slot, short achievement)
    {
        if (!OnAchievementEarned)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnAchievementEarned(player, achievement);
    }
    void Internal_OnAchievementWriteFailed()
    {
        if (!OnAchievementWriteFailed)
            return;
        OnAchievementWriteFailed();
    }
    void Internal_OnBonusUpdated(short numadvanced, short numbronze, short numsilver, short numgold)
    {
        if (!OnBonusUpdated)
            return;
        OnBonusUpdated(numadvanced, numbronze, numsilver, numgold);
    }
    void Internal_OnSpecTargetUpdated(int player_slot, long target)
    {
        if (!OnSpecTargetUpdated)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSpecTargetUpdated(player, target);
    }
    void Internal_OnSpecModeUpdated(int player_slot)
    {
        if (!OnSpecModeUpdated)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSpecModeUpdated(player);
    }
    void Internal_OnEntityVisible(int player_slot, short subject, const char *classname, const char *entityname)
    {
        if (!OnEntityVisible)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnEntityVisible(player, subject, classname, entityname);
    }
    void Internal_OnGameInstructorDraw()
    {
        if (!OnGameInstructorDraw)
            return;
        OnGameInstructorDraw();
    }
    void Internal_OnGameInstructorNodraw()
    {
        if (!OnGameInstructorNodraw)
            return;
        OnGameInstructorNodraw();
    }
    void Internal_OnFlareIgniteNCP(long entindex)
    {
        if (!OnFlareIgniteNCP)
            return;
        OnFlareIgniteNCP(entindex);
    }
    void Internal_OnHelicoptedGrenadePuntMiss()
    {
        if (!OnHelicoptedGrenadePuntMiss)
            return;
        OnHelicoptedGrenadePuntMiss();
    }
    void Internal_OnPhysgunPickup(long target)
    {
        if (!OnPhysgunPickup)
            return;
        OnPhysgunPickup(target);
    }
    void Internal_OnInventoryUpdated()
    {
        if (!OnInventoryUpdated)
            return;
        OnInventoryUpdated();
    }
    void Internal_OnCarUpdated()
    {
        if (!OnCarUpdated)
            return;
        OnCarUpdated();
    }
    void Internal_OnStorePricesheetUpdated()
    {
        if (!OnStorePricesheetUpdated)
            return;
        OnStorePricesheetUpdated();
    }
    void Internal_OnItemSchemaInitialized()
    {
        if (!OnItemSchemaInitialized)
            return;
        OnItemSchemaInitialized();
    }
    void Internal_OnDropRateModified()
    {
        if (!OnDropRateModified)
            return;
        OnDropRateModified();
    }
    void Internal_OnEventTicketModified()
    {
        if (!OnEventTicketModified)
            return;
        OnEventTicketModified();
    }
    void Internal_OnGCConnected()
    {
        if (!OnGCConnected)
            return;
        OnGCConnected();
    }
    void Internal_OnInstructorStartLesson(int player_slot, const char *hint_name, long hint_target, unsigned char vr_movement_type, bool vr_single_controller, unsigned char vr_controller_type)
    {
        if (!OnInstructorStartLesson)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnInstructorStartLesson(player, hint_name, hint_target, vr_movement_type, vr_single_controller, vr_controller_type);
    }
    void Internal_OnInstructorCloseLesson(int player_slot, const char *hint_name)
    {
        if (!OnInstructorCloseLesson)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnInstructorCloseLesson(player, hint_name);
    }
    void Internal_OnInstructorServerHintCreate(int player_slot, const char *hint_name, const char *hint_replace_key, long hint_target, int hint_activator_user_slot, short hint_timeout, const char *hint_icon_onscreen, const char *hint_icon_offscreen, const char *hint_caption, const char *hint_activator_caption, const char *hint_color, float hint_icon_offset, float hint_range, long hint_flags, const char *hint_binding, const char *hint_gamepad_binding, bool hint_allow_nodraw_target, bool hint_nooffscreen, bool hint_forcecaption, bool hint_local_player_only)
    {
        if (!OnInstructorServerHintCreate)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        Player *hint_activator_user = g_playerManager->GetPlayer(hint_activator_user_slot);
        if (hint_activator_user == nullptr)
            return;
        OnInstructorServerHintCreate(player, hint_name, hint_replace_key, hint_target, hint_activator_user, hint_timeout, hint_icon_onscreen, hint_icon_offscreen, hint_caption, hint_activator_caption, hint_color, hint_icon_offset, hint_range, hint_flags, hint_binding, hint_gamepad_binding, hint_allow_nodraw_target, hint_nooffscreen, hint_forcecaption, hint_local_player_only);
    }
    void Internal_OnClinetsideLessonClosed(const char *lesson_name)
    {
        if (!OnClinetsideLessonClosed)
            return;
        OnClinetsideLessonClosed(lesson_name);
    }
    void Internal_OnDynamicShadowLightChanged()
    {
        if (!OnDynamicShadowLightChanged)
            return;
        OnDynamicShadowLightChanged();
    }
    void Internal_OnGameuiHidden()
    {
        if (!OnGameuiHidden)
            return;
        OnGameuiHidden();
    }
    void Internal_OnItemsGifted(int player_slot, long itemdef, short numgifts, long giftidx, long accountid)
    {
        if (!OnItemsGifted)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnItemsGifted(player, itemdef, numgifts, giftidx, accountid);
    }
    void Internal_OnPlayerScore(int player_slot, short kills, short deaths, short score)
    {
        if (!OnPlayerScore)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerScore(player, kills, deaths, score);
    }
    void Internal_OnPlayerShoot(int player_slot, unsigned char weapon, unsigned char mode)
    {
        if (!OnPlayerShoot)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerShoot(player, weapon, mode);
    }
    void Internal_OnGameInit()
    {
        if (!OnGameInit)
            return;
        OnGameInit();
    }
    void Internal_OnGameStart(long roundslimit, long timelimit, long fraglimit, const char *objective)
    {
        if (!OnGameStart)
            return;
        OnGameStart(roundslimit, timelimit, fraglimit, objective);
    }
    void Internal_OnGameEnd(unsigned char winner)
    {
        if (!OnGameEnd)
            return;
        OnGameEnd(winner);
    }
    void Internal_OnRoundAnnounceMatchPoint()
    {
        if (!OnRoundAnnounceMatchPoint)
            return;
        OnRoundAnnounceMatchPoint();
    }
    void Internal_OnRoundAnnounceFinal()
    {
        if (!OnRoundAnnounceFinal)
            return;
        OnRoundAnnounceFinal();
    }
    void Internal_OnRoundAnnounceLastRoundHalf()
    {
        if (!OnRoundAnnounceLastRoundHalf)
            return;
        OnRoundAnnounceLastRoundHalf();
    }
    void Internal_OnRoundAnnouceMatchStart()
    {
        if (!OnRoundAnnouceMatchStart)
            return;
        OnRoundAnnouceMatchStart();
    }
    void Internal_OnRoundAnnounceWarmup()
    {
        if (!OnRoundAnnounceWarmup)
            return;
        OnRoundAnnounceWarmup();
    }
    void Internal_OnRoundEndUploadStats()
    {
        if (!OnRoundEndUploadStats)
            return;
        OnRoundEndUploadStats();
    }
    void Internal_OnRoundOfficiallyEnded()
    {
        if (!OnRoundOfficiallyEnded)
            return;
        OnRoundOfficiallyEnded();
    }
    void Internal_OnRoundTimeWarning()
    {
        if (!OnRoundTimeWarning)
            return;
        OnRoundTimeWarning();
    }
    void Internal_OnUGCMapInfoReceived(uint64_t published_file_id)
    {
        if (!OnUGCMapInfoReceived)
            return;
        OnUGCMapInfoReceived(published_file_id);
    }
    void Internal_OnUGCMapUnsubscribed(uint64_t published_file_id)
    {
        if (!OnUGCMapUnsubscribed)
            return;
        OnUGCMapUnsubscribed(published_file_id);
    }
    void Internal_OnUGCMapDownloadError(uint64_t published_file_id, long error_code)
    {
        if (!OnUGCMapDownloadError)
            return;
        OnUGCMapDownloadError(published_file_id, error_code);
    }
    void Internal_OnUGCFileDownloadFinished(uint64_t hcontent)
    {
        if (!OnUGCFileDownloadFinished)
            return;
        OnUGCFileDownloadFinished(hcontent);
    }
    void Internal_OnUGCFileDownloadStart(uint64_t hcontent, uint64_t published_file_id)
    {
        if (!OnUGCFileDownloadStart)
            return;
        OnUGCFileDownloadStart(hcontent, published_file_id);
    }
    void Internal_OnBeginNewMatch()
    {
        if (!OnBeginNewMatch)
            return;
        OnBeginNewMatch();
    }
    void Internal_OnDMBonusWeaponStart(short time, short Pos)
    {
        if (!OnDMBonusWeaponStart)
            return;
        OnDMBonusWeaponStart(time, Pos);
    }
    void Internal_OnSurvivalAnnouncePhase(short phase)
    {
        if (!OnSurvivalAnnouncePhase)
            return;
        OnSurvivalAnnouncePhase(phase);
    }
    void Internal_OnBrokenBreakable(long entindex, int player_slot, unsigned char material)
    {
        if (!OnBrokenBreakable)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnBrokenBreakable(entindex, player, material);
    }
    void Internal_OnPlayerDecal(int player_slot)
    {
        if (!OnPlayerDecal)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerDecal(player);
    }
    void Internal_OnSetInstructorGroupEnabled(const char *group, short enabled)
    {
        if (!OnSetInstructorGroupEnabled)
            return;
        OnSetInstructorGroupEnabled(group, enabled);
    }
    void Internal_OnInstructorServerHintStop(const char *hint_name)
    {
        if (!OnInstructorServerHintStop)
            return;
        OnInstructorServerHintStop(hint_name);
    }
    void Internal_OnReadGameTitledata(short controllerId)
    {
        if (!OnReadGameTitledata)
            return;
        OnReadGameTitledata(controllerId);
    }
    void Internal_OnWriteGameTitledata(short controllerId)
    {
        if (!OnWriteGameTitledata)
            return;
        OnWriteGameTitledata(controllerId);
    }
    void Internal_OnResetGameTitledata(short controllerId)
    {
        if (!OnResetGameTitledata)
            return;
        OnResetGameTitledata(controllerId);
    }
    void Internal_OnWeaponhudSelection(int player_slot, unsigned char mode, long entindex)
    {
        if (!OnWeaponhudSelection)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnWeaponhudSelection(player, mode, entindex);
    }
    void Internal_OnVoteEnded()
    {
        if (!OnVoteEnded)
            return;
        OnVoteEnded();
    }
    void Internal_OnVoteCast(unsigned char vote_option, short team, int player_slot)
    {
        if (!OnVoteCast)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnVoteCast(vote_option, team, player);
    }
    void Internal_OnVoteOptions(unsigned char count, const char *option1, const char *option2, const char *option3, const char *option4, const char *option5)
    {
        if (!OnVoteOptions)
            return;
        OnVoteOptions(count, option1, option2, option3, option4, option5);
    }
    void Internal_OnEndmatchMapvoteSelectingMap(unsigned char count, unsigned char slot1, unsigned char slot2, unsigned char slot3, unsigned char slot4, unsigned char slot5, unsigned char slot6, unsigned char slot7, unsigned char slot8, unsigned char slot9, unsigned char slot10)
    {
        if (!OnEndmatchMapvoteSelectingMap)
            return;
        OnEndmatchMapvoteSelectingMap(count, slot1, slot2, slot3, slot4, slot5, slot6, slot7, slot8, slot9, slot10);
    }
    void Internal_OnEndmatchCMMStartRevealItems()
    {
        if (!OnEndmatchCMMStartRevealItems)
            return;
        OnEndmatchCMMStartRevealItems();
    }
    void Internal_OnClientLoadoutChanged()
    {
        if (!OnClientLoadoutChanged)
            return;
        OnClientLoadoutChanged();
    }
    void Internal_OnAddPlayerSonarIcon(int player_slot, float pos_x, float pos_y, float pos_z)
    {
        if (!OnAddPlayerSonarIcon)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnAddPlayerSonarIcon(player, pos_x, pos_y, pos_z);
    }
    void Internal_OnAddBulletHitMarker(int player_slot, short bone, short pos_x, short pos_y, short pos_z, short ang_x, short ang_y, short ang_z, short start_x, short start_y, short start_z, bool hit)
    {
        if (!OnAddBulletHitMarker)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnAddBulletHitMarker(player, bone, pos_x, pos_y, pos_z, ang_x, ang_y, ang_z, start_x, start_y, start_z, hit);
    }
    void Internal_OnOtherDeath(short otherid, const char *othertype, short attacker, const char *weapon, const char *weapon_itemid, const char *weapon_fauxitemid, const char *weapon_originalowner_xuid, bool headshot, short penetrated, bool noscope, bool thrusmoke, bool attackerblind)
    {
        if (!OnOtherDeath)
            return;
        OnOtherDeath(otherid, othertype, attacker, weapon, weapon_itemid, weapon_fauxitemid, weapon_originalowner_xuid, headshot, penetrated, noscope, thrusmoke, attackerblind);
    }
    void Internal_OnItemPurchase(int player_slot, short team, short loadout, const char *weapon)
    {
        if (!OnItemPurchase)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnItemPurchase(player, team, loadout, weapon);
    }
    void Internal_OnDefuserDropped(long entityid)
    {
        if (!OnDefuserDropped)
            return;
        OnDefuserDropped(entityid);
    }
    void Internal_OnDefuserPickup(long entityid, int player_slot)
    {
        if (!OnDefuserPickup)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDefuserPickup(entityid, player);
    }
    void Internal_OnAnnouncePhaseEnd()
    {
        if (!OnAnnouncePhaseEnd)
            return;
        OnAnnouncePhaseEnd();
    }
    void Internal_OnCSIntermission()
    {
        if (!OnCSIntermission)
            return;
        OnCSIntermission();
    }
    void Internal_OnHostageFollows(int player_slot, short hostage)
    {
        if (!OnHostageFollows)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnHostageFollows(player, hostage);
    }
    void Internal_OnHostageHurt(int player_slot, short hostage)
    {
        if (!OnHostageHurt)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnHostageHurt(player, hostage);
    }
    void Internal_OnHostageKilled(int player_slot, short hostage)
    {
        if (!OnHostageKilled)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnHostageKilled(player, hostage);
    }
    void Internal_OnHostageRescued(int player_slot, short hostage, short site)
    {
        if (!OnHostageRescued)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnHostageRescued(player, hostage, site);
    }
    void Internal_OnHostageStopsFollowing(int player_slot, short hostage)
    {
        if (!OnHostageStopsFollowing)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnHostageStopsFollowing(player, hostage);
    }
    void Internal_OnHostageRescuedAll()
    {
        if (!OnHostageRescuedAll)
            return;
        OnHostageRescuedAll();
    }
    void Internal_OnHostageCallForHelp(short hostage)
    {
        if (!OnHostageCallForHelp)
            return;
        OnHostageCallForHelp(hostage);
    }
    void Internal_OnVIPEscaped(int player_slot)
    {
        if (!OnVIPEscaped)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnVIPEscaped(player);
    }
    void Internal_OnVIPKilled(int player_slot, int attacker_slot)
    {
        if (!OnVIPKilled)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        Player *attacker = g_playerManager->GetPlayer(attacker_slot);
        if (attacker == nullptr)
            return;
        OnVIPKilled(player, attacker);
    }
    void Internal_OnPlayerRadio(int player_slot, short slot)
    {
        if (!OnPlayerRadio)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerRadio(player, slot);
    }
    void Internal_OnBombBeep(long entindex)
    {
        if (!OnBombBeep)
            return;
        OnBombBeep(entindex);
    }
    void Internal_OnWeaponFire(int player_slot, const char *weapon, bool silenced)
    {
        if (!OnWeaponFire)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnWeaponFire(player, weapon, silenced);
    }
    void Internal_OnWeaponFireOnEmpty(int player_slot, const char *weapon)
    {
        if (!OnWeaponFireOnEmpty)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnWeaponFireOnEmpty(player, weapon);
    }
    void Internal_OnGrenadeThrown(int player_slot, const char *weapon)
    {
        if (!OnGrenadeThrown)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnGrenadeThrown(player, weapon);
    }
    void Internal_OnWeaponOutOfAmmo(int player_slot)
    {
        if (!OnWeaponOutOfAmmo)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnWeaponOutOfAmmo(player);
    }
    void Internal_OnWeaponReload(int player_slot)
    {
        if (!OnWeaponReload)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnWeaponReload(player);
    }
    void Internal_OnWeaponZoom(int player_slot)
    {
        if (!OnWeaponZoom)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnWeaponZoom(player);
    }
    void Internal_OnSilencerDetach(int player_slot)
    {
        if (!OnSilencerDetach)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSilencerDetach(player);
    }
    void Internal_OnInspectWeapon(int player_slot)
    {
        if (!OnInspectWeapon)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnInspectWeapon(player);
    }
    void Internal_OnWeaponZoomRifle(int player_slot)
    {
        if (!OnWeaponZoomRifle)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnWeaponZoomRifle(player);
    }
    void Internal_OnPlayerSpawned(int player_slot, bool inrestart)
    {
        if (!OnPlayerSpawned)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerSpawned(player, inrestart);
    }
    void Internal_OnItemPickupSlerp(int player_slot, short index, short behavior)
    {
        if (!OnItemPickupSlerp)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnItemPickupSlerp(player, index, behavior);
    }
    void Internal_OnItemPickupFailed(int player_slot, const char *item, short reason, short limit)
    {
        if (!OnItemPickupFailed)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnItemPickupFailed(player, item, reason, limit);
    }
    void Internal_OnItemRemove(int player_slot, const char *item, long defindex)
    {
        if (!OnItemRemove)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnItemRemove(player, item, defindex);
    }
    void Internal_OnAmmoPickup(int player_slot, const char *item, long index)
    {
        if (!OnAmmoPickup)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnAmmoPickup(player, item, index);
    }
    void Internal_OnItemEquip(int player_slot, const char *item, long defindex, bool canzoom, bool hassilencer, bool issilenced, bool hastracers, short weptype, bool ispainted)
    {
        if (!OnItemEquip)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnItemEquip(player, item, defindex, canzoom, hassilencer, issilenced, hastracers, weptype, ispainted);
    }
    void Internal_OnBuytimeEnded()
    {
        if (!OnBuytimeEnded)
            return;
        OnBuytimeEnded();
    }
    void Internal_OnEnterRescueZone(int player_slot)
    {
        if (!OnEnterRescueZone)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnEnterRescueZone(player);
    }
    void Internal_OnExitRescueZone(int player_slot)
    {
        if (!OnExitRescueZone)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnExitRescueZone(player);
    }
    void Internal_OnSilencerOff(int player_slot)
    {
        if (!OnSilencerOff)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSilencerOff(player);
    }
    void Internal_OnSilencerOn(int player_slot)
    {
        if (!OnSilencerOn)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSilencerOn(player);
    }
    void Internal_OnBuyMenuOpen(int player_slot)
    {
        if (!OnBuyMenuOpen)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnBuyMenuOpen(player);
    }
    void Internal_OnBuyMenuClose(int player_slot)
    {
        if (!OnBuyMenuClose)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnBuyMenuClose(player);
    }
    void Internal_OnGrenadeBounce(int player_slot)
    {
        if (!OnGrenadeBounce)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnGrenadeBounce(player);
    }
    void Internal_OnHEGrenadeDetonate(int player_slot, short entityid, float x, float y, float z)
    {
        if (!OnHEGrenadeDetonate)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnHEGrenadeDetonate(player, entityid, x, y, z);
    }
    void Internal_OnFlashbangDetonate(int player_slot, short entityid, float x, float y, float z)
    {
        if (!OnFlashbangDetonate)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnFlashbangDetonate(player, entityid, x, y, z);
    }
    void Internal_OnSmokeGrenadeDetonate(int player_slot, short entityid, float x, float y, float z)
    {
        if (!OnSmokeGrenadeDetonate)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSmokeGrenadeDetonate(player, entityid, x, y, z);
    }
    void Internal_OnSmokeGrenadeExpired(int player_slot, short entityid, float x, float y, float z)
    {
        if (!OnSmokeGrenadeExpired)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSmokeGrenadeExpired(player, entityid, x, y, z);
    }
    void Internal_OnMolotovDetonate(int player_slot, float x, float y, float z)
    {
        if (!OnMolotovDetonate)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnMolotovDetonate(player, x, y, z);
    }
    void Internal_OnDecoyDetonate(int player_slot, short entityid, float x, float y, float z)
    {
        if (!OnDecoyDetonate)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDecoyDetonate(player, entityid, x, y, z);
    }
    void Internal_OnDecoyStarted(int player_slot, short entityid, float x, float y, float z)
    {
        if (!OnDecoyStarted)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDecoyStarted(player, entityid, x, y, z);
    }
    void Internal_OnTagrenadeDetonate(int player_slot, short entityid, float x, float y, float z)
    {
        if (!OnTagrenadeDetonate)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnTagrenadeDetonate(player, entityid, x, y, z);
    }
    void Internal_OnInfernoStartBurn(short entityid, float x, float y, float z)
    {
        if (!OnInfernoStartBurn)
            return;
        OnInfernoStartBurn(entityid, x, y, z);
    }
    void Internal_OnInfernoExpire(short entityid, float x, float y, float z)
    {
        if (!OnInfernoExpire)
            return;
        OnInfernoExpire(entityid, x, y, z);
    }
    void Internal_OnInfernoExtinguish(short entityid, float x, float y, float z)
    {
        if (!OnInfernoExtinguish)
            return;
        OnInfernoExtinguish(entityid, x, y, z);
    }
    void Internal_OnDecoyFiring(int player_slot, short entityid, float x, float y, float z)
    {
        if (!OnDecoyFiring)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDecoyFiring(player, entityid, x, y, z);
    }
    void Internal_OnBulletImpact(int player_slot, float x, float y, float z)
    {
        if (!OnBulletImpact)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnBulletImpact(player, x, y, z);
    }
    void Internal_OnDoorMoving(int player_slot, long entindex)
    {
        if (!OnDoorMoving)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDoorMoving(player, entindex);
    }
    void Internal_OnMBInputLockSuccess()
    {
        if (!OnMBInputLockSuccess)
            return;
        OnMBInputLockSuccess();
    }
    void Internal_OnMBInputLockCancel()
    {
        if (!OnMBInputLockCancel)
            return;
        OnMBInputLockCancel();
    }
    void Internal_OnNavBlocked(long area, bool blocked)
    {
        if (!OnNavBlocked)
            return;
        OnNavBlocked(area, blocked);
    }
    void Internal_OnNavGenerate()
    {
        if (!OnNavGenerate)
            return;
        OnNavGenerate();
    }
    void Internal_OnAchievementInfoLoaded()
    {
        if (!OnAchievementInfoLoaded)
            return;
        OnAchievementInfoLoaded();
    }
    void Internal_OnHLTVChangedMode(long oldmode, long newmode, long obs_target)
    {
        if (!OnHLTVChangedMode)
            return;
        OnHLTVChangedMode(oldmode, newmode, obs_target);
    }
    void Internal_OnCSGameDisconnected()
    {
        if (!OnCSGameDisconnected)
            return;
        OnCSGameDisconnected();
    }
    void Internal_OnCSRoundFinalBeep()
    {
        if (!OnCSRoundFinalBeep)
            return;
        OnCSRoundFinalBeep();
    }
    void Internal_OnCSRoundStartBeep()
    {
        if (!OnCSRoundStartBeep)
            return;
        OnCSRoundStartBeep();
    }
    void Internal_OnCSWinPanelRound(bool show_timer_defend, bool show_timer_attack, short timer_time, unsigned char final_event, const char *funfact_token, int funfact_player_slot, long funfact_data1, long funfact_data2, long funfact_data3)
    {
        if (!OnCSWinPanelRound)
            return;
        Player *funfact_player = g_playerManager->GetPlayer(funfact_player_slot);
        if (funfact_player == nullptr)
            return;
        OnCSWinPanelRound(show_timer_defend, show_timer_attack, timer_time, final_event, funfact_token, funfact_player, funfact_data1, funfact_data2, funfact_data3);
    }
    void Internal_OnCSWinPanelMatch()
    {
        if (!OnCSWinPanelMatch)
            return;
        OnCSWinPanelMatch();
    }
    void Internal_OnCSMatchEndRestart()
    {
        if (!OnCSMatchEndRestart)
            return;
        OnCSMatchEndRestart();
    }
    void Internal_OnCSPreRestart()
    {
        if (!OnCSPreRestart)
            return;
        OnCSPreRestart();
    }
    void Internal_OnShowDeathpanel(int victim_slot, long killer, int killer_controller_slot, short hits_taken, short damage_taken, short hits_given, short damage_given)
    {
        if (!OnShowDeathpanel)
            return;
        Player *victim = g_playerManager->GetPlayer(victim_slot);
        if (victim == nullptr)
            return;
        Player *killer_controller = g_playerManager->GetPlayer(killer_controller_slot);
        if (killer_controller == nullptr)
            return;
        OnShowDeathpanel(victim, killer, killer_controller, hits_taken, damage_taken, hits_given, damage_given);
    }
    void Internal_OnHideDeathpanel()
    {
        if (!OnHideDeathpanel)
            return;
        OnHideDeathpanel();
    }
    void Internal_OnAchievementEarnedLocal(short achievement, short splitscreenplayer)
    {
        if (!OnAchievementEarnedLocal)
            return;
        OnAchievementEarnedLocal(achievement, splitscreenplayer);
    }
    void Internal_OnRepostXboxAchievements(short splitscreenplayer)
    {
        if (!OnRepostXboxAchievements)
            return;
        OnRepostXboxAchievements(splitscreenplayer);
    }
    void Internal_OnMatchEndConditions(long frags, long max_rounds, long win_rounds, long time)
    {
        if (!OnMatchEndConditions)
            return;
        OnMatchEndConditions(frags, max_rounds, win_rounds, time);
    }
    void Internal_OnShowSurvivalRespawnStatus(const char *loc_token, long duration, int player_slot)
    {
        if (!OnShowSurvivalRespawnStatus)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnShowSurvivalRespawnStatus(loc_token, duration, player);
    }
    void Internal_OnGGKilledEnemy(int victim_slot, int attacker_slot, short dominated, short revenge, bool bonus)
    {
        if (!OnGGKilledEnemy)
            return;
        Player *victim = g_playerManager->GetPlayer(victim_slot);
        if (victim == nullptr)
            return;
        Player *attacker = g_playerManager->GetPlayer(attacker_slot);
        if (attacker == nullptr)
            return;
        OnGGKilledEnemy(victim, attacker, dominated, revenge, bonus);
    }
    void Internal_OnSwitchTeam(short numPlayers, short numSpectators, short avg_rank, short numTSlotsFree, short numCTSlotsFree)
    {
        if (!OnSwitchTeam)
            return;
        OnSwitchTeam(numPlayers, numSpectators, avg_rank, numTSlotsFree, numCTSlotsFree);
    }
    void Internal_OnWriteProfileData()
    {
        if (!OnWriteProfileData)
            return;
        OnWriteProfileData();
    }
    void Internal_OnTrialTimeExpired(int player_slot)
    {
        if (!OnTrialTimeExpired)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnTrialTimeExpired(player);
    }
    void Internal_OnUpdateMatchmakingStats()
    {
        if (!OnUpdateMatchmakingStats)
            return;
        OnUpdateMatchmakingStats();
    }
    void Internal_OnPlayerResetVote(int player_slot, bool vote)
    {
        if (!OnPlayerResetVote)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerResetVote(player, vote);
    }
    void Internal_OnEnableRestartVoting(bool enable)
    {
        if (!OnEnableRestartVoting)
            return;
        OnEnableRestartVoting(enable);
    }
    void Internal_OnSfuievent(const char *action, const char *data, unsigned char slot)
    {
        if (!OnSfuievent)
            return;
        OnSfuievent(action, data, slot);
    }
    void Internal_OnStartVote(int player_slot, unsigned char type, short vote_parameter)
    {
        if (!OnStartVote)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnStartVote(player, type, vote_parameter);
    }
    void Internal_OnPlayerGivenBomb(int player_slot)
    {
        if (!OnPlayerGivenBomb)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerGivenBomb(player);
    }
    void Internal_OnTRPlayerFlashbanged(int player_slot)
    {
        if (!OnTRPlayerFlashbanged)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnTRPlayerFlashbanged(player);
    }
    void Internal_OnTRMarkComplete(short complete)
    {
        if (!OnTRMarkComplete)
            return;
        OnTRMarkComplete(complete);
    }
    void Internal_OnTRMarkBestTime(long time)
    {
        if (!OnTRMarkBestTime)
            return;
        OnTRMarkBestTime(time);
    }
    void Internal_OnTRExitHintTrigger()
    {
        if (!OnTRExitHintTrigger)
            return;
        OnTRExitHintTrigger();
    }
    void Internal_OnBotTakeover(int player_slot, int bot_slot)
    {
        if (!OnBotTakeover)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        Player *bot = g_playerManager->GetPlayer(bot_slot);
        if (bot == nullptr)
            return;
        OnBotTakeover(player, bot);
    }
    void Internal_OnTRShowFinishMsgbox()
    {
        if (!OnTRShowFinishMsgbox)
            return;
        OnTRShowFinishMsgbox();
    }
    void Internal_OnTRShowExitMsgbox()
    {
        if (!OnTRShowExitMsgbox)
            return;
        OnTRShowExitMsgbox();
    }
    void Internal_OnJoinTeamFailed(int player_slot, unsigned char reason)
    {
        if (!OnJoinTeamFailed)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnJoinTeamFailed(player, reason);
    }
    void Internal_OnTeamChangePending(int player_slot, unsigned char toteam)
    {
        if (!OnTeamChangePending)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnTeamChangePending(player, toteam);
    }
    void Internal_OnMaterialDefaultComplete()
    {
        if (!OnMaterialDefaultComplete)
            return;
        OnMaterialDefaultComplete();
    }
    void Internal_OnCSPrevNextSpectator(bool next)
    {
        if (!OnCSPrevNextSpectator)
            return;
        OnCSPrevNextSpectator(next);
    }
    void Internal_OnNextLevelChanged(const char *nextlevel, const char *mapgroup, const char *skirmishmode)
    {
        if (!OnNextLevelChanged)
            return;
        OnNextLevelChanged(nextlevel, mapgroup, skirmishmode);
    }
    void Internal_OnSeasoncoinLevelup(int player_slot, short category, short rank)
    {
        if (!OnSeasoncoinLevelup)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSeasoncoinLevelup(player, category, rank);
    }
    void Internal_OnTournamentReward(long defindex, long totalrewards, long accountid)
    {
        if (!OnTournamentReward)
            return;
        OnTournamentReward(defindex, totalrewards, accountid);
    }
    void Internal_OnStartHalftime()
    {
        if (!OnStartHalftime)
            return;
        OnStartHalftime();
    }
    void Internal_OnAmmoRefill(int player_slot, bool success)
    {
        if (!OnAmmoRefill)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnAmmoRefill(player, success);
    }
    void Internal_OnParachutePickup(int player_slot)
    {
        if (!OnParachutePickup)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnParachutePickup(player);
    }
    void Internal_OnParachuteDeploy(int player_slot)
    {
        if (!OnParachuteDeploy)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnParachuteDeploy(player);
    }
    void Internal_OnDronegunAttack(int player_slot)
    {
        if (!OnDronegunAttack)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDronegunAttack(player);
    }
    void Internal_OnDroneDispatched(int player_slot, short priority, short drone_dispatched)
    {
        if (!OnDroneDispatched)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDroneDispatched(player, priority, drone_dispatched);
    }
    void Internal_OnLootCrateVisible(int player_slot, short subject, const char *type)
    {
        if (!OnLootCrateVisible)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnLootCrateVisible(player, subject, type);
    }
    void Internal_OnLootCrateOpened(int player_slot, const char *type)
    {
        if (!OnLootCrateOpened)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnLootCrateOpened(player, type);
    }
    void Internal_OnOpenCrateInstructions(int player_slot, short subject, const char *type)
    {
        if (!OnOpenCrateInstructions)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnOpenCrateInstructions(player, subject, type);
    }
    void Internal_OnSmokeBeaconParadrop(int player_slot, short paradrop)
    {
        if (!OnSmokeBeaconParadrop)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSmokeBeaconParadrop(player, paradrop);
    }
    void Internal_OnSurvivalParadropSpawn(short entityid)
    {
        if (!OnSurvivalParadropSpawn)
            return;
        OnSurvivalParadropSpawn(entityid);
    }
    void Internal_OnSurvivalParadropBreak(short entityid)
    {
        if (!OnSurvivalParadropBreak)
            return;
        OnSurvivalParadropBreak(entityid);
    }
    void Internal_OnDroneCargoDetached(int player_slot, short cargo, bool delivered)
    {
        if (!OnDroneCargoDetached)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDroneCargoDetached(player, cargo, delivered);
    }
    void Internal_OnDroneAboveRoof(int player_slot, short cargo)
    {
        if (!OnDroneAboveRoof)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDroneAboveRoof(player, cargo);
    }
    void Internal_OnChoppersIncomingWarning(bool global)
    {
        if (!OnChoppersIncomingWarning)
            return;
        OnChoppersIncomingWarning(global);
    }
    void Internal_OnFirstbombsIncomingWarning(bool global)
    {
        if (!OnFirstbombsIncomingWarning)
            return;
        OnFirstbombsIncomingWarning(global);
    }
    void Internal_OnDZItemInteraction(int player_slot, short subject, const char *type)
    {
        if (!OnDZItemInteraction)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDZItemInteraction(player, subject, type);
    }
    void Internal_OnSurvivalTeammateRespawn(int player_slot)
    {
        if (!OnSurvivalTeammateRespawn)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSurvivalTeammateRespawn(player);
    }
    void Internal_OnSurvivalNoRespawnsWarning(int player_slot)
    {
        if (!OnSurvivalNoRespawnsWarning)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSurvivalNoRespawnsWarning(player);
    }
    void Internal_OnSurvivalNoRespawnsFinal(int player_slot)
    {
        if (!OnSurvivalNoRespawnsFinal)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnSurvivalNoRespawnsFinal(player);
    }
    void Internal_OnPlayerPing(int player_slot, short entityid, float x, float y, float z, bool urgent)
    {
        if (!OnPlayerPing)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerPing(player, entityid, x, y, z, urgent);
    }
    void Internal_OnPlayerPingStop(short entityid)
    {
        if (!OnPlayerPingStop)
            return;
        OnPlayerPingStop(entityid);
    }
    void Internal_OnPlayerSound(int player_slot, long radius, float duration, bool step)
    {
        if (!OnPlayerSound)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnPlayerSound(player, radius, duration, step);
    }
    void Internal_OnGuardianWaveRestart()
    {
        if (!OnGuardianWaveRestart)
            return;
        OnGuardianWaveRestart();
    }
    void Internal_OnTeamIntroStart()
    {
        if (!OnTeamIntroStart)
            return;
        OnTeamIntroStart();
    }
    void Internal_OnTeamIntroEnd()
    {
        if (!OnTeamIntroEnd)
            return;
        OnTeamIntroEnd();
    }
    void Internal_OnBulletFlightResolution(int player_slot, short pos_x, short pos_y, short pos_z, short ang_x, short ang_y, short ang_z, short start_x, short start_y, short start_z)
    {
        if (!OnBulletFlightResolution)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnBulletFlightResolution(player, pos_x, pos_y, pos_z, ang_x, ang_y, ang_z, start_x, start_y, start_z);
    }
    void Internal_OnDoorBreak(long entindex, long dmgstate)
    {
        if (!OnDoorBreak)
            return;
        OnDoorBreak(entindex, dmgstate);
    }
    void Internal_OnDoorClosed(int player_slot, long entindex)
    {
        if (!OnDoorClosed)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDoorClosed(player, entindex);
    }
    void Internal_OnDoorOpen(int player_slot, long entindex)
    {
        if (!OnDoorOpen)
            return;
        Player *player = g_playerManager->GetPlayer(player_slot);
        if (player == nullptr)
            return;
        OnDoorOpen(player, entindex);
    }
    void Internal_OnGamePhaseChanged(short new_phase)
    {
        if (!OnGamePhaseChanged)
            return;
        OnGamePhaseChanged(new_phase);
    }
    void Internal_OnHLTVReplayStatus(long reason)
    {
        if (!OnHLTVReplayStatus)
            return;
        OnHLTVReplayStatus(reason);
    }

    const char *GetPluginAuthor();
    const char *GetPluginVersion();
    const char *GetPluginName();
    const char *GetPluginWebsite();
}

#endif
