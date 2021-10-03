#ifndef A_H
#define A_H

#include <string>

class A {
public:
	//a publikus adattagokat es fuggvenyeket kivulrol is el lehet erni
	A();
	A(std::string a1, std::string a2, std::string a3);
	virtual ~A();

	std::string a1;
	void f1();

	static std::string b1; //ez egy osztalyszintu valtozo, amit barhonnan elerhetunk
	static void g1(); //ez egy osztaly szintu metodus, amit barhonnan meghivhatunk

protected:
	//a kovetkezo membereket es fuggvenyeket csak az A tipusu vagy annak leszarmazottjai erik el
	std::string a2;
	void f2();

	static std::string b2;
	static void g2();

private:
	//ezen blokk tartalmat csak A tipusu oobjektumok erik el
	std::string a3;
	void f3();

	static std::string b3;
	static void g3();
};

#endif // A_H
