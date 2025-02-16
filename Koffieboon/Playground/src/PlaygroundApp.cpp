#include <Koffieboon.h>

class Playground : public Koffieboon::Application
{
public:
	Playground()
	{

	}
	~Playground()
	{

	}
};

Koffieboon::Application* Koffieboon::CreateApplication()
{
	return new Playground();
}