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

	// Test logging
	KB_FATAL("This is a fatal error\n");
	KB_ERROR("This is an error\n");
	KB_WARN("This is a warning\n");
	KB_INFO("This is an info message\n");
	KB_DEBUG("This is a debug message\n");
	KB_TRACE("This is a trace message\n");

	// Test assertions
	KASSERT(1 == 0);

	playground->Run();

	delete playground;
}