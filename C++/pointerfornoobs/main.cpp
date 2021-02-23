/*
#include <iostream>

using namespace std;




class A{
public:
    int a=10;
    void f()const{
    a;
    };
virtual ~A(){
cout<<"végeAAA"<<endl;
}


};
class B:public A{
public:
~B(){
cout<<"végeBBB"<<endl;
};

};

int main()
{
    cout << "Lets begin.." << endl;
    int i=0;
    //for(;;);





    int a= 5;
    int* a_pointer= &a;
    a++;
    cout<<a_pointer<<endl;
    cout<<*a_pointer<<endl;

    int* aa = new int[5]();


    A* b=new B();
    delete b;

    void (*foo)(int);
    foo(a);




    return 0;
}*//*
#include <iostream>



using namespace std;



struct Almafa {

    Almafa() { std::cout << "Hello" << std::endl; }

};



int main(){

     Almafa a();

     return 0;

}
*/

#include <iostream>
template <class T>
T tuple (T n,...)
{
    //tuple(t n,...){};

};


int main(){

int a = tuple<int>(1,2,3.4);
     return 0;

}
/*
#include <iostream>

#include <vector>

#include <assert.h>

struct Dog{

     std::string name;

     int weight;

     bool operator==(Dog const& otherDog) const{

         return name == otherDog.name && weight == otherDog.weight;

     }

};


std::vector<Dog> sortVector(std::vector<Dog> const& vec) {

     // Write your solution here
    std::vector<Dog> arr=vec;
    std::cout<<arr.size();
     for(int i=0;i<arr.size()-1;i++)
     {
         for (int j = 0; j < arr.size()-i-1; j++){
        if (arr[j].weight > arr[j+1].weight)
            {
                Dog temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
         }
     }
     return arr;

}

int main(){

     std::vector<Dog> vec{

         Dog{"Great Dane", 68},

         Dog{"Boxer", 47},

         Dog{"Beagle", 26},

         Dog{"Bulldog", 30},

         Dog{"Rottweiler", 42},

     };

     auto newVec = sortVector(vec);

     std::vector<Dog> resultVec{

        Dog{"Beagle", 26},

        Dog{"Bulldog", 30},

        Dog{"Rottweiler", 42},

        Dog{"Boxer", 47},

        Dog{"Great Dane", 68}

     };

     assert(newVec == resultVec);

}
*//*
#include <iostream>
#include <vector>
using namespace std;
 template<class T>
 T bag()
 {
     vector<T> vec;
     vector<T> num;
     int find(T)
     {


     };
     public :

     void put(T e)
     {
         int id = find(e);
         if(id==-1){

         vec.push_back(e);
         num.push_back(0);
         }else
         {
             num[id]++;

         }


     };
     T remove();
     int size();
     void remove_all();
     count()
 };

using namespace std;



int main()

{

     int points(0);





 //5

bag<long>  your_bag;

your_bag.put(1);

your_bag.put(3);

your_bag.put(1);

your_bag.put(6);

your_bag.put(12);

your_bag.put(6);

your_bag.put(17);

your_bag.put(6);

points = your_bag.size();





//10

your_bag.put(25);

your_bag.put(26);

const bag<long>  bagCopy = your_bag;

your_bag.remove(25);

your_bag.remove(26);

points = (bagCopy.size() - your_bag.size()) * 2;





//15

your_bag.put(6);

your_bag.put(6);

points = your_bag.count(6) * 3;



//20

try

     {

         your_bag.remove_all(50);

         points = your_bag[50];

      }

     catch( bad_value<long> bi )

     {

         points = 20;

     }



     std::cout << "Points: " << points << endl;

     return 0;

}
*/





