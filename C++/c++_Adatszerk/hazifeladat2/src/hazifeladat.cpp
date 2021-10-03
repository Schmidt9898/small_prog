
#include <iostream>
#include "graf.hpp"
using namespace std;

int main() {
	graf kicsi;
	kicsi.beolvasom_graf("small_graph.txt");
	kicsi.beolvasom_szimi("small_simulation.txt");
	kicsi.szimulalok();
	kicsi.beolvasom_graf("medium_graph.txt");
	kicsi.beolvasom_szimi("medium_simulation.txt");
	kicsi.szimulalok();

	return 0;
}
