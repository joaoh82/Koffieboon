# Notes

## ImGui

### How to setup ImGui for OpenGL on Visual Studio

1. Git Clone ImGui as a submodule
    ```bash
    git submodule add https://github.com/ocornut/imgui.git Engine/vendor/imgui
    ```
2. Add the following to the `Engine/CMakeLists.txt` file
    ```cmake
    file(GLOB ENGINE_IMGUI_SOURCES
        "vendor/imgui/*.cpp"
        "vendor/imgui/*.h"
        "vendor/imgui/*.hpp"
    )
    ```
3. Add all the sources to the `Engine` target on visual studio
    - Right click on the `Engine` target
    - Click on `Properties`
    - Click on `Source Files`
    - Add all the sources to the target
4. Go to Engine Project Properties -> C++ -> General and add `$(SolutionDir)Engine\vendor\imgui;` to `Aditional Include Directories`.
5. Add the following to the `Engine/CMakeLists.txt` file
    ```cmake
    target_include_directories(Engine
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui # imgui headers
    )
    ```
6. You might have to add the following definition to Preprocessor Definitions: `_CRT_SECURE_NO_WARNINGS`
7. Add the following to the `Engine/CMakeLists.txt` file
    ```cmake
    target_compile_definitions(Engine
        PRIVATE
            _CRT_SECURE_NO_WARNINGS
    )
    ```

### References

- [ImGui](https://github.com/ocornut/imgui)
- [ImGui OpenGL3 Backend](https://github.com/ocornut/imgui/blob/master/examples/imgui_impl_opengl3.cpp)
- [ImGui GLFW Backend](https://github.com/ocornut/imgui/blob/master/examples/imgui_impl_glfw.cpp)
