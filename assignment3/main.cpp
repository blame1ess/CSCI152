
#include <random>
#include <algorithm>

#include "set.h"
#include "timetable.h"
#include "timer.h"


std::vector< int > randomvector( size_t sz ) 
{
   std::vector< int > res;
   for( size_t i = 0; i != sz; ++ i )
   {
      res. push_back( rand( ) ); 
   } 
   return res;
}

   
int main( int argc, char* argv[ ] )
{

#if 0
   // A few simple tests with std::string.
   set small;    // A small test tree.

   // Case-insensitive set, comparator testing
   small.insert("X");
   small.insert("x");

   std::cout << small << "\n";
   std::cout << small. height( ) << "\n";
   small. insert( "if" );
   std::cout << small. height( ) << "\n"; 
   small. insert( "thE" ); 
   std::cout << small. height( ) << "\n";
   small. insert( "vaLue" );
   std::cout << small << "\n";
   std::cout << small. height( ) << "\n";
   small. clear( );
   std::cout << "this is the tree: " << small << "\n";
   set small3 = small;
   std::cout << small3 << "\n";

   std::cout << small. contains( "Xx" ) << "\n";
   std::cout << small. contains( "vAlUe" ) << "\n";
#endif

#if 0
   //Some more tests with std::string:
   //Make sure that your set is case-insensitive.

   set small;
   small. insert( "oskemen" );
   std::cout << small.height() << std::endl;

   std::cout << small. contains( "kostanay" ) << "\n";

   small. insert( "atyrau" );
   small. insert( "nursultan" );
   small. insert( "Almaty" );
   small. insert( "shymkent" ); 
   small. insert( "almaty" ); 
   small. insert( "pavlodar" );

   small. insert( "PavloDar" ); 
   small. insert( "sHYmKeNt" );  
   std::cout << small << "\n";


   small. remove( "PavLoDar" );
   small. remove( "almaty" );
   std::cout << small. remove( "if" );

   std::cout << small << "\n";

   small. checksorted( );
   std::cout << small << "\n"; 
   std::cout << small. size( ) << "\n";

   /*If the numbers differ much, the tree is badly balanced.*/
   std::cout << "Height is " << small. height( );
   std::cout << " should be approximately " << log_base2( small. size( )) << "\n";
#endif 

#if 0
   // Measurements using int.

   timetable tab( std::string( "BST-based set" ));
   for( size_t s = 1000; s < 4096 * 1000; s = 2 * s )
   {
      std::cout << "----------------------------------------\n";

      // Create random test set of size s:

      std::vector< int > values = randomvector(s);
      std::cout << "z";
      
      //  Turn on if you want to see the test vector.

      bool i_want_to_see_the_test_vector = false;
      if( i_want_to_see_the_test_vector )
      {
         std::cout << "values: ";
         for( const auto& s : values )
            std::cout << s << " ";
         std::cout << "\n";
      }

      // Uncomment to see the performance of a badly balanced tree:

      bool i_want_to_see_the_bad_performance_of_an_unbalanced_tree = false; 
      if( i_want_to_see_the_bad_performance_of_an_unbalanced_tree )
      { 
         std::sort( values. begin( ), values. end( ));
      }
      set someset1;

      timer tt; 
      size_t nr_insertions = 0;
      size_t nr_deletions = 0;

      for( size_t i = 0; i != values. size( ); ++ i ) 
      {
         nr_insertions += someset1. insert( values[i] );
      }

      // We do some deletions too:

      for( const auto& s : values )
      {
         // Remove the odd values:

         if( s & 1 )
            nr_deletions += someset1. remove( s );

         nr_deletions += someset1. remove( s + 2 );  // Probably not there.
      }
    
      // std::cout << someset1 << "\n";
      std::cout << nr_insertions << " " << nr_deletions << "\n";

      auto someset2 = someset1;

      if( nr_insertions - nr_deletions != someset2. size( )) 
      {
         std::cout << "nr = " << nr_insertions << "\n";
         std::cout << "size( ) = " << someset2. size( ) << "\n"; 
         throw std::runtime_error( 
                       "something went wrong with counting insertions" );
      }

      // Don't use size( )! It is O(n), and will mess up your performance. 

      tab. insert( s, tt. time( )); 

      std::cout << "number of insertions " << nr_insertions << "\n";
      std::cout << "number of deletions " << nr_deletions << "\n"; 
      std::cout << "tree-height = " << someset2. height( ) << ", " << "log_base2 = " << log_base2( someset2. size( )) << "\n";

      std::cout << "finished test for " << s << "\n";
   } 

   std::cout << tab << "\n"; 
   std::cout << "totaltime " << tab. totaltime( ) << "\n";
#endif

#if 1
    timetable tab("BST-based set");
    for (size_t s = 1000; s <= 256000; s *= 2) {
        set testSet;
        timer t;
        std::vector<int> values = randomvector(s); // For string, adjust accordingly.

        // Optional: sort values for unbalanced tree measurement.
        // std::sort(values.begin(), values.end());

        for (size_t i = 0; i != values.size(); ++i) {
            testSet.insert(values[i]);
        }

        tab.insert(s, t.time());
        // Optionally, check and document the height vs log_base2(size) comparison here.
    }
    std::cout << tab << "\n";
#endif

#if 0
    // test for calibrating remove function
    set small;

    for (int i = 1; i < 100; ++i) {
        small.insert(i);
    }
    small.remove(1);
    std::cout << small;

    // removing everything from tree including values not exist
    for (int i = 0; i < 120; ++i) {
        small.remove(i);
    }
    std::cout << small;

    small.insert(5);
    small.insert(3);
    small.insert(6);
    small.insert(4);
    small.insert(2);
    small.remove(5);
    std::cout << small;
#endif

#if 0
    //testing copy-constructor
    set originalSet;
    originalSet.insert("a");
    originalSet.insert("b");
    originalSet.insert("c");

    set copiedSet(originalSet);

    std::cout << "original set\n";
    std::cout << originalSet;
    std::cout << "copied set\n";
    std::cout << copiedSet;

    originalSet.remove("a");
    std::cout << "original set\n";
    std::cout << originalSet;
    std::cout << "copied set\n";
    std::cout << copiedSet;

    std::cout << originalSet.contains("c") << std::endl;
    std::cout << copiedSet.contains("c") << std::endl;

#endif

#if 0
    // copy constructor check
    set orgSet;
    orgSet.insert("ff");
    orgSet.insert("cc");
    set copySet = orgSet;
    std::cout << copySet;

    //assignment operator check
    set original;
    original.insert("a");
    original.insert("b");
    original.insert("c");
    original = original;
    std::cout << original;

    set copy;
    copy = original;
    std::cout << copy;

    copy.remove("a");
    std::cout << original;
    std::cout << copy;
#endif

    return 0;
}

/*
 * Performance table of BST-based set (inputsize/runtime in seconds):
     1000/1.7300e-04     2000/3.8600e-04     4000/6.3700e-04     8000/1.2430e-03     16000/2.8940e-03     32000/6.9920e-03     64000/1.5419e-02     128000/2.5691e-02     256000/5.8683e-02
 *
 *
*/

