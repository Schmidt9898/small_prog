#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

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
#include "Line.h"
#include "inputmanagger.h"
#include "Pen.h"
#include "Drawable.h"

class Game;

/// globál változók a triviális dolgokat nem kommentelem
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

Game * mygame=nullptr;
GLFWwindow* window=nullptr;
InputManagger inputmanagger;//a header file ban leírom
unsigned int SCR_WIDTH = 800;
unsigned int SCR_HEIGHT = 600;

double lastframe,currentframe,DeltaTime;//Delta számításhoz








//csak 1 lehet;
class Game
{


    float font=10;


///sceen control
    bool Notclose=true;
    int sceen=0;//menu
//Pens
    Pen *rect = nullptr;
    Pen *player_pen=nullptr;

//Buttons

    Rectangle *btn_line_editor = nullptr;//new Rectangle(0,0.25,0.5,0.25,rect);
    Rectangle *btn_game = nullptr;//new Rectangle(0,0.25,0.5,0.25,rect);
//Rectangle *btn_start = nullptr;
    bool btn_start=false;

//lines vonalak
    Line * selected_line=nullptr;
    Line * line = nullptr;
    Line * linelag = nullptr;
    Line * linebez = nullptr;
//a játékos
    Drawable *player = nullptr;
    glm::vec2 velociti;
    bool grounded=false;
//ágyugolyók lövedékek
    Drawable *cross = nullptr;
    vector<Canonball> Canonballs;


public :
    Game()
    {

        // glfw: initialize and configure
        // ------------------------------
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // glfw window creation
        // --------------------
        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL_gyak_4", nullptr, nullptr);
        if (window == nullptr)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            //return -1;
        }

        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        // glad: load all OpenGL function pointers
        // ---------------------------------------
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            //return -1;
        }

        //init pens
        rect = new Pen("rectangle","files/rectangle.vs","files/rectangle.fs","files/rectangle.txt","files/rectangle.ind");
        player_pen = new Pen("player","files/player.vs","files/player.fs","files/player.txt","files/player.ind");
        //init buttons
        btn_line_editor = new Rectangle(0,-0.25,0.5,0.25,rect);
        btn_game = new Rectangle(0,0.25,0.5,0.25,rect);
        //btn_start = new Rectangle(0.5,0.75,0.2,0.2,rect);







        glfwSetKeyCallback(window, key_callback);
        glfwSetMouseButtonCallback(window, mouse_button_callback);
//return 1;
        // mygame=this;

    }


    int main_loop()
    {



        while (!glfwWindowShouldClose(window) && sceen!=-1)
        {
//sceen selecter

            switch(sceen)
            {
            case 0://menu
                Menu();
                break;
            case 1:
                Editor();
                break;
            case 2://játék
                Gameplay();
                break;

            }
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        glfwTerminate();
        return 0;
    }

private:
    void Menu()
    {

//int action_code = -1;
///gombok definiálása
        inputmanagger.esc.SingleAction=[]()
        {
            mygame->sceen=-1;
        };
        inputmanagger.btn_mouseleft.SingleAction=[]()
        {
            if(mygame->sceen==0)
            {
                if(mygame->btn_line_editor->contain_point(inputmanagger.mouse_position))
                    mygame->sceen=1;
                else if(mygame->btn_game->contain_point(inputmanagger.mouse_position))
                    mygame->sceen=2;
            }
        };
        inputmanagger.Mouse_Hover=[]()
        {
            if(mygame->sceen==0)
            {
                if(mygame->btn_line_editor->contain_point(inputmanagger.mouse_position))
                    mygame->btn_line_editor->color=glm::vec3(1,0.01,0.01);
                else
                    mygame->btn_line_editor->color=glm::vec3(1,0.6,0.6);
                if(mygame->btn_game->contain_point(inputmanagger.mouse_position))
                    mygame->btn_game->color=glm::vec3(1,1,0);
                else
                    mygame->btn_game->color=glm::vec3(1,1,0.6);
            }
        };


        while(sceen==0)
        {
            glClearColor(0, 0, 0, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            btn_game->Draw();
            btn_line_editor->Draw();
            glfwSwapBuffers(window);
            glfwPollEvents();

            inputmanagger.update_continius(window,SCR_WIDTH,SCR_HEIGHT);

            std::this_thread::sleep_for(std::chrono::milliseconds(20));

        }
    }

    void Editor()
    {
        line = new Line();
        linelag = new Line();
        linebez = new Line();


        selected_line = line;
        //line->color=glm::vec3(0,0,0);
        //line->point_color=glm::vec3(0,0,0);

        inputmanagger.btn_f.SingleAction=[]()
        {
            mygame->line->Subdivide();
            std::cout<<"subdivided\n";
        };
        inputmanagger.btn_c.SingleAction=[]()
        {
            mygame->line->Clear();
            mygame->linelag->Clear();
            mygame->linebez->Clear();
            std::cout<<"cleared\n";
        };
        //inputmanagger.btn_c.Action=[](){std::cout<<"c\n";};
        inputmanagger.btn_mouseleft.SingleAction=[]()
        {
            mygame->line->add_point(glm::vec3(inputmanagger.mouse_position,0));
            mygame->line->color=glm::vec3(1,1,1);
        };

        inputmanagger.btn_q.SingleAction=[]()
        {
            LagrangeCurve lag;
            int f=1000;
            for(int i=0; i<mygame->line->getsize(); i++)
            {
                lag.AddControlPoint(mygame->line->cp[i]);
            }
            float div = 1/(float)(f-1);
            //std::cout<<div<<" div\n";
            float t=0;

            mygame->linelag->Clear();
            for(int i=0; i<f; i++)
            {
                mygame->linelag->add_point_f(lag.r(t));
                t+=div;

            }
            mygame->linelag->refresh();
            mygame->linelag->color=glm::vec3(0,1,0);
            mygame->linelag->font=0;
            mygame->line->color=glm::vec3(0,0,0);
        };

        inputmanagger.btn_e.SingleAction=[]()
        {
            BezierCurve bez;
            int f=1000;
            for(int i=0; i<mygame->line->getsize(); i++)
            {
                bez.AddControlPoint(mygame->line->cp[i]);
            }
            float div = 1/(float)(f-1);
            //std::cout<<div<<" div\n";
            float t=0;

            mygame->linebez->Clear();
            for(int i=0; i<f; i++)
            {
                mygame->linebez->add_point_f(bez.r(t));
                t+=div;

            }
            mygame->linebez->refresh();
            mygame->linebez->font=0;
            mygame->linebez->color=glm::vec3(0,0,1);
            mygame->line->color=glm::vec3(0,0,0);
        };

        inputmanagger.esc.SingleAction=[]()
        {
            mygame->sceen=0;
        };



        while(sceen==1)
        {
            glClearColor(0, 0, 0, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            line->Draw();
            linelag->Draw();
            linebez->Draw();
            glfwSwapBuffers(window);
            glfwPollEvents();

            inputmanagger.update_continius(window,SCR_WIDTH,SCR_HEIGHT);

            std::this_thread::sleep_for(std::chrono::milliseconds(20));

        }
        delete line;
        delete linelag;
        delete linebez;



    }
    void Gameplay()
    {
        line = new Line();
        btn_start=false;
        velociti=glm::vec2(0,0);


        line->color=glm::vec3(1,1,1);
        inputmanagger.btn_f.SingleAction=[]()
        {
            mygame->line->Subdivide();
            std::cout<<"subdivided\n";
        };
        inputmanagger.btn_c.SingleAction=[]()
        {
            mygame->line->Clear();
            std::cout<<"cleared\n";
        };
        ///std place holder
        inputmanagger.btn_mouseleft.SingleAction=[]()
        {
            mygame->line->add_point(glm::vec3(inputmanagger.mouse_position,0));
        };
        inputmanagger.enter.SingleAction=[]()
        {
            mygame->btn_start=true;
        };

        inputmanagger.esc.SingleAction=[]()
        {
            mygame->sceen=0;
        };


        while(sceen==2 && !btn_start)
        {
            glClearColor(0, 0, 0, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            line->Draw();

            glfwSwapBuffers(window);
            glfwPollEvents();

            inputmanagger.update_continius(window,SCR_WIDTH,SCR_HEIGHT);

            std::this_thread::sleep_for(std::chrono::milliseconds(20));

        }

        inputmanagger.btn_f.SingleAction=nullptr;
        inputmanagger.btn_c.SingleAction=nullptr;
        inputmanagger.btn_mouseleft.SingleAction=nullptr;



        Line* newline= new Line();


        glm::vec3 temp_1=glm::vec3(-1,0,0);
        glm::vec3 temp_last=glm::vec3(1,0,0);

        if(line->getsize()>0)
        {

            temp_1.x=-1;//bal oldal
            temp_1.y=line->cp[0].y;

            temp_last.x=1;//jobb oldal
            temp_last.y = line->cp[line->getsize()-1].y;
        }
        newline->Clear();
        newline->add_point_f(glm::vec3(-1,-1,0));
        newline->add_point_f(temp_1);
        for(int i=0; i<line->getsize(); i++)
        {
            newline->add_point_f(line->cp[i]);
        }
        newline->add_point_f(temp_last);
        newline->add_point_f(glm::vec3(1,-1,0));
        newline->refresh();
        delete line;
        line=newline;
        line->font=1;

        player = new Rectangle(0,1,0.1,0.1,player_pen);
        player->setColor(1,0.5,0);
        player->laststep=player->pos;


        cross = new Rectangle(0,0,0.01,0.01,rect);
        cross->setColor(1,0,0);

        inputmanagger.a_left.Action=[]()
        {
            if(mygame->grounded)
                mygame->velociti.x=-0.2;
            else
                mygame->velociti.x=-0.5;
        };
        inputmanagger.d_right.Action=[]()
        {
            if(mygame->grounded)
                mygame->velociti.x=0.2;
            else
                mygame->velociti.x=0.5;
        };
        inputmanagger.space.SingleAction=[]()
        {
            if(mygame->grounded)
            {
                mygame->velociti.y=1.5;
                mygame->grounded=false;
            }
            std::cout<<"ugras";
        };

        inputmanagger.btn_mouseleft.SingleAction=[]()
        {
            glm::vec2 dir= mygame->cross->pos - mygame->player->pos;
            Canonball temp(mygame->player->pos.x,mygame->player->pos.y,dir,mygame->rect);
            mygame->Canonballs.push_back(temp);

        };


        while(sceen==2)
        {

            currentframe = glfwGetTime();
            DeltaTime = currentframe - lastframe;
            lastframe = currentframe;
            if(DeltaTime>0.1)//ha delta nagyobb mint 0.1 akkor feltételezhető hogy nem volt aktív az ablak ilyenkor nem mozoghatunk
                DeltaTime=0;

            inputmanagger.update_continius(window,SCR_WIDTH,SCR_HEIGHT);
            cross->pos=inputmanagger.mouse_position;


            player_move();
            canonball_go();


            glClearColor(0, 0, 0, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            //std::cout<<player->pos.y;
            player->Draw();
            for(int i=0; i<Canonballs.size(); i++)
            {
                Canonballs[i].Draw();
            }
            line->Draw();
            cross->Draw();

            glfwSwapBuffers(window);
            glfwPollEvents();



            velociti.x=0;


            std::this_thread::sleep_for(std::chrono::milliseconds(20));

        }
        delete player;
        delete line;
        delete cross;
    }
    void player_move()
    {
        player->pos.y-=0.98*DeltaTime;
        velociti.y-=0.98*DeltaTime;
        if(velociti.y<0)
            velociti.y=0;

        for(int i=1; i<line->getsize()-1; i++)
        {
            if(player->doIntersect(line->cp[i],line->cp[i+1]))
            {
                player->pos=player->laststep;
                //std::cout<<"most kell";
                //player->set_to_edge(line->cp[i],line->cp[i+1]);
                //player->pos.y+=0.01;
                grounded = true;
                break;
            }

        }
        ///a gravitáció és a player mozgást szét kellett szedni mert nem tudnánk mozogni.
        player->pos+=velociti * (float)DeltaTime;



        /*    if(player->doIntersect(line->cp[1],line->cp[2]))
                {
                    player->pos=player->laststep;
                    std::cout<<"most igaz\n";
                    //player->set_to_edge(line->cp[i],line->cp[i+1]);

                }*/

        for(int i=1; i<line->getsize()-1; i++)
        {
            if(player->doIntersect(line->cp[i],line->cp[i+1]))
            {
                player->pos=player->laststep;
                //std::cout<<"most kell";
                //player->set_to_edge(line->cp[i],line->cp[i+1]);
                //player->pos.y+=0.01;
                grounded = true;
                break;
            }
        }

        player->laststep=player->pos;
    }

    void canonball_go()
    {
        for(int i=0; i<Canonballs.size(); i++)
        {
            Canonballs[i].velociti.y+=-0.98*(float)DeltaTime;
            Canonballs[i].pos+=Canonballs[i].velociti*(float)DeltaTime;

        }
        for(int i=0; i<Canonballs.size(); i++)
        {
            bool isdelet = false;

            for(int j=1; j<line->getsize()-1; j++)
            {
                if(Canonballs[i].doIntersect(line->cp[j],line->cp[j+1]))
                {
                    for(int k=1; k<line->getsize()-1; k++)
                    {
                        if(glm::distance(glm::vec3(Canonballs[i].pos,0),line->cp[k])<0.1f)
                        {///Valamiért nem körkörösen változik de nem tudom miért
                            glm::vec3 temp = glm::normalize(line->cp[k] - glm::vec3(Canonballs[i].pos,0)+ 1.0f/2.0f*glm::vec3(Canonballs[i].velociti,0))*0.01f;
                            temp.y= (temp.y>0)? temp.y*-1 : temp.y;
                            line->cp[k] += temp;
                        }
                    }
                    isdelet=true;
                }

            }

            if(isdelet)
            {
                Canonballs[i]=Canonballs[Canonballs.size()-1];
                Canonballs.pop_back();
                i--;
                line->refresh();
            }

        }





    }

};










/*
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
*/

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    SCR_WIDTH=width;
    SCR_HEIGHT=height;
    glViewport(0, 0, width, height);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    inputmanagger.update_keys(key,action);
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    inputmanagger.update_mouse(button,action);
}



#endif // GAME_H_INCLUDED
