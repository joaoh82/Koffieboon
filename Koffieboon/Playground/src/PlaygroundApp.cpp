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

int main() {
	// Allocate a new playground on the heap
	Playground* playground = new Playground();

	PrintInt(5);

	playground->Run();

	delete playground;
}