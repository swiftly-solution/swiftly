# ToUpper

Returns an upper-case string.

### Syntax

```cpp
@returns const char*
ToUpper(const std::string &str);
```

### Example

```cpp
void OnPluginStart()
{
    print("%s\n", ToUpper("message"));
}
```