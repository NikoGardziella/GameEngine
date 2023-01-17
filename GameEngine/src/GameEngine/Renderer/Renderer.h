#pragma once

namespace GameEngine{

	enum class RendererAPI
	{
		none = 0, OpenGL = 1
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }
	private:
		static RendererAPI s_RendererAPI;

	};

}