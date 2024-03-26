#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

#include <rapidjson/document.h>

class LuaPlayerClass
{
public:
    int playerSlot;
    bool fakeClient;

    LuaPlayerClass(int m_playerSlot, bool m_fakeClient) : playerSlot(m_playerSlot), fakeClient(m_fakeClient) {}
};

class LuaPlayerArgsClass
{
public:
    int playerSlot;

    LuaPlayerArgsClass(int m_playerSlot) : playerSlot(m_playerSlot) {}
};

class LuaPlayerTwoArgsClass
{
public:
    int playerSlot;
    uint32 slot;

    LuaPlayerTwoArgsClass(int m_playerSlot, uint32 m_slot) : playerSlot(m_playerSlot), slot(m_slot) {}
};

void SetupLuaPlayer(luacpp::LuaState *state, Plugin *plugin)
{
    auto playerClass = state->CreateClass<LuaPlayerClass>("Player").DefConstructor<int, bool>();

    auto healthClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto armorClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto clantagClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto teamClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto varsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto statsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto moneyClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto coordsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto velocityClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto weaponsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto gravityClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto speedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto eyeangleClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto fovClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto weaponClass = state->CreateClass<LuaPlayerTwoArgsClass>().DefConstructor<int, uint32>();
    auto autokickdisabledClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto availableentitysteadystateClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto predictClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto tickbaseClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lerptimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastrealcommandnumberexecutedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastplayertalktimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastlatecommandexecutedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastentitysteadystateClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lagcompensationClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto islowviolenceClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto ishltvClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hasanysteadystateentsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto gamepausedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto highestgeneratedserverviewanglechangeindexClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hidehudClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto inithudClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hltvreplaydelayClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hltvreplayendClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto characterdefindexClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hasfemalevoiceClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto inhostageresetzoneClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto inbuyzoneClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto wasinbuyzoneClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto inhostagerescuezoneClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto inbombzoneClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto wasinhostagerescuezoneClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto retakesofferingClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto retakesofferingcardClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto retakeshasdefusekitClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto retakesmvplastroundClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto retakesmvpboostitemClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto landsecondsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto aimpunchtickbaseClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto aimpunchtickfractionClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto isbuymenuopenClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastheadbonetransformisvalidClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastlandtimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto ongroundlasttickClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto playerlockedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto timeoflastinjuryClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto nextspraydecaltimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto nextspraydecaltimeexpeditedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto ragdolldamageboneClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto ragdolldamageheadshotClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto econgloveschangedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto skiponeheadconstraintupdateClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hascommunicationabusemuteClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto pendingteamnumClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto forceteamtimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto compteammatecolorClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto everplayedonteamClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto attemptedtogetcolorClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto teammatepreferredcolorClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto teamchangedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto inswitchteamClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hasseenjoingameClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto justbecamespectatorClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto switchteamsonnextroundresetClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto removeallitemsonnextroundresetClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto competitiverankingpredicted_winClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto competitiverankingpredicted_lossClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto competitiverankingpredicted_tieClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto endmatchnextmapvoteClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto activequestidClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto playertvcontrolflagsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto draftindexClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto queuedmodedisconnectiontimestampClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto abandonrecordedreasonClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto cannotbekickedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto everfullyconnectedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto abandonallowssurrenderClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto abandonoffersinstantsurrenderClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto disconnection1minwarningprintedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto scorereportedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto disconnectiontickClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto controllingbotClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hascontrolledbotthisroundClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hasbeencontrolledbyplayerthisroundClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto botscontrolledthisroundClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto cancontrolobservedbotClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto desiredobservermodeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto pawncharacterdefindexClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto pawnlifetimestartClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto pawnlifetimeendClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto pawnbotdifficultyClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto scoreClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto roundscoreClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto roundswonClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto mvpsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto updatecounterClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto showhintsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto nexttimecheckClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto justdidteamkillClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto punishforteamkillClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto gaveteamdamagewarningClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto gaveteamdamagewarningthisroundClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastreceivedpacketplatfloattimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastteamdamagewarningtimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lasttimeplayerwasdisconnectedforpawnsremoveClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto suspicioushitcountClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto nonsuspicioushitstreakClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto displayhistorybitsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastattackedteammateClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto blinduntiltimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto blindstarttimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto allowautofollowtimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto spotrulesClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto playerstateClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastdistancetravelednoticeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto accumulateddistancetraveledClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastfriendlyfiredamagereductionratioClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto respawningClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastpickuppriorityClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastpickupprioritytimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto isscopedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto iswalkingClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto resumezoomClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto isdefusingClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto isgrabbinghostageClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto blockinguseactioninprogressClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto immunetogungamedamagetimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto gungameimmunityClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto molotovdamagetimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hasmovedsincespawnClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto canmoveduringfreezeperiodClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto guardiantoofardistfracClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto nextguardiantoofarhurttimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto detectedbyenemysensortimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto dealtdamagetoenemymostrecenttimestampClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastequippedhelmettimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastequippedarmortimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto heavyassaultsuitcooldownremainingClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto resetarmornextspawnClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastbumpminebumptimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto emitsoundtimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto numspawnsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto shouldhavecashClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto invalidsteamlogondelayedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastactionClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastgivendefusertimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastgivenbombtimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hasnightvisionClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto nightvisiononClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto nextradarupdatetimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastmoneyupdatetimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto introcamtimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto innodefuseareaClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto killedbytaserClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto movestateClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto grenadeparameterstashtimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto grenadeparametersstashedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto diedairborneClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto whichbombzoneClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto inbombzonetriggerClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto wasinbombzonetriggerClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto directionClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto shotsfiredClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto flinchstackClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hitheadingClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hitbodypartClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hostageskilledClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto flashmaxalphaClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto progressbarstarttimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto progressbardurationClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto waitfornoattackClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lowerbodyyawtargetClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto strafingClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto ignoreladderjumptimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto slopedropoffsetClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto slopedropheightClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastweaponfireusercmdClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto vcollisioninittedClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto isspawningClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hidetargetidClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto numdangerzonedamagehitsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hud_miniscorehiddenClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hud_radarhiddenClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastconcurrentkilledClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto deathcammusicClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto addonbitsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto primaryaddonClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto secondaryaddonClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto numenemieskilledthisspawnClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto numenemieskilledthisroundClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto numenemiesatroundstartClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto wasnotkillednaturallyClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto deathflagsClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto currentequipmentvalueClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto roundstartequipmentvalueClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto freezetimeendequipmentvalueClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto survivalteamnumberClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto hasdeathinfoClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto deathinfotimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto killedbyheadshotClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lasthitboxClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lasthealthClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastcollisionceilingClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto lastcollisionceilingchangetimeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto botallowactiveClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();
    auto committingsuicideonteamchangeClass = state->CreateClass<LuaPlayerArgsClass>().DefConstructor<int>();

    playerClass.DefMember("GetSteamID", [](LuaPlayerClass *base) -> uint64_t
                          { return scripting_Player_GetSteamID(base->playerSlot); })
        .DefMember("GetSteamID2", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetSteamID2(base->playerSlot); })
        .DefMember("GetName", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetName(base->playerSlot); })
        .DefMember("SetName", [](LuaPlayerClass *base, const char *name) -> void
                   { scripting_Player_SetName(base->playerSlot, name); })
        .DefMember("GetHealth", [](LuaPlayerClass *base) -> int
                   { return scripting_Player_GetHealth(base->playerSlot); })
        .DefMember("GetIPAddress", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetIPAddress(base->playerSlot); })
        .DefMember("IsFirstSpawn", [](LuaPlayerClass *base) -> bool
                   { return scripting_Player_IsFirstSpawn(base->playerSlot); })
        .DefMember("ShowMenu", [](LuaPlayerClass *base, const char *menuid) -> void
                   { scripting_Player_ShowMenu(base->playerSlot, menuid); })
        .DefMember("GetChatTag", [](LuaPlayerClass *base) -> const char *
                   { return scripting_Player_GetChatTag(base->playerSlot); })
        .DefMember("SetChatTag", [](LuaPlayerClass *base, const char *tag) -> void
                   { scripting_Player_SetChatTag(base->playerSlot, tag); })
        .DefMember("SetCompetitiveRanking", [](LuaPlayerClass *base, int ranking) -> void
                   { scripting_Player_SetCompetitiveRanking(base->playerSlot, ranking); })
        .DefMember("SetCompetitiveRankType", [](LuaPlayerClass *base, int type) -> void
                   { scripting_Player_SetCompetitiveRankType(base->playerSlot, type); })
        .DefMember("SetChatTagColor", [](LuaPlayerClass *base, const char *color) -> void
                   { scripting_Player_SetChatTagColor(base->playerSlot, color); })
        .DefMember("SetNameColor", [](LuaPlayerClass *base, const char *color) -> void
                   { scripting_Player_SetNameColor(base->playerSlot, color); })
        .DefMember("SetChatColor", [](LuaPlayerClass *base, const char *color) -> void
                   { scripting_Player_SetChatColor(base->playerSlot, color); })
        .DefMember("HideMenu", [](LuaPlayerClass *base) -> void
                   { scripting_Player_HideMenu(base->playerSlot); })
        .DefMember("GetConnectedTime", [](LuaPlayerClass *base) -> uint32_t
                   { return scripting_Player_GetConnectedTime(base->playerSlot); })
        .DefMember("SendMsg", [](LuaPlayerClass *base, int dest, const char *message) -> void
                   { return scripting_Player_SendMessage(base->playerSlot, dest, message); })
        .DefMember("SetGloves", [](LuaPlayerClass *base, uint16_t defindex, int paintkit, int seed, float wear) -> void
                   { scripting_Player_SetGloves(base->playerSlot, defindex, paintkit, seed, wear); })
        .DefMember("GetConvarValue", [](LuaPlayerClass *base, const char *name) -> const char *
                   { return scripting_Player_GetConvar(base->playerSlot, name); })
        .DefMember("SetConvar", [](LuaPlayerClass *base, const char *name, const char *value) -> void
                   { scripting_Player_SetConvar(base->playerSlot, name, value); })
        .DefMember("SetFlashDuration", [](LuaPlayerClass *base, float duration) -> void
                   { scripting_Player_SetFlashDuration(base->playerSlot, duration); })
        .DefMember("IsAuthenticated", [](LuaPlayerClass *base) -> bool
                   { return scripting_Player_IsAuthenticated(base->playerSlot); })
        .DefMember("Kill", [](LuaPlayerClass *base) -> void
                   { scripting_Player_Kill(base->playerSlot); })
        .DefMember("Drop", [](LuaPlayerClass *base, int reason) -> void
                   { scripting_Player_Drop(base->playerSlot, reason); })
        .DefMember("IsFakeClient", [](LuaPlayerClass *base) -> bool
                   { return base->fakeClient; })
        .DefMember("GetLatency", [](LuaPlayerClass *base) -> int
                   { return scripting_Player_GetLatency(base->playerSlot); })
        .DefMember("GetSlot", [](LuaPlayerClass *base) -> int
                   { return base->playerSlot; })
        .DefMember("ExecuteCommand", [](LuaPlayerClass *base, const char *command) -> void
                   { scripting_Player_ExecuteCommand(base->playerSlot, command); })
        .DefMember("SetModel", [](LuaPlayerClass *base, const char *model) -> void
                   { scripting_Player_SetModel(base->playerSlot, model); })
        .DefMember("SetMusicKit", [](LuaPlayerClass *base, int musickit) -> void
                   { scripting_Player_SetMusicKit(base->playerSlot, musickit); })
        .DefMember("Respawn", [](LuaPlayerClass *base) -> void
                   { scripting_Player_Respawn(base->playerSlot); })
        .DefMember("SetHealthShotBoostEffectExpirationTime", [](LuaPlayerClass *base, float expireTime) -> void
                   { scripting_Player_SetHealthShotBoostEffectExpirationTime(base->playerSlot, expireTime); })
        .DefMember("health", [healthClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return healthClass.CreateInstance(base->playerSlot); })
        .DefMember("armor", [armorClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return armorClass.CreateInstance(base->playerSlot); })
        .DefMember("clantag", [clantagClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return clantagClass.CreateInstance(base->playerSlot); })
        .DefMember("team", [teamClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return teamClass.CreateInstance(base->playerSlot); })
        .DefMember("vars", [varsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return varsClass.CreateInstance(base->playerSlot); })
        .DefMember("stats", [statsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return statsClass.CreateInstance(base->playerSlot); })
        .DefMember("money", [moneyClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return moneyClass.CreateInstance(base->playerSlot); })
        .DefMember("coords", [coordsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return coordsClass.CreateInstance(base->playerSlot); })
        .DefMember("velocity", [velocityClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return velocityClass.CreateInstance(base->playerSlot); })
        .DefMember("weapons", [weaponsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return weaponsClass.CreateInstance(base->playerSlot); })
        .DefMember("gravity", [gravityClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return gravityClass.CreateInstance(base->playerSlot); })
        .DefMember("speed", [speedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return speedClass.CreateInstance(base->playerSlot); })
        .DefMember("eyeangle", [eyeangleClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return eyeangleClass.CreateInstance(base->playerSlot); })
        .DefMember("autokickdisabled", [autokickdisabledClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return autokickdisabledClass.CreateInstance(base->playerSlot); })
        .DefMember("availableentitysteadystate", [availableentitysteadystateClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return availableentitysteadystateClass.CreateInstance(base->playerSlot); })
        .DefMember("predict", [predictClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return predictClass.CreateInstance(base->playerSlot); })
        .DefMember("gamepaused", [gamepausedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return gamepausedClass.CreateInstance(base->playerSlot); })
        .DefMember("tickbase", [tickbaseClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return tickbaseClass.CreateInstance(base->playerSlot); })
        .DefMember("hasanysteadystateents", [hasanysteadystateentsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hasanysteadystateentsClass.CreateInstance(base->playerSlot); })
        .DefMember("ishltv", [ishltvClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return ishltvClass.CreateInstance(base->playerSlot); })
        .DefMember("islowviolence", [islowviolenceClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return islowviolenceClass.CreateInstance(base->playerSlot); })
        .DefMember("lagcompensation", [lagcompensationClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lagcompensationClass.CreateInstance(base->playerSlot); })
        .DefMember("lastentitysteadystate", [lastentitysteadystateClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastentitysteadystateClass.CreateInstance(base->playerSlot); })
        .DefMember("lastlatecommandexecuted", [lastlatecommandexecutedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastlatecommandexecutedClass.CreateInstance(base->playerSlot); })
        .DefMember("lastplayertalktime", [lastplayertalktimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastplayertalktimeClass.CreateInstance(base->playerSlot); })
        .DefMember("lastrealcommandnumberexecuted", [lastrealcommandnumberexecutedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastrealcommandnumberexecutedClass.CreateInstance(base->playerSlot); })
        .DefMember("lerptime", [lerptimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lerptimeClass.CreateInstance(base->playerSlot); })
        .DefMember("highestgeneratedserverviewanglechangeindex", [highestgeneratedserverviewanglechangeindexClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return highestgeneratedserverviewanglechangeindexClass.CreateInstance(base->playerSlot); })
        .DefMember("hidehud", [hidehudClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hidehudClass.CreateInstance(base->playerSlot); })
        .DefMember("inithud", [inithudClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return inithudClass.CreateInstance(base->playerSlot); })
        .DefMember("hltvreplaydelay", [hltvreplaydelayClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hltvreplaydelayClass.CreateInstance(base->playerSlot); })
        .DefMember("hltvreplayend", [hltvreplayendClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hltvreplayendClass.CreateInstance(base->playerSlot); })
        .DefMember("characterdefindex", [characterdefindexClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return characterdefindexClass.CreateInstance(base->playerSlot); })
        .DefMember("hasfemalevoice", [hasfemalevoiceClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hasfemalevoiceClass.CreateInstance(base->playerSlot); })
        .DefMember("inhostageresetzone", [inhostageresetzoneClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return inhostageresetzoneClass.CreateInstance(base->playerSlot); })
        .DefMember("inbuyzone", [inbuyzoneClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return inbuyzoneClass.CreateInstance(base->playerSlot); })
        .DefMember("wasinbuyzone", [wasinbuyzoneClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return wasinbuyzoneClass.CreateInstance(base->playerSlot); })
        .DefMember("inhostagerescuezone", [inhostagerescuezoneClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return inhostagerescuezoneClass.CreateInstance(base->playerSlot); })
        .DefMember("inbombzone", [inbombzoneClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return inbombzoneClass.CreateInstance(base->playerSlot); })
        .DefMember("wasinhostagerescuezone", [wasinhostagerescuezoneClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return wasinhostagerescuezoneClass.CreateInstance(base->playerSlot); })
        .DefMember("retakesoffering", [retakesofferingClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return retakesofferingClass.CreateInstance(base->playerSlot); })
        .DefMember("retakesofferingcard", [retakesofferingcardClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return retakesofferingcardClass.CreateInstance(base->playerSlot); })
        .DefMember("retakeshasdefusekit", [retakeshasdefusekitClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return retakeshasdefusekitClass.CreateInstance(base->playerSlot); })
        .DefMember("retakesmvplastround", [retakesmvplastroundClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return retakesmvplastroundClass.CreateInstance(base->playerSlot); })
        .DefMember("retakesmvpboostitem", [retakesmvpboostitemClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return retakesmvpboostitemClass.CreateInstance(base->playerSlot); })
        .DefMember("landseconds", [landsecondsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return landsecondsClass.CreateInstance(base->playerSlot); })
        .DefMember("aimpunchtickbase", [aimpunchtickbaseClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return aimpunchtickbaseClass.CreateInstance(base->playerSlot); })
        .DefMember("aimpunchtickfraction", [aimpunchtickfractionClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return aimpunchtickfractionClass.CreateInstance(base->playerSlot); })
        .DefMember("isbuymenuopen", [isbuymenuopenClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return isbuymenuopenClass.CreateInstance(base->playerSlot); })
        .DefMember("lastheadbonetransformisvalid", [lastheadbonetransformisvalidClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastheadbonetransformisvalidClass.CreateInstance(base->playerSlot); })
        .DefMember("lastlandtime", [lastlandtimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastlandtimeClass.CreateInstance(base->playerSlot); })
        .DefMember("ongroundlasttick", [ongroundlasttickClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return ongroundlasttickClass.CreateInstance(base->playerSlot); })
        .DefMember("playerlocked", [playerlockedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return playerlockedClass.CreateInstance(base->playerSlot); })
        .DefMember("timeoflastinjury", [timeoflastinjuryClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return timeoflastinjuryClass.CreateInstance(base->playerSlot); })
        .DefMember("nextspraydecaltime", [nextspraydecaltimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return nextspraydecaltimeClass.CreateInstance(base->playerSlot); })
        .DefMember("nextspraydecaltimeexpedited", [nextspraydecaltimeexpeditedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return nextspraydecaltimeexpeditedClass.CreateInstance(base->playerSlot); })
        .DefMember("ragdolldamagebone", [ragdolldamageboneClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return ragdolldamageboneClass.CreateInstance(base->playerSlot); })
        .DefMember("ragdolldamageheadshot", [ragdolldamageheadshotClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return ragdolldamageheadshotClass.CreateInstance(base->playerSlot); })
        .DefMember("econgloveschanged", [econgloveschangedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return econgloveschangedClass.CreateInstance(base->playerSlot); })
        .DefMember("skiponeheadconstraintupdate", [skiponeheadconstraintupdateClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return skiponeheadconstraintupdateClass.CreateInstance(base->playerSlot); })
        .DefMember("hascommunicationabusemute", [hascommunicationabusemuteClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hascommunicationabusemuteClass.CreateInstance(base->playerSlot); })
        .DefMember("pendingteamnum", [pendingteamnumClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return pendingteamnumClass.CreateInstance(base->playerSlot); })
        .DefMember("forceteamtime", [forceteamtimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return forceteamtimeClass.CreateInstance(base->playerSlot); })
        .DefMember("compteammatecolor", [compteammatecolorClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return compteammatecolorClass.CreateInstance(base->playerSlot); })
        .DefMember("everplayedonteam", [everplayedonteamClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return everplayedonteamClass.CreateInstance(base->playerSlot); })
        .DefMember("attemptedtogetcolor", [attemptedtogetcolorClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return attemptedtogetcolorClass.CreateInstance(base->playerSlot); })
        .DefMember("teammatepreferredcolor", [teammatepreferredcolorClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return teammatepreferredcolorClass.CreateInstance(base->playerSlot); })
        .DefMember("teamchanged", [teamchangedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return teamchangedClass.CreateInstance(base->playerSlot); })
        .DefMember("inswitchteam", [inswitchteamClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return inswitchteamClass.CreateInstance(base->playerSlot); })
        .DefMember("hasseenjoingame", [hasseenjoingameClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hasseenjoingameClass.CreateInstance(base->playerSlot); })
        .DefMember("justbecamespectator", [justbecamespectatorClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return justbecamespectatorClass.CreateInstance(base->playerSlot); })
        .DefMember("switchteamsonnextroundreset", [switchteamsonnextroundresetClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return switchteamsonnextroundresetClass.CreateInstance(base->playerSlot); })
        .DefMember("removeallitemsonnextroundreset", [removeallitemsonnextroundresetClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return removeallitemsonnextroundresetClass.CreateInstance(base->playerSlot); })
        .DefMember("competitiverankingpredicted_win", [competitiverankingpredicted_winClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return competitiverankingpredicted_winClass.CreateInstance(base->playerSlot); })
        .DefMember("competitiverankingpredicted_loss", [competitiverankingpredicted_lossClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return competitiverankingpredicted_lossClass.CreateInstance(base->playerSlot); })
        .DefMember("competitiverankingpredicted_tie", [competitiverankingpredicted_tieClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return competitiverankingpredicted_tieClass.CreateInstance(base->playerSlot); })
        .DefMember("endmatchnextmapvote", [endmatchnextmapvoteClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return endmatchnextmapvoteClass.CreateInstance(base->playerSlot); })
        .DefMember("activequestid", [activequestidClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return activequestidClass.CreateInstance(base->playerSlot); })
        .DefMember("playertvcontrolflags", [playertvcontrolflagsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return playertvcontrolflagsClass.CreateInstance(base->playerSlot); })
        .DefMember("draftindex", [draftindexClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return draftindexClass.CreateInstance(base->playerSlot); })
        .DefMember("queuedmodedisconnectiontimestamp", [queuedmodedisconnectiontimestampClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return queuedmodedisconnectiontimestampClass.CreateInstance(base->playerSlot); })
        .DefMember("abandonrecordedreason", [abandonrecordedreasonClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return abandonrecordedreasonClass.CreateInstance(base->playerSlot); })
        .DefMember("cannotbekicked", [cannotbekickedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return cannotbekickedClass.CreateInstance(base->playerSlot); })
        .DefMember("everfullyconnected", [everfullyconnectedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return everfullyconnectedClass.CreateInstance(base->playerSlot); })
        .DefMember("abandonallowssurrender", [abandonallowssurrenderClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return abandonallowssurrenderClass.CreateInstance(base->playerSlot); })
        .DefMember("abandonoffersinstantsurrender", [abandonoffersinstantsurrenderClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return abandonoffersinstantsurrenderClass.CreateInstance(base->playerSlot); })
        .DefMember("disconnection1minwarningprinted", [disconnection1minwarningprintedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return disconnection1minwarningprintedClass.CreateInstance(base->playerSlot); })
        .DefMember("scorereported", [scorereportedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return scorereportedClass.CreateInstance(base->playerSlot); })
        .DefMember("disconnectiontick", [disconnectiontickClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return disconnectiontickClass.CreateInstance(base->playerSlot); })
        .DefMember("controllingbot", [controllingbotClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return controllingbotClass.CreateInstance(base->playerSlot); })
        .DefMember("hascontrolledbotthisround", [hascontrolledbotthisroundClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hascontrolledbotthisroundClass.CreateInstance(base->playerSlot); })
        .DefMember("hasbeencontrolledbyplayerthisround", [hasbeencontrolledbyplayerthisroundClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hasbeencontrolledbyplayerthisroundClass.CreateInstance(base->playerSlot); })
        .DefMember("botscontrolledthisround", [botscontrolledthisroundClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return botscontrolledthisroundClass.CreateInstance(base->playerSlot); })
        .DefMember("cancontrolobservedbot", [cancontrolobservedbotClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return cancontrolobservedbotClass.CreateInstance(base->playerSlot); })
        .DefMember("desiredobservermode", [desiredobservermodeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return desiredobservermodeClass.CreateInstance(base->playerSlot); })
        .DefMember("pawncharacterdefindex", [pawncharacterdefindexClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return pawncharacterdefindexClass.CreateInstance(base->playerSlot); })
        .DefMember("pawnlifetimestart", [pawnlifetimestartClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return pawnlifetimestartClass.CreateInstance(base->playerSlot); })
        .DefMember("pawnlifetimeend", [pawnlifetimeendClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return pawnlifetimeendClass.CreateInstance(base->playerSlot); })
        .DefMember("pawnbotdifficulty", [pawnbotdifficultyClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return pawnbotdifficultyClass.CreateInstance(base->playerSlot); })
        .DefMember("score", [scoreClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return scoreClass.CreateInstance(base->playerSlot); })
        .DefMember("roundscore", [roundscoreClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return roundscoreClass.CreateInstance(base->playerSlot); })
        .DefMember("roundswon", [roundswonClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return roundswonClass.CreateInstance(base->playerSlot); })
        .DefMember("mvps", [mvpsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return mvpsClass.CreateInstance(base->playerSlot); })
        .DefMember("updatecounter", [updatecounterClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return updatecounterClass.CreateInstance(base->playerSlot); })
        .DefMember("showhints", [showhintsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return showhintsClass.CreateInstance(base->playerSlot); })
        .DefMember("nexttimecheck", [nexttimecheckClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return nexttimecheckClass.CreateInstance(base->playerSlot); })
        .DefMember("justdidteamkill", [justdidteamkillClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return justdidteamkillClass.CreateInstance(base->playerSlot); })
        .DefMember("punishforteamkill", [punishforteamkillClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return punishforteamkillClass.CreateInstance(base->playerSlot); })
        .DefMember("gaveteamdamagewarning", [gaveteamdamagewarningClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return gaveteamdamagewarningClass.CreateInstance(base->playerSlot); })
        .DefMember("gaveteamdamagewarningthisround", [gaveteamdamagewarningthisroundClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return gaveteamdamagewarningthisroundClass.CreateInstance(base->playerSlot); })
        .DefMember("lastreceivedpacketplatfloattime", [lastreceivedpacketplatfloattimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastreceivedpacketplatfloattimeClass.CreateInstance(base->playerSlot); })
        .DefMember("lastteamdamagewarningtime", [lastteamdamagewarningtimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastteamdamagewarningtimeClass.CreateInstance(base->playerSlot); })
        .DefMember("lasttimeplayerwasdisconnectedforpawnsremove", [lasttimeplayerwasdisconnectedforpawnsremoveClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lasttimeplayerwasdisconnectedforpawnsremoveClass.CreateInstance(base->playerSlot); })
        .DefMember("suspicioushitcount", [suspicioushitcountClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return suspicioushitcountClass.CreateInstance(base->playerSlot); })
        .DefMember("nonsuspicioushitstreak", [nonsuspicioushitstreakClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return nonsuspicioushitstreakClass.CreateInstance(base->playerSlot); })
        .DefMember("displayhistorybits", [displayhistorybitsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return displayhistorybitsClass.CreateInstance(base->playerSlot); })
        .DefMember("lastattackedteammate", [lastattackedteammateClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastattackedteammateClass.CreateInstance(base->playerSlot); })
        .DefMember("blinduntiltime", [blinduntiltimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return blinduntiltimeClass.CreateInstance(base->playerSlot); })
        .DefMember("blindstarttime", [blindstarttimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return blindstarttimeClass.CreateInstance(base->playerSlot); })
        .DefMember("allowautofollowtime", [allowautofollowtimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return allowautofollowtimeClass.CreateInstance(base->playerSlot); })
        .DefMember("spotrules", [spotrulesClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return spotrulesClass.CreateInstance(base->playerSlot); })
        .DefMember("playerstate", [playerstateClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return playerstateClass.CreateInstance(base->playerSlot); })
        .DefMember("lastdistancetravelednotice", [lastdistancetravelednoticeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastdistancetravelednoticeClass.CreateInstance(base->playerSlot); })
        .DefMember("accumulateddistancetraveled", [accumulateddistancetraveledClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return accumulateddistancetraveledClass.CreateInstance(base->playerSlot); })
        .DefMember("lastfriendlyfiredamagereductionratio", [lastfriendlyfiredamagereductionratioClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastfriendlyfiredamagereductionratioClass.CreateInstance(base->playerSlot); })
        .DefMember("respawning", [respawningClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return respawningClass.CreateInstance(base->playerSlot); })
        .DefMember("lastpickuppriority", [lastpickuppriorityClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastpickuppriorityClass.CreateInstance(base->playerSlot); })
        .DefMember("lastpickupprioritytime", [lastpickupprioritytimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastpickupprioritytimeClass.CreateInstance(base->playerSlot); })
        .DefMember("isscoped", [isscopedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return isscopedClass.CreateInstance(base->playerSlot); })
        .DefMember("iswalking", [iswalkingClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return iswalkingClass.CreateInstance(base->playerSlot); })
        .DefMember("resumezoom", [resumezoomClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return resumezoomClass.CreateInstance(base->playerSlot); })
        .DefMember("isdefusing", [isdefusingClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return isdefusingClass.CreateInstance(base->playerSlot); })
        .DefMember("isgrabbinghostage", [isgrabbinghostageClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return isgrabbinghostageClass.CreateInstance(base->playerSlot); })
        .DefMember("blockinguseactioninprogress", [blockinguseactioninprogressClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return blockinguseactioninprogressClass.CreateInstance(base->playerSlot); })
        .DefMember("immunetogungamedamagetime", [immunetogungamedamagetimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return immunetogungamedamagetimeClass.CreateInstance(base->playerSlot); })
        .DefMember("gungameimmunity", [gungameimmunityClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return gungameimmunityClass.CreateInstance(base->playerSlot); })
        .DefMember("molotovdamagetime", [molotovdamagetimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return molotovdamagetimeClass.CreateInstance(base->playerSlot); })
        .DefMember("hasmovedsincespawn", [hasmovedsincespawnClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hasmovedsincespawnClass.CreateInstance(base->playerSlot); })
        .DefMember("canmoveduringfreezeperiod", [canmoveduringfreezeperiodClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return canmoveduringfreezeperiodClass.CreateInstance(base->playerSlot); })
        .DefMember("guardiantoofardistfrac", [guardiantoofardistfracClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return guardiantoofardistfracClass.CreateInstance(base->playerSlot); })
        .DefMember("nextguardiantoofarhurttime", [nextguardiantoofarhurttimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return nextguardiantoofarhurttimeClass.CreateInstance(base->playerSlot); })
        .DefMember("detectedbyenemysensortime", [detectedbyenemysensortimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return detectedbyenemysensortimeClass.CreateInstance(base->playerSlot); })
        .DefMember("dealtdamagetoenemymostrecenttimestamp", [dealtdamagetoenemymostrecenttimestampClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return dealtdamagetoenemymostrecenttimestampClass.CreateInstance(base->playerSlot); })
        .DefMember("lastequippedhelmettime", [lastequippedhelmettimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastequippedhelmettimeClass.CreateInstance(base->playerSlot); })
        .DefMember("lastequippedarmortime", [lastequippedarmortimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastequippedarmortimeClass.CreateInstance(base->playerSlot); })
        .DefMember("heavyassaultsuitcooldownremaining", [heavyassaultsuitcooldownremainingClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return heavyassaultsuitcooldownremainingClass.CreateInstance(base->playerSlot); })
        .DefMember("resetarmornextspawn", [resetarmornextspawnClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return resetarmornextspawnClass.CreateInstance(base->playerSlot); })
        .DefMember("lastbumpminebumptime", [lastbumpminebumptimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastbumpminebumptimeClass.CreateInstance(base->playerSlot); })
        .DefMember("emitsoundtime", [emitsoundtimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return emitsoundtimeClass.CreateInstance(base->playerSlot); })
        .DefMember("numspawns", [numspawnsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return numspawnsClass.CreateInstance(base->playerSlot); })
        .DefMember("shouldhavecash", [shouldhavecashClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return shouldhavecashClass.CreateInstance(base->playerSlot); })
        .DefMember("invalidsteamlogondelayed", [invalidsteamlogondelayedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return invalidsteamlogondelayedClass.CreateInstance(base->playerSlot); })
        .DefMember("lastaction", [lastactionClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastactionClass.CreateInstance(base->playerSlot); })
        .DefMember("lastgivendefusertime", [lastgivendefusertimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastgivendefusertimeClass.CreateInstance(base->playerSlot); })
        .DefMember("lastgivenbombtime", [lastgivenbombtimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastgivenbombtimeClass.CreateInstance(base->playerSlot); })
        .DefMember("hasnightvision", [hasnightvisionClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hasnightvisionClass.CreateInstance(base->playerSlot); })
        .DefMember("nightvisionon", [nightvisiononClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return nightvisiononClass.CreateInstance(base->playerSlot); })
        .DefMember("nextradarupdatetime", [nextradarupdatetimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return nextradarupdatetimeClass.CreateInstance(base->playerSlot); })
        .DefMember("lastmoneyupdatetime", [lastmoneyupdatetimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastmoneyupdatetimeClass.CreateInstance(base->playerSlot); })
        .DefMember("introcamtime", [introcamtimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return introcamtimeClass.CreateInstance(base->playerSlot); })
        .DefMember("innodefusearea", [innodefuseareaClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return innodefuseareaClass.CreateInstance(base->playerSlot); })
        .DefMember("killedbytaser", [killedbytaserClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return killedbytaserClass.CreateInstance(base->playerSlot); })
        .DefMember("movestate", [movestateClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return movestateClass.CreateInstance(base->playerSlot); })
        .DefMember("grenadeparameterstashtime", [grenadeparameterstashtimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return grenadeparameterstashtimeClass.CreateInstance(base->playerSlot); })
        .DefMember("grenadeparametersstashed", [grenadeparametersstashedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return grenadeparametersstashedClass.CreateInstance(base->playerSlot); })
        .DefMember("diedairborne", [diedairborneClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return diedairborneClass.CreateInstance(base->playerSlot); })
        .DefMember("whichbombzone", [whichbombzoneClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return whichbombzoneClass.CreateInstance(base->playerSlot); })
        .DefMember("inbombzonetrigger", [inbombzonetriggerClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return inbombzonetriggerClass.CreateInstance(base->playerSlot); })
        .DefMember("wasinbombzonetrigger", [wasinbombzonetriggerClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return wasinbombzonetriggerClass.CreateInstance(base->playerSlot); })
        .DefMember("direction", [directionClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return directionClass.CreateInstance(base->playerSlot); })
        .DefMember("shotsfired", [shotsfiredClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return shotsfiredClass.CreateInstance(base->playerSlot); })
        .DefMember("flinchstack", [flinchstackClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return flinchstackClass.CreateInstance(base->playerSlot); })
        .DefMember("hitheading", [hitheadingClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hitheadingClass.CreateInstance(base->playerSlot); })
        .DefMember("hitbodypart", [hitbodypartClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hitbodypartClass.CreateInstance(base->playerSlot); })
        .DefMember("hostageskilled", [hostageskilledClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hostageskilledClass.CreateInstance(base->playerSlot); })
        .DefMember("flashmaxalpha", [flashmaxalphaClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return flashmaxalphaClass.CreateInstance(base->playerSlot); })
        .DefMember("progressbarstarttime", [progressbarstarttimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return progressbarstarttimeClass.CreateInstance(base->playerSlot); })
        .DefMember("progressbarduration", [progressbardurationClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return progressbardurationClass.CreateInstance(base->playerSlot); })
        .DefMember("waitfornoattack", [waitfornoattackClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return waitfornoattackClass.CreateInstance(base->playerSlot); })
        .DefMember("lowerbodyyawtarget", [lowerbodyyawtargetClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lowerbodyyawtargetClass.CreateInstance(base->playerSlot); })
        .DefMember("strafing", [strafingClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return strafingClass.CreateInstance(base->playerSlot); })
        .DefMember("ignoreladderjumptime", [ignoreladderjumptimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return ignoreladderjumptimeClass.CreateInstance(base->playerSlot); })
        .DefMember("slopedropoffset", [slopedropoffsetClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return slopedropoffsetClass.CreateInstance(base->playerSlot); })
        .DefMember("slopedropheight", [slopedropheightClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return slopedropheightClass.CreateInstance(base->playerSlot); })
        .DefMember("lastweaponfireusercmd", [lastweaponfireusercmdClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastweaponfireusercmdClass.CreateInstance(base->playerSlot); })
        .DefMember("vcollisioninitted", [vcollisioninittedClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return vcollisioninittedClass.CreateInstance(base->playerSlot); })
        .DefMember("isspawning", [isspawningClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return isspawningClass.CreateInstance(base->playerSlot); })
        .DefMember("hidetargetid", [hidetargetidClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hidetargetidClass.CreateInstance(base->playerSlot); })
        .DefMember("numdangerzonedamagehits", [numdangerzonedamagehitsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return numdangerzonedamagehitsClass.CreateInstance(base->playerSlot); })
        .DefMember("hud_miniscorehidden", [hud_miniscorehiddenClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hud_miniscorehiddenClass.CreateInstance(base->playerSlot); })
        .DefMember("hud_radarhidden", [hud_radarhiddenClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hud_radarhiddenClass.CreateInstance(base->playerSlot); })
        .DefMember("lastconcurrentkilled", [lastconcurrentkilledClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastconcurrentkilledClass.CreateInstance(base->playerSlot); })
        .DefMember("deathcammusic", [deathcammusicClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return deathcammusicClass.CreateInstance(base->playerSlot); })
        .DefMember("addonbits", [addonbitsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return addonbitsClass.CreateInstance(base->playerSlot); })
        .DefMember("primaryaddon", [primaryaddonClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return primaryaddonClass.CreateInstance(base->playerSlot); })
        .DefMember("secondaryaddon", [secondaryaddonClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return secondaryaddonClass.CreateInstance(base->playerSlot); })
        .DefMember("numenemieskilledthisspawn", [numenemieskilledthisspawnClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return numenemieskilledthisspawnClass.CreateInstance(base->playerSlot); })
        .DefMember("numenemieskilledthisround", [numenemieskilledthisroundClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return numenemieskilledthisroundClass.CreateInstance(base->playerSlot); })
        .DefMember("numenemiesatroundstart", [numenemiesatroundstartClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return numenemiesatroundstartClass.CreateInstance(base->playerSlot); })
        .DefMember("wasnotkillednaturally", [wasnotkillednaturallyClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return wasnotkillednaturallyClass.CreateInstance(base->playerSlot); })
        .DefMember("deathflags", [deathflagsClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return deathflagsClass.CreateInstance(base->playerSlot); })
        .DefMember("currentequipmentvalue", [currentequipmentvalueClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return currentequipmentvalueClass.CreateInstance(base->playerSlot); })
        .DefMember("roundstartequipmentvalue", [roundstartequipmentvalueClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return roundstartequipmentvalueClass.CreateInstance(base->playerSlot); })
        .DefMember("freezetimeendequipmentvalue", [freezetimeendequipmentvalueClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return freezetimeendequipmentvalueClass.CreateInstance(base->playerSlot); })
        .DefMember("survivalteamnumber", [survivalteamnumberClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return survivalteamnumberClass.CreateInstance(base->playerSlot); })
        .DefMember("hasdeathinfo", [hasdeathinfoClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return hasdeathinfoClass.CreateInstance(base->playerSlot); })
        .DefMember("deathinfotime", [deathinfotimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return deathinfotimeClass.CreateInstance(base->playerSlot); })
        .DefMember("killedbyheadshot", [killedbyheadshotClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return killedbyheadshotClass.CreateInstance(base->playerSlot); })
        .DefMember("lasthitbox", [lasthitboxClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lasthitboxClass.CreateInstance(base->playerSlot); })
        .DefMember("lasthealth", [lasthealthClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lasthealthClass.CreateInstance(base->playerSlot); })
        .DefMember("lastcollisionceiling", [lastcollisionceilingClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastcollisionceilingClass.CreateInstance(base->playerSlot); })
        .DefMember("lastcollisionceilingchangetime", [lastcollisionceilingchangetimeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return lastcollisionceilingchangetimeClass.CreateInstance(base->playerSlot); })
        .DefMember("botallowactive", [botallowactiveClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return botallowactiveClass.CreateInstance(base->playerSlot); })
        .DefMember("committingsuicideonteamchange", [committingsuicideonteamchangeClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return committingsuicideonteamchangeClass.CreateInstance(base->playerSlot); })
        .DefMember("fov", [fovClass](LuaPlayerClass *base) -> luacpp::LuaObject
                   { return fovClass.CreateInstance(base->playerSlot); });

    displayhistorybitsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                                      { return scripting_Player_GetDisplayHistoryBits(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetDisplayHistoryBits(base->playerSlot, val); });
    lastattackedteammateClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                        { return scripting_Player_GetLastAttackedTeammate(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastAttackedTeammate(base->playerSlot, val); });
    blinduntiltimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                  { return scripting_Player_GetBlindUntilTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetBlindUntilTime(base->playerSlot, val); });
    blindstarttimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                  { return scripting_Player_GetBlindStartTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetBlindStartTime(base->playerSlot, val); });
    allowautofollowtimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                       { return scripting_Player_GetallowAutoFollowTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetallowAutoFollowTime(base->playerSlot, val); });
    spotrulesClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                             { return scripting_Player_GetSpotRules(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetSpotRules(base->playerSlot, val); });
    playerstateClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                               { return scripting_Player_GetPlayerState(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetPlayerState(base->playerSlot, (CSPlayerState)val); });
    lastdistancetravelednoticeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                              { return scripting_Player_GetLastDistanceTraveledNotice(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastDistanceTraveledNotice(base->playerSlot, val); });
    accumulateddistancetraveledClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                               { return scripting_Player_GetAccumulatedDistanceTraveled(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetAccumulatedDistanceTraveled(base->playerSlot, val); });
    lastfriendlyfiredamagereductionratioClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                                        { return scripting_Player_GetLastFriendlyFireDamageReductionRatio(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastFriendlyFireDamageReductionRatio(base->playerSlot, val); });
    respawningClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                              { return scripting_Player_GetRespawning(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetRespawning(base->playerSlot, val); });
    lastpickuppriorityClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                      { return scripting_Player_GetLastPickupPriority(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetLastPickupPriority(base->playerSlot, val); });
    lastpickupprioritytimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                          { return scripting_Player_GetLastPickupPriorityTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastPickupPriorityTime(base->playerSlot, val); });
    isscopedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                            { return scripting_Player_GetIsScoped(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsScoped(base->playerSlot, val); });
    iswalkingClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                             { return scripting_Player_GetIsWalking(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsWalking(base->playerSlot, val); });
    resumezoomClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                              { return scripting_Player_GetResumeZoom(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetResumeZoom(base->playerSlot, val); });
    isdefusingClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                              { return scripting_Player_GetIsDefusing(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsDefusing(base->playerSlot, val); });
    isgrabbinghostageClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                     { return scripting_Player_GetIsGrabbingHostage(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsGrabbingHostage(base->playerSlot, val); });
    blockinguseactioninprogressClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                                               { return scripting_Player_GetBlockingUseActionInProgress(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetBlockingUseActionInProgress(base->playerSlot, (CSPlayerBlockingUseAction_t)val); });
    immunetogungamedamagetimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                             { return scripting_Player_GetImmuneToGunGameDamageTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetImmuneToGunGameDamageTime(base->playerSlot, val); });
    gungameimmunityClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                   { return scripting_Player_GetGunGameImmunity(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetGunGameImmunity(base->playerSlot, val); });
    molotovdamagetimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                     { return scripting_Player_GetMolotovDamageTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetMolotovDamageTime(base->playerSlot, val); });
    hasmovedsincespawnClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                      { return scripting_Player_GetHasMovedSinceSpawn(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasMovedSinceSpawn(base->playerSlot, val); });
    canmoveduringfreezeperiodClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                             { return scripting_Player_GetCanMoveDuringFreezePeriod(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetCanMoveDuringFreezePeriod(base->playerSlot, val); });
    guardiantoofardistfracClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                          { return scripting_Player_GetGuardianTooFarDistFrac(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetGuardianTooFarDistFrac(base->playerSlot, val); });
    nextguardiantoofarhurttimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                              { return scripting_Player_GetNextGuardianTooFarHurtTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetNextGuardianTooFarHurtTime(base->playerSlot, val); });
    detectedbyenemysensortimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                             { return scripting_Player_GetDetectedByEnemySensorTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetDetectedByEnemySensorTime(base->playerSlot, val); });
    dealtdamagetoenemymostrecenttimestampClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                                         { return scripting_Player_GetDealtDamageToEnemyMostRecentTimestamp(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetDealtDamageToEnemyMostRecentTimestamp(base->playerSlot, val); });
    lastequippedhelmettimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                          { return scripting_Player_GetLastEquippedHelmetTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastEquippedHelmetTime(base->playerSlot, val); });
    lastequippedarmortimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                         { return scripting_Player_GetLastEquippedArmorTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastEquippedArmorTime(base->playerSlot, val); });
    heavyassaultsuitcooldownremainingClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                                     { return scripting_Player_GetHeavyAssaultSuitCooldownRemaining(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetHeavyAssaultSuitCooldownRemaining(base->playerSlot, val); });
    resetarmornextspawnClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                       { return scripting_Player_GetResetArmorNextSpawn(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetResetArmorNextSpawn(base->playerSlot, val); });
    lastbumpminebumptimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                        { return scripting_Player_GetLastBumpMineBumpTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastBumpMineBumpTime(base->playerSlot, val); });
    emitsoundtimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                 { return scripting_Player_GetEmitSoundTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetEmitSoundTime(base->playerSlot, val); });
    numspawnsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                             { return scripting_Player_GetNumSpawns(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetNumSpawns(base->playerSlot, val); });
    shouldhavecashClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                  { return scripting_Player_GetShouldHaveCash(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetShouldHaveCash(base->playerSlot, val); });
    invalidsteamlogondelayedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                            { return scripting_Player_GetInvalidSteamLogonDelayed(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetInvalidSteamLogonDelayed(base->playerSlot, val); });
    lastactionClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                              { return scripting_Player_GetLastAction(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastAction(base->playerSlot, val); });
    lastgivendefusertimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                        { return scripting_Player_GetLastGivenDefuserTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastGivenDefuserTime(base->playerSlot, val); });
    lastgivenbombtimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                     { return scripting_Player_GetLastGivenBombTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastGivenBombTime(base->playerSlot, val); });
    hasnightvisionClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                  { return scripting_Player_GetHasNightVision(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasNightVision(base->playerSlot, val); });
    nightvisiononClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                 { return scripting_Player_GetNightVisionOn(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetNightVisionOn(base->playerSlot, val); });
    nextradarupdatetimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                       { return scripting_Player_GetNextRadarUpdateTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetNextRadarUpdateTime(base->playerSlot, val); });
    lastmoneyupdatetimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                       { return scripting_Player_GetLastMoneyUpdateTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastMoneyUpdateTime(base->playerSlot, val); });
    introcamtimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                { return scripting_Player_GetIntroCamTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetIntroCamTime(base->playerSlot, val); });
    innodefuseareaClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                  { return scripting_Player_GetInNoDefuseArea(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetInNoDefuseArea(base->playerSlot, val); });
    killedbytaserClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                 { return scripting_Player_GetKilledByTaser(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetKilledByTaser(base->playerSlot, val); });
    movestateClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                             { return scripting_Player_GetMoveState(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetMoveState(base->playerSlot, val); });
    grenadeparameterstashtimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                             { return scripting_Player_GetGrenadeParameterStashTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetGrenadeParameterStashTime(base->playerSlot, val); });
    grenadeparametersstashedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                            { return scripting_Player_GetGrenadeParametersStashed(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetGrenadeParametersStashed(base->playerSlot, val); });
    diedairborneClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                { return scripting_Player_GetDiedAirborne(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetDiedAirborne(base->playerSlot, val); });
    whichbombzoneClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                 { return scripting_Player_GetWhichBombZone(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetWhichBombZone(base->playerSlot, val); });
    inbombzonetriggerClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                     { return scripting_Player_GetInBombZoneTrigger(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetInBombZoneTrigger(base->playerSlot, val); });
    wasinbombzonetriggerClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                        { return scripting_Player_GetWasInBombZoneTrigger(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetWasInBombZoneTrigger(base->playerSlot, val); });
    directionClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                             { return scripting_Player_GetDirection(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetDirection(base->playerSlot, val); });
    shotsfiredClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                              { return scripting_Player_GetShotsFired(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetShotsFired(base->playerSlot, val); });
    flinchstackClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                               { return scripting_Player_GetFlinchStack(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetFlinchStack(base->playerSlot, val); });
    hitheadingClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                              { return scripting_Player_GetHitHeading(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetHitHeading(base->playerSlot, val); });
    hitbodypartClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                               { return scripting_Player_GetHitBodyPart(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetHitBodyPart(base->playerSlot, val); });
    hostageskilledClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                  { return scripting_Player_GetHostagesKilled(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetHostagesKilled(base->playerSlot, val); });
    flashmaxalphaClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                 { return scripting_Player_GetFlashMaxAlpha(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetFlashMaxAlpha(base->playerSlot, val); });
    progressbarstarttimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                        { return scripting_Player_GetProgressBarStartTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetProgressBarStartTime(base->playerSlot, val); });
    progressbardurationClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                       { return scripting_Player_GetProgressBarDuration(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetProgressBarDuration(base->playerSlot, val); });
    waitfornoattackClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                   { return scripting_Player_GetWaitForNoAttack(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetWaitForNoAttack(base->playerSlot, val); });
    lowerbodyyawtargetClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                      { return scripting_Player_GetLowerBodyYawTarget(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLowerBodyYawTarget(base->playerSlot, val); });
    strafingClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                            { return scripting_Player_GetStrafing(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetStrafing(base->playerSlot, val); });
    ignoreladderjumptimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                        { return scripting_Player_GetIgnoreLadderJumpTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetIgnoreLadderJumpTime(base->playerSlot, val); });
    slopedropoffsetClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                   { return scripting_Player_GetSlopeDropOffset(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetSlopeDropOffset(base->playerSlot, val); });
    slopedropheightClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                   { return scripting_Player_GetSlopeDropHeight(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetSlopeDropHeight(base->playerSlot, val); });
    lastweaponfireusercmdClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                         { return scripting_Player_GetLastWeaponFireUsercmd(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetLastWeaponFireUsercmd(base->playerSlot, val); });
    vcollisioninittedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                     { return scripting_Player_GetVCollisionInitted(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetVCollisionInitted(base->playerSlot, val); });
    isspawningClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                              { return scripting_Player_GetIsSpawning(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsSpawning(base->playerSlot, val); });
    hidetargetidClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                { return scripting_Player_GetHideTargetID(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHideTargetID(base->playerSlot, val); });
    numdangerzonedamagehitsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                           { return scripting_Player_GetNumDangerZoneDamageHits(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetNumDangerZoneDamageHits(base->playerSlot, val); });
    hud_miniscorehiddenClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                       { return scripting_Player_GetHud_MiniScoreHidden(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHud_MiniScoreHidden(base->playerSlot, val); });
    hud_radarhiddenClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                   { return scripting_Player_GetHud_RadarHidden(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHud_RadarHidden(base->playerSlot, val); });
    lastconcurrentkilledClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                        { return scripting_Player_GetLastConcurrentKilled(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetLastConcurrentKilled(base->playerSlot, val); });
    deathcammusicClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                 { return scripting_Player_GetDeathCamMusic(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetDeathCamMusic(base->playerSlot, val); });
    addonbitsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                             { return scripting_Player_GetAddonBits(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetAddonBits(base->playerSlot, val); });
    primaryaddonClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                { return scripting_Player_GetPrimaryAddon(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetPrimaryAddon(base->playerSlot, val); });
    secondaryaddonClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                  { return scripting_Player_GetSecondaryAddon(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetSecondaryAddon(base->playerSlot, val); });
    numenemieskilledthisspawnClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                             { return scripting_Player_GetNumEnemiesKilledThisSpawn(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetNumEnemiesKilledThisSpawn(base->playerSlot, val); });
    numenemieskilledthisroundClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                             { return scripting_Player_GetNumEnemiesKilledThisRound(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetNumEnemiesKilledThisRound(base->playerSlot, val); });
    numenemiesatroundstartClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                          { return scripting_Player_GetNumEnemiesAtRoundStart(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetNumEnemiesAtRoundStart(base->playerSlot, val); });
    wasnotkillednaturallyClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                         { return scripting_Player_GetWasNotKilledNaturally(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetWasNotKilledNaturally(base->playerSlot, val); });
    deathflagsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                              { return scripting_Player_GetDeathFlags(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetDeathFlags(base->playerSlot, val); });
    currentequipmentvalueClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint16_t
                                         { return scripting_Player_GetCurrentEquipmentValue(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint16_t val) -> void
                   { scripting_Player_SetCurrentEquipmentValue(base->playerSlot, val); });
    roundstartequipmentvalueClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint16_t
                                            { return scripting_Player_GetRoundStartEquipmentValue(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint16_t val) -> void
                   { scripting_Player_SetRoundStartEquipmentValue(base->playerSlot, val); });
    freezetimeendequipmentvalueClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint16_t
                                               { return scripting_Player_GetFreezetimeEndEquipmentValue(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint16_t val) -> void
                   { scripting_Player_SetFreezetimeEndEquipmentValue(base->playerSlot, val); });
    survivalteamnumberClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                      { return scripting_Player_GetSurvivalTeamNumber(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetSurvivalTeamNumber(base->playerSlot, val); });
    hasdeathinfoClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                { return scripting_Player_GetHasDeathInfo(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasDeathInfo(base->playerSlot, val); });
    deathinfotimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                 { return scripting_Player_GetDeathInfoTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetDeathInfoTime(base->playerSlot, val); });
    killedbyheadshotClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                    { return scripting_Player_GetKilledByHeadshot(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetKilledByHeadshot(base->playerSlot, val); });
    lasthitboxClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                              { return scripting_Player_GetLastHitBox(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetLastHitBox(base->playerSlot, val); });
    lasthealthClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                              { return scripting_Player_GetLastHealth(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetLastHealth(base->playerSlot, val); });
    lastcollisionceilingClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                        { return scripting_Player_GetLastCollisionCeiling(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastCollisionCeiling(base->playerSlot, val); });
    lastcollisionceilingchangetimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                                  { return scripting_Player_GetLastCollisionCeilingChangeTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastCollisionCeilingChangeTime(base->playerSlot, val); });
    botallowactiveClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                  { return scripting_Player_GetBotAllowActive(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetBotAllowActive(base->playerSlot, val); });
    committingsuicideonteamchangeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                                 { return scripting_Player_GetCommittingSuicideOnTeamChange(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetCommittingSuicideOnTeamChange(base->playerSlot, val); });

    characterdefindexClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint16_t
                                     { return scripting_Player_GetCharacterDefIndex(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint16_t val) -> void
                   { scripting_Player_SetCharacterDefIndex(base->playerSlot, val); });
    hasfemalevoiceClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                  { return scripting_Player_GetHasFemaleVoice(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasFemaleVoice(base->playerSlot, val); });
    inhostageresetzoneClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                      { return scripting_Player_GetInHostageResetZone(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetInHostageResetZone(base->playerSlot, val); });
    inbuyzoneClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                             { return scripting_Player_GetInBuyZone(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetInBuyZone(base->playerSlot, val); });
    wasinbuyzoneClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                { return scripting_Player_GetWasInBuyZone(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetWasInBuyZone(base->playerSlot, val); });
    inhostagerescuezoneClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                       { return scripting_Player_GetInHostageRescueZone(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetInHostageRescueZone(base->playerSlot, val); });
    inbombzoneClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                              { return scripting_Player_GetInBombZone(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetInBombZone(base->playerSlot, val); });
    wasinhostagerescuezoneClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                          { return scripting_Player_GetWasInHostageRescueZone(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetWasInHostageRescueZone(base->playerSlot, val); });
    retakesofferingClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                   { return scripting_Player_GetRetakesOffering(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetRetakesOffering(base->playerSlot, val); });
    retakesofferingcardClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                       { return scripting_Player_GetRetakesOfferingCard(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetRetakesOfferingCard(base->playerSlot, val); });
    retakeshasdefusekitClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                       { return scripting_Player_GetRetakesHasDefuseKit(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetRetakesHasDefuseKit(base->playerSlot, val); });
    retakesmvplastroundClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                       { return scripting_Player_GetRetakesMVPLastRound(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetRetakesMVPLastRound(base->playerSlot, val); });
    retakesmvpboostitemClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                       { return scripting_Player_GetRetakesMVPBoostItem(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetRetakesMVPBoostItem(base->playerSlot, val); });
    landsecondsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                               { return scripting_Player_GetLandseconds(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLandseconds(base->playerSlot, val); });
    aimpunchtickbaseClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                    { return scripting_Player_GetAimPunchTickBase(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetAimPunchTickBase(base->playerSlot, val); });
    aimpunchtickfractionClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                        { return scripting_Player_GetAimPunchTickFraction(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetAimPunchTickFraction(base->playerSlot, val); });
    isbuymenuopenClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                 { return scripting_Player_GetIsBuyMenuOpen(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsBuyMenuOpen(base->playerSlot, val); });
    lastheadbonetransformisvalidClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                                { return scripting_Player_GetLastHeadBoneTransformIsValid(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetLastHeadBoneTransformIsValid(base->playerSlot, val); });
    lastlandtimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                { return scripting_Player_GetLastLandTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastLandTime(base->playerSlot, val); });
    ongroundlasttickClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                    { return scripting_Player_GetOnGroundLastTick(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetOnGroundLastTick(base->playerSlot, val); });
    playerlockedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                { return scripting_Player_GetPlayerLocked(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetPlayerLocked(base->playerSlot, val); });
    timeoflastinjuryClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                    { return scripting_Player_GetTimeOfLastInjury(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetTimeOfLastInjury(base->playerSlot, val); });
    nextspraydecaltimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                      { return scripting_Player_GetNextSprayDecalTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetNextSprayDecalTime(base->playerSlot, val); });
    nextspraydecaltimeexpeditedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                               { return scripting_Player_GetNextSprayDecalTimeExpedited(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetNextSprayDecalTimeExpedited(base->playerSlot, val); });
    ragdolldamageboneClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                     { return scripting_Player_GetRagdollDamageBone(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetRagdollDamageBone(base->playerSlot, val); });
    ragdolldamageheadshotClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                         { return scripting_Player_GetRagdollDamageHeadshot(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetRagdollDamageHeadshot(base->playerSlot, val); });
    econgloveschangedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint8_t
                                     { return scripting_Player_GetEconGlovesChanged(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint8_t val) -> void
                   { scripting_Player_SetEconGlovesChanged(base->playerSlot, val); });
    skiponeheadconstraintupdateClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                               { return scripting_Player_GetSkipOneHeadConstraintUpdate(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetSkipOneHeadConstraintUpdate(base->playerSlot, val); });

    hascommunicationabusemuteClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                             { return scripting_Player_GetHasCommunicationAbuseMute(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasCommunicationAbuseMute(base->playerSlot, val); });
    pendingteamnumClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint8_t
                                  { return scripting_Player_GetPendingTeamNum(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint8_t val) -> void
                   { scripting_Player_SetPendingTeamNum(base->playerSlot, val); });
    forceteamtimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                 { return scripting_Player_GetForceTeamTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetForceTeamTime(base->playerSlot, val); });
    compteammatecolorClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                     { return scripting_Player_GetCompTeammateColor(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetCompTeammateColor(base->playerSlot, val); });
    everplayedonteamClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                    { return scripting_Player_GetEverPlayedOnTeam(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetEverPlayedOnTeam(base->playerSlot, val); });
    attemptedtogetcolorClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                       { return scripting_Player_GetAttemptedToGetColor(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetAttemptedToGetColor(base->playerSlot, val); });
    teammatepreferredcolorClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                          { return scripting_Player_GetTeammatePreferredColor(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetTeammatePreferredColor(base->playerSlot, val); });
    teamchangedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                               { return scripting_Player_GetTeamChanged(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetTeamChanged(base->playerSlot, val); });
    inswitchteamClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                { return scripting_Player_GetInSwitchTeam(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetInSwitchTeam(base->playerSlot, val); });
    hasseenjoingameClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                   { return scripting_Player_GetHasSeenJoinGame(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasSeenJoinGame(base->playerSlot, val); });
    justbecamespectatorClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                       { return scripting_Player_GetJustBecameSpectator(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetJustBecameSpectator(base->playerSlot, val); });
    switchteamsonnextroundresetClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                               { return scripting_Player_GetSwitchTeamsOnNextRoundReset(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetSwitchTeamsOnNextRoundReset(base->playerSlot, val); });
    removeallitemsonnextroundresetClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                                  { return scripting_Player_GetRemoveAllItemsOnNextRoundReset(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetRemoveAllItemsOnNextRoundReset(base->playerSlot, val); });
    competitiverankingpredicted_winClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                                   { return scripting_Player_GetCompetitiveRankingPredicted_Win(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetCompetitiveRankingPredicted_Win(base->playerSlot, val); });
    competitiverankingpredicted_lossClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                                    { return scripting_Player_GetCompetitiveRankingPredicted_Loss(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetCompetitiveRankingPredicted_Loss(base->playerSlot, val); });
    competitiverankingpredicted_tieClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                                   { return scripting_Player_GetCompetitiveRankingPredicted_Tie(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetCompetitiveRankingPredicted_Tie(base->playerSlot, val); });
    endmatchnextmapvoteClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                       { return scripting_Player_GetEndMatchNextMapVote(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetEndMatchNextMapVote(base->playerSlot, val); });
    activequestidClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint16_t
                                 { return scripting_Player_GetActiveQuestId(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint16_t val) -> void
                   { scripting_Player_SetActiveQuestId(base->playerSlot, val); });
    playertvcontrolflagsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                                        { return scripting_Player_GetPlayerTvControlFlags(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetPlayerTvControlFlags(base->playerSlot, val); });
    draftindexClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                              { return scripting_Player_GetDraftIndex(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetDraftIndex(base->playerSlot, val); });
    queuedmodedisconnectiontimestampClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                                                    { return scripting_Player_GetQueuedModeDisconnectionTimestamp(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetQueuedModeDisconnectionTimestamp(base->playerSlot, val); });
    abandonrecordedreasonClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                                         { return scripting_Player_GetAbandonRecordedReason(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetAbandonRecordedReason(base->playerSlot, val); });
    cannotbekickedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                  { return scripting_Player_GetCannotBeKicked(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetCannotBeKicked(base->playerSlot, val); });
    everfullyconnectedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                      { return scripting_Player_GetEverFullyConnected(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetEverFullyConnected(base->playerSlot, val); });
    abandonallowssurrenderClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                          { return scripting_Player_GetAbandonAllowsSurrender(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetAbandonAllowsSurrender(base->playerSlot, val); });
    abandonoffersinstantsurrenderClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                                 { return scripting_Player_GetAbandonOffersInstantSurrender(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetAbandonOffersInstantSurrender(base->playerSlot, val); });
    disconnection1minwarningprintedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                                   { return scripting_Player_GetDisconnection1MinWarningPrinted(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetDisconnection1MinWarningPrinted(base->playerSlot, val); });
    scorereportedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                 { return scripting_Player_GetScoreReported(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetScoreReported(base->playerSlot, val); });
    disconnectiontickClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                     { return scripting_Player_GetDisconnectionTick(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetDisconnectionTick(base->playerSlot, val); });
    controllingbotClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                  { return scripting_Player_GetControllingBot(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetControllingBot(base->playerSlot, val); });
    hascontrolledbotthisroundClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                             { return scripting_Player_GetHasControlledBotThisRound(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasControlledBotThisRound(base->playerSlot, val); });
    hasbeencontrolledbyplayerthisroundClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                                      { return scripting_Player_GetHasBeenControlledByPlayerThisRound(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasBeenControlledByPlayerThisRound(base->playerSlot, val); });
    botscontrolledthisroundClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                           { return scripting_Player_GetBotsControlledThisRound(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetBotsControlledThisRound(base->playerSlot, val); });
    cancontrolobservedbotClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                         { return scripting_Player_GetCanControlObservedBot(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetCanControlObservedBot(base->playerSlot, val); });
    desiredobservermodeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                       { return scripting_Player_GetDesiredObserverMode(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetDesiredObserverMode(base->playerSlot, val); });
    pawncharacterdefindexClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint16_t
                                         { return scripting_Player_GetPawnCharacterDefIndex(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint16_t val) -> void
                   { scripting_Player_SetPawnCharacterDefIndex(base->playerSlot, val); });
    pawnlifetimestartClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                     { return scripting_Player_GetPawnLifetimeStart(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetPawnLifetimeStart(base->playerSlot, val); });
    pawnlifetimeendClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                   { return scripting_Player_GetPawnLifetimeEnd(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetPawnLifetimeEnd(base->playerSlot, val); });
    pawnbotdifficultyClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                     { return scripting_Player_GetPawnBotDifficulty(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetPawnBotDifficulty(base->playerSlot, val); });
    scoreClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                         { return scripting_Player_GetScore(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetScore(base->playerSlot, val); });
    roundscoreClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                              { return scripting_Player_GetRoundScore(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetRoundScore(base->playerSlot, val); });
    roundswonClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                             { return scripting_Player_GetRoundsWon(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetRoundsWon(base->playerSlot, val); });
    mvpsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                        { return scripting_Player_GetMVPs(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetMVPs(base->playerSlot, val); });
    updatecounterClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                 { return scripting_Player_GetUpdateCounter(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetUpdateCounter(base->playerSlot, val); });
    showhintsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                             { return scripting_Player_GetShowHints(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetShowHints(base->playerSlot, val); });
    nexttimecheckClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                 { return scripting_Player_GetNextTimeCheck(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetNextTimeCheck(base->playerSlot, val); });
    justdidteamkillClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                   { return scripting_Player_GetJustDidTeamKill(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetJustDidTeamKill(base->playerSlot, val); });
    punishforteamkillClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                     { return scripting_Player_GetPunishForTeamKill(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetPunishForTeamKill(base->playerSlot, val); });
    gaveteamdamagewarningClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                         { return scripting_Player_GetGaveTeamDamageWarning(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetGaveTeamDamageWarning(base->playerSlot, val); });
    gaveteamdamagewarningthisroundClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                                  { return scripting_Player_GetGaveTeamDamageWarningThisRound(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetGaveTeamDamageWarningThisRound(base->playerSlot, val); });
    lastreceivedpacketplatfloattimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> double
                                                   { return scripting_Player_GetLastReceivedPacketPlatFloatTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, double val) -> void
                   { scripting_Player_SetLastReceivedPacketPlatFloatTime(base->playerSlot, val); });
    lastteamdamagewarningtimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                             { return scripting_Player_GetLastTeamDamageWarningTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastTeamDamageWarningTime(base->playerSlot, val); });
    lasttimeplayerwasdisconnectedforpawnsremoveClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                                               { return scripting_Player_GetLastTimePlayerWasDisconnectedForPawnsRemove(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastTimePlayerWasDisconnectedForPawnsRemove(base->playerSlot, val); });
    suspicioushitcountClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                                      { return scripting_Player_GetSuspiciousHitCount(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetSuspiciousHitCount(base->playerSlot, val); });
    nonsuspicioushitstreakClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                                          { return scripting_Player_GetNonSuspiciousHitStreak(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetNonSuspiciousHitStreak(base->playerSlot, val); });

    highestgeneratedserverviewanglechangeindexClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                                                              { return scripting_Player_GetHighestGeneratedServerViewAngleChangeIndex(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetHighestGeneratedServerViewAngleChangeIndex(base->playerSlot, val); });
    hidehudClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                           { return scripting_Player_GetHideHUD(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetHideHUD(base->playerSlot, val); });
    inithudClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                           { return scripting_Player_GetInitHUD(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetInitHUD(base->playerSlot, val); });
    hltvreplaydelayClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                   { return scripting_Player_GetHltvReplayDelay(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetHltvReplayDelay(base->playerSlot, val); });
    hltvreplayendClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                 { return scripting_Player_GetHltvReplayEnd(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetHltvReplayEnd(base->playerSlot, val); });

    gamepausedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                              { return scripting_Player_GetGamePaused(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetGamePaused(base->playerSlot, val); });

    lastplayertalktimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                      { return scripting_Player_GetLastPlayerTalkTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastPlayerTalkTime(base->playerSlot, val); });

    lerptimeClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                            { return scripting_Player_GetLerpTime(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLerpTime(base->playerSlot, val); });

    lastrealcommandnumberexecutedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                                 { return scripting_Player_GetLastRealCommandNumberExecuted(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetLastRealCommandNumberExecuted(base->playerSlot, val); });

    ishltvClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                          { return scripting_Player_GetIsHLTV(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsHLTV(base->playerSlot, val); });

    lastlatecommandexecutedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                           { return scripting_Player_GetLastLateCommandExecuted(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetLastLateCommandExecuted(base->playerSlot, val); });

    lastentitysteadystateClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                                         { return scripting_Player_GetLastEntitySteadyState(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float val) -> void
                   { scripting_Player_SetLastEntitySteadyState(base->playerSlot, val); });

    lagcompensationClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                   { return scripting_Player_GetLagCompensation(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetLagCompensation(base->playerSlot, val); });

    islowviolenceClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                 { return scripting_Player_GetIsLowViolence(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetIsLowViolence(base->playerSlot, val); });

    hasanysteadystateentsClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                         { return scripting_Player_GetHasAnySteadyStateEnts(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetHasAnySteadyStateEnts(base->playerSlot, val); });

    healthClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int
                          { return scripting_Player_GetHealth(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int health) -> void
                   { scripting_Player_SetHealth(base->playerSlot, health); })
        .DefMember("Take", [](LuaPlayerArgsClass *base, int health) -> void
                   { scripting_Player_TakeHealth(base->playerSlot, health); })
        .DefMember("GetMax", [](LuaPlayerArgsClass *base) -> int
                   { return scripting_Player_GetMaxHealth(base->playerSlot); })
        .DefMember("SetMax", [](LuaPlayerArgsClass *base, int health) -> void
                   { scripting_Player_SetMaxHealth(base->playerSlot, health); });

    gravityClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                           { return scripting_Player_GetGravity(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float gravity) -> void
                   { scripting_Player_SetGravity(base->playerSlot, gravity); });

    speedClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> float
                         { return scripting_Player_GetSpeed(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, float speed) -> void
                   { scripting_Player_SetSpeed(base->playerSlot, speed); });

    armorClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int
                         { return scripting_Player_GetArmor(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int armor) -> void
                   { scripting_Player_SetArmor(base->playerSlot, armor); })
        .DefMember("Take", [](LuaPlayerArgsClass *base, int armor) -> void
                   { scripting_Player_TakeArmor(base->playerSlot, armor); });

    clantagClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> const char *
                           { return scripting_Player_GetClanTag(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, const char *tag) -> void
                   { scripting_Player_SetClanTag(base->playerSlot, tag); });

    teamClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint8
                        { return scripting_Player_GetTeam(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int team) -> void
                   { scripting_Player_SetTeam(base->playerSlot, team); });

    varsClass.DefMember("Get", [state](LuaPlayerArgsClass *base, const char *key) -> luacpp::LuaObject
                        {
                            rapidjson::Document doc;
                            doc.Parse(scripting_Player_GetVar(base->playerSlot, key));
                            if(doc.HasParseError()) return state->CreateNil();

                            if(doc["value"].IsString()) return state->CreateString(doc["value"].GetString());
                            else if(doc["value"].IsInt()) return state->CreateInteger(doc["value"].GetInt());
                            else if(doc["value"].IsInt64()) return state->CreateInteger(doc["value"].GetInt64());
                            else if(doc["value"].IsUint()) return state->CreateInteger(doc["value"].GetUint());
                            else if(doc["value"].IsUint64()) return state->CreateInteger(doc["value"].GetUint64());
                            else if(doc["value"].IsBool()) return state->CreateInteger(doc["value"].GetBool());
                            else if(doc["value"].IsFloat()) return state->CreateNumber(doc["value"].GetFloat());
                            else if(doc["value"].IsDouble()) return state->CreateNumber(doc["value"].IsDouble());
                            else return state->CreateNil(); })
        .DefMember("Set", [plugin](LuaPlayerArgsClass *base, const char *key, luacpp::LuaObject value) -> void
                   {
                        if(value.GetType() == LUA_TBOOLEAN) scripting_Player_SetVar(base->playerSlot, key, 7, value.ToBool());
                        else if(value.GetType() == LUA_TSTRING) scripting_Player_SetVar(base->playerSlot, key, 1, value.ToString());
                        else if(value.GetType() == LUA_TNUMBER) {
                            lua_rawgeti(plugin->GetLuaRawState(), LUA_REGISTRYINDEX, value.GetRefIndex());
                            if(lua_isinteger(plugin->GetLuaRawState(), -1) == 1) scripting_Player_SetVar(base->playerSlot, key, 8, value.ToInteger());
                            else {
                                double val = value.ToNumber();
                                scripting_Player_SetVar(base->playerSlot, key, 4, val);
                            }
                            lua_pop(plugin->GetLuaRawState(), 1);
                        } });

    statsClass.DefMember("Get", [](LuaPlayerArgsClass *base, int stat) -> int
                         { return scripting_Player_FetchMatchStat(base->playerSlot, (PlayerStat)stat); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int stat, int value) -> void
                   { scripting_Player_SetMatchStat(base->playerSlot, (PlayerStat)stat, value); });

    autokickdisabledClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                                    { return scripting_Player_GetAutoKickDisabled(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetAutoKickDisabled(base->playerSlot, val); });

    availableentitysteadystateClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int32_t
                                              { return scripting_Player_GetAvailableEntitySteadyState(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int32_t val) -> void
                   { scripting_Player_SetAvailableEntitySteadyState(base->playerSlot, val); });

    moneyClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> int
                         { return scripting_Player_GetMoney(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, int money) -> void
                   { scripting_Player_SetMoney(base->playerSlot, money); })
        .DefMember("Take", [](LuaPlayerArgsClass *base, int money) -> void
                   { scripting_Player_TakeMoney(base->playerSlot, money); });

    predictClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> bool
                           { return scripting_Player_GetPredict(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, bool val) -> void
                   { scripting_Player_SetPredict(base->playerSlot, val); });

    tickbaseClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                            { return scripting_Player_GetTickBase(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t val) -> void
                   { scripting_Player_SetTickBase(base->playerSlot, val); });

    coordsClass.DefMember("Get", [state](LuaPlayerArgsClass *base) -> luacpp::LuaObject
                          {
                            rapidjson::Document doc;
                            doc.Parse(scripting_Player_GetCoords(base->playerSlot));
                            if(doc.HasParseError()) return state->CreateNil();
                            if(!doc["value"].IsObject()) return state->CreateNil();

                            float x = doc["value"]["x"].GetFloat();
                            float y = doc["value"]["y"].GetFloat();
                            float z = doc["value"]["z"].GetFloat();

                            LuaFuncWrapper wrapper(state->Get("vector3"));
                            wrapper.PrepForExec();
                            luacpp::PushValues(wrapper.GetML(), x, y, z);
                            return wrapper.ExecuteWithReturnRaw("vector3", 3); })
        .DefMember("Set", [state](LuaPlayerArgsClass *base, luacpp::LuaObject coordsObj) -> void
                   {
                        if(coordsObj.GetType() != LUA_TTABLE) {
                            PRINT("Runtime", "Coords field needs to be a vector3.\n");
                            return;
                        }

                        luacpp::LuaTable coords = luacpp::LuaTable(coordsObj);

                        if(coords.Get("x").GetType() == LUA_TNIL || coords.Get("y").GetType() == LUA_TNIL || coords.Get("z").GetType() == LUA_TNIL) {
                            PRINT("Runtime", "Coords field needs to be a vector3.\n");
                            return;
                        }

                        scripting_Player_SetCoords(base->playerSlot, (float)coords.GetNumber("x"), (float)coords.GetNumber("y"), (float)coords.GetNumber("z")); });

    velocityClass.DefMember("Get", [state](LuaPlayerArgsClass *base) -> luacpp::LuaObject
                            {
                            rapidjson::Document doc;
                            doc.Parse(scripting_Player_GetVelocity(base->playerSlot));
                            if(doc.HasParseError()) return state->CreateNil();
                            if(!doc["value"].IsObject()) return state->CreateNil();

                            float x = doc["value"]["x"].GetFloat();
                            float y = doc["value"]["y"].GetFloat();
                            float z = doc["value"]["z"].GetFloat();

                            LuaFuncWrapper wrapper(state->Get("vector3"));
                            wrapper.PrepForExec();
                            luacpp::PushValues(wrapper.GetML(), x, y, z);
                            return wrapper.ExecuteWithReturnRaw("vector3", 3); })
        .DefMember("Set", [state](LuaPlayerArgsClass *base, luacpp::LuaObject coordsObj) -> void
                   {
                        if(coordsObj.GetType() != LUA_TTABLE) {
                            PRINT("Runtime", "Coords field needs to be a vector3.\n");
                            return;
                        }

                        luacpp::LuaTable coords = luacpp::LuaTable(coordsObj);

                        if(coords.Get("x").GetType() == LUA_TNIL || coords.Get("y").GetType() == LUA_TNIL || coords.Get("z").GetType() == LUA_TNIL) {
                            PRINT("Runtime", "Coords field needs to be a vector3.\n");
                            return;
                        }

                        scripting_Player_SetVelocity(base->playerSlot, (float)coords.GetNumber("x"),(float)coords.GetNumber("y"), (float)coords.GetNumber("z")); });

    weaponsClass.DefMember("DropWeapons", [](LuaPlayerArgsClass *base) -> void
                           { scripting_Player_Weapons_Drop(base->playerSlot); })
        .DefMember("RemoveWeapons", [](LuaPlayerArgsClass *base) -> void
                   { scripting_Player_Weapons_Remove(base->playerSlot); })
        .DefMember("GiveWeapons", [](LuaPlayerArgsClass *base, const char *name) -> void
                   { scripting_Player_Weapons_Give(base->playerSlot, name); })
        .DefMember("SetActiveWeapon", [](LuaPlayerArgsClass *base, uint32 slot) -> void
                   { scripting_Player_Weapons_SetActiveWeapon(base->playerSlot, slot); })
        .DefMember("GetWeaponFromSlot", [weaponClass](LuaPlayerArgsClass *base, uint32 slot) -> luacpp::LuaObject
                   { return weaponClass.CreateInstance(base->playerSlot, scripting_Player_Weapons_GetWeaponID(base->playerSlot, slot)); })
        .DefMember("GetWeapon", [weaponClass](LuaPlayerArgsClass *base, uint32 weaponID) -> luacpp::LuaObject
                   { return weaponClass.CreateInstance(base->playerSlot, weaponID); });

    weaponClass.DefMember("Remove", [](LuaPlayerTwoArgsClass *base) -> void
                          { scripting_Player_Weapon_Remove(base->playerSlot, base->slot); })
        .DefMember("Drop", [](LuaPlayerTwoArgsClass *base) -> void
                   { scripting_Player_Weapon_Drop(base->playerSlot, base->slot); })
        .DefMember("SetStatTrack", [](LuaPlayerTwoArgsClass *base, bool stattrack) -> void
                   { scripting_Player_Weapon_SetStatTrack(base->playerSlot, base->slot, stattrack); })
        .DefMember("SetWear", [](LuaPlayerTwoArgsClass *base, float wear) -> void
                   { scripting_Player_Weapon_SetWear(base->playerSlot, base->slot, wear); })
        .DefMember("SetPaintKit", [](LuaPlayerTwoArgsClass *base, int paintkit) -> void
                   { scripting_Player_Weapon_SetPaintKit(base->playerSlot, base->slot, paintkit); })
        .DefMember("SetSeed", [](LuaPlayerTwoArgsClass *base, int seed) -> void
                   { scripting_Player_Weapon_SetSeed(base->playerSlot, base->slot, seed); })
        .DefMember("GetStatTrack", [](LuaPlayerTwoArgsClass *base) -> bool
                   { return scripting_Player_Weapon_GetStatTrack(base->playerSlot, base->slot); })
        .DefMember("GetWear", [](LuaPlayerTwoArgsClass *base) -> float
                   { return scripting_Player_Weapon_GetWear(base->playerSlot, base->slot); })
        .DefMember("GetPaintKit", [](LuaPlayerTwoArgsClass *base) -> int
                   { return scripting_Player_Weapon_GetPaintKit(base->playerSlot, base->slot); })
        .DefMember("GetSeed", [](LuaPlayerTwoArgsClass *base) -> int
                   { return scripting_Player_Weapon_GetSeed(base->playerSlot, base->slot); })
        .DefMember("GetType", [](LuaPlayerTwoArgsClass *base) -> uint32
                   { return scripting_Player_Weapon_GetType(base->playerSlot, base->slot); })
        .DefMember("GetName", [](LuaPlayerTwoArgsClass *base) -> const char *
                   { return scripting_Player_Weapon_GetName(base->playerSlot, base->slot); })
        .DefMember("Exists", [](LuaPlayerTwoArgsClass *base) -> bool
                   { return scripting_Player_Weapon_Exists(base->playerSlot, base->slot); })
        .DefMember("SetDefaultChangeSkinAttributes", [](LuaPlayerTwoArgsClass *base) -> void
                   { scripting_Player_Weapon_SetDefaultChangeSkinAttributes(base->playerSlot, base->slot); })
        .DefMember("GetID", [](LuaPlayerTwoArgsClass *base) -> uint32
                   { return base->slot; })
        .DefMember("SetNametag", [](LuaPlayerTwoArgsClass *base, const char *text) -> void
                   { scripting_Player_Weapon_SetNametag(base->playerSlot, base->slot, text); })
        .DefMember("GetSilencerType", [](LuaPlayerTwoArgsClass *base) -> uint32_t
                   { return scripting_Player_Weapon_GetSilencerType(base->playerSlot, base->slot); })
        .DefMember("SetClipAmmo", [](LuaPlayerTwoArgsClass *base, int ammo) -> void
                   { scripting_Player_Weapon_SetClipAmmo(base->playerSlot, base->slot, ammo); })
        .DefMember("SetClip2Ammo", [](LuaPlayerTwoArgsClass *base, int ammo) -> void
                   { scripting_Player_Weapon_SetClip2Ammo(base->playerSlot, base->slot, ammo); })
        .DefMember("SetReserveAmmo", [](LuaPlayerTwoArgsClass *base, int ammo) -> void
                   { scripting_Player_Weapon_SetReserveAmmo(base->playerSlot, base->slot, ammo); })
        .DefMember("GetNextPrimaryAttackTick", [](LuaPlayerTwoArgsClass *base) -> int32_t
                   { return scripting_Player_Weapon_GetNextPrimaryAttackTick(base->playerSlot, base->slot); })
        .DefMember("SetNextPrimaryAttackTick", [](LuaPlayerTwoArgsClass *base, int32_t tick) -> void
                   { scripting_Player_Weapon_SetNextPrimaryAttackTick(base->playerSlot, base->slot, tick); })
        .DefMember("GetNextSecondaryAttackTick", [](LuaPlayerTwoArgsClass *base) -> int32_t
                   { return scripting_Player_Weapon_GetNextSecondaryAttackTick(base->playerSlot, base->slot); })
        .DefMember("SetNextSecondaryAttackTick", [](LuaPlayerTwoArgsClass *base, int32_t tick) -> void
                   { scripting_Player_Weapon_SetNextSecondaryAttackTick(base->playerSlot, base->slot, tick); })
        .DefMember("GetNextPrimaryAttackTickRatio", [](LuaPlayerTwoArgsClass *base) -> float
                   { return scripting_Player_Weapon_GetNextPrimaryAttackTickRatio(base->playerSlot, base->slot); })
        .DefMember("SetNextPrimaryAttackTickRatio", [](LuaPlayerTwoArgsClass *base, float ratio) -> void
                   { scripting_Player_Weapon_SetNextPrimaryAttackTickRatio(base->playerSlot, base->slot, ratio); })
        .DefMember("GetNextSecondaryAttackTickRatio", [](LuaPlayerTwoArgsClass *base) -> float
                   { return scripting_Player_Weapon_GetNextSecondaryAttackTickRatio(base->playerSlot, base->slot); })
        .DefMember("SetNextSecondaryAttackTickRatio", [](LuaPlayerTwoArgsClass *base, float ratio) -> void
                   { scripting_Player_Weapon_SetNextSecondaryAttackTickRatio(base->playerSlot, base->slot, ratio); });

    eyeangleClass.DefMember("Get", [state](LuaPlayerArgsClass *base) -> luacpp::LuaObject
                            {
                            QAngle angle = scripting_Player_GetEyeAnglesRaw(base->playerSlot);

                            float x = angle.x;
                            float y = angle.y;
                            float z = angle.z;

                            LuaFuncWrapper wrapper(state->Get("vector3"));
                            wrapper.PrepForExec();
                            luacpp::PushValues(wrapper.GetML(), x, y, z);
                            return wrapper.ExecuteWithReturnRaw("vector3", 3); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, luacpp::LuaObject coordsObj) -> void
                   {
                                if (coordsObj.GetType() != LUA_TTABLE) {
                                    PRINT("Runtime", "Coords field needs to be a vector3.\n");
                                    return;
                                }

                                luacpp::LuaTable coords = luacpp::LuaTable(coordsObj);

                                if (coords.Get("x").GetType() == LUA_TNIL || coords.Get("y").GetType() == LUA_TNIL || coords.Get("z").GetType() == LUA_TNIL) {
                                    PRINT("Runtime", "Coords field needs to be a vector3.\n");
                                    return;
                                }

                                scripting_Player_SetEyeAngles(base->playerSlot, (float)coords.GetNumber("x"), (float)coords.GetNumber("y"), (float)coords.GetNumber("z")); });

    fovClass.DefMember("Get", [](LuaPlayerArgsClass *base) -> uint32_t
                       { return scripting_Player_GetDesiredFOV(base->playerSlot); })
        .DefMember("Set", [](LuaPlayerArgsClass *base, uint32_t fov)
                   { scripting_Player_SetDesiredFOV(base->playerSlot, fov); });
}