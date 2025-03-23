#pragma once

#include "Koffieboon/Renderer/BufferLayout.h"

/// <summary>
/// Buffer.h is a header file that contains the VertexBuffer and IndexBuffer classes.
/// </summary>

namespace Koffieboon
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		/// <summary>
		/// Bind is a function that binds the vertex buffer.
		/// </summary>
		virtual void Bind() const = 0;

		/// <summary>
		/// Unbind is a function that unbinds the vertex buffer.
		/// </summary>
		virtual void Unbind() const = 0;

		virtual const BufferLayout& GetLayout() const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;

		/// <summary>
		/// Create is a static function that creates a vertex buffer.
		/// </summary>
		/// <param name="vertices"></param>
		/// <param name="size"></param>
		/// <returns></returns>
		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() const = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
	};

} // namespace Koffienoon