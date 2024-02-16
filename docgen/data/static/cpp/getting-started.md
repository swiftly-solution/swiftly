---
sidebar_position: 0
---

# Getting Started

## Mandatory Includes

### swiftly.h

You need to include `swiftly/swiftly.h` in every main plugin file.

```cpp
#include <swiftly/swiftly.h>
```

### gameevents.h

You need to include `swiftly/gameevents.h` in the main plugin file.

```cpp
#include <swiftly/gameevents.h>
```

## Mandatory Variables

You need to define the Player Manager varialbe in the main plugin file.

```cpp
PlayerManager *g_playerManager = nullptr;
```

## Mandatory Functions

Below will be listed the mandatory functions needed in any Swiftly C++ Plugin.

### OnProgramLoad

The following setup needs to be in the plugin:

```cpp
void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    Swiftly_Setup(pluginName, mainFilePath);
}
```

### GetPluginAuthor

The following setup needs to be in the plugin:

```cpp
const char *GetPluginAuthor()
{
    return "AUTHOR";
}
```

### GetPluginVersion

```cpp
const char *GetPluginVersion()
{
    return "VERSION";
}
```

### GetPluginName

```cpp
const char *GetPluginName()
{
    return "PLUGIN_NAME";
}
```

### GetPluginWebsite

```cpp
const char *GetPluginWebsite()
{
    return "WEBSITE";
}
```
