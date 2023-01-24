#include <GameEngine.h>

#include "imgui/imgui.h"


class ExampleLayer : public GameEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	
	}

	void OnUpdate() override
	{
		RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 0.1f });
		RenderCommand::Clear;

		m_Camera.SetPosition({ 0.5f, 0.5f, 0.0f });
		m_Camera.SetRotation(45.0f);

		Renderer::BeginScene(m_Camera);

		Renderer::Submit(m_BlueShader, m_SquareVA);
		Renderer::Submit(m_Shader, m_VertexArray);

		Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{

	}

	void OnEvent(GameEngine::Event& event) override
	{

	}

private:
	std::shared_ptr<Shader> m_Shader;
	std::shared_ptr<VertexArray> m_VertexArray;

	std::shared_ptr<Shader> m_BlueShader;
	std::shared_ptr<VertexArray> m_SquareVA;

	OrthographicCamera m_Camera;
};

class Sandbox : public GameEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		
	}

	~Sandbox()
	{

	}

};


GameEngine::Application* GameEngine::CreateApplication()
{
	return new Sandbox;
}