# ToLower

Returns a lower-case string.

### Syntax

```cpp
@returns const char*
ToLower(const std::string &str);
```

### Example

```cpp
void OnPluginStart()
{
    print("%s\n", ToLower("MESSAGE"));
}
```