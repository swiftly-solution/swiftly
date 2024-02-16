# StringToInt

Returns an integer based on string provided.

### Syntax

```cpp
@returns int
StringToInt(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    int number = StringToInt(args[0]);
}
```