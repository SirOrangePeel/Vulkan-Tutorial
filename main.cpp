#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication {
    public:
        void run() {
            initVulkan();
            mainLoop();
            cleanup();
        }

    private:
        //Window Pointer
        GLFWwindow* window;

        void initVulkan() {
            //Initializing Window manager
            glfwInit();

            //Telling GLFW window to not use OpenGL Context && that it can't be resized
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            /*This is only relevant to OpenGl                        ↓↓↓↓↓↓↓*/
            window = glfwCreateWindow( 800, 600, "Vulkan", nullptr,  nullptr);
        }

        void mainLoop() {
            while (!glfwWindowShouldClose(window)) {
                glfwPollEvents();
            }
        }

        void cleanup() {
            glfwDestroyWindow(window);

            glfwTerminate();
        }
};

int main() {
    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}