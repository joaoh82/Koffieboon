#include <Koffieboon.h>

class Playground : public Koffieboon::Application
{
public:
	Playground()
	{
		//PlatformStartup(1280, 720, "Playground", WindowMode_Windowed, nullptr);
	}	
	~Playground()
	{

	}
};

Koffieboon::Application* Koffieboon::CreateApplication()
{
	Koffieboon::Window window(1280, 720, "Playground");

	while (!window.ShouldClose())
	{
		window.PollEvents();
	}
	
	return new Playground();
}