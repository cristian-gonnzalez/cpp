/** const X* p  — pointer to const object
 */
#include <iostream>

/*
What does “const X* p” mean?

  It means p points to an object of class X, but p can’t be used to change that X object 
(naturally p could also be NULL).
  
  For example, if class X has a const member function such as inspect() const, it is okay 
to say p->inspect(). But if class X has a non-const member function called mutate(), it is 
an error if you say p->mutate().

  Significantly, this error is caught by the compiler at compile-time — no run-time tests 
are done. That means const doesn’t slow down your program and doesn’t require you to write 
extra test-cases to check things at runtime — the compiler does the work at compile-time.
*/

struct UDT
{
    int inspect() const
    //            ^~~~~
    //         This is a promise to not modify the object state
    {
        return i_;
    }

    int inspect_non_const()
    {
        return i_;
    }
    void do_nothing() // Even though this does not modify the object state
    {                 // The compiler does not analyze the body. So this means
    }                 // that this method cannot be called wiht const

    void mutate()
    {
        i_ = (i_ + 1) * 2;
    }

    int i_{0};
};


int main()
{
    UDT u1;

    UDT* p2 = &u1;  // pointer to mutable object 

    p2->i_ = 5;
    std::cout << p2->inspect() << std::endl;
    p2->mutate();
    std::cout << p2->inspect() << std::endl;
    

    // Read it right-to-left: “p is a pointer to an UDT that is constant.”
    const UDT* p = &u1;   // pointer to const object
    //         ^
    //  p cannot be used to change the object

    {
        
        // error: assignment of member 'UDT::i_' in read-only object
        //p->i_ = 5;
        //~~~~~~^~~
    }

    {
        std::cout << p->inspect() << std::endl;
        //              ^~~~~~~
        //    inspect() promises not to modify the object

        // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
        //p->mutate();
        //~~~~~~~~~^~
    
    
        // Cannot call a non_const funtion even though the dunction does not modify the object
        // state
        // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
        //std::cout << p->inspect_non_const() << std::endl;
        //             ~~~~~~~~~~~~~~~~~~~~^~
    
        // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
        //p->do_nothing();
        //~~~~~~~~~~~~~^~

        // Note: 
        //   Const correctness is about interface contracts, not implementation guesses:
        // Even if a function does not modify state, it must still be declared const to 
        // be callable. The compiler does NOT analyze function bodies.
        
    }

    p = nullptr;

  return 0;
}