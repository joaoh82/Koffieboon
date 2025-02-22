#include <Koffieboon.h>

class Playground : public Koffieboon::Application
{
public:
	Playground()
	{
		//PlatformStartup(1280, 720, "Playground", WindowMode_Windowed, nullptr);
		KASSERT_MSG(1, "This is a test");
		KASSERT_MSG(0, "This is a failed test");
	}	
	~Playground()
	{

	}
};

Koffieboon::Application* Koffieboon::CreateApplication()
{
	return new Playground();
}