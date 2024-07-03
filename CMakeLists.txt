cmake_minimum_required(VERSION 3.5)
project(RaySnake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s -mwindows")

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif ()
endif ()

# Our Project

add_executable(${PROJECT_NAME} main.cpp
        src/Application.cpp
        src/Application.h
        src/Game.cpp
        src/Game.h
        src/Menu/Menu.h
        src/Menu/MainMenu.h
        src/Menu/MainMenu.cpp
        src/Menu/AboutMenu.h
        src/Menu/AboutMenu.cpp
        src/Menu/Menu.cpp
        src/Objects/GameObject.h
        src/Objects/Player.h
        src/Objects/Food.h src/Objects/Player.cpp)
target_link_libraries(${PROJECT_NAME} raylib)


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
#target_precompile_headers(${PROJECT_NAME} PUBLIC gpch.h)

#target_sources(${PROJECT_NAME} PRIVATE res/app.rc)


# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()