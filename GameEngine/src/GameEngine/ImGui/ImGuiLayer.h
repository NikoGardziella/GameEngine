#pragma once

#include "GameEngine/Layer.h"

namespace GameEngine {

	class ImGui : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate();
		void OnEvent(Event& event);
	private:

	};
}

