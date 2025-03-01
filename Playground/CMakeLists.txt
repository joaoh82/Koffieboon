# Playground/CMakeLists.txt

# List your source files for the executable.
set(PLAYGROUND_SOURCES
    src/PlaygroundApp.cpp
    # Add additional source files as needed.
)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    # Use the same settings as in Engine/CMakeLists.txt
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

# Link the executable with the Engine DLL.
target_link_libraries(Playground PRIVATE Engine)

# Add compile definition for the Playground project.
target_compile_definitions(Playground 
    PRIVATE 
        KB_PLATFORM_WINDOWS 
        $<$<CONFIG:Release>:KB_RELEASE>
)

target_compile_options(Playground PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# Add a post-build step to copy Engine.dll to the output directory
add_custom_command(TARGET Playground POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_BINARY_DIR}/Engine/$<CONFIG>/Engine.dll"
        $<TARGET_FILE_DIR:Playground>
)