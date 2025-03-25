#pragma once

#include "Koffieboon/Defines.h"
#include "Koffieboon/Core/Asserts.h"
#include <string>
#include <vector>

namespace Koffieboon
{
	/// <summary>
	/// ShaderDataType is an enum class that contains the data types.
	/// </summary>
	enum class BufferElementDataType
	{
		None = 0, Float, Vec2, Vec3, Vec4, Mat3, Mat4, Int, IVec2, IVec3, IVec4, UInt, Bool
	};

	static uint32_t BufferElementDataTypeSize(BufferElementDataType type)
	{
		switch (type)
		{
		case BufferElementDataType::Float:    return 4;
		case BufferElementDataType::Vec2:   return 4 * 2;
		case BufferElementDataType::Vec3:   return 4 * 3;
		case BufferElementDataType::Vec4:   return 4 * 4;
		case BufferElementDataType::Mat3:     return 4 * 3 * 3;
		case BufferElementDataType::Mat4:     return 4 * 4 * 4;
		case BufferElementDataType::Int:      return 4;
		case BufferElementDataType::IVec2:     return 4 * 2;
		case BufferElementDataType::IVec3:     return 4 * 3;
		case BufferElementDataType::IVec4:     return 4 * 4;
		case BufferElementDataType::UInt:     return 4;
		case BufferElementDataType::Bool:     return 1;
		}

		KASSERT_MSG(false, "Unknown BufferElementDataType!");
		return 0;
	}

	/// <summary>
	/// BufferElement is a struct that contains the name, type, size, offset and normalized.
	/// </summary>
	struct BufferElement
	{
		std::string Name;
		BufferElementDataType Type;
		uint32_t Size;
		uint32_t Offset;
		bool Normalized;

		BufferElement() {}

		BufferElement(BufferElementDataType type, const std::string& name, bool normalized = false)
			: Name(name), Type(type), Size(BufferElementDataTypeSize(type)), Offset(0), Normalized(normalized)
		{
		}

		uint32_t GetComponentCount() const
		{
			switch (Type)
			{
			case BufferElementDataType::Float:   return 1;
			case BufferElementDataType::Vec2:  return 2;
			case BufferElementDataType::Vec3:  return 3;
			case BufferElementDataType::Vec4:  return 4;
			case BufferElementDataType::Mat3:    return 3 * 3;
			case BufferElementDataType::Mat4:    return 4 * 4;
			case BufferElementDataType::Int:     return 1;
			case BufferElementDataType::IVec2:    return 2;
			case BufferElementDataType::IVec3:    return 3;
			case BufferElementDataType::UInt:    return 1;
			case BufferElementDataType::IVec4:    return 4;

			case BufferElementDataType::Bool:    return 1;
			}

			KASSERT_MSG(false, "Unknown BufferElementDataType!");
			return 0;
		}
	};

	/// <summary>
	/// BufferLayout is a class that contains the layout of the buffer.
	/// </summary>
	class BufferLayout
	{
	public:
		// Constructor
		BufferLayout() {}

		// Constructor
		BufferLayout(const std::initializer_list<BufferElement>& elements)
			: m_Elements(elements)
		{
			CalculateOffsetsAndStride();
		}

		// GetStride is a function that returns the stride.
		inline uint32_t GetStride() const { return m_Stride; }

		// GetElements is a function that returns the elements.
		inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }
		
	private:
		// CalculateOffsetsAndStride is a function that calculates the offsets and stride.
		void CalculateOffsetsAndStride()
		{
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}

	private: 
		// Member Variables
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride = 0;	
	};

} // namespace Koffieboon