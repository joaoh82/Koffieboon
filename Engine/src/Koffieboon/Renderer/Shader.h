#pragma once

#include <string>

/// <summary>
/// Shader.h is a header file that contains the Shader class.
/// </summary>

namespace Koffieboon
{
	class Shader
	{
	public:

		virtual ~Shader() {};

		/// <summary>
		/// Bind is a function that binds the shader.
		/// </summary>
		virtual void Bind() const = 0;

		/// <summary>
		/// Unbind is a function that unbinds the shader.
		/// </summary>
		virtual void Unbind() const = 0;

		static Shader* Create(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

	private:
		/// <summary>
		/// m_RendererID is an unsigned integer that represents the shader renderer ID.
		/// unsigned int
		/// </summary>
		uint32_t m_RendererID;
	};
} // namespace Koffieboon