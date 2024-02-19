<br/>
<p align="center">
    <img src="https://sttci.b-cdn.net/status.swiftlycs2.net/2105/logo.png" alt="Swiftly Private Message Logo" width="600" height="131">
  <p align="center">
    Swiftly is a server modification plugin for Counter Strike 2 servers which is based on Metamod:Source 2.x
    <br/>
    <a href="https://github.com/swiftly-solution/swiftly/issues">Report Bug</a>
    <a href="https://github.com/swiftly-solution/swiftly/issues">Discord Server</a>
  </p>
</p>

<div align="center">

![Downloads](https://img.shields.io/github/downloads/swiftly-solution/swiftly/total) ![Contributors](https://img.shields.io/github/contributors/swiftly-solution/swiftly?color=dark-green) ![Issues](https://img.shields.io/github/issues/swiftly-solution/swiftly) ![License](https://img.shields.io/github/license/swiftly-solution/swiftly)

</div>

---

### Requirements
-   [hl2sdk](https://github.com/alliedmodders/hl2sdk/tree/cs2) (Downloads automatically with the git cloning using Recurse Submodules)
-   [metamod-source](https://github.com/alliedmodders/metamod-source)
-   [python3](https://www.python.org/)
-   [ambuild](https://github.com/alliedmodders/ambuild) (MAKE SURE `ambuild` COMMAND IS AVAILABLE VIA `PATH` FOR WINDOWS)
---
### Downloads
- [Public Releases (recomended)](https://github.com/swiftly-solution/swiftly/releases)
- [Builds (use at your own risk)](https://github.com/swiftly-solution/swiftly/actions)
---
### For Developers
- [My First Plugin](https://docs.swiftlycs2.net/category/my-first-plugin)
- [Swiftly C++ Docs](https://docs.swiftlycs2.net/category/c-1)
- [Swiftly LUA Docs](https://docs.swiftlycs2.net/category/lua-1)
---
### Building Commands

#### Close Repository

```
git clone --recurse-submodules https://github.com/swiftly-solution/swiftly
```

#### Setup

```
./setup.ps1 - Windows
./setup.sh - Linux
```

#### Build

```
cd build
ambuild
```

---

### License

Swiftly is licensed under the MIT License. You can view the license in the LICENSE file.

---

### Credits

I've used the Schema System and the base SDK classes fields provided by [CS2Fixes](https://github.com/Source2ZE/CS2Fixes). The rest of SDK fields were provided by [Source2SDK](https://github.com/neverlosecc/source2sdk/tree/cs2/sdk).

---

### Statistics

![Alt](https://repobeats.axiom.co/api/embed/742f846684c4bb9f8314c0a43c2a6b314fc63b6b.svg "Repobeats analytics image")