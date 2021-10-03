/*
 * graf.hpp
 *
 *  Created on: 2017. nov. 15.
 *      Author: Laci
 */


#ifndef GRAF_HPP_
#define GRAF_HPP_
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class graf
{
	struct keto
			{
				int suly;
				int kivel;
			};
	struct haz
	{
		int ID;
		vector<keto> kapcsik;
	};
	vector<int>raktarok;
	vector<haz>pontok;
	struct kamion
	{
	    int holvagyok;
	    int teherbiras;
	    vector<int> hova;
	};
	vector<kamion> k;
	vector<keto> rendeles;

public:
	graf(){};
	~graf(){};
	void beolvasom_graf(string filename);
	void beolvasom_szimi(string filename);
	void szimulalok();
	int konnyu(vector<keto> v);
	int nehez();
	int itt_van_e(kamion& k);
	int rovid(kamion& k);

};



#endif /* GRAF_HPP_ */
