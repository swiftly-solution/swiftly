using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.SDK.CS2.Classes;

namespace SwiftlyS2.API.Scripting
{
    public class Weapons
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("Weapons", "Weapons", CallKind.ClassFunction);
        }
        public class Weapon : ClassData
        {
            public Weapon(int playerid, ClassData ptr): base(Internal_API.Invoker.CallNative<IntPtr>("Weapon", "Weapon", CallKind.ClassFunction, playerid, ptr))
            {
            }
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