#include "CPrivate.h"
#include <iostream>

CPrivate::CPrivate() {
	std::cout << "Constructor CPrivate()" << std::endl;
}

CPrivate::~CPrivate() {
	std::cout << "Destructor ~CPrivate()" << std::endl;
}

void CPrivate::hh() {
	//itt mar nem erunk el semmilyen A-tol orokolt dolgot!!! a kovetkezo sor kikommentelese forditasi hibat okoz!
	//std::cout<<a1<<std::endl;
}
