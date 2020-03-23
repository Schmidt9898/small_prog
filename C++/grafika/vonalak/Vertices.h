#ifndef VERTICES_H_INCLUDED
#define VERTICES_H_INCLUDED
#include <vector>

class VerticeObject
{

    std::vector<float> vertices;
    std::vector<float> indices;


public:
    VerticeObject() {};
    size_t getsize(){return vertices.size()*sizeof(float);}
    size_t getindsize(){return indices.size()*sizeof(float);}
    float* getvertices(){return vertices.data();}
    float* getindices(){return indices.data();}

    bool LoadVerticies(std::string filename)
    {
        try
        {
            std::ifstream f(filename);
            float temp;
            while(!f.eof())
            {
                f>>temp>>std::ws;
                vertices.push_back(temp);
            }
            f.close();
            return true;
        }
        catch(std::ifstream::failure)
        {
            std::cerr << "Exception opening/reading/closing "<<filename<<"\n";
            return false;
        }
    }
    bool LoadIndicies(std::string filename)
    {
        try
        {
            std::ifstream f(filename);
            float temp;
            while(!f.eof())
            {
                f>>temp>>std::ws;
                indices.push_back(temp);
            }
            f.close();
            return true;
        }
        catch(std::ifstream::failure)
        {
            std::cerr << "Exception opening/reading/closing "<<filename<<"\n";
            return false;
        }
    }
    bool LoadVerInd(std::string filenamever,std::string filenameind)
    {
        return LoadVerticies(filenamever) && LoadIndicies(filenameind);

    }



};



#endif // VERTICES_H_INCLUDED
