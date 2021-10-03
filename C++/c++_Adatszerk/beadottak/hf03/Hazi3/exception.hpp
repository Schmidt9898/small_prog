#ifndef LISTEXCEPTION_HPP_INCLUDED
#define LISTEXCEPTION_HPP_INCLUDED

#include <exception>

using namespace std;

class invalid_column_name : public exception
{
    public:
        const char* what() const throw() { return "Helytelen nev!"; }
};

class invalid_index : public exception
{
    public:
        const char* what() const throw() { return "Nem letezo index!"; }
};

class invalid_value : public exception
{
    public:
        const char* what() const throw() { return "Ervenytelen feltetel!"; }
};

class invalid_condition : public exception
{
    public:
        const char* what() const throw() { return "Ervenytelen kondicio!"; }
};

#endif // LISTEXCEPTION_HPP_INCLUDED
