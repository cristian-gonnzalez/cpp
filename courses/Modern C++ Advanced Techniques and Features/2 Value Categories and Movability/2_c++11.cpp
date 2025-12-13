/** Value categories: C++11 onwards
 */
#include <iostream>

struct Widget
{
};

// Note: 
//   If an expression has 'identity', then you can take its address.
//
// For ex:
//      const i = 42;
//            ^ this is initialization, not assignment.
//      
//      i = 5; -> ERROR Cannot assign  (Identity does not means you can assign, it measn sth you can take its address)

// The standards commitee wanted to make it more efficient the way that objects get copied around. 
// They wanted to try to avoid unnecsary copying
//
// Since C++11, there are 3 primary value categories
//
//     - Has identity:
//              lvalue  - same as lvalue before -> has identity, it is a variable. it has an address 
//                                                 and lives on (It's going to live for a long long timne)
//              xvalue  - an 'expiring value' -> has identity, it is a variable, it has an address but the
//                                       variable thinks that it's going to be destroyed any moment soon. 
//
//      - No odentity:
//              prvalue - a pure rvalue, same as an rvalue before -> Its just a number like 42
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
//
// There are also 2 mixed value categories:
//      glvalue  - a 'generalized lvalue' (i.e., it has identity). It could be a lvalue or a xvalue
//      rvalue   - an rvalue (i.e, either xvalue or prvalue)
//                                         ^           ^ 
//                                         |           |
//                                         |        just a literal number 
//                                         |
//                                 it could expire at any moment      
//    -------------------
//    |   ___________   |         
//    |  |  lvalue   |  |         
//    |  |___________|  |
// -------------------------------------------------------                 
// |  |   ___________   |          ___________           |
// |  |  |  xvalue   |  |         |  prvalue  |  rvalue  |
// |  |  |___________|  |         |___________|          | -> Type &&
// |  |                 |             ^                  |    ~~~~~~~~
// -----------------------------------|-------------------      rvalue reference
//    |     glvalue     |             |
//    -------------------             |
//            ^                       |
//            |                       | 
//        Has identity            No identity
//
//  The motivation for ths is that we have now the concept of an 'rvalue reference'. An rvalue rference can only
// refer to an rvalue (xvalue -- it's going to expire -- or prvalue -- literal value like the number 42 )
//



// It creates a Widget object and then returns it
//
// - C++ rule:
//     Returning an lvalue creates a prvalue to initialize the function’s return object.
// 
Widget makeWidget()                                                            
{  

    // Nore: NRVO (Named Return Value Optimization)
    //   The Widget constructor is called in the caller’s stack frame (the return 
    // object’s storage) instead of this function's stack frame.
    //
    //   So 'w' acts as an alias inside this function.

    // This line runs, but no local Widget object is created here.
    // The constructor was already called in the caller’s frame.
    Widget w;   // lvalue
    return w;   // prvalue  
    //     ^       
    // 'w' is an lvalue; returned object is initialized as a prvalue. 
    // NRVO eliminates the copy/move, so no second constructor is called.
}




//You will only ever see rvalue reference in functions.
void some_function(Widget&& rvalue)
//                  ~~~~~~~~
//                 rvalue reference
//   The key point is that an rvalue is like a temporary object so it is an object that isnt going to need 
// its data.
//   Note: An rvalue has data but the object is about to die any moment. So if you want to, you can
// basically steal that data yourself (this is where we are going to be heading)
{
}


int main()
{
    // OK to pass rvalue into some_function();
    some_function( makeWidget() );
    //             ~~~~~~~~~~~~
    //                prvalue -> this value will only lives in the statement that is used
    // Note: When you call a function (i.e. makeWidget) and it returns a value. If you dont use that value 
    // imediatelly, then it is discarted. So it is a 'temporary object'.
                       
    // Not OK to pass lvalue into some_function()
    Widget w;
    some_function(w);
    //            ^
    // error: cannot bind rvalue reference of type 'Widget&&' to lvalue of type 'Widget'
    //
    // note: initializing argument 1 of 'void some_function(Widget&&)'
    //                                                      ~~~~~~^^

    // 'w' will continue to live after some_function() is called. So it is not a temporary object


    //   The key point is when you have an rvalue reference, it can only refer to a temporary object (we can steal its data). 
    // It cannot refer to a long-live object.

    return 0;
}