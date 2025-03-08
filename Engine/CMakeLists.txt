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

# Set static runtime libraries at the top level
if(MSVC)
    # Use static runtime libraries
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    
    # # Add linker option to ignore conflicting library
    # add_link_options(/NODEFAULTLIB:LIBCMT$<$<CONFIG:Debug>:D>)
endif()

# Create the static library (DLL)
add_library(Engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

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
        SPDLOG_COMPILED_LIB
        $<$<CONFIG:Release>:KB_RELEASE>
)

target_compile_options(Engine PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
