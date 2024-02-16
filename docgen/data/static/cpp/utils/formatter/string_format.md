# String Format

Returns a formatted string based on it's arguments.

### Syntax

```cpp
@returns const char*
format(const char *str, ...)
```

### Example

```cpp
void OnPluginStart()
{
    const char* formatted = format("UNIX Time: %llu", GetTime());
    print("Formatted string: %s\n", formatted);
}
```