
#include <iostream>
#include <vector>

#include "timetable.h"
#include "sorting.h"
#include "string.h"
#include "timer.h"
 
int main( int argc, char* argv[] )
{
 
#if 0
   timetable heap_times( "heapsort" );
   timetable quick_times( "quicksort from library" );
   timetable bubble_times( "bubblesort" );
   timetable insertion_times( "insertion sort" );

   // My experience from earlier, similar tasks is that doubling
   // is much more informative than adding a fixed step.

   for( size_t s = 2000; s < 130000; s *= 2 )
   { 
      std::vector<int> test = randomvector(s);

      { 
         auto v = test; timer t; heap_sort(v); 
         heap_times. insert( s, t. time( )); 
         std::cout << v << "\n";
      }

      {
         auto v = test; timer t; quick_sort(v); 
         quick_times. insert( s, t. time( ));
         std::cout << v << "\n";
      }

      {
         auto v = test; timer t; bubble_sort(v); 
         bubble_times. insert( s, t. time( ));
         std::cout << v << "\n";
      }
 
      {
         auto v = test; timer t; insertion_sort(v); 
         insertion_times. insert( s, t. time( ));
         std::cout << v << "\n";
      }
   }

   std::cout << heap_times << "\n";
   std::cout << quick_times << "\n";
   std::cout << bubble_times << "\n";
   std::cout << insertion_times << "\n";
   std::cout << "this is the total time: ";
   std::cout << heap_times.totaltime( ) + quick_times.totaltime( ) + 
                bubble_times.totaltime( ) + 
                insertion_times.totaltime( ) << "\n";

#endif

#if 1
   std::cout << "\n";
   std::cout << "measuring performance of string operations\n";

   timetable string_times( "string with multiplying/adding ensure_capacity" );
  
   unsigned int start = 1000000; 
   for( size_t s = start; s < 32 * start; s *= 2 )
   {
      timer t;
      csci152::string str; 
      for( size_t i = 0; i != s; ++ i )  
         str. push_back( 'a' + ( i % 26 ));

      while( str. size( ))
         str. pop_back( ); 
      
      string_times. insert( s, t. time( )); 
   }

   std::cout << string_times << "\n";
#endif

   return 0; 
}

/*
Performance table of heapsort (inputsize/runtime in seconds):
     2000/1.4100e-04     4000/2.1500e-04     8000/4.5500e-04     16000/9.7700e-04     32000/2.1660e-03     64000/4.6240e-03     128000/1.3426e-02

Performance table of quicksort from library (inputsize/runtime in seconds):
     2000/1.2500e-04     4000/2.0500e-04     8000/4.4900e-04     16000/9.9300e-04     32000/2.0500e-03     64000/4.4130e-03     128000/9.3180e-03

Performance table of bubblesort (inputsize/runtime in seconds):
     2000/3.1010e-03     4000/1.1759e-02     8000/4.6798e-02     16000/2.0708e-01     32000/1.4149e+00     64000/6.7212e+00     128000/2.8689e+01

Performance table of insertion sort (inputsize/runtime in seconds):
     2000/5.5600e-03     4000/2.3522e-02     8000/6.9532e-02     16000/2.6002e-01     32000/7.8715e-01     64000/2.2184e+00     128000/7.1840e+00

this is the total time: 4.7682e+01

As you can see, for input size 130000, the total time was 47.682 seconds.
O(n^2) : Insertion Sort and Bubble Sort
O(n * log(n)) : Heap sort and Quick Sort
 */

/*

 size_t new_cap = c + 1000 :
 measuring performance of string operations
Performance table of string with multiplying/adding ensure_capacity (inputsize/runtime in seconds):
     1000000/2.9333e-02     2000000/1.0037e-01     4000000/7.5634e-01     8000000/3.3228e+00     16000000/1.3762e+01

size_t new_cap = c * 2 :
 measuring performance of string operations
Performance table of string with multiplying/adding ensure_capacity (inputsize/runtime in seconds):
     1000000/2.8620e-03     2000000/5.1290e-03     4000000/1.1977e-02     8000000/1.7508e-02     16000000/3.0139e-02

 size_t new_cap = c * 3 :
 measuring performance of string operations
Performance table of string with multiplying/adding ensure_capacity (inputsize/runtime in seconds):
     1000000/2.8610e-03     2000000/4.7530e-03     4000000/1.1349e-02     8000000/1.6721e-02     16000000/2.9635e-02

 */


 
