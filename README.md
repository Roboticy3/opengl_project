Build instructions:
    Install glfw3
    Open in vscode with the CMake and CMake Tools extentions
    Build from vscode

I haven't tested this outside of my environment, but I am making this on ubuntu with GCC, and had a lot of trouble installing glfw

Building creates a build folder containing the opengl_project executable

Run options:
    After building, run ./app from the root directory, which itself is just a link to the executable created by building.
    ./app -f -w <window-name>
    
    -f : make the window fullscreen
    -w <window-name> : name the window
