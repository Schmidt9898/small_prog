#include "CPublic.h"
#include <iostream>

CPublic::CPublic() {
	std::cout << "Constructor CPublic()" << std::endl;
}

CPublic::~CPublic() {
	std::cout << "Destructor ~CPublic()" << std::endl;
}

void CPublic::hh() {
	f2();
}
