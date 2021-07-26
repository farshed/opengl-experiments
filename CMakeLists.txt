cmake_minimum_required(VERSION 3.16)
project(opengl)

set(CMAKE_CXX_STANDARD 17)

#add_executable(opengl src main.cpp)

SET(CMAKE_OSX_ARCHITECTURES "arm64")


# Add header file
set(GLEW_H /opt/homebrew/Cellar/glew/2.2.0_1/include/GL)
set(GLFW_H /opt/homebrew/Cellar/glfw/3.3.4/include/GLFW)
include_directories(${GLEW_H} ${GLFW_H})

# Add target link
set(GLEW_LINK /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.dylib)
set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.3.4/lib/libglfw.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

# Execute compilation command
set(SOURCE_FILES main.cpp)
add_executable(test main.cpp)

if (APPLE)
    target_link_libraries(test "-framework OpenGL")
    target_link_libraries(test " -framework GLUT")
endif()