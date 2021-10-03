#ifndef LISTEXCEPTION_HPP_INCLUDED
#define LISTEXCEPTION_HPP_INCLUDED

#include <exception>

class UnderFlowException : public std::exception
{
    public:
        const char* what() const throw() { return "Alulcsordulas!"; }
};

class CurNullException : public std::exception
{
    public:
        const char* what() const throw() { return "Nincs aktualis elem kivalasztva!"; }
};

class InvalidIterator : public std::exception
{
    public:
        const char* what() const throw() { return "Ervenytelen iterator!"; }
};

#endif // LISTEXCEPTION_HPP_INCLUDED
