# CreateThread

Calls the specified function on a separate thread.

### Syntax

```cpp
CreateThread(std::function<void()> cb)
```

:::note
The function argument also supports lambda function ( \[]\{ ... } ).
:::

### Example

```cpp
void OnPluginStart()
{
    CreateThread([]() {
        print("Called on the first server tick!\n");
    });
}
```