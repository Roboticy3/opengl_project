cmake_minimum_required(VERSION 3.0.0)
project(opengl_project VERSION 0.1.0)

file(GLOB SOURCES "src/*")

add_executable(opengl_project 
    ${SOURCES}
)

target_link_libraries(opengl_project 
    glfw
)