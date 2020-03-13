#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include "shader.h"
#include "Vertices.h"
#include <thread>
#include <vector>
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
float font=10;
float trans_x = 0, trans_y=0;
   unsigned int VBO, VAO;
glm::vec3 pontok[100];
    int pontcounter=0;


int main() {
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

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


    // set up vertex data (and buffer(s)) and configure vertex attributes
    // -------------------------

    Shader ourshader("4.0.shader.vs","4.0.shader.fs");

std::cout<<sizeof(glm::vec3)<<" : "<<sizeof(float)*3<<"\n";
std::cout<<sizeof(pontok)<<"\n";

    VerticeObject VER;
    VER.LoadVerticies("haromszog.txt");


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pontok), &pontok, GL_DYNAMIC_DRAW);///nézd meg

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

     //glDeleteBuffers(1, &VBO);


    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    pontok[0]=glm::vec3(0.1,0,0);
    pontok[1]=glm::vec3(0.5,0.1,0);
    pontok[2]=glm::vec3(0.1,0.5,0);



    while (!glfwWindowShouldClose(window)) {
            glPointSize(font);
        // render
        // ------
        glClearColor(0, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ourshader.use();
        ourshader.setVec3("unicolor",1,1,1);

        glBindVertexArray(VAO);

        glDrawArrays(GL_LINE_STRIP , 0, pontcounter);
        ourshader.setVec3("unicolor",1,0,0);
        glDrawArrays(GL_POINTS, 0, pontcounter);

       /* glDrawArrays(GL_LINE_STRIP_ADJACENCY , 0, pontcounter);
        ourshader.setVec3("unicolor",1,0,0);
        glDrawArrays(GL_POINTS, 0, pontcounter);
*/
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

    if(glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        pontcounter=0;
    }
    if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
        font=10;
    }
    if(glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
        font=20;
    }
     if(glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
    font=1;
    }
     if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {

    }
     if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {

    }
     if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {

    }
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;

        glfwGetCursorPos(window, &xpos, &ypos);

        float x= 2.0/SCR_WIDTH*xpos-1.0;
        float y= 2.0/SCR_HEIGHT*ypos-1.0;
        y*=-1;

        //std::cout << "Cursor Position at (" << x << " : " << y << "\n";
        //glm::vec3 pont = glm::vec3(x,y,0);
        pontok[pontcounter]=glm::vec3(x,y,0);
        std::cout << "Cursor Position at (" << pontok[pontcounter].x << " : " << pontok[pontcounter].y << "\n";
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        glBufferSubData(GL_ARRAY_BUFFER,pontcounter*sizeof(glm::vec3),sizeof(glm::vec3),&pontok[pontcounter]);
        glBindVertexArray(0);
        pontcounter++;

    }
}

