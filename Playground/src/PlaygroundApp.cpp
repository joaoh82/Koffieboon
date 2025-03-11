#include <Koffieboon.h>

#include "imgui/imgui.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}

class ExampleLayer : public Koffieboon::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		//auto cam = camera(5.0f, { 0.0f, 0.0f });
	}

	void OnUpdate() override
	{
		// Check if the tab key is pressed
		if (Koffieboon::Input::IsKeyPressed(KB_KEY_TAB))
			KB_TRACE("Tab key is pressed!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
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