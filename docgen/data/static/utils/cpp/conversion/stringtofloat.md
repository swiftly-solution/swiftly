# StringToFloat

Returns a float based on string provided.

### Syntax

```cpp
@returns float
StringToFloat(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    float number = StringToFloat(args[0]);
}
```