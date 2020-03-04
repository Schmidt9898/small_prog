#ifndef GLOBAL_VAOS_H_INCLUDED
#define GLOBAL_VAOS_H_INCLUDED
#include <string>
struct Pen;

std::vector<Pen*> Pens;





struct Pen
{
    std::string name="none";
    unsigned int VAO;
    Shader *shader=nullptr;
    unsigned int indiciessize = 0;
//VerticeObject *ver=nullptr;

    virtual ~Pen()
    {
        glDeleteVertexArrays(1,&VAO);
        //glDeleteBuffers(1,&VBO);
        //glDeleteBuffers(1,&EBO);
        delete shader;
        // delete ver;
    };

public:
        Pen(std::string name,
               std::string vertexfile,
               std::string fragmentfile,
               std::string verfile,
               std::string indfile)
    {

        shader = new Shader(vertexfile.c_str(),fragmentfile.c_str());

        VerticeObject ver;
        if(!ver.LoadVerticies(verfile,indfile))
            std::cerr<<"baj van\n";
        unsigned int EBO,VBO;


        glGenVertexArrays(1,&VAO);
        glGenBuffers(1,&EBO);
        glGenBuffers(1,&VBO);///létrehoz
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);///összeköt? csak 1 lehet egyszerre

        glBufferData(GL_ARRAY_BUFFER,ver.getsize(),ver.getvertices(),GL_STATIC_DRAW);///átmásol elküld

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);///összeköt? csak 1 lehet egyszerre

        glBufferData(GL_ELEMENT_ARRAY_BUFFER,ver.getindsize(),ver.getindices(),GL_STATIC_DRAW);///átmásol elküld

        indiciessize = ver.getind_db();
        //std::cout<<indiciessize<<"\n";
        //pointerezés  // nincsenek szinek
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);/// megmondja honnan olvassa

        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER,0);

        glBindVertexArray(0);

        ///testing deleting + vertices
        glDeleteBuffers(1,&VBO);
        glDeleteBuffers(1,&EBO);
        std::cout<<"good?\n";
    }
    void Draw(glm::mat4 trans,glm::vec3 color)
    {

            shader->use();
            glBindVertexArray(VAO);

            shader->setVec3("color",color);
            shader->setMat4("trans",trans);
            glDrawElements(GL_TRIANGLES,indiciessize,GL_UNSIGNED_INT,0);
            //glDrawArrays(GL_TRIANGLES,0,3);
    }

};


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





#endif // GLOBAL_VAOS_H_INCLUDED
