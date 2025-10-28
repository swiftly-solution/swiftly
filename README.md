<br/>
<p align="center">
    <img src="https://sttci.b-cdn.net/status.swiftlycs2.net/2105/logo.png" alt="Swiftly Private Message Logo" width="600" height="131">
  <p align="center">
    Swiftly is a server modification plugin for Counter Strike 2 servers which is based on Metamod:Source 2.x.
    <br/>
    <a href="https://github.com/swiftly-solution/swiftly/issues">Report Bug</a>
    <a href="https://swiftlycs2.net/discord">Discord Server</a>
  </p>
</p>

<div align="center">

README is also available in [Ukrainian](https://github.com/swiftly-solution/swiftly/blob/master/README-UA.md) ![ua](https://raw.githubusercontent.com/stevenrskelton/flag-icon/master/png/16/country-4x3/ua.png) and [Russian](https://github.com/swiftly-solution/swiftly/blob/master/README-RU.md) ![ru](https://raw.githubusercontent.com/stevenrskelton/flag-icon/master/png/16/country-4x3/ru.png) and [Chinese](https://github.com/swiftly-solution/swiftly/blob/master/README-CN.md) ![ru](https://raw.githubusercontent.com/stevenrskelton/flag-icon/master/png/16/country-4x3/cn.png)

![Downloads](https://img.shields.io/github/downloads/swiftly-solution/swiftly/total) ![Contributors](https://img.shields.io/github/contributors/swiftly-solution/swiftly?color=dark-green) ![Issues](https://img.shields.io/github/issues/swiftly-solution/swiftly) ![License](https://img.shields.io/github/license/swiftly-solution/swiftly)

</div>

### Notice

This project is in maintenance-only mode since the date of 10th of October 2025. The project will be discontinued after 6 months from this date, meaning 10th of April 2026.
This mode is meant to keep the project functional until people using it will migrate to the new variant of the framework.
Check out [SwiftlyS2](https://github.com/swiftly-solution/swiftlys2) and it's new features at https://swiftlys2.net

---

### Build Requirements

- [hl2sdk](https://github.com/alliedmodders/hl2sdk/tree/cs2) (Downloads automatically with the git cloning using Recurse Submodules)
- [metamod-source](https://github.com/alliedmodders/metamod-source) (Downloads automatically with the git cloning using Recurse Submodules)
- [XMake](https://xmake.io/)

---

### Downloads

- [Public Releases (recomended)](https://github.com/swiftly-solution/swiftly/releases)
- [Builds (use at your own risk)](https://github.com/swiftly-solution/swiftly/actions)

---

### Get Plugins

- [Discord (recomended)](https://swiftlycs2.net/discord)
- [GitHub Topic](https://github.com/topics/swiftly-solution)

---

### For Developers

- [Beginners](https://swiftlycs2.net/for-beginners)
- [Plugin Docs](https://swiftlycs2.net/plugin-docs)
- [Extension Docs](https://swiftlycs2.net/ext-docs)
- [SDK Docs](https://swiftlycs2.net/sdk)

---

### Building Commands

#### Clone Repository

```
git clone --recurse-submodules https://github.com/swiftly-solution/swiftly
```

#### Build

```
./setup.ps1 - Windows
./setup.sh - Linux
```

#### Build using Docker

```
docker run --rm -it -e "FOLDER=swiftly" -e "GAME=cs2" -v .:/swiftly ghcr.io/swiftly-solution/swiftly:cross-compiler
```

---

### License

Swiftly is licensed under the GNU GPL 3 License. You can view the license in the LICENSE file.

---

### Credits

The Schema System and the base SDK classes fields provided by [CS2Fixes](https://github.com/Source2ZE/CS2Fixes).

The rest of SDK fields were provided by [SteamDatabase](https://github.com/SteamDatabase).

Thanks to GAMMACASE, Poggu, and all the people which are constantly working for the Counter Strike 2 Server Community to become better.

---

### Statistics

![Alt](https://repobeats.axiom.co/api/embed/742f846684c4bb9f8314c0a43c2a6b314fc63b6b.svg "Repobeats analytics image")
