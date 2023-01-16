#include "gepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace GameEngine {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		GE_CORE_ASSERT(windowHandle, "window handle is null");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GE_CORE_ASSERT(status, "Failed to initialize Glad!");

		GE_CORE_INFO("OpenGL info:");
		GE_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		GE_CORE_INFO(" Render: {0}", glGetString(GL_RENDER),);
		GE_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
	}
	void OpenGLContext::SwapBuffer()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}