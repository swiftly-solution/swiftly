# StringToShort

Returns a short based on string provided.

### Syntax

```cpp
@returns short
StringToShort(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    short number = StringToShort(args[0]);
}
```