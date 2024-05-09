# Color

```cpp
class Color
{
public:
    int r, g, b, a;
    Color(int m_r, int m_g, int m_b, int m_a) : r(m_r), g(m_g), b(m_b), a(m_a) {}
};
```

## Create a Color\*

```cpp
Color* color = new Color(int r, int g, int b, int a);
```

## Create a Color

```cpp
Color color(int r, int g, int b, int a);
```
