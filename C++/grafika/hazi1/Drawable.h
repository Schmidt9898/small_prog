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
    //protected:
    public:
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
    virtual bool is_colide_with(Drawable *obj)
    {
        bool colide_x = pos.x + scale.x >= obj->pos.x &&
        obj->pos.x + obj->scale.x >= pos.x;
        bool colide_y = pos.y + scale.y >= obj->pos.y &&
        obj->pos.y + obj->scale.y >= pos.y;

    return colide_x && colide_y;
    }
     virtual glm::vec2 box_colider(Drawable *obj) //only if coliding, only if it's a box
    {
        glm::vec2 corr_vector=pos;
        if((laststep.x+scale.x) <= obj->pos.x)
        corr_vector.x= obj->pos.x-scale.x;
        if(laststep.x>=(obj->pos.x+obj->scale.x))
        corr_vector.x=obj->pos.x+obj->scale.x;

        if((laststep.y+scale.y) <= obj->pos.y)
        corr_vector.y = (obj->pos.y-0.1);
        if(laststep.y>=(obj->pos.y+obj->scale.y))
        corr_vector.y=obj->pos.y+obj->scale.y;


        std::cout<<corr_vector.x<<" x:y "<<corr_vector.y<<"\n";

    return corr_vector;
    }

};

class Rectangle : public Drawable
{
    public:
        Rectangle(float x,float y,float w,float h,Pen* p):Drawable(p){
        pos = glm::vec2(x,y);
        scale = glm::vec2(w,h);
        };



};






#endif // DRAWABLE_H_INCLUDED
