#include "gepch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace GameEngine {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::none: GE_CORE_ASSERT(false, "RenrereAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}
		GE_CORE_ASSERT(false, "Unknown RenderAPI!");
		return nullptr;
	}
	
	IndexBuffer *IndexBuffer::Create(uint32_t *indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::none: GE_CORE_ASSERT(false, "RenrereAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}
		GE_CORE_ASSERT(false, "Unknown RenderAPI!");
		return nullptr;
	}
}