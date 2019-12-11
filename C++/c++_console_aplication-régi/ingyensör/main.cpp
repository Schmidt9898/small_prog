 #include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

while(true)
{
system("notepad");
cout << "\a";
FreeConsole();

}
return 0;
}
