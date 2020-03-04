#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


using namespace std;


static void key_callback(GLFWwindow* window,int key,int scancode,int action,int mods);
float r=0.0,g=0.0,b=0.0;

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

        while(!glfwWindowShouldClose(window))
        {
            ///rendering
            glClearColor(r,g,b,1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            ///swap
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

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
