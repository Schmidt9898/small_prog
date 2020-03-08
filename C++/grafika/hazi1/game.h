#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include <thread>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Drawable.h"





class Game{

const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 600;

GLFWwindow* window;

//Pens
Pen* tri;
Pen* rect;

//float r = 0, g = 0, b = 0;

//float trans_x = 0, trans_y=0;
//float x=0,y=0;

//entities
Rectangle* player;


void PEN_Init()
{
tri = new Pen("triangle","files/triangle.vs","files/triangle.fs","files/triangle.txt","none");
rect = new Pen("rectangle","files/rectangle.vs","files/rectangle.fs","files/rectangle.txt","files/rectangle.ind");
}


//callbacks
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
///TODO resize callback
//sceens

int menusceen();
int playsceen();

//delta
void CalculateDelta();
//player movement
void CalculatePlayerMove();

public:
Game();//init
void loop();//loop







};


#endif // GAME_H_INCLUDED
