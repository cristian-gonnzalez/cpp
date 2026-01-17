/** Default constructor: copy constructor deletes default constructor
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>


/*
  If user declared copy constructor (either user-provided, deleted or defaulted)
prevents the implicit generation of a default constructor

*/
 
struct A
{
    A& operator=(const A&) {return *this;}
    // A::A() is implicitly defined as deleted
};
 
struct B
{
    B& operator=(const B&) = delete;
    // B::B() is implicitly defined as deleted
};
 
struct C
{
    C& operator=(const C&) = default;
    // C::C() is implicitly defined as deleted
};


struct G
{
    G(const G&) {}
    // G::G() is implicitly defined as deleted
};
 
struct H
{
    H(const H&) = delete;
    // H::H() is implicitly defined as deleted
};
 
struct I
{
    I(const I&) = default;
    // I::I() is implicitly defined as deleted
};
 
int main()
{
    A a;
    A b;
    A c;

//  G g; // compile error
//  H h; // compile error
//  I i; // compile error
}