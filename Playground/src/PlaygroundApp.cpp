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
		// Check if the tab key is pressed
		if (Koffieboon::Input::IsKeyPressed(KB_KEY_TAB))
			KB_TRACE("Tab key is pressed!");
	}

	void OnEvent(Koffieboon::Event& event) override
	{
		if (event.GetEventType() == Koffieboon::EventType::KeyPressed)
		{
			// Check if the tab key is pressed
			Koffieboon::KeyPressedEvent& e = (Koffieboon::KeyPressedEvent&)event;
			if (e.GetKeyCode() == KB_KEY_TAB)
				KB_TRACE("Tab key is pressed (event)!");
			KB_TRACE("{0}", (char)e.GetKeyCode());
		}
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