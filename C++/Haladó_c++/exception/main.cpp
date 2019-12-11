#include <iostream>

using namespace std;
template<class T>
struct save{
T tsaved;
T* t;
bool okk=false;
save(T &t) {
t=t;
tsaved=t;
}

void ok(){
okk=true;
}

~save()
{
    if(!okk)
    {
        *t=tsaved;
cout<<"assssssssssssss";
    }

}
};

void fv(int & a,int & b){



save<int> savea(a),saveb(b);

a+=b;
b=a-b;

throw std::runtime_error("alma") ;


a-=b;

savea.ok();
saveb.ok();



}


int main()
{
    cout << "Hello world!" << endl;

    int a=5,b=10;

    cout << "a erteke: " <<a<<" b erteke: "<<b<< endl;
    cout << "fv" << endl;

    try{
    fv(a,b);
    }catch(runtime_error e){
        cout << "kivetel" << endl;
    }
    cout << "a erteke: " <<a<<" b erteke: "<<b<< endl;





    return 0;
}
