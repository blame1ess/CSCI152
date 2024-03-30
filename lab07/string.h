
#ifndef CSCI152_STRING_
#define CSCI152_STRING_

#include <string>
#include <algorithm>
#include <iostream>

namespace csci152
{

   class string
   {
      size_t cap; 
      size_t sz;

      char* data; 
         // INVARIANT: Either cap == 0, sz == 0, and data == nullptr, 
         //   or 
         // cap != 0, sz <= cap, and data is a pointer to a heap memory
         // segment of size cap. 
         // 
         // We are not sharing our allocated data with any other data 
         // structure. We also preserve the global variant: All 
         // allocated blocks of memory 
         // are reachable from a live variable through valid pointer
         // applications. 

      void ensure_capacity( size_t c );
         // Ensure that cap >= c. 
 
   public: 
      // We only have moving constructors and assignment operator:

      string( ) noexcept; 
      string( string&& s ) noexcept;
      string& operator = ( string&& s ) noexcept;
      ~string( ) noexcept;

      void push_back( char c );
      void pop_back( );
      void push_back( const char* s );
      
      void clear( ); 
      size_t size( ) const;
      bool empty( ) const;  

      void print( std::ostream& out ) const;

      using iterator = char* ;
      using const_iterator = const char* ;

      iterator begin( ) { return data; }
      iterator end( ) { return data + sz; }
      const_iterator begin( ) const { return data; }
      const_iterator end( ) const { return data + sz; }

      friend int main( int argc, char* argv[] );
   }; 

   inline std::ostream& operator << ( std::ostream& out, const string& str )
   {
      for( char c : str )
         out. put(c); 
      return out;
   }
}

#endif


