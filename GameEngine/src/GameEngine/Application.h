#pragma once

#include "Core.h"

#include "GameEngine/LayerStack.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

#include "GameEngine/Core/Timestep.h"
#include "GameEngine/ImGui/ImGuiLayer.h"



namespace GameEngine {

	class Application
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
	private:	

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrametime = 0.0f;
	private:
		static Application* s_Instance;
 	};
	
	//To be defiend by client
	Application* CreateApplication();

}

