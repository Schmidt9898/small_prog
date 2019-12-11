/*
 * skiplist.hpp
 *
 *  Created on: 2017. okt. 19.
 *      Author: Laci
 */
#ifndef SKIPLIST_HPP_
#define SKIPLIST_HPP_
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
using namespace::std;
/*TODU
void insert(x)*
void contains(x)*
void erase(x)
void size(x)
*/
class skiplist
{
private:
	class node
	{
	public:
		int adat;
		vector<node*> v;
		node(const int& adat0):adat(adat0){}
		~node(){
			//std::cout<<"meghaltam: "<<adat<<std::endl;
		}
	};
	node* head;
	node* tail;
	int meret=0;
public:
	skiplist(){
	    head = tail = nullptr;
		srand(time(0));
	};
	~skiplist();


vector<node*> magic(int x);
bool contains(int x);
void insert(int x);
int size();
void erase(int x);
void p();
};

vector<skiplist::node*> skiplist::magic(int x){
	node* akt=head;
	vector<skiplist::node*> v(10,nullptr);
	if(head!=nullptr){
	unsigned int i=9;
	while((i+1)!=0)
	{
		if(x<=akt->adat){
			v[i]=akt;
			i--;
		}
		else if(x>akt->adat){
			if(akt->v[i]!=nullptr and x>=akt->v[i]->adat){
			akt=akt->v[i];
			v[i]=akt;}
			else{
				v[i]=akt;
				i--;
			}
		}
	}}
return v;

}
bool skiplist::contains(int x)
{
	vector<skiplist::node*> v=this->magic(x);
	if(v[0]==nullptr)
        return (false);
    else
	return ((v[0]->adat)==x);
}
void skiplist::insert(int x)
{
	if(head==nullptr)
	{
		node* uj=new node(x);
		for(unsigned int i=0;i<10;i++)
					{
						uj->v.push_back(nullptr);
					}
		head=tail=uj;
		meret++;
	}else{
        if(x<head->adat)
            {
                int kalman=head->adat;
                head->adat=x;
                this->insert(kalman);
            }
            else if(x>tail->adat)
                {
                    if(tail==head)
                    {
                        tail=new node(x);
                        for(unsigned int i=0;i<10;i++)
                            {
                                tail->v.push_back(nullptr);
                                head->v[i]=tail;
                            }
                            meret++;
                    }else{
                        int kalman=tail->adat;
                        tail->adat=x;
                        this->insert(kalman);
                        }
                }
                else if(!this->contains(x))
                {
                    vector<skiplist::node*> k=this->magic(x);
                    node* uj=new node(x);
                    uj->v.push_back(k[0]->v[0]);
                    k[0]->v[0]=uj;
                    int pali=rand()%2;
                    unsigned int i=1;
                    while(pali and i<10)
                    {
                        uj->v.push_back(k[i]->v[i]);
                        k[i]->v[i]=uj;
                        pali=rand()%2;
                        i++;
                    }
                    meret++;

	}}
}
int skiplist::size(){
	return meret;

}
void skiplist::erase(int x){
    if(head!=nullptr){
	vector<skiplist::node*> k=this->magic(x);
	if(k[0]->adat==x)
	{
		if(k[0]==head)
		{
		    if(head->v[0]!=nullptr)
            {
			node* p=head;
			head=head->v[0];
			for(unsigned int i=head->v.size();i<10;i++)
					{
						head->v.push_back(p->v[i]);
					}
					delete p;
					meret--;
            }else{
            delete head;
            head=nullptr;
            meret=0;
            }
		}else if(k[0]==tail)
		{
		    std::cout<<"???: "<<x<<std::endl;
		    node* p=tail;
		    k=this->magic((x-1));
		    tail=k[0];
		    for(unsigned int i=tail->v.size();i<10;i++)
					{
						tail->v.push_back(p->v[i]);
					}
            delete p;
            meret--;
		}
		else{
            node* p=k[0];
            k=this->magic((x-1));
            for(int i=0;i<p->v.size();i++)
                {
                    k[i]->v[i]=p->v[i];
                }
            delete p;
            meret--;
            }
	}}
}
skiplist::~skiplist()
{
	if(head!=nullptr)
    {
        node* akt=head;
        node* next=head->v[0];
        while(next!=nullptr)
            {
                delete akt;
                akt=next;
                next=akt->v[0];
            }
        delete akt;
	}
}
void skiplist::p()
{
	if(head!=nullptr){
	for(int i=0;i<10;i++){
    node* akt=head;
	node* next=head->v[i];
	while(next!=nullptr)
	{
		std::cout<<" "<<akt->adat<<" ";
		akt=next;
		next=akt->v[i];
	}
	std::cout<<" "<<akt->adat<<std::endl;
	}
	}
}



#endif /* SKIPLIST_HPP_ */
