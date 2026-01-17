/** Value catogory
 */

#include <iostream>

/*    
                VALUE CATEGORIES (C++11–C++20)

            (has identity)
       -------------------           
      |   ┌───────────┐   |
      |   │  lvalue   │   |
      |   └───────────┘   |
     -|-------------------|--------------------------------               
    | |    ┌─────────┐    |       ┌───────────────┐        |
    | |    │ xvalue  │    |       │   prvalue     │ rvalue | (temporary)
    | |    └─────────┘    |       │ (no identity) │        |
    | |                   |       └───────────────┘        |
     -|-------------------|--------------------------------    
      |      glvalue      | 
       -------------------        

Note: 
  If an expression has 'identity', then you can take its address.

- Has identiy: 

    * lvalue:
        Has identity (a stable memory location): it is a variable and you can take its address with &.

        int i = 10;
        For ex: &(i)  // i is an lvalue

                                    lvalue  
    * xvalue (expiring value):      ^~~~~~
        Has identity (belongs to an object), so you can take its address with &
      but that object thinks is about to expire so can be reused or moved-from.

        Think of an xvalue as a casting expression: it is simply an expression that refers
      to an existing object but says 'treat this object as movable' to enable move semantics.

        We typically create xvalues by casting an lvalue to an rvalue reference:

            • std::move(x)              // implicitly cast to an xvalue
            • static_cast<T&&>(x)       // explicit cast to an rvalue reference
            • function calls returning T&&   // uncommon, but produce xvalues
        
- No identity:

    * prvalue (pure rvalue)
        Does not point anywhere. You cannot take an address since there is no storage (No identity) 
      It is just a value in an expression. It does not denote any object, and therefore:

        - it has no identity -> it has no address
        - it has no lifetime

        Conceptually, a prvalue does not “live” anywhere. 
        
        It is a literal number (like 42) or computation expression, constructor call (temp object created) 
      or the return by value of a function (temp object created).

    Note: C++17 temporary materialization:
      If a prvalue needs to become an object (e.g., to bind to a reference, pass as function argument, 
    or store somewhere), the compiler creates a temporary object.


  There are also 2 mixed value categories:
      glvalue (generalized lvalue) - It could be a lvalue or a xvalue
      rvalue                       - either xvalue or prvalue
*/

int get42()
{
    return 42;
}

int main()
{       
    //   If I create a variable in memory and I assign something to it, that variable
    // exists in a stable memory location and has an identity.

//      (rvalue) 
//      On the right-hand side of an assigment when 
//    you are creating a new variable
//          ^~ 
    int i = 10;  
//  ^~~~~
// (lvalue)
//   left-hand side of an assingment when   ->  'i' is a stack-allocated variable 
// you are creating a new variable             that lives for this scope
 
    {
        // The number 10 may be embedded directly in machine code (no memory address) 
        // ^
        // 10 = i;  // ❌ 
        // ^~
        // error: lvalue required as left operand of assignment    
        // It needs some location in memory.
    }

    {                       // Has an address
                            //         ~
        int a = 1;          // lvalue: a     rvalue: 1 (prvalue)
        int b = 2;          // lvalue: b     rvalue: 2 (prvalue)
        int c = (a + b);    // lvalue: c     rvalue: a + b   -> We cannot take &(a+b)
        //       ~~~~~ 
        //   The compiler can materialize this expresion in a temporary object to initialize c.
        // But the expression a+b has no identity and it is a prvalue.      
    }
    {
        int array[100];

        int a =1;
        array[10+a];
        //    ~~~~
        //  expresion, Cant take the address. 10+a is a prvalue, we are not storing 10+a in some
        // addresable place in memory.
    }
    
    {
        //get42() = 100;   // Equivalent -> 42 = 100
    //    ~~~~~^~
    //  error: lvalue required as left operand of assignment
    //
    //  The function returns a number, we cannot assign sth to a number
        
    }

    return 0; 
}
 