/** C++ Casting: static_cast and dynamic_cast
 */
#include <iostream>

/*
  In C++, the different casts describe what your intnet is. They provide more 
'type-safety' than C-style casts by making conversions explicit and restricted.

        - static_cast
        - dynamic_cast
        - const_cast
        - reinterpret_cast

- C-style cast in C++:
    
      (T)expr         A C-style cast attempts, in order:
        
                          const_cast -> static_cast -> static_cast + const_cast 
                          -> reinterpret_cast -> reinterpret_cast + const_cast
                             ^~~~~~~~~~~~~~~~
                          It is basically treat these bits exactly 
                        as Im telling to.
  
  Because it may fall back to reinterpret_cast, a C-style cast can silently perform 
dangerous conversions.


- static_cast:
    static_cast tries to figure out at compile-time if we are able to perform the cast.

    Used for well-defined, related conversions.

    Typical uses:
        - Numeric conversions
        - Converting between related class types (upcasting)
        - Explicitly documenting narrowing or intent

    Example:
      static_cast try to determinate if I can treat this Dreived as Base at compile-time.
    Also we can try if we can treat Base as Derived

                    Base
                     ^
                     |
                   Derived

            Base* b = static_cast<Base*>(derived_ptr);   // safe upcast

      Downcasting with static_cast:
            Derived* d = static_cast<Derived*>(base_ptr);

      This compiles, but is only safe if the object is actually Derived.
    The compiler does NOT verify this.

- dynamic_cast:
    It is similar to static_cast in a sense that the goal is to treat one data type as another
  but this works only with pointers and references. 

    It safely converts pointers and references to classes up, down, and sideways along the 
  inheritance hierarchy (downcasting and cross-casting).

    The word safely means that dynamic_cast will attempt at run-time to do the conversion and
  if it fails then it will return a null pointer or throws std::bad_cast. This gives us the 
  posibility to check

        - Pointer cast: returns nullptr on failure
        - Reference cast: throws std::bad_cast

    Example:

        if (Derived* d = dynamic_cast<Derived*>(base_ptr))
        {
            // cast succeeded
        }

    Note: RTTI (Runtime Type Information)
      dynamic_cast relies on RTTI to figure out is this a valid conversion.

      RTTI is the information (vtable) to perform the dynamic_cast. This means that
    requires polymorphic types (at least one virtual function)


            static_cast               dynamic_cast
   ---------------------------------------------------------
   Compile-time checked        | Runtime checked
   No runtime overhead         | Runtime cost
   Faster                      | Safer for downcasting
   Can be dangerous            | Requires polymorphism
                               | Pointers & references only                             

Final note:
  Avoid casting where possible: if you are trying to change types, maybe it is in fact some
sort of code-smell
  
  Prefer dynamic_cast if you must, so you can check at run-time the safety of the cast...unless 
of course you really need performance (since dynamic_cast needs to carry extra information with
your classes -- RTTI ). Then try to use static_cast    

Core Guidelines:
  - See https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es49-if-you-must-use-a-cast-use-a-named-cast
  - See https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c146-use-dynamic_cast-where-class-hierarchy-navigation-is-unavoidable

*/

int main()
{
    int i = (int)3.14f; 
    //             ^~  
    //       Get rid off after the decimals: 3.XX  

     return 0;
}