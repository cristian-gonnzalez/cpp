/** STL std::multiset (And how to compare non-trivial types) | Modern Cpp Series Ep. 123
 */
#include <iostream>
#include <set>
#include <algorithm>

/** Non trivial type example
  
std::multiset (see multiset.cpp):

template<
    class Key,                            
    class Compare = std::less<Key>,      We need to specify the ordering. In this example we do it
                                         by changing this template parameter. This means we create
                                         our own Compare function object (functor) and pass it as
                                         the second template argument.
    class Allocator = std::allocator<Key>                   ^
> class multiset;                                           |    
                                         bool operator()( const T& lhs, const T& rhs ) const;

*/
// Example helper class
struct Custom
{
    int field1;
    int field2;

    Custom(int _field1, int _field2)
    :field1{_field1}, field2{_field2}
    {
    }

    void print() const {
        std::cout << "(" << field1 << "," << field2 << ") = " << (field1 + field2);
    }
};

// In case that you dont have the ability to modify 
// the class, write a function object (functor) to 
// provide the comparison logic.
struct compare{

    // NOTE: For this to work, we need something callable.
    //       That's why we overload operator().
    //
    // IMPORTANT: The 'const' at the end is required. A comparator must
    //            not modify the objects it compares. Without 'const',
    //            a compilation error would occur.
    bool operator()(const Custom& lhs, const Custom& rhs) const 
    {                                                  // ~~~~~
        int lhs_sum = lhs.field1 + lhs.field2;
        int rhs_sum = rhs.field1 + rhs.field2;

        return lhs_sum < rhs_sum;
    }
};


void _test( auto s )
{
    // Create several Custom values. c1 and c2 have equal sums.
    Custom c0(1, 6);
    Custom c1(2, 7);
    Custom c2(3, 6);  // Same sum as c1 (9)
    Custom c3(9, -5);

    s.insert(c0);
    s.insert(c1);
    s.insert(c2);
    s.insert(c3);

    std::cout << "[";
    std::for_each(s.begin(), s.end(), 
                [](const Custom& cdt)
                {
                    cdt.print();
                    std::cout << ", ";
                });
    std::cout << "]\n"; 
}

int main()
{
    std::set<Custom, compare> s;
    std::multiset<Custom, compare> ms;
                     //   ~~~~~~~
                     // Pass the Compare functor as a template parameter.
                     // Note: We could also use a lambda instead of a struct.
                   
    _test( s );   // [(9,-5) = 4, (1,6) = 7, (2,7) = 9, ]
    _test( ms );  // [(9,-5) = 4, (1,6) = 7, (2,7) = 9, (3,6) = 9, ] 
    
    return 0;
}