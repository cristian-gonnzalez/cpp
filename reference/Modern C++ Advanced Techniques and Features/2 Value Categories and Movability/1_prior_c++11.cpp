/** Value categories: Prior to C++11
 */
#include <iostream>

int& f1() // function that return a reference
{
    static int a[5]; // a = [ , , , , ]
                     //      ^
    return a[0];     //    return a reference to this position
}


int f2()
{
    static int a[5]{1,3,5,7,9}; // a = [1,3,5,7,9]
                                //      ^
    return a[0];                //    return a copy of this position
}

int main()
{
    //  Prior to C++11:
    //    lvalues could go on the left hand side and rvlaues could only go on the rigth hand side. 
        
    // lvalue:
    //    An lvalue is a variable that has identity, it has an address and a name. So you can give a value into 
    // that address and it occupies storage. ^~~~~~~~
    //                  ~~~~~~~~~~~~~~~~~~~     |
    //                                          | 
    //          If an expression has 'identity', then you can take its address.
    //
    {
        //  lvalue - has identity, you can assign and take address:

        int i = 21;        // You can put 'i' in the left-hand side of the assigment - 
        i = 42;            // OK - can assign value to 'i' - it's an lvalue
        int* pi = &i;      // OK - can take address of 'i' - it's an lvalue
        
        f1() = 24;         // OK - can assign value to 'f1()' - it's an lvalue  -> Equivalent a[0] = 24;
      //~~~
      // When I call the function, Im going to get back a reference to an absolute slot in memory so the 
      // function return is an lvalue since it return the element 0 of the static array. 
        int* pf1 = &f1();  // OK - can take address of 'f1()' - it's an lvalue
                //  ^~~~
                // f1 returns a reference to a[0] so we can take its address - it's an lvalue
                //
                //   Equivalent ->  int* pf1 = &a[0];
    }
    
    // rvalue
    //   A rvalue is just a number. It doesnt have a location, doesnt have an address so you can't
    // take the address
    //
    {/*
        // rvalue - no identity, you can't assing or address:

    // can't assign value to 21 (because is just a number)
    //  ^~ 
        21 = 42;         // No - cant assign value to 21 - it's an rvalue
        int* p1 = &21;    // No - cant address of 21 - it's an rvalue
    //            ^ You cant take an address because it is just a temporary value, just
    //            like a literal 

        f2() = 42;        // No - cant assign value to 'f2()' - it's a rvalue  - Equivalent -> 1 = 42
      //~~~
      // When I call the function, Im going to get back a number so I cant put on the left hand side of an 
      // assigment. 
         int* pf2 = &f2();  // No - can take address of 'f2()' - it's a rvalue
         //          ~~~
         // It returns a number. Equivalent -> int* pf2 = &1;
     */
    }

    return 0;
}