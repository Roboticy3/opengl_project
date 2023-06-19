#include <iostream>

#include "inputs.h"
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    char* name = (char*)glfwGetKeyName(key, scancode);

    if (!name) {
        name = (char*)"?";
    }
    
    std::cout << name << action << mods << "\n";
}

void init_inputs(GLFWwindow* window) {
    
    glfwSetKeyCallback(window, key_callback);

}