---
sidebar_position: 1
---

# Getting started

To use the Swiftly JSON system you need the following code in your plugin.

```cpp
JSON *json = nullptr;

void OnProgramLoad(const char *pluginName, const char *mainFilePath)
{
    ...
    json = new JSON();
    ...
}
```
