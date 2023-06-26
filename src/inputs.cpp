#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "inputs.h"
#include <GLFW/glfw3.h>

const char* unknown_key = (char*)"?name?";

enum inputs {
    INPUTS_CONFIRM = 0,
    INPUTS_ESCAPE,

    INPUTS_UP,
    INPUTS_DOWN,
    INPUTS_RIGHT,
    INPUTS_LEFT,

    INPUTS_M_UP,
    INPUTS_M_DOWN,
    INPUTS_M_RIGHT,
    INPUTS_M_LEFT
};

const std::unordered_map<int, inputs> input_map {
    
    {GLFW_KEY_SPACE, INPUTS_CONFIRM},
    {GLFW_KEY_ENTER, INPUTS_CONFIRM},

    {GLFW_KEY_ESCAPE, INPUTS_ESCAPE},
    
    {GLFW_KEY_UP, INPUTS_UP},
    {GLFW_KEY_DOWN, INPUTS_M_DOWN},
    {GLFW_KEY_RIGHT, INPUTS_M_RIGHT},
    {GLFW_KEY_LEFT, INPUTS_M_LEFT},
    
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    auto itr = input_map.find(key);
    if (itr == input_map.end()) {
        std::cout << "undefined input " << key << "\n";
        return;
    }

    auto[k,i] = *itr;

    std::cout << "input " << i << "\n";
}

void init_inputs(GLFWwindow* window) {
    
    glfwSetKeyCallback(window, key_callback);



}