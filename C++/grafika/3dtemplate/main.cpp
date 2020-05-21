#include <iostream>
#include "Game.h"

using namespace std;


static void key_callback(GLFWwindow* window,int key,int scancode,int action,int mods);

//GLFWwindow* window=nullptr;



int main()
{
    cout << "Start!" << endl;
    Game mygame;
    mygame.Loop();
    cout << "End!" << endl;
    return 0;
}




static void key_callback(GLFWwindow* window,int key,int scancode,int action,int mods)
{

}
