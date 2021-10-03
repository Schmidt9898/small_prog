#pragma once

#define Ddim(arr,x,y) arr[(y) + (x)*YY]
struct komplex
{
    double i, v;
    komplex(double vv, double ii)
    {
        i = ii;
        v = vv;
    }
    double re()
    {
        return(v);
    }
    double im()
    {
        return (i);
    }


};
komplex  operator+ (komplex a, komplex b)
{
    a.i += b.i;
    a.v += b.v;
    return a;
}
komplex  operator* (komplex a, komplex b)
{
    komplex c(0, 0);
    c.i = a.v * b.i + a.i * b.v;
    c.v = a.i * b.i * -1 + (a.v * b.v);
    return c;
}

void mandelrajz(float* data,int XX, const int YY, const int MAX, const double mag, const double xoff, const double yoff) {
    for (int x = 0;x < XX;x++) {
        for (int y = 0;y < YY;y++) {
            double cr = (mag / double(XX)) * x - mag/2-xoff;
            double ci = (mag / double(YY)) * y - mag/2-yoff;
            komplex c(cr, ci);
            komplex z(0, 0);
            float t = 0;
            while (z.re() * z.re() + z.im() * z.im() < 4.0 && t < MAX) {
                z = z * z + c;
                ++t;
            }
            Ddim(data, x, y) = t;
            //gout << move_to(x, y) << color(t, t, t) << dot;
        }

    }
}