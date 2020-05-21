#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include <vector>
class Line{

//std::vector<glm::vec3> cp;

int cp_size=0;
int cp_capacity=1000;



unsigned int VAO,VBO;
Shader *shaderprogram=nullptr;


public:
    glm::vec3 color=glm::vec3(1,1,1);
    glm::vec3* cp=nullptr;
    float font=5;
    Line()
    {
        cp = new glm::vec3[cp_capacity];
        shaderprogram = new Shader("4.0.shader.vs","4.0.shader.fs");
        glGenVertexArrays(1,&VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*cp_capacity, cp, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
    ~Line()
    {
        delete[] cp;
    }
    int getsize()
    {
        return cp_size;
    }

    void add_point(glm::vec3 point)
    {
        if(cp_size>=cp_capacity)
            return;
        cp[cp_size] = point;
        std::cout<<cp_size<<"\n"<<cp[cp_size].x<<"\n";

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        //std::cout<<VBO<<"vbo\n";
        glBufferSubData(GL_ARRAY_BUFFER,cp_size*sizeof(glm::vec3),sizeof(glm::vec3),&cp[cp_size]);
        glBindVertexArray(0);

        cp_size++;


    }
        void add_point_f(glm::vec3 point)///úgy add pontott hozzá hogy nem frissíti a videókártya buffert
    {
        if(cp_size>=cp_capacity)
            return;
        cp[cp_size] = point;
        cp_size++;
    }
    void refresh()///frissíti a videó memóriát
    {
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        //std::cout<<VBO<<"vbo\n";
        glBufferSubData(GL_ARRAY_BUFFER,0,cp_size*sizeof(glm::vec3),&cp[0]);
        glBindVertexArray(0);

    }
    void Clear()
    {
        cp_size=0;
        std::cout<<"cleared\n";
    }

    void Draw(){
        glPointSize(font);
        shaderprogram->use();
        shaderprogram->setVec3("unicolor",color);

        glBindVertexArray(VAO);


        glDrawArrays(GL_LINE_STRIP, 0, cp_size);
        shaderprogram->setVec3("unicolor",1,0,0);
        if(font!=0)
        glDrawArrays(GL_POINTS, 0, cp_size);
        glBindVertexArray(0);
        //std::cout<<cp_size<<"\n";

    };
    void Subdivide()/// órai algoritmus megvalósítása a dia képekbõl
    {
        ///minden 2 pont közé felveszek egy újat azokat meghagyom és minden eredeti pontot 50 százalékát megtartom és 50 % át az új pontok teszik ki lásd lentebb
        if(cp_size<2 || 2*cp_size-1 > cp_capacity)
            return;
        std::vector<glm::vec3> green;
        for(int i=0;i<cp_size-1;i++)
        {
            green.push_back(half_point(cp[i],cp[i+1]));
        }
        std::vector<glm::vec3> new_points;


        for(int i=0;i<cp_size-1;i++)
        {
        new_points.push_back(cp[i]);
        new_points.push_back(green[i]);
        }
        new_points.push_back(cp[cp_size-1]);



        if(new_points.size()>=5){

            for(unsigned int i=2;i<new_points.size()-2;i+=2)
            {
                new_points[i]= new_points[i]*0.5f + new_points[i-1]*0.25f + new_points[i+1]*0.25f; /// <-itt láthatod
            }
        }
        memcpy(cp,&new_points[0],new_points.size()*sizeof(glm::vec3));// copy memory
        cp_size=new_points.size();

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);
        glBufferSubData(GL_ARRAY_BUFFER,0,cp_size*sizeof(glm::vec3),cp);
        glBindVertexArray(0);

    }
    glm::vec3 half_point(glm::vec3 A,glm::vec3 B)/// egy szakasz felezõpontja A-B be megyek de csak az AB vektor felét.
    {
        return A+((B-A)/2.0f);
    }

};

#endif // LINE_H_INCLUDED
