# Engine/CMakeLists.txt

# Optionally add GLFW via add_subdirectory if you have its CMake project in vendor
# If GLFW is not a CMake project or you prefer a prebuilt library, adjust accordingly.
# Uncomment the next line if Engine/vendor/glfw has a CMakeLists.txt
# add_subdirectory(vendor/glfw)

# Add files from ImGui located in vendor/imgui
file(GLOB ENGINE_IMGUI_SOURCES
    "vendor/imgui/*.cpp"
    "vendor/imgui/*.h"
    "vendor/imgui/*.hpp"
)

# Find all source and header files recursively
file(GLOB_RECURSE ENGINE_SOURCES 
    "src/*.cpp"
    "src/*.c"
)

file(GLOB_RECURSE ENGINE_HEADERS
    "src/*.h"
    "src/*.hpp"
)

# Add files from Glad located in vendor/glad
file(GLOB ENGINE_GLAD_SOURCES
    "vendor/glad/src/glad.c"
)

# Add files from GLM located in vendor/glm
file(GLOB ENGINE_GLM_SOURCES
    "vendor/glm/*.inl"
    "vendor/glm/*.hpp"
)



# Set static runtime libraries at the top level
if(MSVC)
    # Use static runtime libraries
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    
    # # Add linker option to ignore conflicting library
    # add_link_options(/NODEFAULTLIB:LIBCMT$<$<CONFIG:Debug>:D>)
endif()

# Create the static library - include Glad sources
add_library(Engine STATIC 
    ${ENGINE_SOURCES} 
    ${ENGINE_HEADERS}
    ${ENGINE_GLAD_SOURCES}
    ${ENGINE_IMGUI_SOURCES}
    ${ENGINE_GLM_SOURCES}
)

# Disable precompiled headers for glad sources
set_source_files_properties(
    ${ENGINE_GLAD_SOURCES}
    PROPERTIES 
    SKIP_PRECOMPILE_HEADERS ON
)

# Disable precompiled headers for imgui sources
set_source_files_properties(
    ${ENGINE_IMGUI_SOURCES}
    PROPERTIES 
    SKIP_PRECOMPILE_HEADERS ON
)

# Set the PCH header and source
set(PCH_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/src/kbpch.h)
set(PCH_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/kbpch.cpp)
target_precompile_headers(Engine PRIVATE ${PCH_HEADER})

# Add GLFW as a subdirectory if you have its source
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw)

# Specify include directories for Engine
target_include_directories(Engine
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include  # GLFW headers
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include # spdlog headers
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include # glad headers
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui # imgui headers
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm # glm headers
)

# Link against GLFW
target_link_libraries(Engine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/lib/glfw3_mt.lib  # Use MT version
    opengl32.lib
)

# (Optional) Set any definitions needed for DLL export/import.
# Add compile definitions for the Engine project.
target_compile_definitions(Engine 
    PRIVATE 
        KB_PLATFORM_WINDOWS 
        _CRT_SECURE_NO_WARNINGS
        $<$<CONFIG:Release>:KB_RELEASE>
        GLFW_INCLUDE_NONE
)

target_compile_options(Engine PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
