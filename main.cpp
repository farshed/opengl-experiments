#include <iostream>
#include <string.h>
#include <glew.h>
#include <glfw3.h>

#define log(x) std::cout << x << std::endl

const GLint WIDTH = 1200, HEIGHT = 900;

GLuint VAO, VBO, shader;

void createTriangle() {
     GLfloat vertices[] = {
             -1.0f, 1.0f, 0.0f,
             1.0f, -1.0f, 0.0f,
             0.0f, 1.0f, 0.0f
     };
     
}

int main() {
    if (!glfwInit()) {
        log("Couldn't initialize glfw");
        glfwTerminate();
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Main Window", NULL, NULL);
    if (!mainWindow) {
        log("Couldn't create a window");
        glfwTerminate();
        return 1;
    }

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    glfwMakeContextCurrent(mainWindow);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        log("Couldn't initialize glew");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    glViewport(0, 0, bufferWidth, bufferHeight);

    while (!glfwWindowShouldClose(mainWindow)) {
        glfwPollEvents();
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(mainWindow);
    }
}