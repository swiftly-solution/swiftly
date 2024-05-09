# GetTime

Returns the UNIX Time in milliseconds.

### Syntax

```cpp
@returns uint64_t
GetTime()
```

### Example

```cpp
void OnPluginStart()
{
    print("UNIX Time: %llu\n", GetTime());
}
```