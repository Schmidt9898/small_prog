#include "Game.h"
#include <iostream>
//#include "Pen.h"

#include <thread>
#include "Camera.h"
#include "inputmanagger.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
float currentFrame,deltaTime,lastFrame;

//bool firstMouse = true; // csak lekezeljuk az eslo eger mozgatast
//float pitch =  0.0f;
//float lastX =  800.0f / 2.0;  // kezdeti eger pozicio
//float lastY =  600.0 / 2.0;   // kezdeti eger pozicio
bool toogle_menu=false;
float fov   =  45.0f;

GLFWwindow* window=nullptr;
unsigned int screen_W=1240,screen_H=720;
glm::mat4 projection = glm::mat4(1.0f);

InputManagger inputmanagger;

Movement player_movement;

int selected_templates_id=0;
int selected_templates_size=0;
///pens
Pen *cube;

///materials
Material *mat_floor;
Material *mat_sky;
Material *mat_wood;
Material *mat_stone;
Material *mat_brick;
Material *mat_grass;
///components
Camera* MainCamera=nullptr;

Drawable *sky = nullptr;
Drawable* cross=nullptr;




Game::Game()
{

    //std::cout<<"init game object\n";
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,0);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_TRUE);


    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    window = glfwCreateWindow(screen_W,screen_H,"Application",nullptr,nullptr);
    if(window==nullptr)
    {

        //std::cout<<"upsz window terminated";
        glfwTerminate();
        throw -1;
        //return -1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        //std::cout<<"upsz coud not load, terminated";
        throw -1;
        //return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    glEnable(GL_DEPTH_TEST);
///pens
cube = new Pen("cube","files/cube.txt","files/cube.fs","files/cube.vs");
///materials
mat_floor = new Material("textures/meter.jpg");
mat_floor->tiling=100;
mat_sky = new Material("textures/sky.jpg");
mat_wood = new Material("textures/wood.jpg");
mat_stone = new Material("textures/stone.jpg");
mat_brick = new Material("textures/brick.jpg");
mat_grass = new Material("textures/grass.jpg");


mat_brick->tiling=0.2;
mat_stone->tiling=0.2;
mat_grass->tiling=0.5;
///components
MainCamera=new Camera(glm::vec3(0,1,0));
floor = Make_Drawable(cube,0,-0.05,0,100,0.1,100);
floor->myMaterial=mat_floor;
sky = Make_Drawable(cube,0,0,0,100,100,100);
sky->myMaterial=mat_sky;

player=new Player(cube,0,1,0,0.5,1,0.5);
player->myMaterial=mat_stone;
player->myCamera=MainCamera;


Drawable * temp = Make_Drawable(cube,0,1,1,0.1,0.1,0.1);
temp->myMaterial=mat_wood;
templates.push_back(temp);

temp = Make_Drawable(cube,0,1,1,0.1,0.1,0.1);
temp->myMaterial=mat_stone;
templates.push_back(temp);

temp = Make_Drawable(cube,0,1,1,0.1,0.1,0.1);
temp->myMaterial=mat_brick;
templates.push_back(temp);

temp = Make_Drawable(cube,0,1,1,0.1,0.1,0.1);
temp->myMaterial=mat_grass;
templates.push_back(temp);

selected_templates_size=templates.size();

//boxes.push_back(temp);
cross = Make_Drawable(cube,0,0,0,0.03,0.03,0.03);
cross->myMaterial=mat_stone;






/// inputs do
    inputmanagger.Mouse_Hover=[]{
    MainCamera->Yaw += inputmanagger.Yaw*0.1f;
    MainCamera->Pitch += inputmanagger.Pitch*0.1f;
            ///clamp
            if (MainCamera->Pitch > 50.0f)
                MainCamera->Pitch = 50.0f;
            if (MainCamera->Pitch < -50.0f)
                MainCamera->Pitch = -50.0f;
    MainCamera->updateCameraVectors();
    };

    inputmanagger.w_up.Action=[]{player_movement.forward_=1;};
    inputmanagger.s_down.Action=[]{player_movement.forward_=-1;};
    inputmanagger.a_left.Action=[]{player_movement.right_=-1;};
    inputmanagger.d_right.Action=[]{player_movement.right_=1;};
    inputmanagger.shift.Action=[]{player_movement.speed=4;};
    inputmanagger.space.SingleAction=[]{if(player_movement.jump<=0) player_movement.jump=10;};

    inputmanagger.btn_mouseleft.SingleAction=[this]{
        glm::vec3 offset = glm::normalize(MainCamera->Front);
        offset+=MainCamera->Position;
        Drawable* temp=templates[selected_templates_id]->Clone();
        temp->pos=offset;
        temp->laststep=temp->pos;temp->laststep.y+=100;
        temp->scale=glm::vec3(0.5,0.5,0.5);
    boxes.push_back(temp);
    std::cout<<"kesz\n";


    };
    inputmanagger.btn_mouseright.SingleAction=[this]{
        glm::vec3 point = MainCamera->Front;
        point+=MainCamera->Position;

        for(size_t i=0;i<boxes.size();i++)
        {
            if(boxes[i]->Contain_point(point))
               {
                   boxes[i]=boxes[boxes.size()-1];
                   boxes.pop_back();
               }

        }
    };



}

void Game::Loop()
{

projection = glm::perspective(glm::radians(70.0f), (float)screen_W / (float)screen_H, 0.1f, 100.0f);

//    myplayer.body = Make_Drawable(p,0,0,0,1,2,1);
  //  myplayer.myCamera = MainCamera;


    /**
        -input
        -skybox
        -objects drawing
        -jump
        -materials
        -collisions
        -gravity
        -raycast
        -placing
        -cloning
    */










    lastFrame = glfwGetTime();

    while(!glfwWindowShouldClose(window))
    {
        ///delta
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        if(deltaTime>0.1)
            deltaTime=0;
        ///player_moves
        player->UpDate(player_movement,deltaTime);
        player_movement.clear();
        ///everithing moves
        for(size_t i=0;i<boxes.size();i++)
        {
            boxes[i]->UpDate(deltaTime);
        }

        ///collide
        //player with enviroment
        for(size_t i=0;i<boxes.size();i++)
        {
            if(player->is_colide_with_box(boxes[i]))
                player->box_colider_correction(boxes[i]);
        }
        if(player->is_colide_with_box(floor))
                player->box_colider_correction(floor);
        //boxes with eachother
        for(size_t i=0;i<boxes.size();i++)
        {
            for(size_t j=0;j<boxes.size();j++)
            {
                if(i!=j && boxes[i]->is_colide_with_box(boxes[j]))
                    boxes[i]->box_colider_correction(boxes[j]);
            }
            //with the floor
            if(boxes[i]->is_colide_with_box(floor))
                boxes[i]->box_colider_correction(floor);
        }
        ///correction
        for(size_t i=0;i<boxes.size();i++)
        {
            if(player->is_colide_with_box(boxes[i]))
                player->box_colider_correction(boxes[i]);
        }





        ///save_positions
        player->save_position();
        for(size_t i=0;i<boxes.size();i++)
        {
            boxes[i]->save_position();
        }

        templates[selected_templates_id]->pos=(player->pos+glm::vec3(0,0.3,0)+MainCamera->Right*0.1f+MainCamera->Front*0.5f);
        cross->pos=MainCamera->Position+MainCamera->Front;
        ///rendering
        glClearColor(0,0,0,1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glm::mat4 view = MainCamera->GetViewMatrix();



        cube->update_view(view);
        cube->update_projection(projection);

        templates[selected_templates_id]->Draw();

        sky->Draw();
        floor->Draw();
        cross->Draw();
        //player->Draw();
        for(size_t i = 0;i<boxes.size();i++)
        {
            boxes[i]->Draw();
        }





        ///swap
        glfwSwapBuffers(window);
        ///input
        glfwPollEvents();
        ///input continous
        inputmanagger.update_continius(window,screen_W,screen_H);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    glfwTerminate();
}






void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    screen_W=width,screen_H=height;
    projection = glm::perspective(glm::radians(70.0f), (float)screen_W / (float)screen_H, 0.1f, 100.0f);
    glViewport(0, 0, width, height);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

        inputmanagger.update_keys(key,action);

}

// FPS like kamera mozgas
// 1) Calculate the mouse's offset since the last frame.
// 2) Add the offset values to the camera's yaw and pitch values.
// 3) Add some constraints to the maximum/minimum pitch values
// 4) Calculate the direction vector

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {


        inputmanagger.update_mouse(button,action);

}


void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{

   /* if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    MainCamera->Yaw += xoffset*0.1f;
    MainCamera->Pitch += yoffset*0.1f;

            if (MainCamera->Pitch > 89.0f)
                MainCamera->Pitch = 89.0f;
            if (MainCamera->Pitch < -89.0f)
                MainCamera->Pitch = -89.0f;
    MainCamera->updateCameraVectors();*/
}

// zooming
// amikor a fov kisebb lesz akkor a projektalt space is kisebb lesz ami olyan hatast kelt mintha zoom olnank
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
   // camera.ProcessMouseScroll(yoffset);
   if(yoffset>0)
   {
       selected_templates_id++;
       if(selected_templates_id>=selected_templates_size)
            selected_templates_id=0;
   }else if(yoffset<0)
   {
       selected_templates_id--;
       if(selected_templates_id<0)
            selected_templates_id=selected_templates_size-1;

   }
   std::cout<<selected_templates_id<<"\n";

}
