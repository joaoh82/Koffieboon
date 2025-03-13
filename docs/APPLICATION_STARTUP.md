
# Application Startup

This is a common pattern in game engine development. While you don't see the main() function here, it actually exists in the engine code. Here's how it works:

## Entry Point Pattern

1. The engine (Koffieboon) defines the `main()` function in an entry point file.

```cpp
extern Koffieboon::Application* Koffieboon::CreateApplication();

int main(int argc, char** argv)
{
	Koffieboon::Logger::InitializeLogging();
	KB_INFO("Initialized logging\n");

	KB_INFO("Koffieboon Engine...\n");

	auto app = Koffieboon::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
```

2. The engine declares a function that client applications must implement:
```cpp
namespace Koffieboon {
    // To be defined in the client. Client must implement this function.
    Application* CreateApplication();
}
```

3. Playground code implements this `CreateApplication()` function:
```cpp
Koffieboon::Application* Koffieboon::CreateApplication()
{
    return new Playground();
}
```

This pattern is called the "Entry Point" pattern and has several benefits:

- The engine controls the application lifecycle
- The engine can perform necessary initialization before the application starts
- Client code only needs to define their specific application behavior
- Consistent startup sequence across all applications using the engine

So when we run the program:

1. The engine's main() function is called
2. It initializes the engine systems
3. It calls your CreateApplication() function to get your application instance
4. It runs your application through the engine's main loop
5. When the application exits, it handles cleanup

This is why we can create a working application without writing our own `main()` function - the engine provides it for us!