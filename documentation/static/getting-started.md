# Getting Started

<Tabs defaultValue="lua">
  <TabsList class="grid w-full grid-cols-2">
    <TabsTrigger value="lua">Lua</TabsTrigger>
    <TabsTrigger value="js">JavaScript</TabsTrigger>
  </TabsList>
  <TabsContent value="lua">
## Mandatory Functions

Below are all of the mandatory functions needed in any Swiftly Lua Plugin, in a single plugin file.

```lua title="main.lua"
function GetPluginAuthor()
    return "AUTHOR"
end

function GetPluginVersion()
    return "VERSION"
end

function GetPluginName()
    return "PLUGIN_NAME"
end

function GetPluginWebsite()
    return "WEBSITE"
end
```
  </TabsContent>
  <TabsContent value="js">
## Mandatory Functions

Below are all of the mandatory functions needed in any Swiftly JavaScript Plugin, in a single plugin file.

```js title="main.js"
function GetPluginAuthor() {
    return "AUTHOR"
}

function GetPluginVersion() {
    return "VERSION"
}

function GetPluginName() {
    return "PLUGIN_NAME"
}

function GetPluginWebsite() {
    return "WEBSITE"
}
```
  </TabsContent>
</Tabs>