# Engine/CMakeLists.txt

# Optionally add GLFW via add_subdirectory if you have its CMake project in vendor
# If GLFW is not a CMake project or you prefer a prebuilt library, adjust accordingly.
# Uncomment the next line if Engine/vendor/glfw has a CMakeLists.txt
# add_subdirectory(vendor/glfw)

# Find all source and header files recursively
file(GLOB_RECURSE ENGINE_SOURCES 
    "src/*.cpp"
    "src/*.c"
)

file(GLOB_RECURSE ENGINE_HEADERS
    "src/*.h"
    "src/*.hpp"
)

# Add this at the top, after the file globbing
if(MSVC)
    # Force MSVC to use dynamic runtime libraries
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    
    # Or if you prefer static runtime:
    # set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    
    # Additional MSVC-specific options
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
endif()

# Create the shared library (DLL)
add_library(Engine SHARED ${ENGINE_SOURCES} ${ENGINE_HEADERS})

set(PCH_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/src/kbpch.h)
set(PCH_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/kbpch.cpp)
target_precompile_headers(Engine PRIVATE ${PCH_HEADER})


# Specify include directories for Engine
target_include_directories(Engine
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/include  # GLFW headers
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include # spdlog headers
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glew/include # glew headers
)

# Link against GLFW.
# If you built GLFW via add_subdirectory, its target might be called "glfw" or "glfw3".
# Otherwise, if you are linking to a prebuilt static GLFW, use its library file directly:
#
target_link_libraries(Engine PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw/lib/glfw3.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glew/lib/Release/x64/glew32.lib
    opengl32.lib
)
#
# For this example, assume GLFW was added as a subdirectory and provides a target "glfw":
# target_link_libraries(Engine PRIVATE glfw)
# Add the new link options right after
if(MSVC)
    target_link_options(Engine 
        PRIVATE 
            $<$<CONFIG:Debug>:/NODEFAULTLIB:MSVCRT>
            $<$<CONFIG:Release>:/NODEFAULTLIB:MSVCRTD>
    )
endif()

# (Optional) Set any definitions needed for DLL export/import.
# Add compile definitions for the Engine project.
target_compile_definitions(Engine 
    PRIVATE 
        KB_PLATFORM_WINDOWS 
        KB_BUILD_DLL
        $<$<CONFIG:Release>:KB_RELEASE>
)

target_compile_options(Engine PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
