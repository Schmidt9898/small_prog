#include <iostream>
#include <thread>
#include  <mutex>
#include <condition_variable>

using namespace std;

   std::mutex adam;/// mutex olyan mint a monitor javaban
   std::mutex monitor;
   std::condition_variable monitor_c; /// mutexre nem lehet waitelni se notifyolni
                                      ///ez�rt kell egy olyan valami amire lehet ,k�l�nbs�g
                                      ///,hogy ezt nem lehet m�solni ez�rt kell k�l�n

void func(int * a)///sima szinkroniz�ci� csak mutexel
{
    adam.lock();
    *a += 1;
    cout<<"helo az a: "<<*a<<endl;
    adam.unlock();
}


void f(string smg){///szinkroniz�l�s waitingel
while(true){


monitor.lock();
cout<<"thread " << smg <<" waiting"<<endl;
monitor.unlock();

unique_lock<std::mutex> lk(monitor);///also locking it so no need to lock again
                                    /// ja �s nem is lehetne mert deadlock lesz



monitor_c.wait(lk);///ameddig wait el addig nem fogja a monitort.
///itt viszaszerzi a lock ot
//std::condition_variable::wait(lk);///not good

//monitor.lock();
this_thread::sleep_for(chrono::milliseconds(1000));///alszik
cout<<"thread " << smg <<" waiting over"<<endl;
monitor.unlock();///felold
//lk.unlock();///ez is j�


}

}

class test{
    string ss="";
public:
    test(string ss_){ss=ss_;};
void f(string s){
cout<<ss<<s<<endl;

}

};



int main()
{
    cout << "Hello world!" << endl;

   /* int * a= new int(5);
    thread szal(func,a);
    func(a);
    szal.join();
*/

thread szal1(f,"1");///sz�lat �gy h�vsz f a f�ggv�ny minden m�s a param�ter ez a sor ut�n egyb�l fut.
thread szal2(f,"2");
thread szal3(f,"3");
test t("helo ");
thread szal4(test::f,&t,"asdasd");

string s;

while(true){
    monitor.lock();
        cout<<"pres any than enter"<<endl;
monitor.unlock();
cin>>s;
cout<<s<<endl;
monitor.lock();
monitor_c.notify_all();
monitor.unlock();



}





    cout<<"the end"<<endl;
    return 0;
}
