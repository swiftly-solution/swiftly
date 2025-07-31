using SwiftlyS2.API.SDK.CS2;
using SwiftlyS2.Internal_API;

namespace SwiftlyS2.API.Scripting
{
    public class WeaponManager
    {
        private static IntPtr _ctx = IntPtr.Zero;
    
        private static void InitializeContext()
        {
            if (_ctx != IntPtr.Zero) return;
            _ctx = Invoker.CallNative<IntPtr>("WeaponManager", "WeaponManager", CallKind.ClassFunction);
        }
        public static void DropWeapons()
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("WeaponManager", "DropWeapons", Internal_API.CallKind.ClassFunction, _ctx);
        }
        public static Weapons.Weapon GetFIrstInSlot(gear_slot_t slot)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<Weapons.Weapon>("WeaponManager", "GetFIrstInSlot", Internal_API.CallKind.ClassFunction, _ctx, slot);
        }
        public static Weapons.Weapon[] GetInSlot(gear_slot_t slot)
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<Weapons.Weapon[]>("WeaponManager", "GetInSlot", Internal_API.CallKind.ClassFunction, _ctx, slot) ?? [];
        }
        public static Weapons.Weapon[] GetWeapons()
        {
            InitializeContext();
            return Internal_API.Invoker.CallNative<Weapons.Weapon[]>("WeaponManager", "GetWeapons", Internal_API.CallKind.ClassFunction, _ctx) ?? [];
        }
        public static void GiveWeapon(string weapon_name)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("WeaponManager", "GiveWeapon", Internal_API.CallKind.ClassFunction, _ctx, weapon_name);
        }
        public static void RemoveByClassname(string classname)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("WeaponManager", "RemoveByClassname", Internal_API.CallKind.ClassFunction, _ctx, classname);
        }
        public static void RemoveByItemDefinition(long idx)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("WeaponManager", "RemoveByItemDefinition", Internal_API.CallKind.ClassFunction, _ctx, idx);
        }
        public static void RemoveBySlot(gear_slot_t slot)
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("WeaponManager", "RemoveBySlot", Internal_API.CallKind.ClassFunction, _ctx, slot);
        }
        public static void RemoveWeapons()
        {
            InitializeContext();
            Internal_API.Invoker.CallNative("WeaponManager", "RemoveWeapons", Internal_API.CallKind.ClassFunction, _ctx);
        }
    }
}