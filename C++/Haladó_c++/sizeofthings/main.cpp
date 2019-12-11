#include <iostream>
#include <bitset>
using namespace std;

struct S{
float i;

//virtual void r(){};
};

class D
{};
class A: public D
{};
class B:public D{};
class C:public A, public B{};



int main()
{

    S s;
   // s.c='a';
    s.i=1;
    //s.j=1;

    cout << "Hello world!" << endl;
    cout<<sizeof(S)<<endl;
    const int m=sizeof(S);
    cout<<sizeof(char)<<endl;


   //unsigned short short1 = 4;
    //bitset<16> bitset1();   // the bitset representation of 4
    //cout << bitset1 << endl;  // 0b00000000'00000100

    float b=0.231;
    char* buff = reinterpret_cast<char*>(&b);
    for(int j=0;j<m;j++){
bitset<8> bits(buff[j]);
  cout << bits<< endl;
    }
cout << endl;
    float a=2;
     buff = reinterpret_cast<char*>(&a);
    for(int j=0;j<m;j++){
bitset<8> bits(buff[j]);
  cout << bits<< endl;
    }






  //  bitset<m> T(buff);

    //cout<<T;
    //cout<<(byte)
    return 0;
}
