#pragma once

#include "Core.h"

#include "GameEngine/LayerStack.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "glm/glm.hpp"

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
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
 	};
	
	//To be defiend by client
	Application* CreateApplication();

}

