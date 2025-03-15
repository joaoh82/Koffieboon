#include "kbpch.h"
#include "Shader.h"

//#include <glad/glad.h>

#include "Renderer.h"

#include "Koffieboon/Platform/OpenGL/OpenGLShader.h"

namespace Koffieboon
{
	
	Shader* Shader::Create(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:    KASSERT_MSG(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL:  return new OpenGLShader(vertexShaderSource, fragmentShaderSource);
		}
		KASSERT_MSG(false, "Unknown RendererAPI!");
		return nullptr;
	}

} // namespace Koffieboon