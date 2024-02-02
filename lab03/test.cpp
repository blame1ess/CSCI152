
#include <iostream>

#include "date.h"

int main( int argc, char* argv [ ] )
{
   date d1 = date( 1995, 3, 8 );
   date d2 = date( 1995, 3, 8 );
   std::cout << (d1 == d2) << " " << (d1 <= d2) << " " << (d2 <= d1) << "\n";
   // Must print 1 1 1

   d1 = date( 2000, 5, 12 );
   d2 = date( 2000, 3, 7 );
   std::cout << (d1 == d2) << " " << (d1 <= d2) << " " << (d2 <= d1) << "\n";
   // Must print 0 0 1

   d1 = date( 1991, 3, 8 );
   d2 = date( 1990, 5, 12 );
   std::cout << (d1 == d2) << " " << (d1 <= d2) << " " << (d2 <= d1) << "\n";
   // Must print 0 0 1

   std::cout << "\n";
   std::cout << ( d1 == d2 ) << " " << ( d1 != d2 ) << "\n";
   std::cout << ( d1 < d2 ) << " " << ( d1 > d2 ) << "\n";
   std::cout << "\n";

   std::cout << date( 2024,12,31 ). days1jan( ) << "\n";
   std::cout << date( 2024,1,1 ). days1jan( ) << "\n";
   std::cout << date( 2021,3,8 ). days1jan( ) << "\n";
   std::cout << "\n";

   for( unsigned int i = 0; i < 365; ++ i )
   {
      d1 = { 1992, 1, 1 };
      d2 = d1;
      d2. setdays1jan(i);
      if( d2. days1jan( ) != i )
         throw std::logic_error( "something went wrong with day counting" );
   }

   unsigned int totaldays = 0;
   for( unsigned int i = 0; i < 10000; ++ i )
   {
      totaldays += date::daysinyear(i);
   }
   std::cout << "average length of year = " << totaldays / 10000.0;
   // Astronomically correct is 365.2422 

   std::cout << "\n\n";

   std::cout << "Astana has been called Nursultan for ";
   std::cout << date( 2022, 9, 17 ) - date( 2019, 3, 23 ) << " days\n";

   std::cout << "The DDR has existed for ";
   std::cout << date( 1990, 10, 3 ) - date( 1949, 10, 7 ) << " days\n";

   // Turn this on for thorough testing: 

   if constexpr( true )
   {
      date startdate = { 1991, 12, 16 };
      for( int i1 = -1000; i1 != 1000; ++ i1 )
      {
         for( int i2 = -1000; i2 != 1000; ++ i2 ) 
         {
            auto d1 = startdate + i1;
            auto d2 = startdate + i2;
        
            if( d1 - startdate != i1 || startdate - d1 != -i1 )
               throw std::logic_error( "problem with d1" );
            if( d2 - startdate != i2 || startdate - d2 != -i2 )
               throw std::logic_error( "problem with d2" );
            if( d2 - d1 != i2 - i1 )
               throw std::logic_error( "difference is wrong" );
         } 
      }
   }

   std::cout << date( 1900, 1, 1 ). getweekday( ) << "\n";
      // Monday. 
   std::cout << date( 2024, 2, 1 ). getweekday( ) << "\n";
      // Deadline of thie exercise, Thursday.
   std::cout << date( 1959, 2, 3 ). getweekday( ) << "\n";
      // the day the music died, Tuesday. 

   std::cout << date( 1969, 7, 20 ). getweekday( ) << "\n";
      // First moon landing, Sunday. 
   std::cout << date( 1991, 12, 16 ). getweekday( ) << "\n";
      // Independence of Kazakhstan, Monday. 
   std::cout << date( 1961, 4, 12 ). getweekday( ) << "\n";
      // Space flight of Yuri Gagarin, Wednesday. 

   return 0;
}

