#include "../scripting.h"

std::map<std::string, bool> BlockedCS2GuidelinesFields = {
    {"m_bIsValveDS", true},
    {"m_bIsQuestEligible", true},
    {"m_iEntityLevel", true},
    {"m_iItemIDHigh", true},
    {"m_iItemIDLow", true},
    {"m_iAccountID", true},
    {"m_iEntityQuality", true},
    {"m_bInitialized", true},
    {"m_szCustomName", true},
    {"m_iAttributeDefinitionIndex", true},
    {"m_iRawValue32", true},
    {"m_iRawInitialValue32", true},
    {"m_flValue", true},
    {"m_flInitialValue", true},
    {"m_bSetBonus", true},
    {"m_nRefundableCurrency", true},
    {"m_OriginalOwnerXuidLow", true},
    {"m_OriginalOwnerXuidHigh", true},
    {"m_nFallbackPaintKit", true},
    {"m_nFallbackSeed", true},
    {"m_flFallbackWear", true},
    {"m_nFallbackStatTrak", true},
    {"m_iCompetitiveWins", true},
    {"m_iCompetitiveRanking", true},
    {"m_iCompetitiveRankType", true},
    {"m_iCompetitiveRankingPredicted_Win", true},
    {"m_iCompetitiveRankingPredicted_Loss", true},
    {"m_iCompetitiveRankingPredicted_Tie", true},
    {"m_nActiveCoinRank", true},
    {"m_nMusicID", true},
};

void WriteSchemaPtrValue(void* ptr, const char* className, const char* fieldName, bool isStruct, byte* value, int size)
{
    if (BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end() && g_Config->FetchValue<bool>("core.FollowCS2ServerGuidelines"))
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\n", className, fieldName);
        PRINT("To get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\n");
        PRINT("Note: Using non-compliant field values can result in a GSLT ban.\n");
        PRINT("Note: We are not providing any kind of support for people which are using these fields.\n");
        return;
    }

    auto datatable_hash = hash_32_fnv1a_const(className);
    auto prop_hash = hash_32_fnv1a_const(fieldName);
    const auto m_key = sch::GetOffset(className, datatable_hash, fieldName, prop_hash);

    void* fieldPtr = reinterpret_cast<std::add_pointer_t<void>>((uintptr_t)(ptr)+m_key.offset);

    Plat_WriteMemory(fieldPtr, value, size);
}

void* GetSchemaPtr(void* ptr, const char* className, const char* fieldName)
{
    if (BlockedCS2GuidelinesFields.find(fieldName) != BlockedCS2GuidelinesFields.end() && g_Config->FetchValue<bool>("core.FollowCS2ServerGuidelines"))
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\n", className, fieldName);
        PRINT("To get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\n");
        PRINT("Note: Using non-compliant field values can result in a GSLT ban.\n");
        PRINT("Note: We are not providing any kind of support for people which are using these fields.\n");
        return 0;
    }

    auto datatable_hash = hash_32_fnv1a_const(className);
    auto prop_hash = hash_32_fnv1a_const(fieldName);
    auto m_key = sch::GetOffset(className, datatable_hash, fieldName, prop_hash);

    return reinterpret_cast<void*>((uintptr_t)(ptr)+m_key.offset);
}

void scripting_StateUpdate(std::string ptr, std::string classname, std::string field, bool isStruct)
{
    if (BlockedCS2GuidelinesFields.find(field) != BlockedCS2GuidelinesFields.end() && g_Config->FetchValue<bool>("core.FollowCS2ServerGuidelines"))
    {
        PRINTF("Getting or setting %s::%s is not permitted due to CS2 Server Guidelines violation.\n", classname.c_str(), field.c_str());
        PRINT("To get or set this value, switch to false the \"core.FollowCS2ServerGuidelines\" field.\n");
        PRINT("Note: Using non-compliant field values can result in a GSLT ban.\n");
        PRINT("Note: We are not providing any kind of support for people which are using these fields.\n");
        return;
    }

    if (!starts_with(ptr, "0x")) return;
    void* vPtr = (void*)(strtol(ptr.c_str(), nullptr, 16));

    SetStateChanged((uintptr_t)vPtr, classname, field, 0, isStruct);
}