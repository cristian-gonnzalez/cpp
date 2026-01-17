#include <iostream>

/*
Unordered associative containers: (since C++11)
--------------------------------

Changing Key equality:
-----------------------

template<
    .....                                                        
    class KeyEqual = std::equal_to<Key>,         -> Used to determine whether two keys in the *same bucket* are equal.
>;                                                  

    bool operator()(const Key& a, const Key& b) const;

           
	- The KeyEqual function object (functor) can be customized by supplying a 
custom 'function object' as the KeyEqual template parameter:

        struct MyEqual {
            bool operator()(int a, int b) const {
                return a == b;
            }
        };

        std::unordered_set<int, std::hash<int>, MyEqual> s;


	- When the Key type is a 'user-defined type', you must provide a way to
compare keys. This can be done in one of two ways:


		1. Provide a equality functor (recommended when you cannot modify 
		the class)

		       std::unordered_map<UDT, MyHash, MyKeyEqual> m;
					              ~~~          ~~~~~~~~~~
					              Key 

		2. Overload 'operator==' in the class definition (only if you own 
		the type)

		        struct UDT {
		            int age;
		            bool operator==(const UDT& other) const {
		                return age == other.age;
		            }
		        };

		        std::unordered_set<UDT, MyHash> s;

*/

int main()
{
    return 0;
}