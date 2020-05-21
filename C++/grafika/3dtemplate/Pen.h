#ifndef PEN_H_INCLUDED
#define PEN_H_INCLUDED
#include <string>
#include "shader.h"
#include "Vertices.h"


/*
Ez az osztály kezeli a shader programot és a open gl kirajzolásához szükséges  műveleteket.
Mindent alakzatot háromszögekként értelmez így bármilyen ponthalmazból tud rajzolni.
*/


struct Pen
{
    std::string name="none";
    unsigned int VAO,VBO,EBO;
    Shader *shader=nullptr;
    unsigned int indiciessize = 0;
    FloatBuff *f_buff=nullptr;

    virtual ~Pen()
    {
        glDeleteVertexArrays(1,&VAO);
        glDeleteBuffers(1,&VBO);
        glDeleteBuffers(1,&EBO);
        delete shader;
        delete f_buff;
        std::cout<<name<<" deleted\n";
    };

public:
    Pen(std::string name,
               std::string txtfile,
               std::string fragmentfile,
               std::string versfile)//kezeli az adatok videómemóriába másolását
    {
        this->name=name;
        shader = new Shader(versfile.c_str(),fragmentfile.c_str());

        f_buff = new FloatBuff();
        if(!f_buff->LoadVerticies(txtfile))
            std::cerr<<"something wrong default set\n";
        //unsigned int EBO,VBO;


        glGenVertexArrays(1,&VAO);
        glGenBuffers(1,&EBO);
        glGenBuffers(1,&VBO);///létrehoz
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);///összeköt? csak 1 lehet egyszerre

        glBufferData(GL_ARRAY_BUFFER,f_buff->getsize_byte(),f_buff->getvertices(),GL_STATIC_DRAW);///átmásol elküld

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);///összeköt? csak 1 lehet egyszerre

        glBufferData(GL_ELEMENT_ARRAY_BUFFER,f_buff->getindsize_byte(),f_buff->getindices(),GL_STATIC_DRAW);///átmásol elküld

        indiciessize = f_buff->getind_db();
        //std::cout<<indiciessize<<"\n";
        //pointerezés  // nincsenek szinek
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)0);/// megmondja honnan olvassa a pozíciót
        glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(3*sizeof(float)));/// megmondja honnan olvassa textúrát

        glEnableVertexAttribArray(0);
         glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER,0);

        glBindVertexArray(0);

        /// deleting + vertices már nincs rá szükség <-- NO dont do that
        //glDeleteBuffers(1,&VBO);
        //glDeleteBuffers(1,&EBO);
        std::cout<<"Pen "<<name<<" Loaded.\n";
    }
   virtual void Draw(glm::mat4 model,glm::vec3 color)//Rajzoláshoz elég a traszformáció mátrixa és a szín
    {

            shader->use();
            glBindVertexArray(VAO);

            //shader->setVec3("color",color);
            shader->setMat4("model",model);
            shader->setFloat("tiling",1);
           // std::cout<<indiciessize<<"\n";
            glDrawElements(GL_TRIANGLES,indiciessize,GL_UNSIGNED_INT,0);

            //glDrawArrays(GL_TRIANGLES,0,indiciessize);
    }
     virtual void Draw(glm::mat4 model,float tiling)//Rajzoláshoz elég a traszformáció mátrixa és a szín
    {

            shader->use();
            glBindVertexArray(VAO);

            shader->setVec3("color",1,1,1);
            shader->setMat4("model",model);
            shader->setFloat("tiling",tiling);
           // std::cout<<indiciessize<<"\n";
            glDrawElements(GL_TRIANGLES,indiciessize,GL_UNSIGNED_INT,0);

            //glDrawArrays(GL_TRIANGLES,0,indiciessize);
    }

    virtual void update_view(glm::mat4& view)
    {
            shader->setMat4("view",view);
    }

    virtual void update_projection(glm::mat4& projection)
    {
        shader->setMat4("projection",projection);
    }
};



struct Material
{
     unsigned int texture;
     float tiling=1.0f;

     Material(std::string path);

     void Use();



};





/*
ha több pent akarunnk definiálni akár dinamikusan is akkor ezzel lehet név ként lementeni és castolni.
*/

/* ///I dont need these now
struct PenFactory {
std::vector<Pen*> Pens;

~PenFactory(){DeletePens();};


Pen* GetPen(std::string name)
{
    for(unsigned int i=0;i<Pens.size();i++)
    {
        if(Pens[i]->name==name)
            return Pens[i];

    }
    return nullptr; // ha nincs meg
}
bool ContainsPen(std::string name)
{
    for(unsigned int i=0;i<Pens.size();i++)
    {
        if(Pens[i]->name==name)
            return true;
    }
    return false;
}
void AddPen(Pen* p)
{
    if(!ContainsPen(p->name))
        Pens.push_back(p);

}


void DeletePens()
{
    for(unsigned int i=0;i<Pens.size();i++)
    {
        delete Pens[i];
    }
    Pens.clear();

}

};


*/



#endif // PEN_H_INCLUDED
