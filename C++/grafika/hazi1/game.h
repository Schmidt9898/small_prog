#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include <thread>
#include  <mutex>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Drawable.h"
#include <time.h>
#include "Bubi_Sound.h"



class Game{

Bubi_Sound atmos; // Saj�t hang k�nyvt�r halad� c++ projektb�l
//M�r nem eml�kszem hogy m�k�dik.
//float screenscale=1;

GLFWwindow* window; // az ablak

//Pens // toll gy�jtem�ny
Pen* tri;
Pen* rect;
Pen* playerpen;

//float r = 0, g = 0, b = 0;

//float trans_x = 0, trans_y=0;
//float x=0,y=0;

//entities
//t�bb helyen is kell ez�rt nem lehet localis
Rectangle* player=nullptr;
Rectangle* exit=nullptr;
int pont=0;

vector<Ghost*> Enemies;//szellemek
vector<Rectangle*> Walls;//falak
vector<Rectangle*> Food;//felvehet� pontok
//vector<Drawable*>
///scripting
/*
egyszer� scriptel�s k�l�n sz�lon, sz�lbiztos
*/
std::thread *script=nullptr;
std::mutex monitor;


void PEN_Init()//tollak bet�lt�se a mem�ri�ba �s a vide�k�rty�ra
{
tri = new Pen("triangle","files/triangle.vs","files/triangle.fs","files/triangle.txt","none");
rect = new Pen("rectangle","files/rectangle.vs","files/rectangle.fs","files/rectangle.txt","files/rectangle.ind");
playerpen = new Pen("player","files/player.vs","files/player.fs","files/player.txt","files/player.ind");
}


//callbacks az �rai
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
///TODO resize callback
//sceens

int menusceen();//1
int playsceen();//2
int editorsceen();//3
//int load1();//nem haszn�ltam

//delta
void CalculateDelta(); // legut�bbi k�pkocka ut�n eltelt id�
//player movement
void CalculatePlayerMove(); // player mozg�s sz�m�t�sa lenyomott billenty�kb�l
//




void scriptfv();//script f�ggv�ny

public:
Game();//init
void loop();//loop
int gameid=0;//ahoz hogy a scripp ne befoly�solja az �j j�t�kot ha meghalunk �s m�g a script �lne
int levelid=1;// szintl�p�shez 7 szint van a j�t�kban


const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 600;




};


#endif // GAME_H_INCLUDED
