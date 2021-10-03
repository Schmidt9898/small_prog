#include <iostream>

using namespace std;

class parent
{

   public: void ask_child_to_do_thing()
   {

       cout<<"Parent: Child do the cleaning! \n Child: "<<do_my_thing()<<endl;
   };

   /// protected: virtual string do_my_thing()=0;  // - legyen m�s
   protected: virtual string do_my_thing(){return "Yes, I am doing it.";};  ///ez az �s r�sz
};

class child : public parent
{

     protected: string do_my_thing()    /// ITT fel�l defini�ljuk az �s r�szt, ha az �s =0 nullpointer lenne akkor is ez t�rt�nik csak a null�t �rjuk fel�l
   {

       return "You have no control over me.";
   };
};

int main()
{
    parent * fater_with_teenager=new parent();
    parent * child_who_is_older_than_18=new child();
    cout << "N�zz�k az alap esetet ahol a gyerek m�g kiskor�:" << endl<<endl;
    fater_with_teenager->ask_child_to_do_thing();

    cout << endl<<"N�zz�k meg mi lesz ha a gyerek bet�lti a 18-at:" << endl<<endl;
    child_who_is_older_than_18->ask_child_to_do_thing();

    return 0;
}
