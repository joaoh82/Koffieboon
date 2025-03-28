#pragma once

#include <string>

#include "Koffieboon/Renderer/Shader.h"

namespace Koffieboon
{
	class OpenGLShader : public Shader
	{
	public:
	
		OpenGLShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
		
		virtual ~OpenGLShader();
		
		virtual void Bind() const override;
		virtual void Unbind() const override;
	
	private:
		uint32_t m_RendererID;
	};
} // namespace Koffieboon