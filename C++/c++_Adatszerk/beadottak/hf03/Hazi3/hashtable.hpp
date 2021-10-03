/*
 * hashtable.hpp
 *
 *  Created on: 2017. dec. 2.
 *      Author: Laci
 */

#ifndef HASHTABLE_HPP_
#define HASHTABLE_HPP_
#include <list>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct sint
	{
		string value;
		int sorban;
	};
class HashTable
{
    std::vector<std::list<sint> > table ;
    int capacity ;

    int actualsize ;

public:
    HashTable(int capacity) :
        table(capacity),
        capacity(capacity),
        actualsize(0)
    {
    }

    int size()
    {
        return actualsize ;
    }

    bool empty()
    {
        return actualsize == 0 ;
    }

    void clear()
    {
        for (int i = 0; i < capacity; ++i)
        {
            table[i].clear() ;
        }

        actualsize = 0;
    }
    void insert(const sint & key)
    {
        int myHash = getHash(key.value) ;
        for (std::list<sint>::iterator it = table[myHash].begin(); it != table[myHash].end(); ++it)
        {
            if (it->value == key.value)
            {
                return ;
            }
        }
        table[myHash].push_back(key) ;
        ++actualsize ;
    }
    int find(const string & key)
    {
        int myHash = getHash(key) ;
        for (std::list<sint>::iterator it = table[myHash].begin(); it != table[myHash].end(); ++it)
        {
            if (it->value == key)
            {
                return it->sorban ;
            }
        }
        return -1 ;
    }
    void erase(const sint & key)
    {
        int myHash = getHash(key.value) ;
        for (std::list<sint>::iterator it = table[myHash].begin(); it != table[myHash].end(); ++it)
        {
            if (it->value == key.value)
            {
                table[myHash].erase(it) ;
                --actualsize ;
                return ;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < capacity; ++i)
        {
            std::cout << i << ": " ;
            for (std::list<sint>::iterator it = table[i].begin(); it != table[i].end(); ++it)
            {
                std::cout << it->value << " " ;
            }
            std::cout << std::endl ;
        }
    }

private:
    int getHash(const string & key)
    {
    	int i=0;
for(char c:key)
{
	i+=(int) c;
}
        return i % capacity ;
    }
} ;
#endif /* HASHTABLE_HPP_ */
