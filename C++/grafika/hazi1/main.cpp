#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include "shader.h"
#include "Vertices.h"
#include <thread>
#include "Drawable.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float r = 0, g = 0, b = 0;

float trans_x = 0, trans_y=0;
float x=0,y=0;


int main() {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL_gyak_4", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    //Pen pen("adam","files/triangle.vs","files/triangle.fs","files/triangle.txt","none");
    Pen pen("adam","files/rectangle.vs","files/rectangle.fs","files/rectangle.txt","files/rectangle.ind");


    while (!glfwWindowShouldClose(window)) {

        glClearColor(0, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        //glUseProgram(shaderProgram);
//        ourshader.use();
  //      glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        double t=glfwGetTime();
        double r = (sin(t) /2.0 + 0.5);
        double g = (sin(t/2) /2.0 + 0.5);
        double b = (sin(t/4) /2.0 + 0.5);
    //    ourshader.setVec3("unicolor",r,g,b);
       // glUniform4f(unicolorlocation,r,g,b,1);



          glm::mat4 trans = glm::mat4(1.0f);

        //trans = glm::translate(trans,glm::vec3(0.5,0,0.0));




        trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0,0,1));
        trans = glm::scale(trans,glm::vec3(1,0.1,0.0));
        //trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0,0,1));
        pen.Draw(trans,glm::vec3(r,g,b));


        glfwSwapBuffers(window);
        glfwPollEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        if(r < 1.0 )
            r += 0.1;
        else
            r = 0.0;
    }
    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
        if(g < 1.0 )
            g += 0.1;
        else
            g = 0.0;
    }
    if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
        if(b < 1.0 )
            b += 0.1;
        else
            b = 0.0;
    }
     if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        trans_y=-0.01;
    }
     if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    trans_y=0.01;
    }
     if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
       trans_x=0.01;
    }
     if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
       trans_x=-0.01;
    }
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        //getting cursor position
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout << "Cursor Position at (" << xpos << " : " << ypos << "\n";
    }
}

