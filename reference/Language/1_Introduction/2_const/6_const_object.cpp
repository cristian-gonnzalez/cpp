/** const object
 */
#include <iostream>

/*
const X x; 


What does “const X& x” mean?

  It means x aliases an X object, but you can’t change that X object via x.

  Read it right-to-left: “x is a reference to an X that is const.”

  For example, if class X has a const member function such as inspect() const, it is okay 
to say x.inspect(). But if class X has a non-const member function called mutate(), it is 
an error if you say x.mutate().

  This is entirely symmetric with pointers to const, including the fact that the compiler 
does all the checking at compile-time, which means const doesn’t slow down your program and 
doesn’t require you to write extra test-cases to check things at runtime.

Note:
    'X const& x' is equivalent to 'const X& x'
*/
struct UDT
{
    int inspect() const
    //            ^~~~~
    //         This is a promise to not modify the object state
    {
        return i_;
    }

    int inspect_non_const() // non-const method
    {                       
        return i_;         
    }
    void do_nothing()       //   Even though these ( inspect_non_const() and do_nothing() )  
    {                       // do not modify the object state, the compiler does not analyze the body. 
    }                       // So this meansthat these methods cannot be called wiht const

    void mutate()
    {
        i_ = (i_ + 1) * 2;
    }

    int i_{0};
};


int main()
{
    UDT u1;
    u1.i_ = 5;

    std::cout << u1.inspect() << std::endl;
    u1.mutate();
    std::cout << u1.inspect() << std::endl;
    std::cout << u1.inspect_non_const() << std::endl;
    u1.do_nothing();

    {
        // ref is a reference to an UDT that is const. Cannot modify u1 via ref
        const UDT& ref = u1;

        // error: assignment of member 'UDT::i_' in read-only object
        //ref.i_ = 5;
        //~~~~~~~^~

        std::cout << ref.inspect() << std::endl;
        // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
        //ref.mutate();
        //~~~~~~~~~^~
        
        // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
        //std::cout << ref.inspect_non_const() << std::endl;
        //ref.do_nothing();

        // error: binding reference of type 'UDT&' to 'const UDT' discards qualifiers
        //UDT& non_const_ref = ref;
        //         ^~
    }

    {
        const UDT u2;

        std::cout << u2.inspect() << std::endl;
        
        // error: assignment of member 'UDT::i_' in read-only object
        //u2.i_ = 5;
        //~~~~~~^~

        // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
        //u2.mutate();
        //~~~~~~~~~^~
        
        // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
        //std::cout << u2.inspect_non_const() << std::endl;
        //u2.do_nothing();

        // error: binding reference of type 'UDT&' to 'const UDT' discards qualifiers
        //UDT& non_const_ref = u2;
        //         ^~
    }
 
    return 0;
}