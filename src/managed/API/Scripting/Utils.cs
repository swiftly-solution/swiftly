using SwiftlyS2.API.SDK.CS2;

namespace SwiftlyS2.API.Scripting.Utils
{
    public class CS2
    {
        public static List<string> ItemsList = [
            "item_assaultsuit",
            "item_defuser",
            "item_kevlar"
        ];

        public static List<string> WeaponsList = [
            "weapon_ak47",
            "weapon_aug",
            "weapon_awp",
            "weapon_bizon",
            "weapon_c4",
            "weapon_cz75a",
            "weapon_deagle",
            "weapon_decoy",
            "weapon_elite",
            "weapon_famas",
            "weapon_fiveseven",
            "weapon_flashbang",
            "weapon_g3sg1",
            "weapon_galilar",
            "weapon_glock",
            "weapon_healthshot",
            "weapon_hegrenade",
            "weapon_incgrenade",
            "weapon_knife",
            "weapon_m249",
            "weapon_m4a1",
            "weapon_mac10",
            "weapon_mag7",
            "weapon_molotov",
            "weapon_mp5sd",
            "weapon_mp7",
            "weapon_mp9",
            "weapon_negev",
            "weapon_nova",
            "weapon_p2000",
            "weapon_p250",
            "weapon_p90",
            "weapon_sawedoff",
            "weapon_scar20",
            "weapon_sg556",
            "weapon_smokegrenade",
            "weapon_ssg08",
            "weapon_tec9",
            "weapon_ump45",
            "weapon_usp_silencer",
            "weapon_xm1014",
        ];

        public static Dictionary<string, Team> teamSelector = new()
        {
            { "@ct", Team.CT },
            { "@t", Team.CT },
            { "@spec", Team.CT },
        };

        public static Dictionary<string, LifeState_t> lifeStateSelector = new()
        {
            { "@alive", LifeState_t.LIFE_ALIVE },
            { "@dying", LifeState_t.LIFE_DYING },
            { "@dead", LifeState_t.LIFE_DEAD },
        };
    }
}
