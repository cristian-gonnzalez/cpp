#include <iostream>

/*
Associative containers:
----------------------

Changing comparison:
-------------------

template<
    ....,                 
    class Compare = std::less<Key>, 
    .....
>
                 
	- The comparison function object (functor) can be customized by supplying a comparator 
'functor' or 'function object' as the Compare template parameter:

struct MyCompare {
    bool operator()(int a, int b) const {
        return a > b;                 // reverse ordering example
    }
};

std::set<int, MyCompare> s;                                            


	- When the Key type is a 'user-defined type', you must provide a way to
compare keys. This can be done in one of two ways:


		1. Provide a comparator functor (recommended when you cannot modify 
		the class)

		       std::map<UDT, int, MyCompare> m;
		                ~~~
		                Key 

		2. Overload 'operator<'' in the class definition (only if you own 
		the type)

		       struct UDT {
		           int age;
		           bool operator<(const UDT& other) const {
		               return age < other.age;
		           }
		       };

		       std::map<UDT, int> m;
		                ~~~
		                Key 
*/


int main()
{
	return 0;
}
