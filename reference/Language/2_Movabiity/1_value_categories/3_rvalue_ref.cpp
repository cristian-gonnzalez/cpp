/** rvalue references
 */

#include <iostream>

void set_value_to_99(int& change_me)
{
    change_me = 99;
}

int main()
{   
   // int& rvref = 10;
   //              ^~
   // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
   
   int&& rvref = 10;
//    ^^
// Using double & we indicates that it is an rvalue reference
//
//  This allows us to take this temporary value created from the rvalue and actuablly store it 
// here
   
    std::cout << rvref << std::endl; // 10


    // The motivation for this came from:

    int a = 1;
    int b = 2;
    int c = a+b;
    //      ~~~~
    // we are creating some temporary storage or instruction to store the result a+b
    // and then we are copying this value into c

    // We dont want to just copying things and evaluating these results and generating them so
    // instead it might be more efficient for us to just move (transfer) sth that's already been
    // created

    std::string s1 = "mike ";
    std::string s2 = "a really long str";
    std::string s3 = s1 + s2;
                 //  ~~~~~~~
                 //  temp std::string
                 //
                 //   It evaluate the expresion, then it creates a temporary storage to store the 
                 // concatination of s1 and s2 and then copy to s3 with the copy constructor
                 //
                 //   If I have already done the work of creating this so whay not just move those
                 // values
                 //
                 // Note: C++17 (copy elision) 
                 //   The compiler construct the returned object directly in the caller's storage.
                 //   This is because the operator+ returns an lvalue and the compiler use NRVO.
                 //
                 //   So in this case: The string inside operator+ is not constructed as a separate 
                 // temporary. Instead, (s1 + s2) is constructed directly in its final location s3 
                 // calling s3 constructor once.
                 //
                 //   So no extra object exists: no other constructor is called
                 //
                 // Therefore:
                 //   No copy, No move, No temporary string destructor.
                 //


    
    // What happens with:
    
    std::string&& s4 = s1 + s2;  // You are forcing the expression to refer to a temporary, so the compiler must materialize one.

    // 1. s1 + s2 produces a prvalue
    // 
    //   This prvalue is not an object yet — it is just the result of an expression.
    // 
    // 2. Binding a prvalue to an rvalue reference requires temporary materialization
    // 
    //   C++ creates a temporary object because the reference must refer to an actual object.
    // 
    // 3. That temporary object lives to the end of the full expression where s4 is declared
    // 
    //   So:
    //     * A temporary std::string object is created
    //     * Its lifetime is extended to the lifetime of the reference s4
    //     * No copies or moves are involved (C++17 prvalue rules)
    //     * s4 becomes an alias to that temporary object

    //    
    // In this case:
    //
    //   std::string s3 = s1 + s2;
    //
    // There is no temporary at all. Guaranteed copy-elision constructs s3 directly

   return 0; 
}
 