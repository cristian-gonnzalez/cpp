/* Nullability:

nullptr and nullptr_t

You should use nullptr to represent a null pointer rather than using NULL or 0;

The NULL is not part of the specification of the c++ language but in most of the compiler they defined as 0

*/

#include <iostream>



int main()
{
    const char* p1 = nullptr;

    if(p1)
        std::cout << "OK - conversion from nullptr to bool\n";

    //int i = nullptr; 
    //        ~~~~~~~
    //     Error -  no conversion from nullptr to int 
    //
    // The type of nullptr is std::nullptr_t

    {
        int* p1 = nullptr;
        int* p2 = NULL;
        int* p3 = 0;

        if( p1 == p2 &&
            p1 == p3 )
            std::cout << "Traditional uses of 0 and NULL are still allowed\n"; // Traditional uses of 0 and NULL are still allowed
    }
    
    return 0;
}