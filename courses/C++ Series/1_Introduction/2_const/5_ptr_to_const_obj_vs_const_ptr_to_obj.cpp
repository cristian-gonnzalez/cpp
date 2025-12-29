/** 'const X* p' vs 'X* const p' vs 'const X* const p'
 */
#include <iostream>

/*
What’s the difference between “const X* p”, “X* const p” and “const X* const p”?

Read the pointer declarations right-to-left.

 - const X* p:
     means “p points to an X that is const”: the X object can’t be changed via p.

    Note: 'X const* p' is equivalent to 'const X* p'.

 - X* const p: 
     means “p is a const pointer to an X that is non-const”: you can’t change the 
  pointer p itself, but you can change the X object via p.

 - const X* const p:
     means “p is a const pointer to an X that is const”: you can’t change the pointer p 
  itself, nor can you change the X object via p.

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
    UDT u;

    {
        // means “p points to an UDT that is const”: the UDT object can’t be changed via p.
        const UDT* p = &u;
    
        std::cout << p->inspect() << std::endl;
    
        // Cannot modify the state of the object
        // error: assignment of member 'UDT::i_' in read-only object
        // p->i_ = 5;
        //~~~~~~^~~

        
        // Cannot call any member function that is non-const
        // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
        //p->mutate();
        //std::cout << p->inspect_non_const() << std::endl;
        //p->do_nothing();

        p = nullptr;
    }
    {
        // means “p is a const pointer to an UDT that is non-const”: you can’t change the 
        // pointer p itself, but you can change the X object via p.

        UDT* const p = &u;
  
        p->i_ = 5;

        std::cout << p->inspect() << std::endl;
        p->mutate();
        std::cout << p->inspect() << std::endl;
        std::cout << p->inspect_non_const() << std::endl;
        p->do_nothing();

        // error: assignment of read-only variable 'p'
        //p = nullptr;
        //~~^~~~~~~~~
    }
    
    {
        // means “p is a const pointer to an UDT that is const”: you can’t change the pointer p 
        // itself, nor can you change the UDT object via p.
        const UDT* const p = &u;
    
        // Cannot modify the state of the object
        // error: assignment of member 'UDT::i_' in read-only object
        // p->i_ = 5;
        //~~~~~~^~~

        // Cannot call any member function that is non-const
        // error: passing 'const UDT' as 'this' argument discards qualifiers [-fpermissive]
        //p->mutate();
        //std::cout << p->inspect_non_const() << std::endl;
        //p->do_nothing();

        // error: assignment of read-only variable 'p'
        //p = nullptr;
        //~~^~~~~~~~~
 
    }

    
    return 0;
}