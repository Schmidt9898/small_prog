/*
 * networksort.hpp
 *
 *  Created on: 2017. dec. 15.
 *      Author: Laci
 */

#ifndef NETWORKSORT_HPP_
#define NETWORKSORT_HPP_
#include <math.h>
#include "exception.hpp"
using namespace std;
template <typename T>
void rendezo_halozat(T *tomb, int meret)
{
    if (log2(meret)!=(int)log2(meret)) throw invalid_size();
    for (unsigned int j = 1; j < (unsigned int)meret; j*=2){
        for (unsigned int k = j; k >= 1; k/=2)
        {
            bool erre = true;
            unsigned int szam = 0;
            int szamolom = 0;
            for (unsigned int f = 0; f+k < (unsigned int)meret; f++)
            {
                if (szamolom==(int)k) szamolom=-k;
                szamolom++;
                if (szamolom<=0)
                continue;
                if (szam==j) {
                	erre=!erre;
                	szam=0;
            	}
                szam++;
                if (erre) {
                	if (tomb[f]>tomb[k+f])
                		swap<T>(tomb[f],tomb[k+f]);}
                else
                {
                	if (tomb[f]<tomb[k+f])
                		swap<T>(tomb[f],tomb[k+f]);
                }
            }
        }
    }
}



#endif /* NETWORKSORT_HPP_ */
