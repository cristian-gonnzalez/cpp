/** Universal references
 *
 */
#include <iostream>


struct Widget
{
};

Widget makeWidget()
{
    Widget w; 
    return w;
}  

// If you use && on a template type parameter:
//
//      - It's know as a 'universal' reference
//      - Can bind to either an lvalue or rvalue
template<typename T>
void tfunc(T&& arg)
//         ~~~
//     When it is a template function, the && does not mean rvalue reference
{
}


int main()
{   
    //if you pass in an lvalue, args is an 'lvalue reference'
    Widget w;
    tfunc(w);  // Pass an lvalue, so arg is 'Widget&' and it will use copy semantics just like normal lvalues  
   
    /*
    // this will generate this specialization
    template<>
    void tfunc<Widget &>(Widget & arg)
    {
    }
    
    */

    // If you pass in an rvalue, arg is an 'rvalue reference'
    tfunc( makeWidget() );        // Pass an rvalue, so arg is Widget&& and it will use move behaviour
   
    /*
    // this will generate this specialization
    template<>
    void tfunc<Widget>(Widget && arg)
    {
    }
    
    */
    return 0;
}