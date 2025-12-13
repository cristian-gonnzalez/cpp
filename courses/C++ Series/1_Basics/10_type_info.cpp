/** Types: typeid
 */
#include <iostream>
#include <typeinfo> // Allows us to inspect or see the actual types

int main()
{
    int x = 42;
    int& ref = x;
 
    std::cout << "x           : " << x << std::endl                // x           : 42
              << "type       x: " << typeid(x).name() << std::endl // type       x: i
              << "address_of x: " << &x << std::endl;              // address_of x: 0x7ffc7decb98c
     
    std::cout << "ref           : " << ref << std::endl                // ref           : 42
              << "type       ref: " << typeid(ref).name() << std::endl // type       ref: i
              << "address_of ref: " << &ref << std::endl;              // address_of ref: 0x7ffc7decb98c

    ref = 43;

    std::cout << "x           : " << x << std::endl                // x           : 43
              << "type       x: " << typeid(x).name() << std::endl // type       x: i
              << "address_of x: " << &x << std::endl;              // address_of x: 0x7ffc7decb98c
     
    std::cout << "ref           : " << ref << std::endl                // ref           : 43
              << "type       ref: " << typeid(ref).name() << std::endl // type       ref: i
              << "address_of ref: " << &ref << std::endl;              // address_of ref: 0x7ffc7decb98c
}