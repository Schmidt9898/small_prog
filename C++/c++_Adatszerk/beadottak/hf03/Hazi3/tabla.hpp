/*
 * tabla.hpp
 *
 *  Created on: 2017. nov. 27.
 *      Author: Laci
 */


#ifndef TABLA_HPP_
#define TABLA_HPP_
#include <vector>
#include <string>
#include "hashtable.hpp"
#include "exception.hpp"
using namespace std;

class db_table
{
	struct oszlop
	{
		string cim;
		vector<string> sor;
	};
	struct parok
	{
		string a="",b="";
	};
	vector<oszlop> tabla;
	int sor=0;
public:
void add_column(string name);
vector<string> column_names();
void add_row();
int row_count();
void set(string col, size_t row, string value);
string get(string col, size_t row);
db_table join(db_table& other,string cond);
int hash(string s);
int get_colum();
bool van_e(string nev)
{
	for(unsigned int i=0;i<tabla.size();i++)
		{
		if(tabla[i].cim==nev)
			return true;
		}
	return false;
}
void print()
{
	for(int j=0;j<sor;j++)
	{
	for(int i=0;i<tabla.size();i++)
	{
		cout<<tabla[i].sor[j]<<" | ";
	}
	cout<<endl;
	}
}
};

void db_table::add_column(string name)
{
	if(name=="")
		throw invalid_column_name();
for(char c:name)
{
	if(!(((int)c >=65 and (int)c<=90 )or((int)c>=97 and (int)c<=122)or((int)c>=48 and (int)c<=57)))
throw invalid_column_name();
}
for(unsigned int i=0;i<tabla.size();i++)
{
	if(tabla[i].cim==name)
		throw invalid_column_name();
}
	oszlop a;
	a.cim=name;
	for(int i=0;i<sor;i++)
	{
		a.sor.push_back("");
	}
	tabla.push_back(a);
}
vector<string> db_table::column_names()
{
	vector<string> v;
	for(unsigned int i=0;i<tabla.size();i++)
	{
		v.push_back(tabla[i].cim);
	}
	return v;
}
void db_table::add_row()
{
	for(unsigned int i=0;i<tabla.size();i++)
		{
			tabla[i].sor.push_back("");
		}
	sor++;
}
int db_table::row_count()
{
	return sor;
}
int db_table::get_colum()
{
	return tabla.size();
}
void db_table::set(string col, size_t row, string value)
{
	for(char c:value){
		if(c=='\0')
			throw invalid_value();
	}
	if(row>sor)
		throw invalid_index();
	for(unsigned int i=0;i<tabla.size();i++)
	{
		if(tabla[i].cim==col)
		{
			tabla[i].sor[row]=value;
			break;
		}
		if(tabla.size()-1==i)
			throw invalid_index();
	}
}
string db_table::get(string col, size_t row)
{
	if(row>sor)
		throw invalid_index();
	for(unsigned int i=0;i<tabla.size();i++)
	{
		if(tabla[i].cim==col)
		{
			return tabla[i].sor[row];
		}
		if(tabla.size()-1==i)
			throw invalid_index();
	}
	return 0;
}
db_table db_table::join(db_table& other, string cond)
{
	for(unsigned int i=0;i<this->tabla.size();i++)
	{
		if(other.van_e(this->tabla[i].cim))
			{throw invalid_condition();}
	}
	vector<parok> v;
	parok add;
	bool T=true;
	for(char c:cond)
	{
		if(c=='=' and !T)
			throw invalid_condition();
			if(c=='='){T=false;continue;}
			if(c==',' and add.a!="" and add.b!=""){
				if(!(this->van_e(add.a) and other.van_e(add.b)))
					throw invalid_condition();
				v.push_back(add);
				T=true;
				add.a="";
				add.b="";
				continue;
			}else if(c==',' and add.a=="" and add.b=="")
				throw invalid_condition();
			if(T)
			{
				add.a+=c;
			}else
			{
				add.b+=c;
			}
	}
	if(add.a=="" or add.b=="")
		throw invalid_condition();
	if(!(this->van_e(add.a) and other.van_e(add.b)))
						throw invalid_condition();
	v.push_back(add);
vector<string> sa,sb;
for(int j=0;j<sor;j++){
	string s="0";
	for(unsigned int i=0;i<v.size();i++)
		{
		s=s+this->get(v[i].a,j);
			s.push_back('\0');
		}
	sa.push_back(s);
}
for(int j=0;j<sor;j++){
	string s="0";
	for(unsigned int i=0;i<v.size();i++)
		{
		s=s+other.get(v[i].b,j);
		s.push_back('\0');
		}
	sb.push_back(s);
}
////////////////////////cond lebontása/////////////////////////////////
db_table uj;
for(int i=0;i<this->tabla.size();i++)
{
	uj.add_column(this->tabla[i].cim);
}
for(int i=0;i<other.tabla.size();i++)
{
	uj.add_column(other.tabla[i].cim);
}
HashTable htabla(sa.size());
sint siet;
for(unsigned int i=0;i<sa.size();i++)
{
	siet.sorban=i;
	siet.value=sa[i];
	htabla.insert(siet);
}
for(unsigned int i=0;i<sb.size();i++)
{
	int ott=htabla.find(sb[i]);
	if(ott!=-1)
	{
		uj.add_row();
		for(int k=0;k<this->tabla.size();k++)
		{
			uj.tabla[k].sor[uj.sor-1]=this->tabla[k].sor[ott];
		}
		for(int k=this->tabla.size();k<other.tabla.size()+this->tabla.size();k++)
			{
				uj.tabla[k].sor[uj.sor-1]=other.tabla[k-(this->tabla.size())].sor[i];
			}

	}
}
this->print();
other.print();
uj.print();
return (uj);


}

#endif /* TABLA_HPP_ */
