#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char **argv)
{
	GameEngine::Log::Init();
	GE_CORE_WARN("GetCoreLogger initialized");
	int a = 5;
	GE_INFO("GetClientLogger initialized var={0}",a);
	printf("GameEngine\n");
	auto app = GameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
