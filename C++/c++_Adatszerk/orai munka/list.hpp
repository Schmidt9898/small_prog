#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include "listexception.hpp"
#include <iostream>
//#include "listexception.hpp"
using namespace::std;
class List
{
    private:
        class Node  /// A szerkezetet felépítő belső osztály, kívülről nem látszik
        {
            public:
                int data;         //Az eltárolt érték
                Node *prev;       //Az előző elemre mutató pointer
                Node *next;       //A következő elemre mutató pointer

                Node(const int& data0) : data(data0), prev(NULL), next(NULL) {} //Konstruktor, ami beállít egy értéket, és lenullázza a mutatókat
                Node(const int& data0, Node* prev0,Node* next0)
                 : data(data0),prev(prev0),next(next0) {}   //Konstuktor, ami beállítja az értéket, és beállítja a mutatókat
        };
        Node *head;               //A lista elejére mutató pointer
        Node *tail;               //A lista végére mutató pointer
        Node *cur;                //A lista aktuális elemére mutató pointer

    public:
        List();                   //Üres lista konstruktor
        ~List();                  //Lista destruktor

        /// Az aktuális (cur) elemet befolyásoló metódusok
        void toFirst();           //Az első elemre ugrik
        void toLast();            //A második elemre ugrik
        void stepNext();          //Hátra lép egy elemet  (A lista vége felé halad)
        void stepPrev();          //Előre lép egy elemet  (A lista eleje felé halad)
        int getValue() const;     //Az aktuális elemben tárolt értéket adja vissza
        void setValue(int e);     //Az aktuális elem értékét módosítja

        /// A lista állapotát lekérdező metódusok
        bool isEmpty() const;     //Üres-e a lista?
        bool isLast() const;      //A lista aktuális mutatója az utolsó elemen áll-e?
        bool isFirst() const;     //A lista aktuális mutatója az első helyen áll-e?
        bool isCurNull() const;   //A lista aktuális mutatója mutat-e elemre?

        /// Beszúró metódusok
        void insertFirst(int e);  //Új elem hozzáfűzése a lista elejéhez
        void insertLast(int e);   //Új elem hozzáfűzése a lista végéhez
        void insertBefore(int e); //Elem beszúrása az aktuális elem elé
        void insertAfter(int e);  //Elem beszúrása az aktuális elem mögé

        /// Törlő metódusok
        void removeFirst();       //A lista első elemének törlése
        void removeLast();        //A lista utolsó elemének törlése
        void removeCur();         //Az aktuális elem törlése

        /// Kiegészítő eljárás
        void print() const;     //kiíratás
        //Nem része a lista adatszerkezetnek, csak nekünk segítség!
};

/// ----- Most következnek a metódus implementációk ----- ///
//Alap konstruktor, üres listát hoz létre
List::List()
{
    head = tail = cur = NULL; //A mutatókat mind NULL-ra állítjuk
}

//Destructor
List::~List()
{
    while(!isEmpty())      //Amíg van elem a listában,
        removeLast();   //addig kiszedjük az utolsó elemet
}

/// Az aktuális (cur) elemet befolyásoló metódusok implementációi
//Az aktuális elemet az elsõ lista elemre állítja
void List::toFirst()
{
    cur = head;         //Az aktuális mutasson az első elemre
}

//Az aktuális elemet az utolsó lista elemre állítja
void List::toLast()
{
    cur = tail;         //Az aktuálsi mutasson az utolsó elemre
}

//Az aktuális mutatót (ha nem NULL az értéke) egy elemmel hátrébb állítja
//Vegyük észre, hogy ez az eljárás NULL-á teheti az cur-t! (Ha cur = tail volt)
void List::stepNext()
{
    if(cur)              //Ha az aktuális mutató érvényes elemre mutat
        cur = cur->next; //akkor az aktuálist egyel hátrább léptetjük
       // if(cur==tail){UnderFlowException();}
}

//Az aktuális mutatót (ha nem NULL az értéke) egy elemmel előrébb állítja
//Vegyük észre, hogy ez az eljárás NULL-á teheti az cur-t! (Ha cur = head volt)
void List::stepPrev()
{
    if(cur)              //Ha az aktuális mutató érvényes elemre mutat
        cur = cur->prev; //akkor az aktuálist egyel előrébb léptetjük
}

//Visszaadja az aktuális elem értékét
int List::getValue() const
{
    if(isEmpty()){ //Ha üres a lista
        throw(UnderFlowException());} //akkor egy UnderFlowException-t dobunk
    if(!cur) {           //Ha nem üres, mert nem dobtunk kivételt, de az cur = NULL
        throw(CurNullException());
        // return 0;
        }  //akkor egy CurNullException-t dobunk
    return cur->data;   //Ha minden rendbe, mert nem volt kivétel, akkor visszadjuk az aktuális elem értékét
}

//Beállítjuk az aktuális elem értékét
void List::setValue(int e)
{
    if(isEmpty()) {    //Ha üres a lista
        throw(UnderFlowException());} //akkor egy UnderFlowException-t dobunk
    if(!cur)            //Ha nem üres, mert nem dobtunk kivételt, de az cur = NULL
        throw(CurNullException());   //akkor egy CurNullExceptiont dobunk
    cur->data = e;      //Ha minden rendben, akkor be tudjuk állítani az aktuális elem értékét
}

/// A lista állapotát lekérdező metódusok implementációi
//Megvizsgálja, hogy üres-e a lista (TRUE: ha üres, FALSE: ha nem üres)
bool List::isEmpty() const
{
    return head == NULL;    //Visszaadjuk, hogy a head NULL-e, mert az csak akkor NULL, ha üres a lista.
}

//Megvizsgálja, hogy az aktuális elem-e az utolsó (TRUE: ha igen, FALSE: ha nem)
bool List::isLast() const
{
    return cur == tail;     //Ha a két mutató megegyezik, akkor az aktuális elem az utolsó
}

//Megvizsgálja, hogy az aktuális elem-e az első (TRUE: ha igen, FALSE: ha nem)
bool List::isFirst() const
{
    return cur == head;     //Ha a két mutató megyegyezik, akkor az aktuális elem az első
}

//Megvizsgáljuk, hogy a lista végén vagyunk-e (TRUE: ha igen, FALSE: ha nem)
bool List::isCurNull() const
{
    return cur == NULL;     //Visszaadjuk, hogy az cur == NULL igaz-e
}

/// Beszúró metódusok implementálása
//A lista elejére szúrja be a paraméterben kapott új értéket

/// Kiegészítő eljárás implementálása
//Kiírja konzolra a lista tartalmát az elejérõl a végéig haladva
void List::print() const
{
    //Egy i pointer fut végig az elemeken, amíg a tail után ki nem fut a listából
    for(Node* i=head; i!=NULL; i=i->next)
        cout << i->data << ", ";   // és kiírja az aktuális elem értékét
    cout << endl;                  // !Ez a sor már nem tartozik a for ciklushoz!
}
void List::insertFirst(int e)
{
	if(head==nullptr){
		Node* p=new Node(e);
		head=cur=tail=p;

	}else
	{
		Node* p=new Node(e,head->prev,head);
		head->prev=p;
		cur=head=p;
	}
}
void List::insertLast(int e)
{
	if(head==nullptr){
		this->insertFirst(e);
	}else
	{
		Node* uj=new Node(e,tail,nullptr);
		tail->next=uj;
		tail=uj;
	}
	cur=tail;
}
void List::insertAfter(int e)
{
	if(head==nullptr){
		this->insertFirst(e);
	}else
	{
		Node* uj=new Node(e,cur,cur->next);
		cur->next->prev=uj;
		cur->next=uj;
		cur=uj;
	}
}
void List::insertBefore(int e)
{
    if(!cur)
        throw(UnderFlowException());
	cur=cur->prev;
	if(!cur){
		this->insertFirst(e);
	}else
	{
		this->insertAfter(e);
	/*	Node* uj=new Node(e,cur,cur->next);
		cur->next=uj;
		cur->next->prev=uj;
		cur=uj;*/
	}
}
void List::removeFirst()
{
	if(head==nullptr){
		UnderFlowException();
	}else
	{
		Node* pill;
		pill=head;
		head=head->next;
		head->prev=nullptr;
		delete pill;
	}
}
void List::removeLast()
{
	if(!tail){
		UnderFlowException();
	}else
	{
		Node* pill;
		pill=tail;
		tail=tail->prev;
		if(tail)
            tail->next=nullptr;
        else
            head = tail;
        cur=tail;
		delete pill;
	}
}
void List::removeCur()
{
	if(head==nullptr){
		CurNullException();
	}else
	{
		if(cur==head){this->removeFirst();}
		else if(cur==tail){this->removeLast();}
		else{
		Node* pill;
		pill=cur;
		cur=cur->prev;
		cur->next=pill->next;
		pill->next->prev=cur;
		cur=cur->next;
		delete pill;
		}
	}
}


#endif // LIST_HPP_INCLUDED

