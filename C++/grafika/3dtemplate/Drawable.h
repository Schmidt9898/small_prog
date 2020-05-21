#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Pen.h"
#include <time.h>
#include "Camera.h"
using namespace std;
//PenFactory _penfactory;

//struct p16fgu {p16fgu(){PEN_Init();};};p16fgu _p16fgu;//haladó cpp-s varázslat lett volna ha indokolt lenne de nem volt az


/*
Minden eggyes alakzat amit kirajzolunk van paraméterei mely csak rá igaz, és ezek változók változhatnak (méret szög,helyzet).
 Drawable az ősosztály ami bármi lehet.
*/

float Random_between(float a,float b);
class Drawable
{
public:
    const float gravity=-10.0f;


    Pen *mypen=nullptr; //a toll közös lehet több hasonló alakzatéval mert nem befolyásol semmit viszont kevesebb memóriát igényel ha nagy az alakzat
    //Material *myMaterial=nullptr;

    glm::vec3 laststep = glm::vec3(0.0f,0.0f,0.0f); //előző pozíció
    glm::vec3 pos = glm::vec3(0.0f,0.0f,0.0f);//mostani pozíció //world space eltolás
    glm::vec3 scale = glm::vec3(1.0,1.0,1.0f);// méret //x,y,z  méretek
    //float rotation=0;// elforgatás // nem használom
    //for box and sphere colider
    ///local space
    glm::vec3 colider_scale = glm::vec3(0.0,0.0,0.0f);//objektumot befogadó téglatest mérete
    glm::vec3 colider_center = glm::vec3(0.0,0.0,0.0f);//objektumot befogadó téglatest közepe
    float colider_r = 0;//objektumot befogadó gömb sugara





public:
    Material *myMaterial=nullptr;//TODO make Private


    glm::vec3 color=glm::vec3(1,1,1); // alapszin a fehér

    virtual ~Drawable() {};
    Drawable(Pen * p):mypen(p) {};// mit rajzoljon átveszi
    virtual void Draw(); // végrehajtja a transzformációt és kirajzolja

    bool Contain_point_box(glm::vec3 dot);// benne van e a pont , egyszerű téglatest tartomány
    bool Contain_point_sphere(glm::vec3 dot);///TODO
    virtual bool Contain_point(glm::vec3 dot)
    {
        Contain_point_box(dot);
    };


    virtual bool is_colide_with_box(Drawable *obj);//van e közös pontjuk
    virtual bool is_colide_with_sphere(Drawable *obj);///TODO //van e közös pontjuk

    virtual glm::vec3 box_colider_correction(Drawable *obj); //only if coliding, only if it's a box colider
    virtual glm::vec3 sphere_colider_correction(Drawable *obj);//only if coliding


    void setColor(float r,float g, float b)//szineket állít
    {
        color= glm::vec3(r,g,b);
    }
    virtual void save_position()
    {
        laststep=pos;
        //myCamera->Position=pos;///Remove this line
        //myCamera->Position.y+=scale.y/3;///and this too

    }
    virtual void UpDate(float delta)
    {
        pos.y+=gravity*delta;
    }
    virtual Drawable* Clone()
    {
        Drawable* new_d = new Drawable(mypen);

        new_d->laststep =pos;
        new_d->laststep.y+=10;
        new_d->pos=pos;
        new_d->scale =scale;

        new_d->colider_scale=colider_scale ;
        new_d->colider_center=colider_center;
        new_d->myMaterial=myMaterial;

        return new_d;

    }



    friend Drawable* Make_Drawable(Pen* p,float x,float y,float z,float sx,float sy,float sz);
    friend Drawable* Make_Drawable(Pen* p,float x,float y,float z,glm::vec3);
    friend Drawable* Make_Drawable(Pen* p,glm::vec3,glm::vec3);


};

Drawable* Make_Drawable(Pen* p,float x,float y,float z,float sx,float sy,float sz);
Drawable* Make_Drawable(Pen* p,float x,float y,float z,glm::vec3);
Drawable* Make_Drawable(Pen* p,glm::vec3,glm::vec3);
struct Movement
{
    int forward_=0;
    int right_=0;
    float speed=2;
    float jump=0;
    void clear()
    {
        speed=2;
        forward_=0;
        right_=0;
    }
};
class Player : public Drawable
{

    bool isGrounded=false;
public:
    Camera* myCamera=nullptr;

    Player(Pen* p,float x,float y,float z,float sx,float sy,float sz):Drawable(p)
    {
        pos=glm::vec3(x,y,z);
        laststep=pos;
        laststep.z+=10;
        scale=glm::vec3(sx,sy,sz);
        unsigned int f_pont=p->f_buff->get_f_pont();// atributum méret
        unsigned int point_db = p->f_buff->getver_db();
        float* cordinates = p->f_buff->getvertices();
        //std::cout<<f_pont;
        //float weight = 1.0/point_db;
        glm::vec3 min_cor = glm::vec3(0,0,0);
        glm::vec3 max_cor = glm::vec3(0,0,0);


        //kiszámoljuk hol van a tényleges közepe az objektumnak
        for(unsigned int i = 0; i<point_db; i+=f_pont)
        {
            min_cor.x=min(min_cor.x,cordinates[i]);
            min_cor.y=min(min_cor.y,cordinates[i+1]);
            min_cor.z=min(min_cor.z,cordinates[i+2]);

            max_cor.x=min(min_cor.x,cordinates[i]);
            max_cor.y=min(min_cor.y,cordinates[i+1]);
            max_cor.z=min(min_cor.z,cordinates[i+2]);
        }

        colider_center = min_cor + (max_cor-min_cor)/2.0f;
        colider_scale = max_cor-min_cor;
    }

    void UpDate(Movement &m,float delta)
    {
        glm::vec3 offset = myCamera->Front*((float)m.forward_);
        offset+=myCamera->Right*((float)m.right_);
        offset.y=0;
        if(glm::length(offset)!=0)
        {
            glm::vec3 offsetnormalt = glm::normalize(offset);
            pos+=offsetnormalt*delta*m.speed;
        }
        pos.y+=gravity*delta;
        pos.y+=m.jump*delta*2;
        m.jump+=gravity*delta;
        if(m.jump<0)
            m.jump=0;
        //std::cout<<pos.y<<"\n";


        //myCamera->Position=pos;///Remove this line
        //myCamera->Position.y+=scale.y/3;///and this too

    }
    void save_position()
    {
        laststep=pos;
        myCamera->Position=pos;
        myCamera->Position.y+=scale.y/3;

    }






};











/*
class Rectangle : public Drawable // sima class ami téglalapot rajzol
{
public:
    Rectangle(float x,float y,float w,float h,Pen* p):Drawable(p)
    {
        pos = glm::vec2(x,y);
        scale = glm::vec2(w,h);
    };
};
*/
/*
class Canonball : public Drawable
{

public:
    glm::vec2 velociti;
    Canonball(float x,float y,glm::vec2 dir,Pen* p):Drawable(p){
       laststep = pos = glm::vec2(x,y);
       velociti=glm::normalize(dir);
        scale = glm::vec2(0.01,0.01);
    };
};

*/


#endif // DRAWABLE_H_INCLUDED
