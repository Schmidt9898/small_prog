#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Pen.h"
#include <time.h>

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
    glm::vec3 color=glm::vec3(1,1,1);

    virtual ~Drawable() {};
    Drawable(Pen * p):mypen(p) {};
    virtual void Draw()
    {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans,glm::vec3(pos,0.0));
        trans = glm::rotate(trans,rotation,glm::vec3(0,0,1));
        trans = glm::scale(trans,glm::vec3(scale,0.0));
        mypen->Draw(trans,color);
    }
    virtual bool is_colide_with(Drawable *obj)
    {
        bool colide_x = pos.x + scale.x >= obj->pos.x &&
                        obj->pos.x + obj->scale.x >= pos.x;
        bool colide_y = pos.y + scale.y >= obj->pos.y &&
                        obj->pos.y + obj->scale.y >= pos.y;

        return colide_x && colide_y;
    }
    virtual glm::vec2 box_colider_correction(Drawable *obj) //only if coliding, only if it's a box
    {
        glm::vec2 corr_vector=pos;
        if((laststep.x+scale.x) <= obj->pos.x)
            corr_vector.x= obj->pos.x-scale.x-0.000001;
        if(laststep.x>=(obj->pos.x+obj->scale.x))
            corr_vector.x=obj->pos.x+obj->scale.x+0.000001;

        if((laststep.y+scale.y) <= obj->pos.y)
            corr_vector.y= obj->pos.y-scale.y-0.000001;
        if(laststep.y>=(obj->pos.y+obj->scale.y))
            corr_vector.y=obj->pos.y+obj->scale.y+0.000001;


       // std::cout<<corr_vector.x<<" x:y "<<corr_vector.y<<"\n";
        pos=corr_vector;
        return corr_vector;
    }
    /*
     virtual glm::vec2 box_colider(Drawable *obj) //only if coliding, only if it's a box
    {
        glm::vec2 corr_vector=pos;
        if((laststep.x+scale.x) <= obj->pos.x)
        corr_vector.x= obj->pos.x-scale.x-0.000001;
        if(laststep.x>=(obj->pos.x+obj->scale.x))
        corr_vector.x=obj->pos.x+obj->scale.x+0.000001;

        if((laststep.y+scale.y) <= obj->pos.y)
        corr_vector.y= obj->pos.y-scale.y-0.000001;
        if(laststep.y>=(obj->pos.y+obj->scale.y))
        corr_vector.y=obj->pos.y+obj->scale.y+0.000001;


        std::cout<<corr_vector.x<<" x:y "<<corr_vector.y<<"\n";

    return corr_vector;
    }*/
    void setColor(float r,float g, float b)
    {
        color= glm::vec3(r,g,b);
    }

};

class Rectangle : public Drawable
{
public:
    Rectangle(float x,float y,float w,float h,Pen* p):Drawable(p)
    {
        pos = glm::vec2(x,y);
        scale = glm::vec2(w,h);
    };
};

class Ghost : public Drawable
{
    // <- 0 fel 1 -> 2 le 3
    int direction = 0;

public:
    Ghost(float x,float y,float w,float h,Pen* p):Drawable(p)
    {
        pos = glm::vec2(x,y);
        scale = glm::vec2(w,h);
        direction = rand()%4;
    };
    void Go(float delta,vector<Rectangle*> &walls,vector<Ghost*> &others)
    {
        ///TODO "AI"
        //direction = direction%4;
        laststep=pos;
        switch (direction)
        {
        case 0 ://balra
            pos.x-=0.5*delta;
            break;
        case 1 ://fel
            pos.y+=0.5*delta;
            break;
        case 2 ://jobra
            pos.x+=0.5*delta;
            break;
        case 3 ://le
            pos.y-=0.5*delta;
            break;
        }
        for(f:walls)
        {
            if(is_colide_with(f))
            {
                box_colider_correction(f);
                direction=rand()%4;
            }
        }
        for(f:others)
        {
            if(this!=f && is_colide_with(f))
            {
                box_colider_correction(f);
                direction=rand()%4;
            }
        }

        //detect screen edge
        if(pos.x<=-1)
        {
            pos.x=-1+0.000001;
            direction=rand()%4;
        }
        if(pos.y<=-1)
        {
            pos.y=-1+0.000001;
            direction=rand()%4;
        }

        if(pos.x+scale.x>=1)
        {
            pos.x=1-scale.x-0.000001;
            direction=rand()%4;
        }
        if(pos.y+scale.y>=1)
        {
            pos.y=1-scale.y-0.000001;
            direction=rand()%4;
        }

    }

} ;






#endif // DRAWABLE_H_INCLUDED
