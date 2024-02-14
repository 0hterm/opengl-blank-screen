#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Callback function for resetting viewport after window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0,0,width,height);
}

// Function to process input
void processInput(GLFWwindow *window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

int main() {

    // Initializing GLFW Window
    glfwInit();
    // Setting the OpenGL version to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Setting the OpenGL profile to core
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Creating a window object
    GLFWwindow* window = glfwCreateWindow(800,600,"LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // Making the window the current/main context
    glfwMakeContextCurrent(window);

    // Initializing GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Setting the viewport
    glViewport(0,0,800,600);

    // Tell GLFW to call this function on every window resize by registering it
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Render Loop, to keep window open until it is told to close
    while(!glfwWindowShouldClose(window)) {

        /* 
        We want to place all render events within
        this render loop   
        */

        // Clear the frame at start of each iteration
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // Change color with these parameters
        glClear(GL_COLOR_BUFFER_BIT);

        // Process input
        processInput(window);

        // Polling for events
        glfwSwapBuffers(window);
        // Swapping the color buffer
        glfwPollEvents();

    }

    // Terminating GLFW
    glfwTerminate();
    return 0;
}