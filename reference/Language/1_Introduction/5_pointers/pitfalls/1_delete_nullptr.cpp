/** Pointer pitfalls: Delete a ptr to 'nullptr'
 */

#include <iostream>

cope

int main()
{
    //
    // Delete a ptr to 'nullptr'
    //
    {
        
        // this pointers holds no address
        int* p = nullptr;

        // It is safe to call delete or delete[] on a nullptr. It does nothing.
        // the C++ standard explicitly guarantees this.

        delete p;      // safe
        delete p;      // safe
        delete[] p;    // safe
    }

    //
    // Delete a ptr to NULL or 0 (C-style)
    //
    {
        // this pointers holds no address
        int* p = 0; // or using 'NULL'   C-style

        // The C++ standard explicitly does NOT guarantees this is safe althouh most of the compiler treats as 'do nothing'. 

        delete p;      // safe
        delete p;      // safe
        delete[] p;    // safe
    }

    return 0;
}