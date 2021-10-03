#include "BPrivate.h"
#include <iostream>

BPrivate::BPrivate() {
	std::cout << "Constructor BPrivate()" << std::endl;
}

BPrivate::~BPrivate() {
	std::cout << "Destructor ~BPrivate()" << std::endl;
}

void BPrivate::h() {
	f1();
	g1();
	std::cout << a1 << std::endl;
	std::cout << b1 << std::endl << std::endl;
}
