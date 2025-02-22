#include "kbpch.h"
#include "Platform_DEPRECATED.h"

b8 PlatformStartup(i32 width, i32 height, const char* application_name, WindowMode window_mode, GLFWwindow* share)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return FALSE;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, application_name, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return FALSE;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        ///* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

	return TRUE;
}