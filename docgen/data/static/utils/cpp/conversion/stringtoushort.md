# StringToUShort

Returns an unsigned short based on string provided.

### Syntax

```cpp
@returns unsigned short
StringToUShort(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    unsigned short number = StringToUShort(args[0]);
}
```