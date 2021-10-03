#include "komplex.hpp"
#include "graphics.hpp"
using namespace genv;


void mandelrajz(int XX, int YY, int MAX) {
    for (int x=0;x<XX;x++) {
        for (int y=0;y<YY;y++) {
            double cr = (4.0/double(XX))*x - 2.0;
            double ci = (4.0/double(YY))*y - 2.0;
            komplex c(cr, ci);
            komplex z(0,0);
            int t = 0;
            while (z.re()*z.re()+z.im()*z.im() < 4.0 && t < MAX) {
                z = z*z+c;
                ++t;
            }
            t=t*15;
            gout << move_to(x,y) << color(t,t,t) << dot;
        }

    }
}
