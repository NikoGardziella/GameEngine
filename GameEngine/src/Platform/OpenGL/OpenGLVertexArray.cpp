#include "gepch.h"
#include "OpenGLVertexArray.h"

#include "glad/glad.h"

namespace GameEngine {

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}
	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
	const OpenGLVertexArray::AddVerteBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer)
	{
		glBindVertexArray(m_RendererID);
		VertexBuffer->Bind();
		uint32_t index = 0;
		const &auto layout = m_VertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
			GetComponentCount(),
			ShaderDataTypeToOpenGLBaseType(element.Type),
			element.Normalized ? GL_TRUE : GL_FALSE,
			layout.GetStride(),
			(const void*)element.Offset);
			index++;
		}
	}
	const OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer)
	{
		return nullptr;
	}
}