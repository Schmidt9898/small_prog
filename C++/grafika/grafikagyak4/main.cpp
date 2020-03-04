#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include "shader.h"
#include "Vertices.h"
#include <thread>

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
/*
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0,0.0,0.0,
        0.5f, -0.5f, 0.0f,  0.0,1.0,0.0,
        0.0f,  0.5f, 0.0f,  0.0,0.0,1.0
    };
*/
    VerticeObject VER;
    VER.LoadVerticies("haromszog.txt");
    unsigned int VBO, VAO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, VER.getsize(), VER.getvertices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);


    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

     glDeleteBuffers(1, &VBO);


    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    //glEnable(GL_DEPTH_BUFFER_BIT);
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        // render
        // ------
        glClearColor(0, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw our first triangle
        //glUseProgram(shaderProgram);
        ourshader.use();
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        double t=glfwGetTime()*10;
        double r = (sin(t) /2.0 + 0.5)*0.5;
        double g = (sin(t+45) /2.0 + 0.5)*0.5;
        double b = (sin(t+90) /2.0 + 0.5)*0.5;
        ourshader.setVec3("unicolor",r,g,b);
       // glUniform4f(unicolorlocation,r,g,b,1);

     /*  for(int i=0;i<2;i++)
       {/// A transzformációk lentrõl felvfele az az fordított sorrendben történnek meg, mert balról van szorozva.
        glm::mat4 trans = glm::mat4(1.0f);

        if(i==0)
        trans = glm::translate(trans,glm::vec3(trans_y,trans_x,0.0));

        if(i==1)
        trans = glm::translate(trans,glm::vec3(0.5-1,0.5,0.0));

        trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0,0,1));

        trans = glm::scale(trans,glm::vec3(0.5,0.1,0.0));

        ourshader.setMat4("trans",trans);

        glDrawArrays(GL_TRIANGLES, 0, 3);
       }*/

       for(int i=0;i<15;i++){
          glm::mat4 trans = glm::mat4(1.0f);

        trans = glm::translate(trans,glm::vec3(-0.9+(1.9/15*i),0.9,0.0));

        trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0,0,1));

        trans = glm::scale(trans,glm::vec3(0.1,0.1,0.0));

        ourshader.setMat4("trans",trans);

        glDrawArrays(GL_TRIANGLES, 0, 3);
       }

       x+=trans_x;
       y+=trans_y;
       x*=0.8;
       y*=0.8;

       if(x>1)
       x=1;
       if(y>1)
       y=1;
       if(x<-1)
       x=-1;
       if(y<-1)
       y=-1;
       if(x>1 || y>1 || x<-1 || y<-1){
        trans_x=0;
        trans_y=0;
       }


        glm::mat4 trans = glm::mat4(1.0f);

        trans = glm::translate(trans,glm::vec3(y,x,0.0));

        trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0,0,1));

        trans = glm::scale(trans,glm::vec3(0.5,0.1,0.0));
        ourshader.setMat4("trans",trans);
        ourshader.setVec3("unicolor",0,0,0);
        glDrawArrays(GL_TRIANGLES, 0, 3);





        /*trans = glm::translate(trans,glm::vec3(0.5,0.5,0.0));

        trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0,0,1));
        trans = glm::scale(trans,glm::vec3(0.5,0.1,0.0));

        ourshader.setMat4("trans",trans);

        glDrawArrays(GL_TRIANGLES, 0, 3);*/

        // glBindVertexArray(0); // no need to unbind it every time

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
         std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
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

