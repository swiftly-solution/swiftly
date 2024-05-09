# StringToULong

Returns an unsigned long based on string provided.

### Syntax

```cpp
@returns unsigned long
StringToULong(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    unsigned long number = StringToULong(args[0]);
}
```