# StringToULongLong

Returns an unsigned long long based on string provided.

### Syntax

```cpp
@returns unsigned long long
StringToULongLong(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    unsigned long long number = StringToULongLong(args[0]);
}
```