/** Member variable destruction
 */
#include <iostream>

/* 
  C++ guarantees member destruction happens in the reverse order of declaration.

📜 The rule (guaranteed by the C++ standard)

    For a class object:

        -Construction order
            -- Base classes (in declaration order)
            -- Data members in the order they are declared in the class

        -Destruction order
            -- Data members in reverse declaration order
            -- Base classes (reverse order)

*/
struct A
{
    A()
    { 
        std::cout << "A()\n";
    }

    ~A()
    { 
        std::cout << "~A()\n";
    }
};

struct B
{
    B()
    { 
        std::cout << "B()\n";
    }
    ~B()
    { 
        std::cout << "~B()\n";
    }; 
};


class UDT 
{
    private:
        A a_;
        B b_;
};


int main()
{
    // The order is:
    //      - Construction: a → b
    //      - Destruction: b → a
    // 
    // This is not implementation-defined or compiler-dependent — it is guaranteed.
    {
        UDT udt;                                         // A()
                                                         // B()

        std::cout << "This line is here on purpose\n\n";
    } // ~B()
      // ~A()
    
    std::cout << "This line is here on purpose\n\n";
    return 0;
}