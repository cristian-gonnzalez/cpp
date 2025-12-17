/** STL std::multiset (And how to compare non-trivial types) | Modern Cpp Series Ep. 123
 */
#include <iostream>
#include <set>
#include <algorithm>

/** 
Non trivial type example
 
    std::multiset (see multiset.cpp):

template<
    class Key,                            
    class Compare = std::less<Key>,   ---> We need to tell the ordering. In this case, we will do it 'in-class'  
                                           definition so this means we do not pass by template param list, we 
                                           overload the operator< (less-than).
    class Allocator = std::allocator<Key>
> class multiset;

*/


// Example helper class
struct Custom
{
    int field1;
    int field2;

    Custom(int _field1, int _field2)
    : field1{_field1}, field2{_field2}
    {
    }

    // Comparision
    //
    // In order to std::set/std::multiset have an order, we need a way to 
    // tell the ordering.
    //
    // Defining operator< allows std::less<Custom> (the default comparator
    // used by std::multiset) to establish an ordering without explicitly
    // providing a custom Compare type.
    //
    /** Less-than operator overload.
     * 
     *  rhs     right-hand side of the comparison.
     * 
     *  returns true if the left-hand side object is considered less than rhs. Otherwise, false.
     */
    bool operator<(const Custom& rhs) const {
        int lhs_sum = field1 + field2;
        int rhs_sum = rhs.field1 + rhs.field2;
        return lhs_sum < rhs_sum;
    }

    void print() const {
        std::cout << "(" << field1 << "," << field2 << ") = " << (field1 + field2);
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
    // As long as Custom defines operator<, we can use it in std::set/std::multiset 
    // with  the default comparator.
    std::set<Custom> s;
    std::multiset<Custom> ms;
        
    _test( s );   // [(9,-5) = 4, (1,6) = 7, (2,7) = 9, ]
    _test( ms );  // [(9,-5) = 4, (1,6) = 7, (2,7) = 9, (3,6) = 9, ] 
    
    return 0;
}