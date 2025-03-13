#pragma once

namespace Koffieboon
{
	/// <summary>
	/// GraphicsContext is an abstract class that represents a graphics context.
	/// </summary>
	class GraphicsContext
	{
	public:
		/// <summary>
		/// Init is a pure virtual function that initializes the graphics context.
		/// </summary>
		virtual void Init() = 0;

		/// <summary>
		/// SwapBuffers is a pure virtual function that swaps the buffers.
		/// </summary>
		virtual void SwapBuffers() = 0;

		/// <summary>
		/// SetViewport is a pure virtual function that sets the viewport.
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="width"></param>
		/// <param name="height"></param>
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
	};
}