#pragma once

#include <string>

namespace Koffieboon
{
	class Shader
	{
	public:
		Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

		~Shader();

		/// <summary>
		/// Bind is a function that binds the shader.
		/// </summary>
		void Bind() const;

		/// <summary>
		/// Unbind is a function that unbinds the shader.
		/// </summary>
		void Unbind() const;

	private:
		/// <summary>
		/// m_ShaderRendererID is an unsigned integer that represents the shader renderer ID.
		/// </summary>
		unsigned int m_ShaderRendererID;
	};
} // namespace Koffieboon