#ifndef LAGRANGE_H_INCLUDED
#define LAGRANGE_H_INCLUDED
/*

Az előadás diákban szereplő kód c++ ra írva és kijavítva egyenletes súlyozásra.
*/
class LagrangeCurve{
     public:
    std::vector<glm::vec3>cps;// control pts
    std::vector<float>ts; // knots

    float L(unsigned int i, float t) {
        float Li = 1.0f;
        for(unsigned int j = 0; j < cps.size(); j++){
            if(j!=i){
                //Li*=(t-ts[j])/(ts[i]-ts[j]);//ha a súlyok nem egyenlõek. egyenlõ sújnál hibás mert 0 val oszt
                Li*= (t*(double)(cps.size()-1)-(double)j)/((double)i-(double)j);
                }
            }
        return Li;
        }

            void AddControlPoint(glm::vec3 cp) {
                cps.push_back(cp);
                 ts.push_back(1.0);

        }
        float sum_ts()
        {
            float val=0.0;
            for(float i : ts)
                val+=i;
            return val;
        }
        glm::vec3 r(float t){
            glm::vec3 rr(0, 0, 0);
            for(unsigned int i = 0; i <cps.size(); i++)
                rr+= cps[i]*L(i,t);
            return rr;
            }
        };

#endif // LAGRANGE_H_INCLUDED
