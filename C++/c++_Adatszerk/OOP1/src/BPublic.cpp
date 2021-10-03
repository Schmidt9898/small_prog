#include "BPublic.h"
#include <iostream>

BPublic::BPublic() {
	std::cout << "Constructor BPublic()" << std::endl;
}

BPublic::~BPublic() {
	std::cout << "Destructor ~BPublic()" << std::endl;
}

void BPublic::h() {
	//A protected fuggvenyei, valtozoi elerhetok
	f2();
	g2();

	/*A privat resze viszont mar nem, forditasi hiba lesz, ha kiszedjuk a kommentet
	 f3 ();
	 g3 ();
	 //*/
}
