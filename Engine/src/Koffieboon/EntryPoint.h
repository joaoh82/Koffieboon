#pragma once

#ifdef KB_PLATFORM_WINDOWS

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

#endif // KB_PLATFORM_WINDOWS
