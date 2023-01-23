#pragma once

#include "Core.h"

#include "GameEngine/LayerStack.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "glm/glm.hpp"

#include "GameEngine/ImGui/ImGuiLayer.h"

#include "GameEngine/Renderer/Shader.h"
#include "GameEngine/Renderer/Buffer.h"
#include "GameEngine/Renderer/VertexArray.h"

namespace GameEngine {

	class GE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run(); 

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
 	};
	
	//To be defiend by client
	Application* CreateApplication();

}

