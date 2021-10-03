#include <iostream>
#include "A.h"
#include "BPublic.h"
#include "BProtected.h"
#include "BPrivate.h"
#include "CPublic.h"
#include "CProtected.h"
#include "CPrivate.h"


using namespace std;


int main() {
    cout << "OOP1" << endl;

    //* Lathatosag tesztelese
    {
        A a;

        //* publikus fuggvenyeket es mezoket kivulrol is elerunk.
		a.f1();
		A::g1();
		cout << a.a1 << endl;
		cout << A::b1 << endl;
        //*/

        // protected es private fuggvenyeket vagy mezoket viszont nem. A kovetkezo blok minden sorara forditasi hibat kapunk!
//		a.f2();
//		a.f3();
//		A::g2();
//		A::g3();
//		cout << a.a2 << endl;
//		cout << a.a2 << endl;
//		cout << A::b2 << endl;
//		cout << A::b3 << endl;
    }
    //*/

    // Publikus orokles
	/*{
		BPublic b;

		//A-tol orokolt publikus fuggvenyek, valtozok tovabbra is elerhetok.
		b.f1();
		BPublic::g1();
		cout << b.a1 << endl;
		cout << BPublic::b1 << endl << endl;

		cout << "Egy BPublic tipusu objektumbol viszont el lehet erni az A-tol orokolt protected dolgokat is" << endl << endl;
		b.h();

		cout << "Es termeszetesen az orokosebol is..." << endl;
		CPublic c;
		c.hh();
	}*/
    //

    /*// Protected orokles
	{
		BProtected b;

		//A-tol orokolt publikus fuggvenyek, itt mar nem erhetoek el... forditasi hiba!
		//b.f1 ();
		//BProtected::g1 ();
		//cout<<b.a1<<endl;
		//cout<<BProtected::b1<<endl<<endl;

		cout << "Egy BProtected tipusu objektumbol viszont el lehet erni az A-tol orokolt protected es publikus dolgokat" << endl << endl;
		b.h();

		cout << "BProtected orokosebol meg mindig el lehet erni az A-tol orokolt public es protected dolgokat!" << endl << endl;
		CProtected c;
		c.hh();
	}
    //*/

    /*// Private orokles
	{
		BPrivate b;

		cout << "Egy BPrivate tipusu objektumbol szinten lehet erni az A-tol orokolt protected es publikus dolgokat" << endl << endl;
		b.h();

		cout << "Visztont BPrivate orokosebol mar nem erheto el kozvetlen A-nak egy adattagja vagy fuggvenye sem!" << endl << endl;

		CPrivate c;
		c.hh();
	}
    //*/

    return 0;
}
