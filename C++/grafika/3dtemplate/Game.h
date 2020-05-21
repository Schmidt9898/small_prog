#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Drawable.h"
#include <vector>
#include "inputmanagger.h"

using namespace std;

class Game
{
public :

    Drawable *floor =  nullptr;
    vector<Drawable*> boxes;
    vector<Drawable*> templates;
    Player *player=nullptr;



    Game();
    void Loop();



};


#endif // GAME_H_INCLUDED
