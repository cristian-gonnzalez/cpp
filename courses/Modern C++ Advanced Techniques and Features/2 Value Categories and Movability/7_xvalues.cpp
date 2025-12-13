/** Additional considerations - What is an xvalue?
 *
 */
#include <iostream>
#include <utility>

struct Type
{
};

//  What is an xvalue?
//
//  An 'xvalue' has identity, but it behaves like an rvalue
//                           
//    -------------------
//    |   ___________   |         
//    |  |  lvalue   |  |         
//    |  |___________|  |
// -------------------------------------------------------                 
// |  |   ___________   |          ___________           |
// |  |  |  xvalue   |  |         |  prvalue  |  rvalue  |
// |  |  |___________|  |         |___________|          | -> Type &&
// |  |                 |                                |    ~~~~~~~~
// -------------------------------------------------------      rvalue reference
//    |     glvalue     |             ^
//    -------------------             |
//            ^                       |
//            |                       | 
//        Has identity            No identity
//
//
//     - Has identity:
//              lvalue  - has identity, it is a variable. it has an address and lives on
//              xvalue  - an 'expiring value' -> has identity, it is a variable, it has an address but the
//                                       variable thinks that it's going to be destroyed momentally 
//
//                          Think of an xvalue as a casting expression: it is simply an expression that refers
//                        to an existing object but says 'treat this object as movable' to enable move semantics.
//
//      - No identity:
//              prvalue - a pure rvalue, it is a temporary object like a return value from a function.
//                                               ~~~~~~~~~~~~~~~~
//                                             temporary materialization
//
//                          A prvalue is an expression that represents a pure value (like the literal 42
//                        or the computation 10 + 2). It does not itself denote an object, and therefore:
//
//                                - it has no identity (you cannot take its address)
//                                - it has no storage until (and unless) temporary materialization occurs
//
//                          prvalues include:
//                                - literal values (42, true, 3.14)
//                                - arithmetic expressions (a + b)
//                                - constructor calls (T{...})
//                                - return-by-value from functions
//                           
//                          A prvalue commonly appears on the right-hand side of an assignment
// 
//                        Note: C++17 temporary materialization
//                          A prvalue does not initially create an object. But when an object is required
//                        (e.g., to bind to a reference, initialize a variable, or pass to a function), the 
//                        compiler creates (materializes) a temporary object from the prvalue.


//    What is the purpose of xvalues?
//
//      You can bind an 'rvalue reference' to an xvalue
//
void func(Type&& arg)
//        ~~~~~~
//          arg is rvalue ref (xvalue or prvalue), so it can utilize a 'move semantics'
{
}

// How to obtain an xvalue
//
//   When you declare a variable and it's got a name, it's an lvaue. So you can 
// convert it into an xvalue as:
//
//      - You can obtain an xvalua via the std::move() function
//          - Receinves an object as a paramert, returns us as an xvalue
//          - The xvalue will thereafter benefit from the move semantics
//
//  NOTE: std::move doesnt move any data. It converts an lvalue into an xvalue.
// 
// Using move semantics to avoid copying 

// A good example is 'swap' function:
template<typename T>
void myswap(T& a, T& b)
{
    T tmp( std::move(a) );  // Move a's data to tmp
//         ~~~~~~~~~~~~
//          It cast lvalue_ref a to xvalue reference 
//
//  Equivalent-> T tmp( (xvalue)a );
//
//      As now 'a' is an xvalue, it can call the temp move constructor instead of the copy constructor


    a = std::move(b);      // Move b's data to a
//    ^ ~~~~~~~~~~~~ 
//    |    It cast lvalue_ref b to xvalue reference: Equivalent-> a = (xvalue)b 
//    |
//  As now 'a' is an xvalue, it can call the 'Move assignment operator'
    
    b =std::move(tmp);    // Move tmp's data to b

} // At the end of the function, the temp object does not destroy anything,


int main()
{   
    return 0;
}