#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED
#include "Vertices.h"
#include "shader.h"
#include "global_VAOS.h"
#include <string>
using namespace std;
class Drawable
{

    //VerticeObject *ver=nullptr;
    //Shader *shader=nullptr;

    float x,y;
    float scale;
    float rotation;
    unsigned int *VAO; ///verticesbuff, Verticesarray, elementbuffer

public:
    virtual ~Drawable() {
      //  glDeleteVertexArrays(1,&VAO);
      //  glDeleteBuffers(1,&VBO);
      //  glDeleteBuffers(1,&EBO);
      //  delete shader;
    };


    Drawable(string vertexfile,string fragmentfile,string verfile,string indfile)
    {
       /* shader = new Shader(vertexfile.c_str(),fragmentfile.c_str());
        if(!ver.LoadVerInd(verfile,indfile))
            cerr<<"baj van\n";
        setupbufferselement();*/
    }
    Drawable(string vertexfile,string fragmentfile,string verfile)
    {
       /* shader = new Shader(vertexfile.c_str(),fragmentfile.c_str());
        if(!ver.LoadVerticies(verfile))
            cerr<<"baj van\n";
        setupbuffers();*/
    }

    void Draw()
    {
       // shader->use();
       // glBindVertexArray(VAO);

        ///TODO transform
        ///
        glDrawArrays(GL_TRIANGLES, 0, 3);

    }

/*
private:
    void setupbuffers()
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBufferData(GL_ARRAY_BUFFER, ver.getsize(), ver.getvertices(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(3*sizeof(float)));
        glEnableVertexAttribArray(1);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);


        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0);

    }
    void setupbufferselement()
    {
        glGenVertexArrays(1,&VAO);
        glGenBuffers(1,&EBO);
        glGenBuffers(1,&VBO);///létrehoz
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);///összeköt? csak 1 lehet egyszerre

        glBufferData(GL_ARRAY_BUFFER,ver.getsize(),ver.getvertices(),GL_STATIC_DRAW);///átmásol elküld

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);///összeköt? csak 1 lehet egyszerre

        glBufferData(GL_ELEMENT_ARRAY_BUFFER,ver.getindsize(),ver.getindices(),GL_STATIC_DRAW);///átmásol elküld

        //pointerezés
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);/// megmondja honnan olvassa

        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER,0);

        glBindVertexArray(0);

    }

*/


};

#endif // DRAWABLE_H_INCLUDED
