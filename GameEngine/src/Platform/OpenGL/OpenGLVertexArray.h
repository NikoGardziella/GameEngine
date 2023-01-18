#pragma once

#include "GameEngine/Renderer/VertexArray.h"

namespace GameEngine {

	class OpenGLVertexArray : public VertexArray
		{
		public:
			OpenGLVertexArray(); 
			virtual ~OpenGLVertexArray() {}


			virtual void Bind() const override;
			virtual void Unbind() const override;

			virtual const AddVerteBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
			virtual const SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;

		private:
			uint32_t m_RendererID;
			std::vector<std::shared_ptr<VertexBuffer> m_VertexBuffers;
			std::shared_ptr<IndexBuffer> m_IndexBuffers;
		};
}
