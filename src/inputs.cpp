#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "inputs.h"
#include <GLFW/glfw3.h>

/* Definitions for each input that can be used on this application */
enum INPUT_BUTTONS {
    INPUTS_CONFIRM = 0,
    INPUTS_ESCAPE,

    INPUTS_UP,
    INPUTS_DOWN,
    INPUTS_RIGHT,
    INPUTS_LEFT,

    INPUTS_M_UP,
    INPUTS_M_DOWN,
    INPUTS_M_RIGHT,
    INPUTS_M_LEFT,

    /* keep this enum to count the number of terms in inputs */
    INPUTS_NUM
};

/* Keep track of which buttons are currently pressed */
bool button_mask[INPUTS_NUM] = {0};

/* Mapping that allows for keys from GLFW to be assigned to inputs
    Multiple keys can be mapped to the same input, but each key can only represent one input*/
const std::unordered_map<int, INPUT_BUTTONS> button_map {
    
    {GLFW_KEY_SPACE, INPUTS_CONFIRM},
    {GLFW_KEY_ENTER, INPUTS_CONFIRM},

    {GLFW_KEY_ESCAPE, INPUTS_ESCAPE},
    
    {GLFW_KEY_UP, INPUTS_UP},
    {GLFW_KEY_DOWN, INPUTS_DOWN},
    {GLFW_KEY_RIGHT, INPUTS_RIGHT},
    {GLFW_KEY_LEFT, INPUTS_LEFT},

    {GLFW_KEY_W, INPUTS_M_UP},
    {GLFW_KEY_S, INPUTS_M_DOWN},
    {GLFW_KEY_D, INPUTS_M_RIGHT},
    {GLFW_KEY_A, INPUTS_M_LEFT},
    
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    auto itr = button_map.find(key);
    if (itr == button_map.end()) {
        //std::cout << "undefined input " << key << "\n";
        return;
    }

    auto[k,i] = *itr;

    button_mask[i] = action;
}

void init_inputs(GLFWwindow* window) {
    
    glfwSetKeyCallback(window, key_callback);



}