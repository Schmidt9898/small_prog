#ifndef VERTICES_H_INCLUDED
#define VERTICES_H_INCLUDED
#include <iostream>
#include <fstream>
class FloatBuff;
FloatBuff* Clone_f_buff();

class FloatBuff
{

    float* ver=nullptr;
    unsigned int* ind=nullptr;
    unsigned int f_pont=0;//verticies tagoló // atributum sizef_b
    unsigned int ver_db=0,ind_db=0;

public:
    friend FloatBuff* Clone_f_buff();

    //VerticeObject() {};
    size_t get_f_pont(){
    return f_pont;
    }

    size_t getsize_byte()
    {
        return ver_db*sizeof(float);
    }
      size_t getver_db()
    {
        return ver_db;
    }
    size_t getindsize_byte()
    {
        return ind_db*sizeof(float);
    }
    size_t getind_db()
    {
        return ind_db;
    }
    float* getvertices()
    {
        return ver;
    }
    unsigned int* getindices()
    {
        return ind;
    }
    ~FloatBuff()
    {
        std::cout<<"VerticieObject delete.\n";
    }

    bool LoadVerticies(std::string filename)
    {

        try
        {
            std::ifstream f(filename);

            if(ver!=nullptr)
            {
                delete[] ver;
            }
            if(ind!=nullptr)
            {
                delete[] ind;
            }



            //float temp=0.0f;
            //unsigned int temp2=0;

            f>>ver_db>>std::ws;
            std::cout<<ver_db<<"ver\n";
            f>>ind_db>>std::ws;
            std::cout<<ind_db<<"ind\n";
            f>>f_pont>>std::ws;
            std::cout<<f_pont<<"f\n";
            ver_db*=f_pont;
            ver = new float[ver_db];

            float temp=0;
            for(unsigned int i=0; i<ver_db; i++)
            {
                f>>temp>>std::ws;
                ver[i]=temp;
                //std::cout<<ver[i]<<"  ";
            }

            if(ind_db==0)
            {
                ind = new unsigned int[ver_db/f_pont];
                ind_db=ver_db/f_pont;
                for(unsigned int i=0; i<ind_db; i++)
                {
                ind[i]=i;
                }

            }else
            {
                ind = new unsigned int[ind_db];
                unsigned int temp2=0;
                for(unsigned int i=0; i<ind_db; i++)
                {
                f>>temp2>>std::ws;
                ind[i]=temp2;
                }

            }

            f.close();

        }
        catch(std::ifstream::failure)
        {
            std::cerr << "Exception opening/reading/closing "<<filename<<"\n";
            return false;
        }
        return true;
    }

};



#endif // VERTICES_H_INCLUDED
