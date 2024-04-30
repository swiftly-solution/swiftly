#ifndef _swiftly_player_h
#define _swiftly_player_h

#include <stdint.h>
#include "swiftly_memory.h"
#include "types.h"
#include <cstdarg>
#include "swiftly_utils.h"

#include "player/health.h"
#include "player/armor.h"
#include "player/clantag.h"
#include "player/team.h"
#include "player/vars.h"
#include "player/stats.h"
#include "player/coords.h"
#include "player/money.h"
#include "player/velocity.h"
#include "player/weapons.h"
#include "player/gravity.h"
#include "player/helmet.h"
#include "player/speed.h"
#include "player/eyeangle.h"
#include "player/fov.h"
#include "player/autokickdisabled.h"
#include "player/availableentitysteadystate.h"
#include "player/predict.h"
#include "player/tickbase.h"
#include "player/lerptime.h"
#include "player/lastrealcommandnumberexecuted.h"
#include "player/lastplayertalktime.h"
#include "player/lastlatecommandexecuted.h"
#include "player/lastentitysteadystate.h"
#include "player/lagcompensation.h"
#include "player/islowviolence.h"
#include "player/ishltv.h"
#include "player/hasanysteadystateents.h"
#include "player/gamepaused.h"
#include "player/highestgeneratedserverviewanglechangeindex.h"
#include "player/hidehud.h"
#include "player/inithud.h"
#include "player/hltvreplaydelay.h"
#include "player/hltvreplayend.h"
#include "player/characterdefindex.h"
#include "player/hasfemalevoice.h"
#include "player/inhostageresetzone.h"
#include "player/inbuyzone.h"
#include "player/wasinbuyzone.h"
#include "player/inhostagerescuezone.h"
#include "player/inbombzone.h"
#include "player/wasinhostagerescuezone.h"
#include "player/retakesoffering.h"
#include "player/retakesofferingcard.h"
#include "player/retakeshasdefusekit.h"
#include "player/retakesmvplastround.h"
#include "player/retakesmvpboostitem.h"
#include "player/landseconds.h"
#include "player/aimpunchtickbase.h"
#include "player/aimpunchtickfraction.h"
#include "player/isbuymenuopen.h"
#include "player/lastheadbonetransformisvalid.h"
#include "player/lastlandtime.h"
#include "player/ongroundlasttick.h"
#include "player/playerlocked.h"
#include "player/timeoflastinjury.h"
#include "player/nextspraydecaltime.h"
#include "player/nextspraydecaltimeexpedited.h"
#include "player/ragdolldamagebone.h"
#include "player/ragdolldamageheadshot.h"
#include "player/econgloveschanged.h"
#include "player/skiponeheadconstraintupdate.h"
#include "player/hascommunicationabusemute.h"
#include "player/pendingteamnum.h"
#include "player/forceteamtime.h"
#include "player/compteammatecolor.h"
#include "player/everplayedonteam.h"
#include "player/attemptedtogetcolor.h"
#include "player/teammatepreferredcolor.h"
#include "player/teamchanged.h"
#include "player/inswitchteam.h"
#include "player/hasseenjoingame.h"
#include "player/justbecamespectator.h"
#include "player/switchteamsonnextroundreset.h"
#include "player/removeallitemsonnextroundreset.h"
#include "player/competitiverankingpredicted_win.h"
#include "player/competitiverankingpredicted_loss.h"
#include "player/competitiverankingpredicted_tie.h"
#include "player/endmatchnextmapvote.h"
#include "player/activequestid.h"
#include "player/playertvcontrolflags.h"
#include "player/draftindex.h"
#include "player/queuedmodedisconnectiontimestamp.h"
#include "player/abandonrecordedreason.h"
#include "player/cannotbekicked.h"
#include "player/everfullyconnected.h"
#include "player/abandonallowssurrender.h"
#include "player/abandonoffersinstantsurrender.h"
#include "player/disconnection1minwarningprinted.h"
#include "player/scorereported.h"
#include "player/disconnectiontick.h"
#include "player/controllingbot.h"
#include "player/hascontrolledbotthisround.h"
#include "player/hasbeencontrolledbyplayerthisround.h"
#include "player/botscontrolledthisround.h"
#include "player/cancontrolobservedbot.h"
#include "player/desiredobservermode.h"
#include "player/pawncharacterdefindex.h"
#include "player/pawnlifetimestart.h"
#include "player/pawnlifetimeend.h"
#include "player/pawnbotdifficulty.h"
#include "player/score.h"
#include "player/roundscore.h"
#include "player/roundswon.h"
#include "player/mvps.h"
#include "player/updatecounter.h"
#include "player/showhints.h"
#include "player/nexttimecheck.h"
#include "player/justdidteamkill.h"
#include "player/punishforteamkill.h"
#include "player/gaveteamdamagewarning.h"
#include "player/gaveteamdamagewarningthisround.h"
#include "player/lastreceivedpacketplatfloattime.h"
#include "player/lastteamdamagewarningtime.h"
#include "player/lasttimeplayerwasdisconnectedforpawnsremove.h"
#include "player/suspicioushitcount.h"
#include "player/nonsuspicioushitstreak.h"
#include "player/displayhistorybits.h"
#include "player/lastattackedteammate.h"
#include "player/blinduntiltime.h"
#include "player/blindstarttime.h"
#include "player/allowautofollowtime.h"
#include "player/spotrules.h"
#include "player/playerstate.h"
#include "player/lastdistancetravelednotice.h"
#include "player/accumulateddistancetraveled.h"
#include "player/lastfriendlyfiredamagereductionratio.h"
#include "player/respawning.h"
#include "player/lastpickuppriority.h"
#include "player/lastpickupprioritytime.h"
#include "player/isscoped.h"
#include "player/iswalking.h"
#include "player/resumezoom.h"
#include "player/isdefusing.h"
#include "player/isgrabbinghostage.h"
#include "player/blockinguseactioninprogress.h"
#include "player/immunetogungamedamagetime.h"
#include "player/gungameimmunity.h"
#include "player/molotovdamagetime.h"
#include "player/hasmovedsincespawn.h"
#include "player/canmoveduringfreezeperiod.h"
#include "player/guardiantoofardistfrac.h"
#include "player/nextguardiantoofarhurttime.h"
#include "player/detectedbyenemysensortime.h"
#include "player/dealtdamagetoenemymostrecenttimestamp.h"
#include "player/lastequippedhelmettime.h"
#include "player/lastequippedarmortime.h"
#include "player/heavyassaultsuitcooldownremaining.h"
#include "player/resetarmornextspawn.h"
#include "player/lastbumpminebumptime.h"
#include "player/emitsoundtime.h"
#include "player/numspawns.h"
#include "player/shouldhavecash.h"
#include "player/invalidsteamlogondelayed.h"
#include "player/lastaction.h"
#include "player/lastgivendefusertime.h"
#include "player/lastgivenbombtime.h"
#include "player/hasnightvision.h"
#include "player/nightvisionon.h"
#include "player/nextradarupdatetime.h"
#include "player/lastmoneyupdatetime.h"
#include "player/introcamtime.h"
#include "player/innodefusearea.h"
#include "player/killedbytaser.h"
#include "player/movestate.h"
#include "player/grenadeparameterstashtime.h"
#include "player/grenadeparametersstashed.h"
#include "player/diedairborne.h"
#include "player/whichbombzone.h"
#include "player/inbombzonetrigger.h"
#include "player/wasinbombzonetrigger.h"
#include "player/direction.h"
#include "player/shotsfired.h"
#include "player/flinchstack.h"
#include "player/hitheading.h"
#include "player/hitbodypart.h"
#include "player/hostageskilled.h"
#include "player/flashmaxalpha.h"
#include "player/progressbarstarttime.h"
#include "player/progressbarduration.h"
#include "player/waitfornoattack.h"
#include "player/lowerbodyyawtarget.h"
#include "player/strafing.h"
#include "player/ignoreladderjumptime.h"
#include "player/slopedropoffset.h"
#include "player/slopedropheight.h"
#include "player/lastweaponfireusercmd.h"
#include "player/vcollisioninitted.h"
#include "player/isspawning.h"
#include "player/hidetargetid.h"
#include "player/numdangerzonedamagehits.h"
#include "player/hud_miniscorehidden.h"
#include "player/hud_radarhidden.h"
#include "player/lastconcurrentkilled.h"
#include "player/deathcammusic.h"
#include "player/addonbits.h"
#include "player/primaryaddon.h"
#include "player/secondaryaddon.h"
#include "player/numenemieskilledthisspawn.h"
#include "player/numenemieskilledthisround.h"
#include "player/numenemiesatroundstart.h"
#include "player/wasnotkillednaturally.h"
#include "player/deathflags.h"
#include "player/currentequipmentvalue.h"
#include "player/roundstartequipmentvalue.h"
#include "player/freezetimeendequipmentvalue.h"
#include "player/survivalteamnumber.h"
#include "player/hasdeathinfo.h"
#include "player/deathinfotime.h"
#include "player/killedbyheadshot.h"
#include "player/lasthitbox.h"
#include "player/lasthealth.h"
#include "player/lastcollisionceiling.h"
#include "player/lastcollisionceilingchangetime.h"
#include "player/botallowactive.h"
#include "player/committingsuicideonteamchange.h"

class Player
{
private:
    uint32_t m_playerSlot;
    bool m_fakeClient = false;

public:
    Health *health;
    Armor *armor;
    ClanTag *clantag;
    Team *team;
    Vars *vars;
    Stats *stats;
    Coords *coords;
    Money *money;
    Velocity *velocity;
    Weapons *weapons;
    Gravity *gravity;
    Speed *speed;
    EyeAngle *eyeangle;
    Fov *fov;
    AutoKickDisabled *autokickdisabled;
    AvailableEntitySteadyState *availableentitysteadystate;
    Predict *predict;
    TickBase *tickbase;
    LerpTime *lerptime;
    LastRealCommandNumberExecuted *lastrealcommandnumberexecuted;
    LastPlayerTalkTime *lastplayertalktime;
    LastLateCommandExecuted *lastlatecommandexecuted;
    LastEntitySteadyState *lastentitysteadystate;
    LagCompensation *lagcompensation;
    IsLowViolence *islowviolence;
    IsHLTV *ishltv;
    HasAnySteadyStateEnts *hasanysteadystateents;
    GamePaused *gamepaused;
    HighestGeneratedServerViewAngleChangeIndex *highestgeneratedserverviewanglechangeindex;
    HideHUD *hidehud;
    InitHUD *inithud;
    HltvReplayDelay *hltvreplaydelay;
    HltvReplayEnd *hltvreplayend;
    CharacterDefIndex *characterdefindex;
    HasFemaleVoice *hasfemalevoice;
    InHostageResetZone *inhostageresetzone;
    InBuyZone *inbuyzone;
    WasInBuyZone *wasinbuyzone;
    InHostageRescueZone *inhostagerescuezone;
    InBombZone *inbombzone;
    WasInHostageRescueZone *wasinhostagerescuezone;
    RetakesOffering *retakesoffering;
    RetakesOfferingCard *retakesofferingcard;
    RetakesHasDefuseKit *retakeshasdefusekit;
    RetakesMVPLastRound *retakesmvplastround;
    RetakesMVPBoostItem *retakesmvpboostitem;
    Landseconds *landseconds;
    AimPunchTickBase *aimpunchtickbase;
    AimPunchTickFraction *aimpunchtickfraction;
    IsBuyMenuOpen *isbuymenuopen;
    LastHeadBoneTransformIsValid *lastheadbonetransformisvalid;
    LastLandTime *lastlandtime;
    OnGroundLastTick *ongroundlasttick;
    PlayerLocked *playerlocked;
    TimeOfLastInjury *timeoflastinjury;
    NextSprayDecalTime *nextspraydecaltime;
    NextSprayDecalTimeExpedited *nextspraydecaltimeexpedited;
    RagdollDamageBone *ragdolldamagebone;
    RagdollDamageHeadshot *ragdolldamageheadshot;
    EconGlovesChanged *econgloveschanged;
    SkipOneHeadConstraintUpdate *skiponeheadconstraintupdate;
    HasCommunicationAbuseMute *hascommunicationabusemute;
    PendingTeamNum *pendingteamnum;
    ForceTeamTime *forceteamtime;
    CompTeammateColor *compteammatecolor;
    EverPlayedOnTeam *everplayedonteam;
    AttemptedToGetColor *attemptedtogetcolor;
    TeammatePreferredColor *teammatepreferredcolor;
    TeamChanged *teamchanged;
    InSwitchTeam *inswitchteam;
    HasSeenJoinGame *hasseenjoingame;
    JustBecameSpectator *justbecamespectator;
    SwitchTeamsOnNextRoundReset *switchteamsonnextroundreset;
    RemoveAllItemsOnNextRoundReset *removeallitemsonnextroundreset;
    CompetitiveRankingPredicted_Win *competitiverankingpredicted_win;
    CompetitiveRankingPredicted_Loss *competitiverankingpredicted_loss;
    CompetitiveRankingPredicted_Tie *competitiverankingpredicted_tie;
    EndMatchNextMapVote *endmatchnextmapvote;
    ActiveQuestId *activequestid;
    PlayerTvControlFlags *playertvcontrolflags;
    DraftIndex *draftindex;
    QueuedModeDisconnectionTimestamp *queuedmodedisconnectiontimestamp;
    AbandonRecordedReason *abandonrecordedreason;
    CannotBeKicked *cannotbekicked;
    EverFullyConnected *everfullyconnected;
    AbandonAllowsSurrender *abandonallowssurrender;
    AbandonOffersInstantSurrender *abandonoffersinstantsurrender;
    Disconnection1MinWarningPrinted *disconnection1minwarningprinted;
    ScoreReported *scorereported;
    DisconnectionTick *disconnectiontick;
    ControllingBot *controllingbot;
    HasControlledBotThisRound *hascontrolledbotthisround;
    HasBeenControlledByPlayerThisRound *hasbeencontrolledbyplayerthisround;
    BotsControlledThisRound *botscontrolledthisround;
    CanControlObservedBot *cancontrolobservedbot;
    DesiredObserverMode *desiredobservermode;
    PawnCharacterDefIndex *pawncharacterdefindex;
    PawnLifetimeStart *pawnlifetimestart;
    PawnLifetimeEnd *pawnlifetimeend;
    PawnBotDifficulty *pawnbotdifficulty;
    Score *score;
    RoundScore *roundscore;
    RoundsWon *roundswon;
    MVPs *mvps;
    UpdateCounter *updatecounter;
    ShowHints *showhints;
    NextTimeCheck *nexttimecheck;
    JustDidTeamKill *justdidteamkill;
    PunishForTeamKill *punishforteamkill;
    GaveTeamDamageWarning *gaveteamdamagewarning;
    GaveTeamDamageWarningThisRound *gaveteamdamagewarningthisround;
    LastReceivedPacketPlatFloatTime *lastreceivedpacketplatfloattime;
    LastTeamDamageWarningTime *lastteamdamagewarningtime;
    LastTimePlayerWasDisconnectedForPawnsRemove *lasttimeplayerwasdisconnectedforpawnsremove;
    SuspiciousHitCount *suspicioushitcount;
    NonSuspiciousHitStreak *nonsuspicioushitstreak;
    DisplayHistoryBits *displayhistorybits;
    LastAttackedTeammate *lastattackedteammate;
    BlindUntilTime *blinduntiltime;
    BlindStartTime *blindstarttime;
    allowAutoFollowTime *allowautofollowtime;
    SpotRules *spotrules;
    PlayerState *playerstate;
    LastDistanceTraveledNotice *lastdistancetravelednotice;
    AccumulatedDistanceTraveled *accumulateddistancetraveled;
    LastFriendlyFireDamageReductionRatio *lastfriendlyfiredamagereductionratio;
    Respawning *respawning;
    LastPickupPriority *lastpickuppriority;
    LastPickupPriorityTime *lastpickupprioritytime;
    IsScoped *isscoped;
    IsWalking *iswalking;
    ResumeZoom *resumezoom;
    IsDefusing *isdefusing;
    IsGrabbingHostage *isgrabbinghostage;
    BlockingUseActionInProgress *blockinguseactioninprogress;
    ImmuneToGunGameDamageTime *immunetogungamedamagetime;
    GunGameImmunity *gungameimmunity;
    MolotovDamageTime *molotovdamagetime;
    HasMovedSinceSpawn *hasmovedsincespawn;
    CanMoveDuringFreezePeriod *canmoveduringfreezeperiod;
    GuardianTooFarDistFrac *guardiantoofardistfrac;
    NextGuardianTooFarHurtTime *nextguardiantoofarhurttime;
    DetectedByEnemySensorTime *detectedbyenemysensortime;
    DealtDamageToEnemyMostRecentTimestamp *dealtdamagetoenemymostrecenttimestamp;
    LastEquippedHelmetTime *lastequippedhelmettime;
    LastEquippedArmorTime *lastequippedarmortime;
    HeavyAssaultSuitCooldownRemaining *heavyassaultsuitcooldownremaining;
    ResetArmorNextSpawn *resetarmornextspawn;
    LastBumpMineBumpTime *lastbumpminebumptime;
    EmitSoundTime *emitsoundtime;
    NumSpawns *numspawns;
    ShouldHaveCash *shouldhavecash;
    InvalidSteamLogonDelayed *invalidsteamlogondelayed;
    LastAction *lastaction;
    LastGivenDefuserTime *lastgivendefusertime;
    LastGivenBombTime *lastgivenbombtime;
    HasNightVision *hasnightvision;
    NightVisionOn *nightvisionon;
    NextRadarUpdateTime *nextradarupdatetime;
    LastMoneyUpdateTime *lastmoneyupdatetime;
    IntroCamTime *introcamtime;
    InNoDefuseArea *innodefusearea;
    KilledByTaser *killedbytaser;
    MoveState *movestate;
    GrenadeParameterStashTime *grenadeparameterstashtime;
    GrenadeParametersStashed *grenadeparametersstashed;
    DiedAirborne *diedairborne;
    WhichBombZone *whichbombzone;
    InBombZoneTrigger *inbombzonetrigger;
    WasInBombZoneTrigger *wasinbombzonetrigger;
    Direction *direction;
    ShotsFired *shotsfired;
    FlinchStack *flinchstack;
    HitHeading *hitheading;
    HitBodyPart *hitbodypart;
    HostagesKilled *hostageskilled;
    FlashMaxAlpha *flashmaxalpha;
    ProgressBarStartTime *progressbarstarttime;
    ProgressBarDuration *progressbarduration;
    WaitForNoAttack *waitfornoattack;
    LowerBodyYawTarget *lowerbodyyawtarget;
    Strafing *strafing;
    IgnoreLadderJumpTime *ignoreladderjumptime;
    SlopeDropOffset *slopedropoffset;
    SlopeDropHeight *slopedropheight;
    LastWeaponFireUsercmd *lastweaponfireusercmd;
    VCollisionInitted *vcollisioninitted;
    IsSpawning *isspawning;
    HideTargetID *hidetargetid;
    NumDangerZoneDamageHits *numdangerzonedamagehits;
    Hud_MiniScoreHidden *hud_miniscorehidden;
    Hud_RadarHidden *hud_radarhidden;
    LastConcurrentKilled *lastconcurrentkilled;
    DeathCamMusic *deathcammusic;
    AddonBits *addonbits;
    PrimaryAddon *primaryaddon;
    SecondaryAddon *secondaryaddon;
    NumEnemiesKilledThisSpawn *numenemieskilledthisspawn;
    NumEnemiesKilledThisRound *numenemieskilledthisround;
    NumEnemiesAtRoundStart *numenemiesatroundstart;
    WasNotKilledNaturally *wasnotkillednaturally;
    DeathFlags *deathflags;
    CurrentEquipmentValue *currentequipmentvalue;
    RoundStartEquipmentValue *roundstartequipmentvalue;
    FreezetimeEndEquipmentValue *freezetimeendequipmentvalue;
    SurvivalTeamNumber *survivalteamnumber;
    HasDeathInfo *hasdeathinfo;
    DeathInfoTime *deathinfotime;
    KilledByHeadshot *killedbyheadshot;
    LastHitBox *lasthitbox;
    LastHealth *lasthealth;
    LastCollisionCeiling *lastcollisionceiling;
    LastCollisionCeilingChangeTime *lastcollisionceilingchangetime;
    BotAllowActive *botallowactive;
    CommittingSuicideOnTeamChange *committingsuicideonteamchange;

public:
    Player(uint32_t playerSlot, bool fakeClient) : m_playerSlot(playerSlot), m_fakeClient(fakeClient)
    {
        this->health = new Health(playerSlot);
        this->armor = new Armor(playerSlot);
        this->clantag = new ClanTag(playerSlot);
        this->team = new Team(playerSlot);
        this->vars = new Vars(playerSlot);
        this->stats = new Stats(playerSlot);
        this->coords = new Coords(playerSlot);
        this->money = new Money(playerSlot);
        this->velocity = new Velocity(playerSlot);
        this->weapons = new Weapons(playerSlot);
        this->gravity = new Gravity(playerSlot);
        this->speed = new Speed(playerSlot);
        this->eyeangle = new EyeAngle(playerSlot);
        this->fov = new Fov(playerSlot);
        this->lastrealcommandnumberexecuted = new LastRealCommandNumberExecuted(playerSlot);
        this->autokickdisabled = new AutoKickDisabled(playerSlot);
        this->availableentitysteadystate = new AvailableEntitySteadyState(playerSlot);
        this->predict = new Predict(playerSlot);
        this->tickbase = new TickBase(playerSlot);
        this->lerptime = new LerpTime(playerSlot);
        this->lastplayertalktime = new LastPlayerTalkTime(playerSlot);
        this->lastlatecommandexecuted = new LastLateCommandExecuted(playerSlot);
        this->lastentitysteadystate = new LastEntitySteadyState(playerSlot);
        this->lagcompensation = new LagCompensation(playerSlot);
        this->islowviolence = new IsLowViolence(playerSlot);
        this->gamepaused = new GamePaused(playerSlot);
        this->ishltv = new IsHLTV(playerSlot);
        this->hasanysteadystateents = new HasAnySteadyStateEnts(playerSlot);
        this->highestgeneratedserverviewanglechangeindex = new HighestGeneratedServerViewAngleChangeIndex(playerSlot);
        this->hidehud = new HideHUD(playerSlot);
        this->inithud = new InitHUD(playerSlot);
        this->hltvreplaydelay = new HltvReplayDelay(playerSlot);
        this->hltvreplayend = new HltvReplayEnd(playerSlot);
        this->characterdefindex = new CharacterDefIndex(playerSlot);
        this->hasfemalevoice = new HasFemaleVoice(playerSlot);
        this->inhostageresetzone = new InHostageResetZone(playerSlot);
        this->inbuyzone = new InBuyZone(playerSlot);
        this->wasinbuyzone = new WasInBuyZone(playerSlot);
        this->inhostagerescuezone = new InHostageRescueZone(playerSlot);
        this->inbombzone = new InBombZone(playerSlot);
        this->wasinhostagerescuezone = new WasInHostageRescueZone(playerSlot);
        this->retakesoffering = new RetakesOffering(playerSlot);
        this->retakesofferingcard = new RetakesOfferingCard(playerSlot);
        this->retakeshasdefusekit = new RetakesHasDefuseKit(playerSlot);
        this->retakesmvplastround = new RetakesMVPLastRound(playerSlot);
        this->retakesmvpboostitem = new RetakesMVPBoostItem(playerSlot);
        this->landseconds = new Landseconds(playerSlot);
        this->aimpunchtickbase = new AimPunchTickBase(playerSlot);
        this->aimpunchtickfraction = new AimPunchTickFraction(playerSlot);
        this->isbuymenuopen = new IsBuyMenuOpen(playerSlot);
        this->lastheadbonetransformisvalid = new LastHeadBoneTransformIsValid(playerSlot);
        this->lastlandtime = new LastLandTime(playerSlot);
        this->ongroundlasttick = new OnGroundLastTick(playerSlot);
        this->playerlocked = new PlayerLocked(playerSlot);
        this->timeoflastinjury = new TimeOfLastInjury(playerSlot);
        this->nextspraydecaltime = new NextSprayDecalTime(playerSlot);
        this->nextspraydecaltimeexpedited = new NextSprayDecalTimeExpedited(playerSlot);
        this->ragdolldamagebone = new RagdollDamageBone(playerSlot);
        this->ragdolldamageheadshot = new RagdollDamageHeadshot(playerSlot);
        this->econgloveschanged = new EconGlovesChanged(playerSlot);
        this->skiponeheadconstraintupdate = new SkipOneHeadConstraintUpdate(playerSlot);
        this->hascommunicationabusemute = new HasCommunicationAbuseMute(playerSlot);
        this->pendingteamnum = new PendingTeamNum(playerSlot);
        this->forceteamtime = new ForceTeamTime(playerSlot);
        this->compteammatecolor = new CompTeammateColor(playerSlot);
        this->everplayedonteam = new EverPlayedOnTeam(playerSlot);
        this->attemptedtogetcolor = new AttemptedToGetColor(playerSlot);
        this->teammatepreferredcolor = new TeammatePreferredColor(playerSlot);
        this->teamchanged = new TeamChanged(playerSlot);
        this->inswitchteam = new InSwitchTeam(playerSlot);
        this->hasseenjoingame = new HasSeenJoinGame(playerSlot);
        this->justbecamespectator = new JustBecameSpectator(playerSlot);
        this->switchteamsonnextroundreset = new SwitchTeamsOnNextRoundReset(playerSlot);
        this->removeallitemsonnextroundreset = new RemoveAllItemsOnNextRoundReset(playerSlot);
        this->competitiverankingpredicted_win = new CompetitiveRankingPredicted_Win(playerSlot);
        this->competitiverankingpredicted_loss = new CompetitiveRankingPredicted_Loss(playerSlot);
        this->competitiverankingpredicted_tie = new CompetitiveRankingPredicted_Tie(playerSlot);
        this->endmatchnextmapvote = new EndMatchNextMapVote(playerSlot);
        this->activequestid = new ActiveQuestId(playerSlot);
        this->playertvcontrolflags = new PlayerTvControlFlags(playerSlot);
        this->draftindex = new DraftIndex(playerSlot);
        this->queuedmodedisconnectiontimestamp = new QueuedModeDisconnectionTimestamp(playerSlot);
        this->abandonrecordedreason = new AbandonRecordedReason(playerSlot);
        this->cannotbekicked = new CannotBeKicked(playerSlot);
        this->everfullyconnected = new EverFullyConnected(playerSlot);
        this->abandonallowssurrender = new AbandonAllowsSurrender(playerSlot);
        this->abandonoffersinstantsurrender = new AbandonOffersInstantSurrender(playerSlot);
        this->disconnection1minwarningprinted = new Disconnection1MinWarningPrinted(playerSlot);
        this->scorereported = new ScoreReported(playerSlot);
        this->disconnectiontick = new DisconnectionTick(playerSlot);
        this->controllingbot = new ControllingBot(playerSlot);
        this->hascontrolledbotthisround = new HasControlledBotThisRound(playerSlot);
        this->hasbeencontrolledbyplayerthisround = new HasBeenControlledByPlayerThisRound(playerSlot);
        this->botscontrolledthisround = new BotsControlledThisRound(playerSlot);
        this->cancontrolobservedbot = new CanControlObservedBot(playerSlot);
        this->desiredobservermode = new DesiredObserverMode(playerSlot);
        this->pawncharacterdefindex = new PawnCharacterDefIndex(playerSlot);
        this->pawnlifetimestart = new PawnLifetimeStart(playerSlot);
        this->pawnlifetimeend = new PawnLifetimeEnd(playerSlot);
        this->pawnbotdifficulty = new PawnBotDifficulty(playerSlot);
        this->score = new Score(playerSlot);
        this->roundscore = new RoundScore(playerSlot);
        this->roundswon = new RoundsWon(playerSlot);
        this->mvps = new MVPs(playerSlot);
        this->updatecounter = new UpdateCounter(playerSlot);
        this->showhints = new ShowHints(playerSlot);
        this->nexttimecheck = new NextTimeCheck(playerSlot);
        this->justdidteamkill = new JustDidTeamKill(playerSlot);
        this->punishforteamkill = new PunishForTeamKill(playerSlot);
        this->gaveteamdamagewarning = new GaveTeamDamageWarning(playerSlot);
        this->gaveteamdamagewarningthisround = new GaveTeamDamageWarningThisRound(playerSlot);
        this->lastreceivedpacketplatfloattime = new LastReceivedPacketPlatFloatTime(playerSlot);
        this->lastteamdamagewarningtime = new LastTeamDamageWarningTime(playerSlot);
        this->lasttimeplayerwasdisconnectedforpawnsremove = new LastTimePlayerWasDisconnectedForPawnsRemove(playerSlot);
        this->suspicioushitcount = new SuspiciousHitCount(playerSlot);
        this->nonsuspicioushitstreak = new NonSuspiciousHitStreak(playerSlot);
        this->displayhistorybits = new DisplayHistoryBits(playerSlot);
        this->lastattackedteammate = new LastAttackedTeammate(playerSlot);
        this->blinduntiltime = new BlindUntilTime(playerSlot);
        this->blindstarttime = new BlindStartTime(playerSlot);
        this->allowautofollowtime = new allowAutoFollowTime(playerSlot);
        this->spotrules = new SpotRules(playerSlot);
        this->playerstate = new PlayerState(playerSlot);
        this->lastdistancetravelednotice = new LastDistanceTraveledNotice(playerSlot);
        this->accumulateddistancetraveled = new AccumulatedDistanceTraveled(playerSlot);
        this->lastfriendlyfiredamagereductionratio = new LastFriendlyFireDamageReductionRatio(playerSlot);
        this->respawning = new Respawning(playerSlot);
        this->lastpickuppriority = new LastPickupPriority(playerSlot);
        this->lastpickupprioritytime = new LastPickupPriorityTime(playerSlot);
        this->isscoped = new IsScoped(playerSlot);
        this->iswalking = new IsWalking(playerSlot);
        this->resumezoom = new ResumeZoom(playerSlot);
        this->isdefusing = new IsDefusing(playerSlot);
        this->isgrabbinghostage = new IsGrabbingHostage(playerSlot);
        this->blockinguseactioninprogress = new BlockingUseActionInProgress(playerSlot);
        this->immunetogungamedamagetime = new ImmuneToGunGameDamageTime(playerSlot);
        this->gungameimmunity = new GunGameImmunity(playerSlot);
        this->molotovdamagetime = new MolotovDamageTime(playerSlot);
        this->hasmovedsincespawn = new HasMovedSinceSpawn(playerSlot);
        this->canmoveduringfreezeperiod = new CanMoveDuringFreezePeriod(playerSlot);
        this->guardiantoofardistfrac = new GuardianTooFarDistFrac(playerSlot);
        this->nextguardiantoofarhurttime = new NextGuardianTooFarHurtTime(playerSlot);
        this->detectedbyenemysensortime = new DetectedByEnemySensorTime(playerSlot);
        this->dealtdamagetoenemymostrecenttimestamp = new DealtDamageToEnemyMostRecentTimestamp(playerSlot);
        this->lastequippedhelmettime = new LastEquippedHelmetTime(playerSlot);
        this->lastequippedarmortime = new LastEquippedArmorTime(playerSlot);
        this->heavyassaultsuitcooldownremaining = new HeavyAssaultSuitCooldownRemaining(playerSlot);
        this->resetarmornextspawn = new ResetArmorNextSpawn(playerSlot);
        this->lastbumpminebumptime = new LastBumpMineBumpTime(playerSlot);
        this->emitsoundtime = new EmitSoundTime(playerSlot);
        this->numspawns = new NumSpawns(playerSlot);
        this->shouldhavecash = new ShouldHaveCash(playerSlot);
        this->invalidsteamlogondelayed = new InvalidSteamLogonDelayed(playerSlot);
        this->lastaction = new LastAction(playerSlot);
        this->lastgivendefusertime = new LastGivenDefuserTime(playerSlot);
        this->lastgivenbombtime = new LastGivenBombTime(playerSlot);
        this->hasnightvision = new HasNightVision(playerSlot);
        this->nightvisionon = new NightVisionOn(playerSlot);
        this->nextradarupdatetime = new NextRadarUpdateTime(playerSlot);
        this->lastmoneyupdatetime = new LastMoneyUpdateTime(playerSlot);
        this->introcamtime = new IntroCamTime(playerSlot);
        this->innodefusearea = new InNoDefuseArea(playerSlot);
        this->killedbytaser = new KilledByTaser(playerSlot);
        this->movestate = new MoveState(playerSlot);
        this->grenadeparameterstashtime = new GrenadeParameterStashTime(playerSlot);
        this->grenadeparametersstashed = new GrenadeParametersStashed(playerSlot);
        this->diedairborne = new DiedAirborne(playerSlot);
        this->whichbombzone = new WhichBombZone(playerSlot);
        this->inbombzonetrigger = new InBombZoneTrigger(playerSlot);
        this->wasinbombzonetrigger = new WasInBombZoneTrigger(playerSlot);
        this->direction = new Direction(playerSlot);
        this->shotsfired = new ShotsFired(playerSlot);
        this->flinchstack = new FlinchStack(playerSlot);
        this->hitheading = new HitHeading(playerSlot);
        this->hitbodypart = new HitBodyPart(playerSlot);
        this->hostageskilled = new HostagesKilled(playerSlot);
        this->flashmaxalpha = new FlashMaxAlpha(playerSlot);
        this->progressbarstarttime = new ProgressBarStartTime(playerSlot);
        this->progressbarduration = new ProgressBarDuration(playerSlot);
        this->waitfornoattack = new WaitForNoAttack(playerSlot);
        this->lowerbodyyawtarget = new LowerBodyYawTarget(playerSlot);
        this->strafing = new Strafing(playerSlot);
        this->ignoreladderjumptime = new IgnoreLadderJumpTime(playerSlot);
        this->slopedropoffset = new SlopeDropOffset(playerSlot);
        this->slopedropheight = new SlopeDropHeight(playerSlot);
        this->lastweaponfireusercmd = new LastWeaponFireUsercmd(playerSlot);
        this->vcollisioninitted = new VCollisionInitted(playerSlot);
        this->isspawning = new IsSpawning(playerSlot);
        this->hidetargetid = new HideTargetID(playerSlot);
        this->numdangerzonedamagehits = new NumDangerZoneDamageHits(playerSlot);
        this->hud_miniscorehidden = new Hud_MiniScoreHidden(playerSlot);
        this->hud_radarhidden = new Hud_RadarHidden(playerSlot);
        this->lastconcurrentkilled = new LastConcurrentKilled(playerSlot);
        this->deathcammusic = new DeathCamMusic(playerSlot);
        this->addonbits = new AddonBits(playerSlot);
        this->primaryaddon = new PrimaryAddon(playerSlot);
        this->secondaryaddon = new SecondaryAddon(playerSlot);
        this->numenemieskilledthisspawn = new NumEnemiesKilledThisSpawn(playerSlot);
        this->numenemieskilledthisround = new NumEnemiesKilledThisRound(playerSlot);
        this->numenemiesatroundstart = new NumEnemiesAtRoundStart(playerSlot);
        this->wasnotkillednaturally = new WasNotKilledNaturally(playerSlot);
        this->deathflags = new DeathFlags(playerSlot);
        this->currentequipmentvalue = new CurrentEquipmentValue(playerSlot);
        this->roundstartequipmentvalue = new RoundStartEquipmentValue(playerSlot);
        this->freezetimeendequipmentvalue = new FreezetimeEndEquipmentValue(playerSlot);
        this->survivalteamnumber = new SurvivalTeamNumber(playerSlot);
        this->hasdeathinfo = new HasDeathInfo(playerSlot);
        this->deathinfotime = new DeathInfoTime(playerSlot);
        this->killedbyheadshot = new KilledByHeadshot(playerSlot);
        this->lasthitbox = new LastHitBox(playerSlot);
        this->lasthealth = new LastHealth(playerSlot);
        this->lastcollisionceiling = new LastCollisionCeiling(playerSlot);
        this->lastcollisionceilingchangetime = new LastCollisionCeilingChangeTime(playerSlot);
        this->botallowactive = new BotAllowActive(playerSlot);
        this->committingsuicideonteamchange = new CommittingSuicideOnTeamChange(playerSlot);
    }

    ~Player()
    {
        delete this->health;
        delete this->armor;
        delete this->clantag;
        delete this->team;
        delete this->vars;
        delete this->stats;
        delete this->coords;
        delete this->money;
        delete this->velocity;
        delete this->weapons;
        delete this->gravity;
        delete this->speed;
        delete this->eyeangle;
        delete this->fov;
        delete this->autokickdisabled;
        delete this->availableentitysteadystate;
        delete this->predict;
        delete this->lastrealcommandnumberexecuted;
        delete this->lagcompensation;
        delete this->tickbase;
        delete this->islowviolence;
        delete this->lastplayertalktime;
        delete this->gamepaused;
        delete this->hasanysteadystateents;
        delete this->lerptime;
        delete this->lastlatecommandexecuted;
        delete this->lastentitysteadystate;
        delete this->ishltv;
        delete this->highestgeneratedserverviewanglechangeindex;
        delete this->hidehud;
        delete this->inithud;
        delete this->hltvreplaydelay;
        delete this->hltvreplayend;
        delete this->characterdefindex;
        delete this->hasfemalevoice;
        delete this->inhostageresetzone;
        delete this->inbuyzone;
        delete this->wasinbuyzone;
        delete this->inhostagerescuezone;
        delete this->inbombzone;
        delete this->wasinhostagerescuezone;
        delete this->retakesoffering;
        delete this->retakesofferingcard;
        delete this->retakeshasdefusekit;
        delete this->retakesmvplastround;
        delete this->retakesmvpboostitem;
        delete this->landseconds;
        delete this->aimpunchtickbase;
        delete this->aimpunchtickfraction;
        delete this->isbuymenuopen;
        delete this->lastheadbonetransformisvalid;
        delete this->lastlandtime;
        delete this->ongroundlasttick;
        delete this->playerlocked;
        delete this->timeoflastinjury;
        delete this->nextspraydecaltime;
        delete this->nextspraydecaltimeexpedited;
        delete this->ragdolldamagebone;
        delete this->ragdolldamageheadshot;
        delete this->econgloveschanged;
        delete this->skiponeheadconstraintupdate;
        delete this->hascommunicationabusemute;
        delete this->pendingteamnum;
        delete this->forceteamtime;
        delete this->compteammatecolor;
        delete this->everplayedonteam;
        delete this->attemptedtogetcolor;
        delete this->teammatepreferredcolor;
        delete this->teamchanged;
        delete this->inswitchteam;
        delete this->hasseenjoingame;
        delete this->justbecamespectator;
        delete this->switchteamsonnextroundreset;
        delete this->removeallitemsonnextroundreset;
        delete this->competitiverankingpredicted_win;
        delete this->competitiverankingpredicted_loss;
        delete this->competitiverankingpredicted_tie;
        delete this->endmatchnextmapvote;
        delete this->activequestid;
        delete this->playertvcontrolflags;
        delete this->draftindex;
        delete this->queuedmodedisconnectiontimestamp;
        delete this->abandonrecordedreason;
        delete this->cannotbekicked;
        delete this->everfullyconnected;
        delete this->abandonallowssurrender;
        delete this->abandonoffersinstantsurrender;
        delete this->disconnection1minwarningprinted;
        delete this->scorereported;
        delete this->disconnectiontick;
        delete this->controllingbot;
        delete this->hascontrolledbotthisround;
        delete this->hasbeencontrolledbyplayerthisround;
        delete this->botscontrolledthisround;
        delete this->cancontrolobservedbot;
        delete this->desiredobservermode;
        delete this->pawncharacterdefindex;
        delete this->pawnlifetimestart;
        delete this->pawnlifetimeend;
        delete this->pawnbotdifficulty;
        delete this->score;
        delete this->roundscore;
        delete this->roundswon;
        delete this->mvps;
        delete this->updatecounter;
        delete this->showhints;
        delete this->nexttimecheck;
        delete this->justdidteamkill;
        delete this->punishforteamkill;
        delete this->gaveteamdamagewarning;
        delete this->gaveteamdamagewarningthisround;
        delete this->lastreceivedpacketplatfloattime;
        delete this->lastteamdamagewarningtime;
        delete this->lasttimeplayerwasdisconnectedforpawnsremove;
        delete this->suspicioushitcount;
        delete this->nonsuspicioushitstreak;
        delete this->displayhistorybits;
        delete this->lastattackedteammate;
        delete this->blinduntiltime;
        delete this->blindstarttime;
        delete this->allowautofollowtime;
        delete this->spotrules;
        delete this->playerstate;
        delete this->lastdistancetravelednotice;
        delete this->accumulateddistancetraveled;
        delete this->lastfriendlyfiredamagereductionratio;
        delete this->respawning;
        delete this->lastpickuppriority;
        delete this->lastpickupprioritytime;
        delete this->isscoped;
        delete this->iswalking;
        delete this->resumezoom;
        delete this->isdefusing;
        delete this->isgrabbinghostage;
        delete this->blockinguseactioninprogress;
        delete this->immunetogungamedamagetime;
        delete this->gungameimmunity;
        delete this->molotovdamagetime;
        delete this->hasmovedsincespawn;
        delete this->canmoveduringfreezeperiod;
        delete this->guardiantoofardistfrac;
        delete this->nextguardiantoofarhurttime;
        delete this->detectedbyenemysensortime;
        delete this->dealtdamagetoenemymostrecenttimestamp;
        delete this->lastequippedhelmettime;
        delete this->lastequippedarmortime;
        delete this->heavyassaultsuitcooldownremaining;
        delete this->resetarmornextspawn;
        delete this->lastbumpminebumptime;
        delete this->emitsoundtime;
        delete this->numspawns;
        delete this->shouldhavecash;
        delete this->invalidsteamlogondelayed;
        delete this->lastaction;
        delete this->lastgivendefusertime;
        delete this->lastgivenbombtime;
        delete this->hasnightvision;
        delete this->nightvisionon;
        delete this->nextradarupdatetime;
        delete this->lastmoneyupdatetime;
        delete this->introcamtime;
        delete this->innodefusearea;
        delete this->killedbytaser;
        delete this->movestate;
        delete this->grenadeparameterstashtime;
        delete this->grenadeparametersstashed;
        delete this->diedairborne;
        delete this->whichbombzone;
        delete this->inbombzonetrigger;
        delete this->wasinbombzonetrigger;
        delete this->direction;
        delete this->shotsfired;
        delete this->flinchstack;
        delete this->hitheading;
        delete this->hitbodypart;
        delete this->hostageskilled;
        delete this->flashmaxalpha;
        delete this->progressbarstarttime;
        delete this->progressbarduration;
        delete this->waitfornoattack;
        delete this->lowerbodyyawtarget;
        delete this->strafing;
        delete this->ignoreladderjumptime;
        delete this->slopedropoffset;
        delete this->slopedropheight;
        delete this->lastweaponfireusercmd;
        delete this->vcollisioninitted;
        delete this->isspawning;
        delete this->hidetargetid;
        delete this->numdangerzonedamagehits;
        delete this->hud_miniscorehidden;
        delete this->hud_radarhidden;
        delete this->lastconcurrentkilled;
        delete this->deathcammusic;
        delete this->addonbits;
        delete this->primaryaddon;
        delete this->secondaryaddon;
        delete this->numenemieskilledthisspawn;
        delete this->numenemieskilledthisround;
        delete this->numenemiesatroundstart;
        delete this->wasnotkillednaturally;
        delete this->deathflags;
        delete this->currentequipmentvalue;
        delete this->roundstartequipmentvalue;
        delete this->freezetimeendequipmentvalue;
        delete this->survivalteamnumber;
        delete this->hasdeathinfo;
        delete this->deathinfotime;
        delete this->killedbyheadshot;
        delete this->lasthitbox;
        delete this->lasthealth;
        delete this->lastcollisionceiling;
        delete this->lastcollisionceilingchangetime;
        delete this->botallowactive;
        delete this->committingsuicideonteamchange;
    }

    uint32_t GetSlot() { return this->m_playerSlot; }

    const char *GetName()
    {
        REGISTER_METHOD(const char *, "", scripting_Player_GetName, this->m_playerSlot);
    }

    uint64_t GetSteamID()
    {
        REGISTER_METHOD(uint64_t, 0, scripting_Player_GetSteamID, this->m_playerSlot);
    }

    const char *GetSteamID2()
    {
        REGISTER_METHOD(const char *, "STEAM_0:0:000000000", scripting_Player_GetSteamID2, this->m_playerSlot);
    }

    bool IsFirstSpawn()
    {
        REGISTER_METHOD(bool, false, scripting_Player_IsFirstSpawn, this->m_playerSlot);
    }

    bool IsAlive()
    {
        REGISTER_METHOD(bool, false, scripting_Player_IsAlive, this->m_playerSlot);
    }

    bool IsFakeClient()
    {
        REGISTER_METHOD(bool, false, scripting_Player_IsFakeClient, this->m_playerSlot);
    }

    void Drop(ENetworkDisconnectionReason reason)
    {
        REGISTER_METHOD_VOID(scripting_Player_Drop, this->m_playerSlot, reason);
    }

    void Kill()
    {
        REGISTER_METHOD_VOID(scripting_Player_Kill, this->m_playerSlot);
    }

    bool IsAuthenticated()
    {
        REGISTER_METHOD(bool, false, scripting_Player_IsAuthenticated, this->m_playerSlot);
    }

    const char *GetConvarValue(const char *name)
    {
        if (name == nullptr)
            return "";

        REGISTER_METHOD(const char *, "", scripting_Player_GetConvar, this->m_playerSlot, name);
    }

    void SetConvar(const char *name, const char *value)
    {
        if (name == nullptr || value == nullptr)
            return;

        REGISTER_METHOD_VOID(scripting_Player_SetConvar, this->m_playerSlot, name, value);
    }

    const char *GetIPAddress()
    {
        REGISTER_METHOD(const char *, "", scripting_Player_GetIPAddress, this->m_playerSlot);
    }

    void SendMsg(HudDestination dest, const char *message, ...)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, message);
        UTIL_FormatArgs(buffer, sizeof(buffer), message, ap);
        va_end(ap);

        REGISTER_METHOD_VOID(scripting_Player_SendMessage, this->m_playerSlot, dest, buffer);
    }

    uint32_t GetConnectedTime()
    {
        REGISTER_METHOD(uint32_t, 0, scripting_Player_GetConnectedTime, this->m_playerSlot);
    }

    void ExecuteCommand(const char *cmd, ...)
    {
        va_list ap;
        char buffer[2048];

        va_start(ap, cmd);
        UTIL_FormatArgs(buffer, sizeof(buffer), cmd, ap);
        va_end(ap);

        REGISTER_METHOD_VOID(scripting_Player_ExecuteCommand, this->m_playerSlot, buffer);
    }

    void SetModel(const char *model)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetModel, this->m_playerSlot, model);
    }

    void SetMusicKit(int id)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetMusicKit, this->m_playerSlot, id);
    }

    void SetPin(int index)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetPin, this->m_playerSlot, index);
    }

    void ShowMenu(const char *menuid)
    {
        REGISTER_METHOD_VOID(scripting_Player_ShowMenu, this->m_playerSlot, menuid);
    }

    void HideMenu()
    {
        REGISTER_METHOD_VOID(scripting_Player_HideMenu, this->m_playerSlot);
    }

    void SetMoveType(MoveType_t movetype)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetMoveType, this->m_playerSlot, movetype);
    }

    void SetActualMoveType(MoveType_t actualmovetype)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetActualMoveType, this->m_playerSlot, actualmovetype);
    }

    void SetFlashDuration(float duration)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetFlashDuration, this->m_playerSlot, duration);
    }

    void SetGloves(uint16_t defindex, int paintkit, int seed, float wear)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetGloves, this->m_playerSlot, defindex, paintkit, seed, wear);
    }

    int GetLatency()
    {
        REGISTER_METHOD(int, 0, scripting_Player_GetLatency, this->m_playerSlot);
    }

    MoveType_t GetMoveType()
    {
        REGISTER_METHOD(MoveType_t, MOVETYPE_NONE, scripting_Player_GetMoveType, this->m_playerSlot);
    }

    MoveType_t GetActualMoveType()
    {
        REGISTER_METHOD(MoveType_t, MOVETYPE_NONE, scripting_Player_GetActualMoveType, this->m_playerSlot);
    }

    void Respawn()
    {
        REGISTER_METHOD_VOID(scripting_Player_Respawn, this->m_playerSlot);
    }

    void SetHealthShotBoostEffectExpirationTime(float expiretime)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetHealthShotBoostEffectExpirationTime, this->m_playerSlot, expiretime);
    }

    const char *GetChatTag()
    {
        REGISTER_METHOD(const char *, "", scripting_Player_GetChatTag, this->m_playerSlot);
    }

    void SetChatTag(const char *tag)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetChatTag, this->m_playerSlot, tag);
    }

    void SetChatTagColor(const char *color)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetChatTagColor, this->m_playerSlot, color);
    }

    void SetNameColor(const char *color)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetNameColor, this->m_playerSlot, color);
    }

    void SetChatColor(const char *color)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetChatColor, this->m_playerSlot, color);
    }

    void SetName(const char *name)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetName, this->m_playerSlot, name);
    }

    void SetCompetitiveRanking(int ranking)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCompetitiveRanking, this->m_playerSlot, ranking);
    }

    void SetCompetitiveRankType(int type)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCompetitiveRankType, this->m_playerSlot, type);
    }

    void SetCompetitiveWins(int wins)
    {
        REGISTER_METHOD_VOID(scripting_Player_SetCompetitiveWins, this->m_playerSlot, wins);
    }
};

#endif