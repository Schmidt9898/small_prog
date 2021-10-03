#include "BProtected.h"
#include <iostream>

BProtected::BProtected() {
	std::cout << "Constructor BProtected()" << std::endl;
}

BProtected::~BProtected() {
	std::cout << "Destructor ~BProtected()" << std::endl;
}

void BProtected::h() {
	f1();
	g1();
	std::cout << a1 << std::endl;
	std::cout << b1 << std::endl << std::endl;
}
