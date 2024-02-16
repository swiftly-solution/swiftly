# Encode

Encodes a table or a value into a JSON string.

### Syntax

```lua
@returns string
json.encode(value --[[ table / number / string ]][, options --[[ table with options ]]])
```

#### Options

The options table can have the following fields:

```lua
{
    indent, --[[ number ]]
}
```

### Example

```lua
events:on("OnPluginStart", function()
    print(json.encode({ test = nil, test2 = 5325234, test3 = "hello" }, { indent = 4 })) -- pretty printing the table
end)
```
