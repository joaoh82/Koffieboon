#include "kbpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Koffieboon/Platform/OpenGL/OpenGLBuffer.h"

namespace Koffieboon
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    KASSERT_MSG(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
		}

		KASSERT_MSG(false, "Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    KASSERT_MSG(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLIndexBuffer(indices, size);
		}

		KASSERT_MSG(false, "Unknown RendererAPI!");
		return nullptr;
	}
} // namespace Koffieboon