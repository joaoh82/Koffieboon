#include <Koffieboon.h>


class ExampleLayer : public Koffieboon::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		KB_INFO("ExampleLayer::Update");
	}

	void OnEvent(Koffieboon::Event& event) override
	{
		KB_TRACE("{0}",event.ToString());
	}
};

/// <summary>
/// Playground is a class that represents the application.
/// </summary>
class Playground : public Koffieboon::Application
{
public:
	Playground()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Koffieboon::ImGuiLayer());

		//KASSERT_MSG(1, "This is a test");
		//KASSERT_MSG(0, "This is a failed test");
	}	
	~Playground()
	{

	}
};

Koffieboon::Application* Koffieboon::CreateApplication()
{
	return new Playground();
}