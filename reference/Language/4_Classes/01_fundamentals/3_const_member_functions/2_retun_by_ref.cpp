/** Return-by-reference in a const member function
 */
#include <iostream>
/*
  If you want to return a member of your this object by reference from an inspector method, 
you should return it using reference-to-const (const X& inspect() const) or by value (X 
inspect() const).

  The good news is that the compiler will often catch you if you get this wrong. In particular, 
if you accidentally return a member of your this object by non-const reference, such as in 
Person::name_evil() above, the compiler will often detect it and give you a compile-time error w
hile compiling the innards of, in this case, Person::name_evil().

  The bad news is that the compiler won’t always catch you: there are some cases where the 
compiler simply won’t ever give you a compile-time error message.

  Remember the “const philosophy” spread throughout this section: a const member function must 
not change (or allow a caller to change) the this object’s logical state (AKA abstract state 
AKA meaningwise state). Think of what an object means, not how it is internally implemented. 
A Person’s age and name are logically part of the Person, but the Person’s neighbor and employer 
are not. An inspector method that returns part of the this object’s logical / abstract / 
meaningwise state must not return a non-const pointer (or reference) to that part, independent 
of whether that part is internally implemented as a direct data-member physically embedded within 
the this object or some other way.
*/


class Person 
{
    public:
        
        // Right: the caller can't change the Person's name
        const std::string& name_good() const  
        {
            return name_;
        }

    // Wrong: the caller can change the Person's name
    //             ^
        std::string& name_evil() const        
        //                       ^~~~~
        //             This is a promise to not modify the state  
        {
            // error: binding reference of type 'std::string&' to 'const std::string' discards qualifiers
            //     ^~~~~
            return name_;
        }

        
    //  No problem here since we are returning a copy
    //  ^~
        int age() const // Also right: the caller can't change the Person's age   
        {
            return age_;
        }

    private:
        std::string name_{"Mario"};
        int age_{0};
};

int main()
{
    const Person p;
    // The bad news is that the compiler won’t always catch you: there are some cases 
    // where the compiler simply won’t ever give you a compile-time error message.
    p.name_evil() = "Igor";     // But myCode() changed it anyway!!
 
    return 0;
}