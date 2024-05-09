# StringToDouble

Returns a double based on string provided.

### Syntax

```cpp
@returns double
StringToDouble(const char *str)
```

### Example

```cpp
void Command_Test(int playerID, const char **args, uint32_t argsCount, bool silent)
{
    if(argsCount < 1) return;

    double number = StringToDouble(args[0]);
}
```