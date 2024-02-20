# NextTick

Calls the specified function on the next server tick.

### Syntax

```cpp
NextTick(std::function<void()> cb)
```

:::note
The function argument also supports lambda function ( \[]\{ ... } ).
:::

### Example

```cpp
void OnPluginStart()
{
    NextTick([]() {
        print("Called on the first server tick!\n")
    });
}
```