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

#include "lagrange.h"
#include "beziercurve.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void mouse_move();
void CalculateBezier();
void CalculateLagrange();
void Double_cp();

bool btn_down=false;

// settings
unsigned int SCR_WIDTH = 800;
unsigned int SCR_HEIGHT = 600;

bool islagrange=false;
bool isupdate=false;
bool isbezier=false;

float font=10;
float trans_x = 0, trans_y=0;

unsigned int VBO, VAO,VBO_cp,VAO_cp;
glm::vec3 pontok[100];
glm::vec3 cp_pontok[100];
int pontcounter=0;
int selected_point=-1;
int drawnumberpont=0;


GLFWwindow* window=nullptr;

int init()
{
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
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL_gyak_4", nullptr, nullptr);
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
}




int main() {

    if(init()==-1)
        return -1;


    Shader ourshader("4.0.shader.vs","4.0.shader.fs");

std::cout<<sizeof(glm::vec3)<<" : "<<sizeof(float)*3<<"\n";
std::cout<<sizeof(pontok)<<"\n";

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


    glGenVertexArrays(1, &VAO_cp);
    glGenBuffers(1, &VBO_cp);

    glBindVertexArray(VAO_cp);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_cp);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cp_pontok), &cp_pontok, GL_DYNAMIC_DRAW);///nézd meg

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);



    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    /*pontok[0]=glm::vec3(0.1,0,0);
    pontok[1]=glm::vec3(0.5,0.1,0);
    pontok[2]=glm::vec3(0.1,0.5,0);
*/


    while (!glfwWindowShouldClose(window)) {
            glPointSize(font);

            glClearColor(0, 0, 0, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            ourshader.use();
            ourshader.setVec3("unicolor",1,1,1);

            glBindVertexArray(VAO);

            glDrawArrays(GL_LINE_STRIP , 0, drawnumberpont);
            ourshader.setVec3("unicolor",1,0,0);

            glBindVertexArray(VAO_cp);
            glDrawArrays(GL_POINTS, 0, pontcounter);


            if(isupdate){
                if(islagrange)
                    CalculateLagrange();
                if(isbezier)
                    CalculateBezier();
            }


            mouse_move();
            glfwSwapBuffers(window);
            glfwPollEvents();


            std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }




    glfwTerminate();
    return 0;
}

void CalculateLagrange()
{
    if(!isupdate)
        return;
    int f=100;

   // glm::vec3 new_pontok[f];
    LagrangeCurve lag;
    for(int i=0;i<pontcounter;i++)
    {
        lag.AddControlPoint(cp_pontok[i]);
    }
    float div = 1/(float)(f-1);
    //std::cout<<div<<" div\n";
    float t=0;

for(int i=0;i<f;i++)
{
    pontok[i]=lag.r(t);
    //std::cout<<t<<"\n";
    t+=div;

}
//std::cout<<t<<" t\n";
drawnumberpont=f;
   glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        glBufferSubData(GL_ARRAY_BUFFER,0,f*sizeof(glm::vec3),&pontok[0]);
        glBindVertexArray(0);

        std::cout<<"lagrang\n";
        isupdate=false;

}

void CalculateBezier()
{
    if(!isupdate)
        return;
    int f=100;

    //glm::vec3 new_pontok[f];
    BezierCurve bez;
    for(int i=0;i<pontcounter;i++)
    {
        bez.AddControlPoint(cp_pontok[i]);
    }
    float div = 1/(float)(f-1);
    //std::cout<<div<<" div\n";
    float t=0;

for(int i=0;i<f;i++)
{
    pontok[i]=bez.r(t);
    //std::cout<<t<<"\n";
    t+=div;

}
//std::cout<<t<<" t\n";
drawnumberpont=f;
   glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        glBufferSubData(GL_ARRAY_BUFFER,0,f*sizeof(glm::vec3),&pontok[0]);
        glBindVertexArray(0);

        std::cout<<"bezier\n";
        isupdate=false;

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
    SCR_WIDTH=width;
    SCR_HEIGHT=height;
    glViewport(0, 0, width, height);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

if(!btn_down){
        btn_down=true;
     switch(key)
    {
    case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(window, true);
        break;
    case GLFW_KEY_C:
        pontcounter=0;
        drawnumberpont=0;
        break;
    case GLFW_KEY_1:
         font=1;
        break;
    case GLFW_KEY_2:
         font=5;
        break;
    case GLFW_KEY_3:
         font=10;
        break;
    case GLFW_KEY_4:
         font=15;
        break;
    case GLFW_KEY_5:
        break;
    case GLFW_KEY_6:
        break;
    case GLFW_KEY_7:
        break;
    case GLFW_KEY_8:
        break;
    case GLFW_KEY_F:
        Double_cp();
        break;
    case GLFW_KEY_L:
        islagrange=isupdate=true;
        isbezier=false;
        break;
    case GLFW_KEY_B:
        isupdate=true;
        islagrange=false;
        isbezier=true;
        break;
    }
}
if(btn_down && action == GLFW_RELEASE)
    btn_down=false;





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
        cp_pontok[pontcounter]=pontok[pontcounter]=glm::vec3(x,y,0);
       /*
        std::cout << "Cursor Position at (" << pontok[pontcounter].x << " : " << pontok[pontcounter].y << "\n";
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        glBufferSubData(GL_ARRAY_BUFFER,pontcounter*sizeof(glm::vec3),sizeof(glm::vec3),&pontok[pontcounter]);
        glBindVertexArray(0);*/

        glBindVertexArray(VAO_cp);
        glBindBuffer(GL_ARRAY_BUFFER,VBO_cp);
        glBufferSubData(GL_ARRAY_BUFFER,pontcounter*sizeof(glm::vec3),sizeof(glm::vec3),&cp_pontok[pontcounter]);
        glBindVertexArray(0);

        pontcounter++;
        drawnumberpont++;
        isupdate=true;

    }
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        glm::vec3 point = glm::vec3(0,0,0);
        point.x= 2.0/SCR_WIDTH*x-1.0;
        point.y= 2.0/SCR_HEIGHT*y-1.0;
        point.y*=-1;
        float distance=1000;
        if(pontcounter>0)
        {
            for(int i=0;i<pontcounter;i++)
            {
                if(glm::length(cp_pontok[i]-point)<distance)
                {
                    distance=glm::length(cp_pontok[i]-point);
                    selected_point=i;
                }
            }
        }
        std::cout<<selected_point<<"\n";


    }
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE){
        selected_point=-1;
    }


}


void mouse_move()
{
if(selected_point!=-1)
{
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        cp_pontok[selected_point].x= 2.0/SCR_WIDTH*x-1.0;
        cp_pontok[selected_point].y= 2.0/SCR_HEIGHT*y-1.0;
        cp_pontok[selected_point].y*=-1;


        glBindVertexArray(VAO_cp);
        glBindBuffer(GL_ARRAY_BUFFER,VBO_cp);
        glBufferSubData(GL_ARRAY_BUFFER,selected_point*sizeof(glm::vec3),sizeof(glm::vec3),&cp_pontok[selected_point]);
        glBindVertexArray(0);

        isupdate=true;

}

}
void Double_cp()
{
    if(isbezier)
    {
        int f = pontcounter*2;
        if(f>100){
            std::cout<<">100\n";
            return;
        }

        BezierCurve bez;
        for(int i=0; i<pontcounter; i++)
        {
            bez.AddControlPoint(cp_pontok[i]);
        }
        float div = 1/(float)(f-1);
        //std::cout<<div<<" div\n";
        float t=0;

        for(int i=0; i<f; i++)
        {
            cp_pontok[i]=bez.r(t);
            //std::cout<<t<<"\n";
            t+=div;

        }

        pontcounter=f;
        glBindVertexArray(VAO_cp);
        glBindBuffer(GL_ARRAY_BUFFER,VBO_cp);
        glBufferSubData(GL_ARRAY_BUFFER,0,f*sizeof(glm::vec3),&cp_pontok[0]);
        glBindVertexArray(0);

        std::cout<<"bezier duplicate\n";
        isupdate=true;
    }


if(islagrange)
{
        int f = pontcounter*2;
        if(f>100){
            std::cout<<">100\n";
            return;
        }

        LagrangeCurve lag;
        for(int i=0; i<pontcounter; i++)
        {
            lag.AddControlPoint(cp_pontok[i]);
        }
        float div = 1/(float)(f-1);
        //std::cout<<div<<" div\n";
        float t=0;

        for(int i=0; i<f; i++)
        {
            cp_pontok[i]=lag.r(t);
            //std::cout<<t<<"\n";
            t+=div;

        }

        pontcounter=f;
        glBindVertexArray(VAO_cp);
        glBindBuffer(GL_ARRAY_BUFFER,VBO_cp);
        glBufferSubData(GL_ARRAY_BUFFER,0,f*sizeof(glm::vec3),&cp_pontok[0]);
        glBindVertexArray(0);

        std::cout<<"bezier duplicate\n";
        isupdate=true;

}

}

