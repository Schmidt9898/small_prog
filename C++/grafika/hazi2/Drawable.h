#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Pen.h"
#include <time.h>

using namespace std;
//PenFactory _penfactory;



//struct p16fgu {p16fgu(){PEN_Init();};};p16fgu _p16fgu;//haladó cpp-s varázslat lett volna ha indokolt lenne de nem volt az


/*
Minden eggyes alakzat amit kirajzolunk van paraméterei mely csak rá igaz, és ezek változók változhatnak (méret szög,helyzet).
 Drawable az ősosztály ami bármi lehet.
*/

class Drawable
{
    //protected:

public:
    Pen *mypen=nullptr; //a toll közös lehet több hasonló alakzatéval mert nem befolyásol semmit viszont kevesebb memóriát igényel ha nagy az alakzat
    glm::vec2 laststep = glm::vec2(0.0,0.0); //előző pozíció
    glm::vec2 pos = glm::vec2(0.0f,0.0f);//mostani pozíció
    glm::vec2 scale = glm::vec2(0.0,0.0);// méret

    float rotation=0;// elforgatás



    static float random(float a,float b){ //a és b közötti randomszám 1000 felbontással
    return (float)((b-a)/1000)*(rand()%1000)+a;
}

public:
    glm::vec3 color=glm::vec3(1,1,1); // alapszin a fehér
   // glm::vec2 offset = glm::vec2(0.5,0.5);// ofszet ha ell kell valamit tolni

    virtual ~Drawable() {};
    Drawable(Pen * p):mypen(p) {};// mit rajzoljon átveszi
    virtual void Draw() // végrehajtja a transzformációt és kirajzolja
    {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans,glm::vec3(pos,0.0));
        trans = glm::rotate(trans,rotation,glm::vec3(0,0,1));
        trans = glm::scale(trans,glm::vec3(scale,0.0));
        mypen->Draw(trans,color);
    }

    virtual bool contain_point(glm::vec2 dot) // benne van e a pont , egyszerű téglalap tartomány
    {

        bool colide_x = pos.x + scale.x/2 >= dot.x &&
                        dot.x >= pos.x-scale.x/2;


        bool colide_y = pos.y + scale.y/2 >=  dot.y &&
                        dot.y >= pos.y-scale.y/2;

        return colide_x && colide_y;
    }


    virtual bool is_colide_with(Drawable *obj)//van e közös pontjuk két téglalapnak
    {

        bool colide_x = pos.x + scale.x/2 >= obj->pos.x-obj->scale.x/2 &&
                        obj->pos.x + obj->scale.x/2 >= pos.x-scale.x/2;


        bool colide_y = pos.y + scale.y/2 >= obj->pos.y-obj->scale.y/2 &&
                        obj->pos.y + obj->scale.y/2 >= pos.y-scale.y/2;

        return colide_x && colide_y;
    }
    virtual glm::vec2 box_colider_correction(Drawable *obj) //only if coliding, only if it's a box
    {
        /*
        Csak is akkor szabad meghívni ha az is_colide_with függvény igaz
        A fügvény csak is két téglalap között működik
        Feltételezzük, hogy ütközünk és , hogy az ütközés elött laststep nem ütköztünk
        akkor megnézzük , hogy mieny irányban áltunk a másik laphoz és ütközés esetén csak a határfelületig mehetünk el
        így oda állítjuk a kordinátánkat.
        */
        glm::vec2 corr_vector=pos;
        if((laststep.x+scale.x/2) <= obj->pos.x-obj->scale.x/2)
            corr_vector.x= obj->pos.x-obj->scale.x/2-scale.x/2-0.000001;
        if(laststep.x-scale.x/2>=(obj->pos.x+obj->scale.x/2))
            corr_vector.x=obj->pos.x+obj->scale.x/2+scale.x/2+0.000001;

        if((laststep.y+scale.y/2) <= obj->pos.y-obj->scale.y/2)
            corr_vector.y= obj->pos.y-obj->scale.y/2-scale.y/2-0.000001;
        if(laststep.y - scale.y/2 >= (obj->pos.y+obj->scale.y/2))
            corr_vector.y=obj->pos.y+obj->scale.y/2+scale.y/2+0.000001;


       // std::cout<<corr_vector.x<<" x:y "<<corr_vector.y<<"\n";
        pos=corr_vector;
        return corr_vector;
    }
    ///Jó a kövi 3 függvény majdnem teljesen másoltam, de inkább fogalmazzunk úgy hogy
    ///hosszú utánnajárással és megértéssel egy internetes tutoriál alapján készítettem el.
    ///magamtől nem jöttem volna rá de mostmár értem hogy működik
    bool onSegment(glm::vec3 p, glm::vec3 q, glm::vec3 r)///rajta van e az egyenesen a pont
    {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
    }
    int orientation(glm::vec3 A, glm::vec3 B,glm::vec3 C)///Óramutató járásának mejik irányáma van a pont
    {
        double v = (B.y - A.y) * (C.x- B.x) - (B.x - A.x) * (C.y-B.y);
        //std::cout<<"v: "<<v<<"\n ";
//0 colineáris 1 orával megegyező 2 ellenkező
        return (v == 0)? 0 : (v>0)? 1 : 2;

    }
    bool doIntersect(glm::vec3 p1, glm::vec3 q1)//metszi e egymást két egyenes a mi esetünkben a második egyenes a mozgás iránya az utolsó frame óta
{
    glm::vec3 p2 = glm::vec3(laststep,0);
    glm::vec3 q2 = glm::vec3(pos,0);
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    //std::cout<<"||||||||||||||\n";

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}
    void set_to_edge(glm::vec3 A, glm::vec3 B)//csak akkor hívjuk ha a felette lévő igaz, ez visszateszi a metszéspontra,
    {
///de nem működik ezért nem is használom inkább csak az előző lépés helyére teszem vissza
    double a1 = B.y - A.x;
    double b1 = A.x - B.x;
    double c1 = a1*(A.x) + b1*(A.y);

    glm::vec3 D = glm::vec3(laststep,0);
    glm::vec3 C = glm::vec3(pos,0);

    double a2 = D.y - C.y;
    double b2 = C.x - D.x;
    double c2 = a2*(C.x)+ b2*(C.y);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0)
    {
        pos=laststep;
        return;
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        pos.x=x;
        pos.y=y;
        laststep=pos;
        return;
    }



    }

    void setColor(float r,float g, float b)//szineket állít
    {
        color= glm::vec3(r,g,b);
    }

};

class Rectangle : public Drawable // sima class ami téglalapot rajzol
{
public:
    Rectangle(float x,float y,float w,float h,Pen* p):Drawable(p)
    {
        pos = glm::vec2(x,y);
        scale = glm::vec2(w,h);
    };
};

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


/*
class Ghost : public Drawable // az ellenfél az az a szellem osztály
{
    // <- 0 fel 1 -> 2 le 3
    int direction = 0; //milyen irányba néz
bool cansee = true;//keresheti e  játékost
public:
    Ghost(float x,float y,float w,float h,Pen* p):Drawable(p)
    {
        pos = glm::vec2(x,y);
        scale = glm::vec2(w,h);
        direction = rand()%4;// véletlen irány

    };
    void Go(float delta,vector<Rectangle*> &walls,vector<Ghost*> &others,Drawable* player)
    {
        /// "AI?"
        //direction = direction%4;
        /*
        Véletlen irányban megyünk addig amíg bele nem ütközönk egy falba,
        ütközéskor másik véletlen irányba megyek tovább
        ha keresem a játékost akkor megnézem alattam vagy felettem van e egy sávban a méretem 2 szeresével,
        ha igen akkor irányt váltok felé és amíg falnak vagy másik szellemnek nem ütközöm nem módosítom az irányom.
        Azért kell ez mert a teszterek nehéznek találták az ai-t mert túl ügyes volt.
        így már ell lehet bújni egyszer előle.
        *//*
        if(cansee)
        {
          if( abs(pos.x-player->pos.x) < scale.y/2)
          {
              direction = (pos.y<player->pos.y)? 1:3;
              cansee=false;
          }
          if( abs(pos.y-player->pos.y) < scale.x/2)
          {
              direction = (pos.x<player->pos.x)? 2:0;
              cansee=false;
          }


        }




        laststep=pos;
        switch (direction)
        {
        case 0 ://balra
            pos.x-=0.5*delta;
            rotation = 3.1415;
            break;
        case 1 ://fel
            pos.y+=0.5*delta;
            rotation = 3.1415/2;
            break;
        case 2 ://jobra
            pos.x+=0.5*delta;
            rotation = 0;
            break;
        case 3 ://le
            pos.y-=0.5*delta;
            rotation = -3.1415/2;
            break;
        }
        for(f:walls)
        {
            if(is_colide_with(f))
            {
                box_colider_correction(f);
                direction=rand()%4;
                cansee=true;
            }
        }
        for(f:others)
        {
            if(this!=f && is_colide_with(f))
            {
                box_colider_correction(f);
                direction=rand()%4;
                cansee=true;
            }
        }

        //detect screen edge
        if(pos.x-scale.x/2<=-1)
        {
            pos.x=-1+scale.x/2+0.000001;
            direction=rand()%4;
            cansee=true;
        }
        if(pos.y-scale.x/2<=-1)
        {
            pos.y=-1+scale.x/2+0.000001;
            direction=rand()%4;
            cansee=true;
        }

        if(pos.x+scale.x/2>=1)
        {
            pos.x=1-scale.x/2-0.000001;
            direction=rand()%4;
            cansee=true;
        }
        if(pos.y+scale.y/2>=1)
        {
            pos.y=1-scale.y/2-0.000001;
            direction=rand()%4;
            cansee=true;
        }

    }

} ;
*/
///Dont use Boom
/*class Boom : public Drawable{// szikrázás vagy robbanás effect amit nem fejeztem be és bele sem raktam a játékba

glm::vec2 particles[50];
float r,f;//R=sugár F= erõ ala sebesség

public:
    Boom(float x,float y,float r_,float f_,Pen* p):Drawable(p)
    {
        pos=glm::vec3(x,y,0);
        f=f_;
        r=r_;
        for(int i=0;i<50;i++)
        {
            particles[i]=glm::vec2(random(-1/r,1/r),random(-1/r,1/r));
        }
    }

    void Draw(){
        for(int i=0;i<50;i++)
        {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans,glm::vec3(pos.x+particles[i].x,pos.y+particles[i].y,0.0));
        //trans = glm::rotate(trans,rotation,glm::vec3(0,0,1));
        trans = glm::scale(trans,glm::vec3(0.01,0.01,0.0));
        mypen->Draw(trans,color);
        }

    }

};
*/



#endif // DRAWABLE_H_INCLUDED
