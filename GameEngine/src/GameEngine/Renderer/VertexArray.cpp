#include "gepch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace GameEngine {

    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI())
		{
			case RendererAPI::none: GE_CORE_ASSERT(false, "RenrereAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::OpenGL: return new OpenGLVertexArray();
		}
		GE_CORE_ASSERT(false, "Unknown RenderAPI!");
		return nullptr;
    }
}