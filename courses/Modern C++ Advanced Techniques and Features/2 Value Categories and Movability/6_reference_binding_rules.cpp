/** Reference binding rules 
 *
 *      If you have a function that takes an lvalue reference as parameter, 
 + what kind of variable can you pass in?
 *
 *          - lvalue references
 *          - const lvalue references
 *          - rvalue references
 *          - const rvalue references
 *
 */
#include <iostream>

struct Widget
{

};

// The return of a function is a rvalue
// ^
Widget makeWidget()
{
    Widget w; 
    return w;
}   


// Lvalue reference rules
//
//  If you declare an lvalue reference as parameter
//      - It can bind to an lvalue (and change it)
//      - It cannot bind to an rvalue (changes would be lost)
void f_pass_by_lvalue_ref(Widget &w)
//                        ~~~~~~~~~  lvalue reference
{
    // Do something with the lvalue such as update or change it since its not a 'const' variable
}

// Const lvalue reference rules
//
//  If you declare a const lvalue reference as parameter
//      - It can bind to an lvalue
//      - It can bind to an rvalue (because it won't change the value)
//
//
void f_pass_by_const_lvalue_ref(const Widget &w)
//                              ~~~~~~~~~~~~  
//               const lvalue reference -> It is going to refer to an object but not change it
{
}


// Rvalue reference rules
//
//  If you declare a rvalue reference as parameter
//      - It cannot bind to an lvalue (because it vacates the object)
//      - It can bind to an rvalue
//
// NOTE: The only reason you would declare a function that takes an rvalue reference is because you are going
// to steal its data inside the function. 
void f_pass_by_rvalue_ref(Widget &&w)
//                        ~~~~~~~~~~~~  rvalue reference
{
}


// Const rvalue reference rules
//
//  You will probably never declare a const rvalue reference as parameter
//      - Rvalue references typically need to vacate the object.
//      - So, they can´t be const.
//
// IMPORTANT: This makes no sence since the idea of rvalue reference is to steal the data of the object
void f_pass_by_const_rvalue_ref(const Widget &&w)
//                               ~~~~~~~~~~~~  const rvalue reference
{
}

int main()
{

    // Creates an lvalue
    Widget w;   

    // Lvalue reference rules
    {   
        f_pass_by_lvalue_ref(w);                  // OK - can bind to an lvalue

        // The compiler does not let you pass a temporary object (rvalue) into a lvalue reference since 
        // the function would change the object and then those changes would be lost as soon as the 
        // object is discarded. 
        
        //f_pass_by_lvalue_ref( makeWidget() );   // Error - cant bind to an rvalue
        //                      ~~~~~~~~~~^~
        // error: cannot bind non-const lvalue reference of type 'Widget&' to an rvalue of type 'Widget'
        //     
        // Note:
        //    
        //    f_pass_by_lvalue_ref( makeWidget() );
        //                          ~~~~~~~~~~~~  ^ 
        //                             ^        That temporary object is going to
        //                             |       die as soon as we get to the end of
        //                             |       the statement 
        //              It returns a temporary object          
    }
 
     // Const lvalue reference rules
    {   
        f_pass_by_const_lvalue_ref(w);                // OK - can bind to an lvalue

        // This works because the function takes a const reference that is not going to change the object
        //
        // Te compiler knows that you are not going to steal the data of the other object, so
        // it is allowed. Maybe the functions wants to display it
        f_pass_by_const_lvalue_ref( makeWidget() );   // OK - can bind to an rvalue 
        //                          ~~~~~~~~~~~~  ^ 
        //                             ^        That temporary object is going to
        //                             |       die as soon as we get to the end of
        //                             |       the statement 
        //              It returns a temporary object 
    }

    // Rvalue reference rules
    {   
        // The only reason you would declare a function with a rvalue reference is because you are going 
        // to steal its data

        // You are not allowed to pass an lvalue to that function because the lvalue is going to live on and 
        // it is going to need its data later. So you cant just steal it
        // f_pass_by_rvalue_ref(w);                // Error - cannot bind to an lvalue
        //                      ^
        // error: cannot bind rvalue reference of type 'Widget&&' to lvalue of type 'Widget'
        
        // This works because the function takes a const reference that is not going to change the object
        f_pass_by_rvalue_ref( makeWidget() );   // OK - can bind to an rvalue 
        //                   ~~~~~~~~~~~~  ^ 
        //                      ^          That temporary object is going to die as soon as we get to the end of the statement
        //                      |
        //   It returns a temporary object 
    }   
    return 0;
}