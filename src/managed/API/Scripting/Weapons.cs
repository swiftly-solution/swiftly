using SwiftlyS2.API.SDK.CS2;
using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.SDK.CS2.Classes;

namespace SwiftlyS2.API.Scripting
{
    public class Weapons
    {
        public class WeaponManager : ClassData
        {
            public WeaponManager() { }

            public void DropWeapons()
            {
                Internal_API.Invoker.CallNative("WeaponManager", "DropWeapons", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public Weapons.Weapon GetFIrstInSlot(gear_slot_t slot)
            {
                return Internal_API.Invoker.CallNative<Weapons.Weapon>("WeaponManager", "GetFIrstInSlot", Internal_API.CallKind.ClassFunction, m_classData, slot);
            }
            public Weapons.Weapon[] GetInSlot(gear_slot_t slot)
            {
                return Internal_API.Invoker.CallNative<Weapons.Weapon[]>("WeaponManager", "GetInSlot", Internal_API.CallKind.ClassFunction, m_classData, slot) ?? [];
            }
            public Weapons.Weapon[] GetWeapons()
            {
                return Internal_API.Invoker.CallNative<Weapons.Weapon[]>("WeaponManager", "GetWeapons", Internal_API.CallKind.ClassFunction, m_classData) ?? [];
            }
            public void GiveWeapon(string weapon_name)
            {
                Internal_API.Invoker.CallNative("WeaponManager", "GiveWeapon", Internal_API.CallKind.ClassFunction, m_classData, weapon_name);
            }
            public void RemoveByClassname(string classname)
            {
                Internal_API.Invoker.CallNative("WeaponManager", "RemoveByClassname", Internal_API.CallKind.ClassFunction, m_classData, classname);
            }
            public void RemoveByItemDefinition(long idx)
            {
                Internal_API.Invoker.CallNative("WeaponManager", "RemoveByItemDefinition", Internal_API.CallKind.ClassFunction, m_classData, idx);
            }
            public void RemoveBySlot(gear_slot_t slot)
            {
                Internal_API.Invoker.CallNative("WeaponManager", "RemoveBySlot", Internal_API.CallKind.ClassFunction, m_classData, slot);
            }
            public void RemoveWeapons()
            {
                Internal_API.Invoker.CallNative("WeaponManager", "RemoveWeapons", Internal_API.CallKind.ClassFunction, m_classData);
            }
        }

        public class Weapon : ClassData
        {
            public Weapon(int playerid, ClassData ptr): base(Internal_API.Invoker.CallNative<IntPtr>("Weapon", "Weapon", CallKind.ClassFunction, playerid, ptr))
            {
            }
            public Weapon() { }
            public CBasePlayerWeapon CBasePlayerWeapon()
            {
                return Internal_API.Invoker.CallNative<CBasePlayerWeapon>("Weapon", "CBasePlayerWeapon", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public CCSWeaponBase CCSWeaponBase()
            {
                return Internal_API.Invoker.CallNative<CCSWeaponBase>("Weapon", "CCSWeaponBase", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public CBasePlayerWeaponVData CBasePlayerWeaponVData()
            {
                return Internal_API.Invoker.CallNative<CBasePlayerWeaponVData>("Weapon", "CBasePlayerWeaponVData", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public CCSWeaponBaseVData CCSWeaponBaseVData()
            {
                return Internal_API.Invoker.CallNative<CCSWeaponBaseVData>("Weapon", "CCSWeaponBaseVData", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void SetDefaultAttributes()
            {
                Internal_API.Invoker.CallNative("Weapon", "SetDefaultAttributes", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void Remove()
            {
                Internal_API.Invoker.CallNative("Weapon", "Remove", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void Drop()
            {
                Internal_API.Invoker.CallNative("Weapon", "Drop", Internal_API.CallKind.ClassFunction, m_classData);
            }
        }
    }
}