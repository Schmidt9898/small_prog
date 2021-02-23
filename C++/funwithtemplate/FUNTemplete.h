#ifndef FUNTEMPLETE_H_INCLUDED
#define FUNTEMPLETE_H_INCLUDED

#include <iostream>
#include <stdarg.h>
#include <sstream>


using namespace std;

//A simple pair class
template<class T,class Z>
class myPair{
public :
    T first;
    Z sec;

    myPair(T f,Z s)
    {
        first=f;
        sec=s;
    }
    void print()
    {
        cout<<first<<endl;
        cout<<sec<<endl;
    }
};





//a ssimple int print
void Print_int(int num, ...)
{
    cout<<"Unlimited power...  ";

    va_list valist;
   va_start(valist, num);
   for (int i = 0; i < num; i++) {
      cout<<va_arg(valist, int);
   }
   va_end(valist); //clean memory reserved for valist
cout<<endl;
}





//Not so simple print
string helpPrint()
{
    return "";
}
template<class First,class... Args>
string helpPrint(First f, Args... rest)
{
    std::string s;
    std::stringstream ss;
    ss << f;
    ss >> s;
    return s+" "+helpPrint(rest...);
}
template<class First,class... Args>
void Print(First f, Args... rest)
{
    cout<<f<<" "<<helpPrint(rest...)<<endl;

}

template<typename num,typename... nums>
num mymax(num a,num b)
{
    return (a>b)? a:b;
}
template<typename num,typename... nums>
num mymax(num f,num s,nums... rest)
{
    return mymax(f,mymax(s,rest...));
}














//A work in progres
class myTuple{
public:
    myTuple(...)
    {


    }


};





























#endif // FUNTEMPLETE_H_INCLUDED
