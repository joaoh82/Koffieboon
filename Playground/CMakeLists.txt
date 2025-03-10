# Playground/CMakeLists.txt

# List your source files for the executable.
set(PLAYGROUND_SOURCES
    src/PlaygroundApp.cpp
    imgui.ini
    # Add additional source files as needed.
)

# Ensure consistent runtime library usage
if(MSVC)
    # Use static runtime libraries
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    
    # Remove any manual string replacements for runtime flags
    # string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    # string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
endif()

add_executable(Playground ${PLAYGROUND_SOURCES})

# Include directories for Playground:
# - The Engine headers, so that Playground can use Engine's API.
# - The spdlog headers directly, if needed in Playground source files.
target_include_directories(Playground
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/../Engine/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Engine/vendor/spdlog/include
)

# Link the executable with the Engine Static Library.
target_link_libraries(Playground PRIVATE Engine)
# Adding this to prevent warnings about conflicting libraries
target_link_options(Playground PRIVATE "/NODEFAULTLIB:LIBCMT")


# Add compile definition for the Playground project.
target_compile_definitions(Playground 
    PRIVATE 
        KB_PLATFORM_WINDOWS 
        _CRT_SECURE_NO_WARNINGS
        $<$<CONFIG:Release>:KB_RELEASE>
)

target_compile_options(Playground PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
