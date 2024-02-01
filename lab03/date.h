
#ifndef DATE_
#define DATE_

#include <iostream>
#include <stdexcept>

struct date
{
   unsigned int year;
   unsigned int month;
   unsigned int day;

   static bool isleapyear( unsigned int y );

   static bool 
   ispossible( unsigned int year, unsigned int month, unsigned int day ); 

   // We have to decide what to do, when 
   // the user is attempting to construct an ill-defined date.

   date( unsigned int year,
         unsigned int month,
         unsigned int day )
      : year( year ), month( month ), day( day )
   {
      if( !ispossible( year, month, day ))
         throw std::range_error( "tried to construct impossible date" );
   }

   void print_usa( std::ostream& out ) const;
   void print_euro( std::ostream& out ) const;

   static unsigned int daysinyear( unsigned int year );
   static unsigned int daysinmonth( unsigned int year, unsigned int month );

   unsigned int days1jan( ) const; 
      // Number of days since 1st of January in our year.

   void setdays1jan( unsigned int nrdays );
      // Set month and day to the nrdays-th day of our year.

   bool operator == ( date other ) const;
   bool operator <= ( date other ) const; 

   date& operator += ( int diff );
   int operator - ( const date& other ) const; 

   const char* getweekday( ) const; 

};

inline bool operator != ( const date& d1, const date& d2 )
{
    return !(d1 == d2);
}

inline bool operator < ( const date& d1, const date& d2 )
{
    return (d1 <= d2) && !(d1 == d2);
}

inline bool operator > ( const date& d1, const date& d2 )
{
    return !(d1 <= d2) && !(d1 == d2);
}

inline bool operator >= ( const date& d1, const date& d2 )
{
    return !(d1 <= d2) || (d1 == d2);
}

inline std::ostream& operator << ( std::ostream& out, const date& d )
   { }

inline date& operator -= ( date& d, int x ) { return d += -x; }  
inline date operator + ( date d, int x ) { d += x; return d; }
inline date operator - ( date d, int x ) { d += -x; return d; }

#endif

