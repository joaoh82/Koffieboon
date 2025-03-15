#pragma once

namespace Koffieboon
{
	enum class RendererAPI
	{
		None = 0, OpenGL = 1
	}; // enum class RendererAPI

	class Renderer
	{
	public:
		/// <summary>
		/// GetAPI is a static function that returns the renderer API.s
		/// </summary>
		/// <returns></returns>
		inline static RendererAPI GetAPI() { return s_RendererAPI; }

	private:
		/// <summary>
		/// s_RendererAPI is a static RendererAPI that represents the renderer API.
		/// </summary>
		static RendererAPI s_RendererAPI;

	}; // class Renderer

} // namespace Koffieboon