#include "Drawable.h"

float Random_between(float a,float b)  //a �s b k�z�tti randomsz�m 10000 felbont�ssal
{
    return (float)((b-a)/10000)*(rand()%10000)+a;
}
Drawable* Make_Drawable(Pen* p,float x,float y,float z,float sx,float sy,float sz)
{
    return Make_Drawable(p,glm::vec3(x,y,z),glm::vec3(sx,sy,sz));
}
Drawable* Make_Drawable(Pen* p,float x,float y,float z,glm::vec3 scale)
{
    return Make_Drawable(p,x,y,z,scale);
}
Drawable* Make_Drawable(Pen* p,glm::vec3 pos,glm::vec3 scale)
{

    Drawable* obj = new Drawable(p);
    obj->pos=pos;
    obj->laststep=pos;obj->laststep.z+=10;
    obj->scale=scale;
    unsigned int f_pont=p->f_buff->get_f_pont();// atributum m�ret
    unsigned int point_db = p->f_buff->getver_db();
    float* cordinates = p->f_buff->getvertices();
    //std::cout<<f_pont;
    //float weight = 1.0/point_db;
    glm::vec3 min_cor = glm::vec3(0,0,0);
    glm::vec3 max_cor = glm::vec3(0,0,0);


    //kisz�moljuk hol van a t�nyleges k�zepe az objektumnak
    for(unsigned int i = 0;i<point_db;i+=f_pont)
    {
        min_cor.x=min(min_cor.x,cordinates[i]);
        min_cor.y=min(min_cor.y,cordinates[i+1]);
        min_cor.z=min(min_cor.z,cordinates[i+2]);

        max_cor.x=min(min_cor.x,cordinates[i]);
        max_cor.y=min(min_cor.y,cordinates[i+1]);
        max_cor.z=min(min_cor.z,cordinates[i+2]);
    }

    obj->colider_center = min_cor + (max_cor-min_cor)/2.0f;
    obj->colider_scale = max_cor-min_cor;


    return obj;
}



void Drawable::Draw() // v�grehajtja a transzform�ci�t �s kirajzolja
{
    ///TODO 3d texture
    myMaterial->Use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model,pos);
    // trans = glm::rotate(trans,rotation,glm::vec3(0,0,1));
    model = glm::scale(model,scale);
    //mypen->Draw(model,color);
    mypen->Draw(model,myMaterial->tiling);
}
/*

*/
bool Drawable::Contain_point_box(glm::vec3 dot) // benne van e a pont , egyszer� t�glalap tartom�ny
{

      bool colide_x = pos.x + scale.x/2 >= dot.x &&
                      dot.x >= pos.x-scale.x/2;


      bool colide_y = pos.y + scale.y/2 >=  dot.y &&
                      dot.y >= pos.y-scale.y/2;

      bool colide_z = pos.z + scale.z/2 >=  dot.z &&
                      dot.z >= pos.z-scale.z/2;

      return colide_x && colide_y && colide_z;
      //return false;
}
/*

*/
bool Drawable::Contain_point_sphere(glm::vec3 dot) // benne van e a pont , egyszer� t�glalap tartom�ny
{
    throw false;
    return false;
}

/*

*/

bool Drawable::is_colide_with_box(Drawable *obj)//van e k�z�s pontjuk k�t t�glalapnak
{

       bool colide_x = pos.x + scale.x/2 >= obj->pos.x-obj->scale.x/2 &&
                       obj->pos.x + obj->scale.x/2 >= pos.x-scale.x/2;


       bool colide_y = pos.y + scale.y/2 >= obj->pos.y-obj->scale.y/2 &&
                       obj->pos.y + obj->scale.y/2 >= pos.y-scale.y/2;

       bool colide_z = pos.z + scale.z/2 >= obj->pos.z-obj->scale.z/2 &&
                       obj->pos.z + obj->scale.z/2 >= pos.z-scale.z/2;

       return colide_x && colide_y && colide_z;

   // return false;
}
bool Drawable::is_colide_with_sphere(Drawable *obj)//van e k�z�s pontjuk egy g�mbel
{
    throw false;
    return false;
}
/*

*/
glm::vec3 Drawable::box_colider_correction(Drawable *obj) //only if coliding, only if it's a box colider
{
    /*
    Csak is akkor szabad megh�vni ha az is_colide_with f�ggv�ny igaz
    A f�gv�ny csak is k�t t�glalap k�z�tt m�k�dik
    Felt�telezz�k, hogy �tk�z�nk �s , hogy az �tk�z�s el�tt laststep nem �tk�zt�nk
    akkor megn�zz�k , hogy mieny ir�nyban �ltunk a m�sik laphoz �s �tk�z�s eset�n csak a hat�rfel�letig mehet�nk el
    �gy oda �ll�tjuk a kordin�t�nkat.
    */
     glm::vec3 corr_vector=pos;
     if((laststep.x+scale.x/2) <= obj->pos.x-obj->scale.x/2)
         corr_vector.x= obj->pos.x-obj->scale.x/2-scale.x/2-0.000001;
     if(laststep.x-scale.x/2>=(obj->pos.x+obj->scale.x/2))
         corr_vector.x=obj->pos.x+obj->scale.x/2+scale.x/2+0.000001;

     if((laststep.y+scale.y/2) <= obj->pos.y-obj->scale.y/2)
         corr_vector.y= obj->pos.y-obj->scale.y/2-scale.y/2-0.000001;
     if(laststep.y - scale.y/2 >= (obj->pos.y+obj->scale.y/2))
         corr_vector.y=obj->pos.y+obj->scale.y/2+scale.y/2+0.000001;

     if((laststep.z+scale.z/2) <= obj->pos.z-obj->scale.z/2)
         corr_vector.z= obj->pos.z-obj->scale.z/2-scale.z/2-0.000001;
     if(laststep.z - scale.z/2 >= (obj->pos.z+obj->scale.z/2))
         corr_vector.z=obj->pos.z+obj->scale.z/2+scale.z/2+0.000001;


    // std::cout<<corr_vector.x<<" x:y "<<corr_vector.y<<"\n";
    pos=corr_vector;
    return corr_vector;
    //return glm::vec3(0,0,0);
}
glm::vec3 Drawable::sphere_colider_correction(Drawable *obj) //only if coliding, only if it's a box colider
{
    return glm::vec3(0,0,0);
}








