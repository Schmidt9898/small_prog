#ifndef LAGRANGE_H_INCLUDED
#define LAGRANGE_H_INCLUDED

class LagrangeCurve{
     public:
    std::vector<glm::vec3>cps;// control pts
    std::vector<float>ts; // knots

    float L(int i, float t) {
        float Li = 1.0f;
        for(int j = 0; j < cps.size(); j++){
            if(j!=i){
                //Li*=(t-ts[j])/(ts[i]-ts[j]);//ha a súlyok nem egyenlõek. egyenlõ sújnál hibás mert 0 val oszt
                Li*= (t*(double)(cps.size()-1)-(double)j)/((double)i-(double)j);
                }
            }
        return Li;
        }

            void AddControlPoint(glm::vec3 cp) {
                float ti= cps.size(); // or something better

                cps.push_back(cp);
                 //ts.push_back(ti);
                 ts.push_back(1.0);
                /* float a =1.0/ts.size();
                 for(int i=0;i<ts.size();i++)
                    ts[i]=a;*/
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
            for(int i = 0; i <cps.size(); i++)
                rr+= cps[i]*L(i,t);
            return rr;
            }
        };

#endif // LAGRANGE_H_INCLUDED
