#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "inputs.h"

/* arguments given to the program are meant to set these properties, processed by process_args() */
/* all arguments are named, and not positional */
bool should_fullscreen = false;

const char default_window_name[] = "Hello World";
char* window_name = (char*)default_window_name;

const char* options = "hfw:";

int handle_args(int argc, char**argv) {

    int result;

    while (1) {
        switch(getopt(argc, argv, options)) {
            case 'f':
                should_fullscreen = true;
                continue;
            case 'w':
                window_name = optarg;
                continue;
            case '?':
            case 'h':
                std::ifstream readme;
                readme.open("../README.md");
                
                std::cout << readme.rdbuf();

                readme.close();
                return -1;
        }

        break;
    }

    return 0;
}

int main(int argc, char **argv) {

    int err = handle_args(argc, argv);
    if (err) { 
        return err;
    }

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    GLFWmonitor* monitor;

    /* Create a windowed mode window and its OpenGL context */
    if (should_fullscreen) {
        monitor = glfwGetPrimaryMonitor();
        window = glfwCreateWindow(1920, 1080, window_name, monitor, NULL);
    }
    else {
        window = glfwCreateWindow(640, 480, window_name, NULL, NULL);
    }
    

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Couldn't load opengl\n";
        return -1;
    }

    /* Give the window to the input handler */

    init_inputs(window);

    glfwSwapInterval(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}