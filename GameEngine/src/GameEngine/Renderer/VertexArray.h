#pragma once

#include "GameEngine/Renderer/Buffer.h"
#include <memory>

namespace GameEngine {

	class VertexArray
		{
		public:
			virtual ~VertexArray() {}

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
			virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

			static VertexArray* Create();
		};
}
