#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "mandelrajz.hpp"
#include "komplex.hpp"
using namespace genv;
using namespace std;

const int XX=800;
const int YY=600;


const int MAX = 255;

int main()
{
    gout.open(XX,YY);
    mandelrajz(XX,YY, MAX);
    gout << refresh;
    event ev;
    while(gin >> ev && ev.keycode != key_escape) {
    }
    return 0;
}

