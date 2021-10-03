#include <iostream>

using namespace std;

class parent
{

   public: void ask_child_to_do_thing()
   {

       cout<<"Parent: Child do the cleaning! \n Child: "<<do_my_thing()<<endl;
   };

   /// protected: virtual string do_my_thing()=0;  // - legyen más
   protected: virtual string do_my_thing(){return "Yes, I am doing it.";};  ///ez az õs rész
};

class child : public parent
{

     protected: string do_my_thing()    /// ITT felül definiáljuk az õs részt, ha az õs =0 nullpointer lenne akkor is ez történik csak a nullát írjuk felül
   {

       return "You have no control over me.";
   };
};

int main()
{
    parent * fater_with_teenager=new parent();
    parent * child_who_is_older_than_18=new child();
    cout << "Nézzük az alap esetet ahol a gyerek még kiskorú:" << endl<<endl;
    fater_with_teenager->ask_child_to_do_thing();

    cout << endl<<"Nézzük meg mi lesz ha a gyerek betölti a 18-at:" << endl<<endl;
    child_who_is_older_than_18->ask_child_to_do_thing();

    return 0;
}
