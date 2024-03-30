
#include "string.h"
#include <utility>


csci152::string::string( ) noexcept :
    cap(0),
    sz(0),
    data(nullptr)
{ }


csci152::string::string( string&& s ) noexcept :
    cap(std::exchange(s.cap, 0)),
    sz(std::exchange(s.sz, 0)),
    data(std::exchange(s.data, nullptr))
{ }


csci152::string&
csci152::string::operator = ( csci152::string&& s ) noexcept
{
    if (this != &s) { // self-assignment check
        delete[] data;
        cap = std::exchange(s.cap, 0);
        sz = std::exchange(s.sz, 0);
        data = std::exchange(s.data, nullptr);
    }
    return *this;
}

void csci152::string::ensure_capacity( size_t c ) 
{
   if( cap < c )
   {
       if( cap == 0 )
       {
           cap = std::max(c, size_t(4));
           data = new char[cap];
       }
       else
       {
           //size_t new_cap = c + 1000;
           size_t new_cap = c * 2;
           //size_t new_cap = c * 3;

           char* new_data = new char[new_cap];
           std::copy(data, data + sz, new_data);

           delete[] data;
           data = new_data;
           cap = new_cap;
       }
   }
}


csci152::string::~string( ) noexcept
{
    delete[] data;
}


void csci152::string::push_back( char c )
{
    ensure_capacity(sz + 1);
    data[sz] = c;
    sz++;
}

void csci152::string::pop_back( )
{
    if (sz > 0) {
        sz--;
    }
}

void csci152::string::clear( )
{
    sz = 0;
}


size_t csci152::string::size( ) const
{
    return sz;
}

bool csci152::string::empty( ) const
{
    return sz == 0;
}


void csci152::string::push_back( const char* s )
{
    while (*s != '\0') {
        push_back(*s);
        ++s;
    }
}


