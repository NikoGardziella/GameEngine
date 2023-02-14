#include "gepch.h"
#include "Shader.h"


#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace GameEngine {

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentS)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::none: GE_CORE_ASSERT(false, "RenrereAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSrc, fragmentS);
		}
		GE_CORE_ASSERT(false, "Unknown RenderAPI!");
		return nullptr;
	}
}