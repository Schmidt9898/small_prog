#include "CProtected.h"
#include <iostream>

CProtected::CProtected() {
	std::cout << "Constructor CProtected()" << std::endl;
}

CProtected::~CProtected() {
	std::cout << "Destructor ~CProtected()" << std::endl;
}

void CProtected::hh() {
	//itt meg el tudjuk erni A public es protected reszeit, ugyanis az BProtected protected reszebe kerult, amit ebbol az osztalybol siman elerunk.
	f1();
}
