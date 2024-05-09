# Vector

```cpp
class Vector
{
public:
    float x, y, z;
    Vector(float m_x, float m_y, float m_z) : x(m_x), y(m_y), z(m_z) {}
};
```

## Create a Vector\*

```cpp
Vector* coords = new Vector(float x, float y, float z);
```

## Create a Vector

```cpp
Vector coords(float x, float y, float z);
```
