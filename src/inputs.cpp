#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "inputs.h"
#include <GLFW/glfw3.h>

enum inputs {
    INPUTS_CONFIRM = 0,
    INPUTS_ESCAPE,

    INPUTS_UP,
    INPUTS_DOWN,
    INPUTS_RIGHT,
    INPUTS_LEFT
};

const std::string* keys {
    
};

std::map<std::string, inputs> input_map {

    {"space",INPUTS_CONFIRM},
    {"enter",INPUTS_CONFIRM},
    
    {}

};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    std::cout << key << action << mods << "\n";
}

void init_inputs(GLFWwindow* window) {
    
    glfwSetKeyCallback(window, key_callback);



}