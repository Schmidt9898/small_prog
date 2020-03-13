#include "game.h"

float random();
//globals
double lastframe,currentframe,DELTA;
glm::vec2 player_direction;

Game::Game()
{
// glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Game", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    //load pens
    PEN_Init();
    //callbacks
    glfwSetKeyCallback(window, Game::key_callback);
    glfwSetMouseButtonCallback(window, Game::mouse_button_callback);

    srand (time(NULL));


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


int Game::playsceen()
{
    std::cout<<"gamesceen\n";
    player = new Rectangle(-0.5,0,0.1,0.1,rect);
    player->setColor(0,0.5,1);

    Walls.push_back(new Rectangle(-0.2,0,0.7,0.1,rect));
    Walls.push_back(new Rectangle(-0.4,-1,0.1,0.5,rect));
    Walls.push_back(new Rectangle(0.4,0.3,0.1,0.4,rect));
    Walls.push_back(new Rectangle(-1,0.5,0.7,0.1,rect));

    Enemies.push_back(new Ghost(-1,1,0.1,0.1,rect));
    Enemies.push_back(new Ghost(-1,-1,0.1,0.1,rect));
    Enemies.push_back(new Ghost(1,-1,0.1,0.1,rect));
    Enemies.push_back(new Ghost(1,1,0.1,0.1,rect));
    Enemies.push_back(new Ghost(-1,1,0.1,0.1,rect));
    Enemies.push_back(new Ghost(-1,-1,0.1,0.1,rect));
    Enemies.push_back(new Ghost(1,-1,0.1,0.1,rect));
    Enemies.push_back(new Ghost(1,1,0.1,0.1,rect));

    for(e:Enemies)
    {
        e->setColor(1,0.2,0.1);
    }

    for(int i=0; i<100; i++)
    {

        Rectangle* temp=new Rectangle(random(),random(),0.02,0.02,rect);
        temp->setColor(1,1,0);

        for(w:Walls)
        {
            if(temp->is_colide_with(w))
                {
                delete temp;
                temp=nullptr;
               break;
                }
        }
        if(temp!=nullptr)
        for(f:Food)
        {
            if(temp->is_colide_with(f))
                {
                delete temp;
                temp=nullptr;
               break;
                }
        }
        if(temp!=nullptr)
            Food.push_back(temp);
        //std::cout<<temp->pos.x<<" x:pppp:y "<<temp->pos.y<<"\n";

    }
    std::cout<<Food.size()<<"\n";
    /*for(f:Food)
    {
        for(w:Walls)
        {
            if(f->is_colide_with(w))
            {

            }
        }
    }
    */

    while (!glfwWindowShouldClose(window))
    {
        CalculateDelta();

        glClearColor(0, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        CalculatePlayerMove();

        //std::cout<<fal.is_colide_with(player);
        // if(player->is_colide_with(&fal))
        //   player->box_colider_correction(&fal);
        //std::cout<<player->pos.x<<" x:pppp:y "<<player->pos.y<<"\n";
        for(e:Enemies)
        {
            e->Go(DELTA,Walls,Enemies);
            if(player->is_colide_with(e))
                std::cout<<"Vesztettél\n";
            e->Draw();
        }


        for(f:Walls)
        {
            f->Draw();
            if(player->is_colide_with(f))
                player->box_colider_correction(f);
        }

        for(unsigned int i=0;i<Food.size();i++)
        {
            if(player->is_colide_with(Food[i]))
            {
                delete Food[i];
                Food[i]=Food[Food.size()-1];///HA Üres mi lesz????
                Food.pop_back();
                pont++;
                cout<<pont<<"\n";
                i--;
            }else
            {
                Food[i]->Draw();
            }
        }
        for(f:Food)
        {
            f->Draw();
        }

        player->Draw();

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
    if(DELTA>0.1)
        DELTA=0;

}

void Game::CalculatePlayerMove()
{

    glm::vec2 norm = glm::normalize(player_direction);
    if(norm!=norm)
        norm=glm::vec2(0.0,0.0);
    player->laststep=player->pos;
    if(DELTA<0.1)
        player->pos+= glm::vec2(norm.x*DELTA,norm.y*DELTA);

    if(player->pos.x<=-1)
        player->pos.x=-1;
    if(player->pos.y<=-1)
        player->pos.y=-1;

    if(player->pos.x+player->scale.x>=1)
        player->pos.x=1-player->scale.x;
    if(player->pos.y+player->scale.y>=1)
        player->pos.y=1-player->scale.y;

    //std::cout<<DELTA<<"\n";
}
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void Game::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0.5, 0, 600, 600);
}

void Game::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    //zeroing direction
    player_direction = glm::vec2(0.0,0.0);
    //geting direction

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS )
    {
        player_direction = player_direction+glm::vec2(0,1);
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        player_direction = player_direction+glm::vec2(-1,0);
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        player_direction = player_direction+glm::vec2(0,-1);
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        player_direction = player_direction+glm::vec2(1,0);
    }
}

void Game::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        //getting cursor position
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout << "Cursor Position at (" << xpos << " : " << ypos << "\n";
    }
}
float random()
{
    return (float)(2.0/60.0)*(rand()%60)-1.0;
}

