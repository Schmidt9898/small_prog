#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


using namespace std;


static void key_callback(GLFWwindow* window,int key,int scancode,int action,int mods);
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) ;
float r=0.0,g=0.0,b=0.0;
const unsigned int with=400,hight=300;

const char* vertexShaderSource =
"#version 400 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
"}\n\0";

const char* fragmentshadersource =
"#version 400 core\n"
"out vec4 fragcolor;\n"
"void main()\n"
"{\n"
"fragcolor = vec4(0.0,0.0,1.0,1.0);\n"
"}\n\0";


int main()
{
    cout << "Hello world!" << endl;

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,0);
        glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE,GL_TRUE);


        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
        GLFWwindow* window = glfwCreateWindow(400,300,"ablak",nullptr,nullptr);
        if(window==nullptr)
        {

            cout<<"upsz";
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            cout<<"upsz glad";
            return -1;
        }

        glfwSetKeyCallback(window,key_callback);
        glfwSetMouseButtonCallback(window, mouse_button_callback);




        //vertex shader
        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader,1,&vertexShaderSource,nullptr);

        glCompileShader(vertexShader);

        char infolog[512];
        int succes;
        glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&succes);
        if(!succes)
        {
            glGetShaderInfoLog(vertexShader,512,nullptr,infolog);
            cout<<"shader hiba"<<endl;
            cout<<infolog<<endl;

        }
        //fragment shader

        int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader,1,&fragmentshadersource,nullptr);

        glCompileShader(fragmentShader);


        glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&succes);
        if(!succes)
        {
            glGetShaderInfoLog(fragmentShader,512,nullptr,infolog);
            cout<<"fragment hiba"<<endl;
            cout<<infolog<<endl;

        }

        //shaderprogram
        unsigned int shaderProgram= glCreateProgram();
        glAttachShader(shaderProgram,vertexShader);
        glAttachShader(shaderProgram,fragmentShader);

        glLinkProgram(shaderProgram);
        glGetProgramiv(shaderProgram,GL_LINK_STATUS,&succes);

         if(!succes)
        {
            glGetProgramInfoLog(shaderProgram,512,nullptr,infolog);
            cout<<"program hiba"<<endl;
            cout<<infolog<<endl;

        }
        //nem kell, ezért törlés
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);



        float vertices[]={0.5,0.5,0.0,
                            0.5,-0.5,0.0,
                            -0.5, -0.5,0.0,
                            -0.5, 0.5,0.0};

        unsigned int indeces[] = {0,1,3};

        unsigned int VBO,VAO,EBO;

        glGenVertexArrays(1,&VAO);
        glGenBuffers(1,&EBO);
        glGenBuffers(1,&VBO);///létrehoz
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);///összeköt? csak 1 lehet egyszerre

        glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);///átmásol elküld

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);///összeköt? csak 1 lehet egyszerre

        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indeces),indeces,GL_STATIC_DRAW);///átmásol elküld




         //pointerezés
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);

        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER,0);

        glBindVertexArray(0);


 glDeleteBuffers(1,&VBO);
        glDeleteBuffers(1,&EBO);



        while(!glfwWindowShouldClose(window))
        {
            ///rendering
            glClearColor(r,g,b,1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            //glDrawArrays(GL_TRIANGLES,0,3);
            glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);


            ///swap
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glDeleteVertexArrays(1,&VAO);


        glfwTerminate();


    return 0;
}




static void key_callback(GLFWwindow* window,int key,int scancode,int action,int mods)
{
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
    {

        glfwSetWindowShouldClose(window,true);

    }


    if(glfwGetKey(window,GLFW_KEY_A)==GLFW_PRESS)
    {

        r=1.0;

    }
    if(glfwGetKey(window,GLFW_KEY_S)==GLFW_PRESS)
    {

        g=1.0;

    }
    if(glfwGetKey(window,GLFW_KEY_D)==GLFW_PRESS)
    {

        b=1.0;

    }
      if(glfwGetKey(window,GLFW_KEY_W)==GLFW_PRESS)
    {

        r=g=b=0.0;

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

static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}




