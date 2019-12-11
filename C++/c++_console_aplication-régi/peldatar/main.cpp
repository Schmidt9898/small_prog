#include <iostream>

using namespace std;
int *fv(int* tomb,unsigned int meret)
{
    int* t=new int[meret];
    int temp=0;
    for(int i=0;i<meret;i++)
    {
        temp=tomb[i]*2;
        if((temp%10)!=0)
        {
            t[i]=temp;
        }
        else
        t[i]=tomb[i];

    }

    return t;
}
int atlagolo(int* tomb,unsigned int meret)
{
    int atlag=0;
    for(unsigned int i=0;i<meret;i++)
    {
        atlag+=tomb[i];
    }
    atlag/=meret;
    return atlag;
}
int main()
{
    int meret=0;
    cin>>meret;
    int* tomb=new int[meret];
    int temp=2;
    for(int j=0;j<meret;j++)
    {
  bool isPrime = true;

  for(int i = 2; i <= temp / 2; ++i)
  {
      if(temp % i == 0)
      {
          isPrime = false;
          temp++;
          break;
      }
  }
  if (isPrime)
  {
      tomb[j]=temp;
      temp++;
  }
    }
    for(int i=0;i<meret;i++)
    {
        cout<<tomb[i]<<" ";

    }
    cout<<"\n";
    return 0;
}
