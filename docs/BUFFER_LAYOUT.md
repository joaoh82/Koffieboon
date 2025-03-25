# Buffer Layout

A buffer layout is a list of elements that describe the layout of a buffer.

## Buffer Element Data Types

A buffer element type is a type that describes the type of a buffer element.

### Float (4 bytes)

### Vec2 (8 bytes)

### Vec3 (12 bytes)

### Vec4 (16 bytes)

### Mat3 (36 bytes)

### Mat4 (64 bytes)

### Int (4 bytes)

### IVec2 (8 bytes)

### IVec3 (12 bytes)

### IVec4 (16 bytes)

### Uint (4 bytes)

### Bool (1 byte)


## Buffer Element

A buffer element is a single element that describes the layout of a buffer.

```cpp
struct BufferElement
{
    std::string Name; // The name of the element
    BufferElement Type; // The type of the element
    uint32_t Size; // The size of the element
    uint32_t Offset; // The offset of the element
    bool Normalized; // Whether the element is normalized, used for integer types. Which means that the value will be clamped between 0 and 1.
};
```

## Buffer Layout

A buffer layout is a list of buffer elements that describe the layout of a buffer.

```cpp
class BufferLayout
{
    std::vector<BufferElement> m_Elements;
    uint32_t m_Stride;
};
```



