#ifndef LISTEXCEPTION_HPP_INCLUDED
#define LISTEXCEPTION_HPP_INCLUDED

#include <exception>

using namespace std;

class invalid_size : public exception
{
    public:
        const char* what() const throw() { return "Helytelen méret!"; }
};

#endif // LISTEXCEPTION_HPP_INCLUDED
