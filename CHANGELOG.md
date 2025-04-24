# Changelog - Swiftly Core

Over here will be noted all the update change logs.

## v1.6.2 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.2)

### Exports

- Now the earliest point you can call exports is from `OnPluginStart`.

### MySQL

- Windows Fix: Gibberish queries

### Commands

- Swiftly Version

### JavaScript Optimization

- Optimized the memory from a minimum of 3MB per each plugin to a minimum of ~300KB. This was tested with a bare-bone plugin with just the mandatory functions included.

### Events

- Prevent crashes on FireEventToClient
- Sharing event object causing undefined behaviour
- JavaScript: Sometimes not setting out the correct value for EventResult

### Player

- Fix IP Address save

## v1.6.1 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.1)

### VGUI

- [+] Fix Memory Leak
- [+] Fix Entity Spawn

### Exports

- [+] Fix Return Value

### Weapon

- [+] Fix CBasePlayerWeapon
- [+] Fix CCSWeaponBase
- [+] Fix CBasePlayerWeaponVData
- [+] Fix CCSWeaponBaseVData

### Core Commands

- [+] sw status
- [+] sw list

### Player

- [+] Fix Buttons

## v1.6.0 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.0)

### Memory

- [+] memory:Dereferance()

### CCheckTransmitInfo

- [+] cchecktransmitinfo:AddEntityIndex(entityIndex)
- [+] cchecktransmitinfo:RemoveEntityIndex(entityIndex)
- [+] cchecktransmitinfo:Clear()

### CHandle

- [+] chandle:IsValid()
- [+] chandle:GetEntryIndex()
- [+] chandle:GetSerialNumber()

### Player

- [•] player:Drop(reason, optional message)

### VGUI

- [+] vgui:SetColor(textID, color)

### Convar

- [+] convar:Create(name, description, type, flags, default_value, min_value, max_value)
- [+] convar:Delete(name)

### Crash Reporter

- [+] Windows Support

### Extensions

- [+] Hooks via DynoHook being centralized into Swiftly's Core
- [+] GetCurrentGame() -> cs2, unknown

### Hooks

- [+] AddVHook(library, vtable_name, offset, args_list, return_type)

### Events

- [+] OnEntityParentChanged(entity, newparent)

### Game

- [+] GetGameName() -> cs2, unknown

### Addons System

- [+] Multiple VPK Support

### Fixes

- [+] EmitSound volume

### SDKTools

- [+] ListenEntityTouchUse(class_name)
- [+] RemoveListenEntityTouchUse(class_name)

### Lua

- [+] Error Stack Trace

![ImgAlt](https://cdn.skuzzi.ro/zJIsaG8viy2FVsXbtQxmGxCmTJ62iKOD.png)