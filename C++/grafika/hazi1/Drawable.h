#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Pen.h"

using namespace std;
//PenFactory _penfactory;



//struct p16fgu {p16fgu(){PEN_Init();};};p16fgu _p16fgu;

class Drawable
{
    protected:
    Pen *mypen=nullptr;
    glm::vec2 laststep = glm::vec2(0.0,0.0);
    glm::vec2 pos = glm::vec2(0.0f,0.0f);
    glm::vec2 scale = glm::vec2(0.0,0.0);
    float rotation=0;

public:
    virtual ~Drawable() {};
    Drawable(Pen * p):mypen(p){};
    virtual void Draw()
    {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans,glm::vec3(pos,0.0));
        trans = glm::rotate(trans,rotation,glm::vec3(0,0,1));
        trans = glm::scale(trans,glm::vec3(scale,0.0));
        mypen->Draw(trans,glm::vec3(1,1,1));
    }
    virtual void is_colide_with(Drawable obj)
    {
//        bool colide_x = pos

    }

};

class Rectangle : public Drawable
{
    public:
        Rectangle(float x,float y,float w,float h,Pen* p):Drawable(p){
        pos = glm::vec2(x,y);
        scale = glm::vec2(w,h);
        };
       /* void Draw()
    {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans,glm::vec3(x,y,0.0));
        trans = glm::rotate(trans,rotation,glm::vec3(0,0,1));
        trans = glm::scale(trans,glm::vec3(width,hight,0.0));
        mypen->Draw(trans,glm::vec3(1,1,1));
    }*/


};






#endif // DRAWABLE_H_INCLUDED
