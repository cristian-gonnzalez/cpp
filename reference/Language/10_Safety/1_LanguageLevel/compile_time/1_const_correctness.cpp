/** C++ Safety part 1 of n - Language Level Safety 
 *  Compile-time
 */

#include <iostream>
#include <vector>
/*
Safety in C++ Programming:

- const (and const correctness): Lenguage Level Features -- compile-time

    - 'const' is a qualifier used to endorces immutability
        * The compiler can help enforce 'const-correctness' at compile-time.

    - As a general rule you can default your variables and member functions with 'const'
        *  Remember, const after the member function effectively trats members (o.e. the 
        'this' pointer as 'const' -- that's how the compiler enforces things at compile-time)
    - As a general rule, casting away const could be a code-smell
    - See more on 'const corresctess'
        * https://isocpp.org/wiki/faq/const-correctness#overview-const


 This is a compiler's tool for enforcing that some value cannot change

*/

struct Type
{
    int _field;

    // (1) const on memeber functions
    decltype( _field ) get_field() const
//  ^~~~~~~                        ~~~~~
//    int                  member-variables are read-only inside 
//                      this function.
    {
        // this.field = 42; // This is illegal
        return _field;
    }
};

// (2) const as input (often use with pass-by-reference)
int sum_elems(const std::vector<long>& input)
{
    long sum{0};
    for(auto i: input)
        sum += i;
    return sum;
}

int main()
{
   // (3) Const variables
   const float PI = 3.141526;
   // PI = -42; // This is illegal

   std::vector<long> v{1,3,5,7,9};
   // No copy made of elements, only accessed as 'const'
   std::cout << sum_elems(v) << std::endl; // 25

   return 0;
}