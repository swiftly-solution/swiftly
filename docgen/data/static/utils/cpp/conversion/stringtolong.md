# StringToLong

Returns a long based on string provided.

### Syntax

```cpp
@returns long
StringToLong(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    long number = StringToLong(args[0]);
}
```