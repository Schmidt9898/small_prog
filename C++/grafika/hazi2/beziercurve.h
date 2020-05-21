#ifndef BEZIERCURVE_H_INCLUDED
#define BEZIERCURVE_H_INCLUDED
/*
Az elõadás diákban szereplõ kód c++ ra írva és kijavítva egyenletes súlyozásra.
*/
class BezierCurve{
    std::vector<glm::vec3> cps;//control points

    float B(int i, float t)
    {
        int n = cps.size()-1; // n degpolynomial= n+1 pts!
        float choose = 1;
        for(int j = 1; j <= i; j++)
            choose *= (float)(n-j+1)/j;
        return choose * pow(t, i) * pow(1-t,n-i);
    }
    public:
        void AddControlPoint(glm::vec3 cp) {
             cps.push_back(cp);
              }

    glm::vec3 r(float t) {
        glm::vec3 rr(0, 0, 0);
        for(unsigned int i = 0; i <cps.size(); i++)
            rr+= cps[i]* B(i,t);
        return rr;
        }
};

#endif // BEZIERCURVE_H_INCLUDED
