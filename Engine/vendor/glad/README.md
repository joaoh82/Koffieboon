# How to add glad properly to the project?

Main Website: https://github.com/Dav1dde/glad

Steps:

1. Go to the GLAD [web service](https://glad.dav1d.de/), make sure the language is set to C++, 
and in the API section select an OpenGL version of at least 3.3 (I choose 4.6). Also make sure 
the profile is set to Core and that the Generate a loader option is ticked. 
Ignore the extensions (for now) and click Generate to produce the resulting library files.
2. Download, unzip and copy the two folders `include` and `src` into `vendor/glad/`.
3. Go to Engine Project Properties -> C++ -> General and add `$(SolutionDir)Engine\vendor\glad\include;` to `Aditional Include Directories`.
4. Go to Engine Project Properties -> C++ -> Precompiled Definitions and add `GLFW_INCLUDE_NONE`.
5. Go to Engine --> Add --> Existing Item and add `glad.c` from `vendor/glad/src/`.
6. Right click on `glad.c` and select Properties. Using tree on the left side go to the "C++/Precompiled Headers" section. 
On the right side of the window you'll get three properties.  Set property named "Create/Use Precompiled Header" to the value of "Not Using Precompiled Headers".


References:

- https://stackoverflow.com/questions/8862840/unexpected-end-of-file-error
- https://stackoverflow.com/questions/44345811/glad-h-giving-error-that-opengl-header-is-included
- https://learnopengl.com/Getting-started/Creating-a-window