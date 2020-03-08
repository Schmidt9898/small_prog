#include "game.h"

//globals

double lastframe,currentframe,DELTA;

Game::Game(){
// glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

     // glfw window creation
    // --------------------
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Game", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    //load pens
    PEN_Init();
    //callbacks
    glfwSetKeyCallback(window, Game::key_callback);
    glfwSetMouseButtonCallback(window, Game::mouse_button_callback);


}

void Game::loop()
{
    lastframe = glfwGetTime();
    int sceen = 2;
        while(!glfwWindowShouldClose(window) || sceen==-1)
        {
            switch(sceen)
            {
            case 1:
                sceen=menusceen();
                break;
            case 2:
                sceen=playsceen();
                break;
            default :
                break;
            }
        }
    glfwTerminate();
}


int Game::playsceen(){
std::cout<<"gamesceen\n";
Rectangle fal(0,0,1,0.1,rect);
while (!glfwWindowShouldClose(window)) {
        CalculateDelta();

        glClearColor(0, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        //glUseProgram(shaderProgram);
//        ourshader.use();
  //      glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
  /*      double t=glfwGetTime();
        double r = (sin(t) /2.0 + 0.5);
        double g = (sin(t/2) /2.0 + 0.5);
        double b = (sin(t/4) /2.0 + 0.5);*/
    //    ourshader.setVec3("unicolor",r,g,b);
       // glUniform4f(unicolorlocation,r,g,b,1);



          glm::mat4 trans = glm::mat4(1.0f);

        trans = glm::translate(trans,glm::vec3(0.5,0,0.0));
        trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0,0,1));
        trans = glm::scale(trans,glm::vec3(0.1,0.1,0.0));
        //trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0,0,1));
        fal.Draw();

        trans = glm::mat4(1.0f);
        trans = glm::translate(trans,glm::vec3(-0.5,0.0,0.0));
        trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0,0,1));
        trans = glm::scale(trans,glm::vec3(0.1,0.1,0.0));
        //pen2.Draw(trans,glm::vec3(r,g,b));


        glfwSwapBuffers(window);
        glfwPollEvents();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    return -1;


}


int Game::menusceen()
{
    std::cout<<"menusceen\n";
    return 2;
};


void Game::CalculateDelta()
{
    currentframe = glfwGetTime();
    DELTA = currentframe - lastframe;
    lastframe = currentframe;
}






















// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void Game::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void Game::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {

    }
    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {

    }
    if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {

    }
     if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {

    }
     if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {

    }
     if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {

    }
     if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {

    }
}

void Game::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        //getting cursor position
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout << "Cursor Position at (" << xpos << " : " << ypos << "\n";
    }
}


