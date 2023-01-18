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

			virtual const AddVerteBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) const = 0;
			virtual const AddIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) const = 0;

			static VertexArray* Create();
		};
}
