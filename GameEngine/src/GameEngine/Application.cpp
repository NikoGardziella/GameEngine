
#include "Application.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace GameEngine {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		GE_TRACE(e);

		while (true);
	}
}
