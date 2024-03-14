# DamageFlags

```cpp
enum DamageFlags : uint32_t
{
    NONE = 0x0,
    SUPPRESS_HEALTH_CHANGES = 0x1,
    SUPPRESS_PHYSICS_FORCE = 0x2,
    SUPPRESS_EFFECTS = 0x4,
    PREVENT_DEATH = 0x8,
    FORCE_DEATH = 0x10,
    ALWAYS_GIB = 0x20,
    NEVER_GIB = 0x40,
    REMOVE_NO_RAGDOLL = 0x80,
    SUPPRESS_DAMAGE_MODIFICATION = 0x100,
    ALWAYS_FIRE_DAMAGE_EVENTS = 0x200,
    RADIUS_DMG = 0x400,
    LASTDFLAG = 0x400,
    IGNORE_ARMOR = 0x800,
};
```