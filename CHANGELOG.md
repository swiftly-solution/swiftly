# Changelog - Swiftly Core

Over here will be noted all the update change logs.

## v2.0.1 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v2.0.1)

### C# Plugins

- Crashes on plugin load, missing location in elf

### SDK

- Brought back documentation for fields with numbers and SDK for those is available for both languages now

### Exports

- Fixed getting the return value in C# Plugins

### Events

- Fixed getting the return value in C# Plugins

### Configuration

- Fixed getting the return value in C# Plugins

### Database

- Queries can be called now even without a callback
- Added: GetCredentials
- Added: GetKind

## v2.0.0 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v2.0.0)

### VGUI

- Temporary Removal due to Counter-Strike 2's AnimGraph 2 update.

### Resource Monitor

- Register in stack style the usages

### SDK

- Access methods (functions) from parent classes (ex. EmitSound now can be called from CBaseModelEntity).

### Plugins Manifest

- Now there's available a plugin manifest for each plugin. Check it out!

https://swiftlys2.net/plugin-docs/plugin-manifest

### Plugins Runtime

- Removed JavaScript plugins support due to slow runtime performance and limitations.

```
After reviewing your feedback and carefully evaluating our development goals, we’ve made the decision to officially deprecate JavaScript/TypeScript support in Swiftly moving forward.

While we acknowledge the community’s mixed opinions, this choice is grounded in technical limitations we’ve encountered. JavaScript has made certain advanced implementations, like accurate crash call stack tracing and deep function-level monitoring in our Resource Monitor, either impossible or messy without resorting to unreliable workarounds.

Our top priority is to deliver a stable, powerful, and developer-friendly plugin ecosystem. To achieve that, we need a more robust and introspectable language environment.  JavaScript couldn't keep up with the performance standards that we require for Swiftly so that it can run at the best performance. It also couldn't enable us to create a more developer friendly environment as how C# and Lua will make in the next version.

We're actively working on better alternatives and will share more on what’s next very soon. In the meantime, we appreciate your understanding and continued support.

We're terribly sorry if we've upset you, but we hope that you can understand our point of view and our concerns regarding the performance of the game servers.
```

Ref: https://discord.com/channels/1178027657594687608/1178081840616181860/1402674791974043803

- Added support for C# Plugins using .NET 8.0

NuGet Package: https://www.nuget.org/packages/SwiftlyS2
Documentation: https://swiftlys2.net

### GameData

- Fixes for Counter-Strike 2: AnimGraph 2 update.

### Files

- Removal of functions which may collide with Counter-Strike 2's tier0 library.

### Events

- Optimized events calling from extensions. Now they can call specific plugins.

### Profiler

- Support for profiling API in scripting. See https://swiftlys2.net/plugin-docs/profiler

### SoundEvent

- Now you can send sounds using events. See https://swiftlys2.net/plugin-docs/sounds/soundevent

### Garbage Collector Menu

- Now you can see what elements are allocated inside the plugins using `sw gc`

## v1.6.29 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.29)

### Hooks

- Fix hook callbacks not being called

### Weapons

- Fix VData pointer not being correctly set

### Events

- Fix TriggerEvent return value

## v1.6.28 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.28)

### GameData / Signatures

- Fixed GiveNamedItem signature

## v1.6.27 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.27)

### Events

- [OnClientPutInServer](https://swiftlys2.net/plugin-docs/scripting/events/core/onclientputinserver)

## v1.6.26 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.26)

### Websockets

- Added support for Websocket Client inside Scripting. [Documentation](https://swiftlys2.net/plugin-docs/scripting/ws)

## v1.6.25 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.25)

### Players

- At connect, yeet away the object of the player which is already connected on the same slot.
- This seems to happen only for bots, they don't get disconnected, so i just yeet them away

## v1.6.23-24 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.24)

### Map Chooser

- Removed the message spam in chat, now it's gonna be only 3 messages.

### Center Menu

- Fixed crashes when exiting center menu

### Screen Menu

- Disabled on Windows due to an unidentifiable crash inside CheckTransmit, need more debugging

![Debug Output](https://cdn.skuzzi.ro/HZjpEeujxGLfkYWHuwrNlhmxQ48Alo20.png)

## v1.6.21-22 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.22)

### Screen Text

- Possible crash fix for the screen texts

## v1.6.20 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.20)

### WebSockets

- Added support for websockets server inside scripting. [Documentation](https://swiftlys2.net/plugin-docs/scripting/ws)

### UserMessages

- feat(usermessages): Bytes support

## v1.6.18-19 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.18)

### Menus

- possible_fix(menus): Crashes on map change

### Teleport

- fix(Teleport): Angles not being set

## v1.6.17 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.17)

### Menus

- fix(menus): PerformMenuAction empty vector

## v1.6.15-16 - [Release v1.6.15](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.15) - [Release v1.6.16](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.16)

### Resource Monitor

- feat(resmon): Save to JSON (Chrome Performance Visualizer)

![Demo_ALT](https://cdn.skuzzi.ro/XD04gXPsAD6LXR0xyaW4HM8imKeqcUAc.gif)

### VGUI

- fix(ScreenText): AcceptInput for Message at deconstruct

## v1.6.14 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.14)

### Events

- EventResult Handled not being considered & Event Object lifetime

## v1.6.13 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.13)

### Shutdown Crashes

- Fixed crashes related to the shutdown of the server and Swiftly Core.

## v1.6.12 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.12)

### Steam Authorization

- Now in Scripting you can get both authorized and unauthorized SteamID64 / SteamID2, also you can get if the player is authorized.
- There are also events triggered when a player is being authorized or not: [OnClientSteamAuthorize](https://swiftlys2.net/plugin-docs/scripting/events/core/onclientsteamauthorize) and [OnClientSteamAuthorizeFail](https://swiftlys2.net/plugin-docs/scripting/events/core/onclientsteamauthorizefail).

## v1.6.11 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.11)

### Automation

- Update Protobufs, SDK and game events for Counter-Strike 2

### Events

- fix(events): GetInvokingPlugin

### Player

- fix(player/think): Random Crash

### Plugins

- fix(plugins/manager): Unload crash
- fix(embedder): Proper memory collection and lifetime

### Game Events

- feat(gameevents): OnClientProcessUsercmds

### Hooks

- Hook variable not existing

### Memory

- fix(memory): LoadFromSignatureName

## v1.6.10 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.10)

### Precacher

- fix(core): Precacher not being called

## v1.6.9 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.9)

### Stack

- Functions which are taking arguments of any type not recognizing floats

## v1.6.8 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.8)

### Stack

- Functions which are taking arguments of any type not recognizing floats

### FireEventToClient

- Crash when no event_data is being provided

## v1.6.7 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.7)

### OnPlayerCheckTransmit

- Fix transmit pointer not being the good type

## v1.6.6 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.6)

### Database

- Add optional argument to skip connecting to `default_connection`

### Crash Reporter

- Add file location of the function from Call Stack

### Utils

- Added: GetPluginsList

### Menus

- Remove screen menus on windows as they crash without a dump

### CCheckTransmitInfo

- Fix self casting

### Events

- Fix event return values

### SDK

- Fix FollowServerRules check not working

## v1.6.5 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.5)

### HTTP

- Update Extension

## v1.6.4 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.4)

### Core

- Added Crash Prevention for Schema/SDK accessing and for FireEvent.

![imgalt](https://cdn.skuzzi.ro/dfihge478fg3h478veriufh938wf.png)
![imgalt](https://cdn.skuzzi.ro/vj9834uf09asweifmnjw398fj92hfivsewh98w.png)

### Crash Reporter

- Added arguments inside CallStack back.

### CEntityKeyValues

- Fixed crashes when map was changing.

## v1.6.3 - [Release](https://github.com/swiftly-solution/swiftly/releases/tag/v1.6.3)

### OnPlayerDamage

- TakeDamage getting controller on wrong stuff causing crashes

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

- [+] memory:Dereference()

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
