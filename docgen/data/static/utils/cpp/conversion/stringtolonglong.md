# StringToLongLong

Returns a long long based on string provided.

### Syntax

```cpp
@returns long long
StringToLongLong(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    long long number = StringToLongLong(args[0]);
}
```