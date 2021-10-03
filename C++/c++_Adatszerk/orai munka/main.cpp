#include <iostream>
#include "list.hpp"
#include "listexception.hpp"
using namespace::std;
int main()
{
    try
    {
        List egeszek;

        cout << "--- Tegyunk bele par int-et a listaba! ---\n";
        cout << "Be: 0" << endl; egeszek.insertLast(0);
        cout << "Be: 1" << endl; egeszek.insertLast(1);
        cout << "Be: 1" << endl; egeszek.insertLast(1);
        cout << "Be: 2" << endl; egeszek.insertLast(2);
        cout << "Be: 3" << endl; egeszek.insertLast(3);
        cout << "Be: 5" << endl; egeszek.insertLast(5);
        cout << "Be: 8" << endl; egeszek.insertLast(8);

        cout << "\nA lista tartalma: " << endl;
        egeszek.print();

        cout << "\nAz aktualis elem ilyenkor az utolsonak betett elem" << endl;
        cout << "Cur: " << egeszek.getValue() << endl;

        cout << "\nAllitsuk az aktualis elemet az elso elemre" << endl;
        egeszek.toFirst();
        cout << "Cur: " << egeszek.getValue() << endl;

        cout << "\nLepjunk harmat elore (Harom stepNext utan): " << endl;
        egeszek.stepNext();
        egeszek.stepNext();
        egeszek.stepNext();
        cout << "Cur: " << egeszek.getValue() << endl;;

        cout << "\nAz aktualis elem torlesre kerul" << endl;
        egeszek.removeCur();
        cout << "Egyreszt eltunt a szam a listabol: " << endl;
        egeszek.print();
        cout << "Masreszt az aktualis elem a torolt utani lett: " << endl;
        cout << "Cur: " << egeszek.getValue();

        cout << "\n\nLegyen az aktualis az utolso elem" << endl;
        egeszek.toLast();
        cout << "Cur: " << egeszek.getValue();
        cout << "\nHa leptetek rajta egyet hatrafele, es megprobalom kiolvasni, akkor kivetelt fog dobni." << endl;
        egeszek.stepNext();
        //cout<<"nemár";
        cout << "Cur: " << egeszek.getValue() << endl;
    }
    catch(std::exception& e)
    {
        cout << "\n***HIBA tortent!*** " << e.what() << endl;
    }

    //Egy kis hibakezelés:
    cout << endl <<"\n\n--- Pelda nem csak kiiros kivetelkezelesre ---" << endl;
    List szamlista;
    szamlista.insertFirst(104);
    szamlista.insertFirst(105);
    szamlista.insertFirst(107);
    //Most elérjük, hogy az Cur NULL legyen, mivel most az elsö elemen van, ha visszaléptetem kikerül a listáról.
    szamlista.stepPrev();
    while(true) //Addig fut, amíg nem kap break; parancsot!
    {
        try
        {
            //Itt elsőre egy CurNullException kivételt fog dobni, mert nem mutat az Cur sehova
            cout << "Akt elem: " << szamlista.getValue() << endl;
            // ha nem volt exception akkor kilép a ciklusból!
            break;
        }
        catch(CurNullException& e)
        {
            cout << "Az Cur nem mutatott sehova!" << endl;
            szamlista.toFirst(); // Most már az első elemre mutat!
            //Itt nincs break, tehát újraindul a ciklus
        }
        catch(UnderFlowException& e)
        {
            cout << "Ures a lista!";
            break;
        }
    }

}
