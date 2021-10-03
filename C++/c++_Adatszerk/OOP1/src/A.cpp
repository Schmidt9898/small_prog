#include "A.h"

#include <iostream>

//Kezdoerteket kell addni a statikus valtozoknak!
std::string A::b1("public static std::string A::b1");
std::string A::b2("protected static std::string A::b2");
std::string A::b3("private static std::string A::b3");

A::A() :
		a1("public std::string A::a1"), a2("public std::string A::a2"), a3("public std::string A::a3") {
	std::cout << "Constructor A()" << std::endl;
}

A::A(std::string a1, std::string a2, std::string a3) :
		a1(a1), a2(a2), a3(a3) {
	std::cout << "Constructor A(std::string a1, std::string a2, std::string a3)" << std::endl;
}

A::~A() {
	std::cout << "Destructor ~A()" << std::endl;
}

void A::f1() {
	std::cout << "public void A::f1()" << std::endl;
}

void A::f2() {
	std::cout << "protected void A::f2()" << std::endl;
}

void A::f3() {
	std::cout << "private void A::f3()" << std::endl;
}

void A::g1() {
	std::cout << "public static void A::g1()" << std::endl;
}

void A::g2() {
	std::cout << "protected static void A::g2()" << std::endl;
}

void A::g3() {
	std::cout << "private static void A::g3()" << std::endl;
}
