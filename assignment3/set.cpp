
#include "set.h"

int case_insensitive_cmp::operator( ) ( const std::string& s1, const std::string& s2 ) const
{
    size_t len = std::min(s1.length(), s2.length());
    for (size_t i = 0; i < len; ++i) {
        char c1 = std::tolower(static_cast<unsigned char>(s1[i]));
        char c2 = std::tolower(static_cast<unsigned char>(s2[i]));
        if (c1 != c2) {
            return (c1 < c2) ? -1 : 1;
        }
    }

    if (s1.length() == s2.length()) {
        return 0;
    } else {
        return (s1.length() < s2.length()) ? -1 : 1;
    }
}


const treenode* find( const treenode* n, const treenode::valtype& val )
{
    treenode::valcmp cmp;
    while (n != nullptr) {
        int compare = cmp(n->val, val);
        if (compare == 0) {
            return n;
        } else if (compare > 0) {
            n = n->left;
        } else {
            n = n->right;
        }
    }

    return nullptr;
}

treenode** find( treenode** n, const treenode::valtype& val )
{
    treenode::valcmp cmp;
    while (*n != nullptr) {
        int compare = cmp((*n)->val, val);
        if (compare == 0) {
            return n;
        } else if (compare > 0) {
            n = &((*n)->left);
        } else {
            n = &((*n)->right);
        }
    }

    return n;
}

size_t size( const treenode* n )
{
    if (n == nullptr) {
        return 0;
    }

    return 1 + size(n->left) + size(n->right);
}

size_t height( const treenode* n )
{
    if (n == nullptr) {
        return 0;
    }

    size_t left_height = height(n->left);
    size_t right_height = height(n->right);

    return 1 + std::max(left_height, right_height);
}

void deallocate( treenode* n )
{
    if (n != nullptr) {
        deallocate(n->left);
        deallocate(n->right);
        delete n;
    }
}


treenode* makecopy( const treenode* n ) 
{
    if (n == nullptr) {
        return nullptr;
    }

    treenode* newNode = new treenode(n->val);
    newNode->left = makecopy(n->left);
    newNode->right = makecopy(n->right);

    return newNode;
}


// Step to the right as long as possible. When we get
// stuck, we are in the rightmost node. Remove it, and
// return it. (Don't delete it.)
// *from cannot be the empty tree.

treenode* extractrightmost( treenode** from )
{
   while( (*from) -> right )
      from = & (*from) -> right;

   treenode* n = *from;
   *from = (*from) -> left;
   return n;
}

void print( std::ostream& out, const treenode* n, unsigned int indent )
{

   for( unsigned int i = 0; i != indent; ++ i )
      out << "|  "; 
   if(n)
   {
      out << ( n -> val ) << "\n";
      print( out, n -> left, indent + 1 );
      print( out, n -> right, indent + 1 ); 
   }
   else
      out << "#\n"; 
}


// Both the upperbound and the lowerbound are strict.
// We use pointers, so that they can be absent. 
// Of course, this is a tasteless way of dealing with partiality.

void checkbetween( const treenode* n, 
                   const treenode::valtype* lowerbound, 
                   const treenode::valtype* upperbound ) 
{
   treenode::valcmp cmp;

   while(n) 
   {
      if( lowerbound && cmp( *lowerbound, n -> val ) >= 0 ) 
      {
         std::cout << "value " << ( n -> val );
         std::cout << " is not above lower bound " << *lowerbound << "\n";
         throw std::runtime_error( "tree not correct" ); 
      }

      if( upperbound && cmp( *upperbound, n -> val ) <= 0 ) 
      {
         std::cout << "value " << ( n -> val );
         std::cout << "is not below upperbound " << *upperbound << "\n";
         throw std::runtime_error( "tree not correct" );  
      }

      checkbetween( n -> left, lowerbound, &( n -> val ));
      lowerbound = & ( n -> val );
      n = n -> right;
   }
} 


unsigned int log_base2( size_t s )
{
    if (s == 0) return 0;

    unsigned int log = 0;
    while (s > 1) {
        s >>= 1;
        ++log;
    }
    return log;
}

bool set::contains( const valtype& val ) const
{
    const treenode* result = find(tr, val);
    return result != nullptr;
}

 
bool set::insert( const valtype& val )
{
    treenode** current = find(&tr, val);
    if (*current == nullptr) {
        *current = new treenode(val);
        return true;
    } else {
        return false;
    }
}


bool set::remove( const valtype& val )
{
    treenode** target = find(&tr, val);
    if (*target == nullptr) {
        return false;
    }

    treenode* toRemove = *target; // node to remove

    if (toRemove->left == nullptr && toRemove->right == nullptr) {
        *target = nullptr;
    } else if (toRemove->left == nullptr || toRemove->right == nullptr) {
        treenode* child = (toRemove->left != nullptr) ? toRemove->left : toRemove->right;
        *target = child;
    } else {
        // approach A from slides
        treenode** pred = &toRemove->left;
        while((*pred)->right != nullptr) {
            pred = &((*pred)->right);
        }

        toRemove->val = (*pred)->val;
        treenode* temp = *pred;
        *pred = (*pred)->left;
        toRemove = temp;
    }

    delete toRemove;
    return true;
}


size_t set::size( ) const
{
   return ::size( tr );
}

size_t set::height( ) const
{
   return ::height( tr );
}

bool set::empty( ) const
{
    return tr == nullptr;
}

set:: ~set( )
{
    ::deallocate(tr);
    tr = nullptr;
}

void set::clear( )
{
    ::deallocate(tr);
    tr = nullptr;
}

set::set( const set& other ) :
    tr(nullptr)
{
    tr = makecopy(other.tr);
}


set& set::operator = ( const set& other )
{
    if (this != &other) {
        deallocate(tr);
        tr = makecopy(other.tr);
    }

    return *this;
}



void set::checksorted( ) const
{
   ::checkbetween( tr, nullptr, nullptr );
}


void set::print( std::ostream& out, unsigned int indent ) const
{
   ::print( out, tr, indent );
}

