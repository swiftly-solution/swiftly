# StringToUInt

Returns an unsigned integer based on string provided.

### Syntax

```cpp
@returns unsigned int
StringToUInt(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    unsigned int number = StringToUInt(args[0]);
}
```