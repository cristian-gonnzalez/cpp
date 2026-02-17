/** noexcept specifier
 */
 
#include <iostream>
#include <stdexcept>
#include <utility>

/* 
  noexcept specifies that a function does not throw exceptions. 
  
  It is a contract: If an exception escapes a function declared noexcept,
std::terminate() is called immediately.

  No further stack unwinding occurs beyond that boundary.
 
  Syntax:
 
       void f() noexcept;
       void g() noexcept(true);
       void h() noexcept(false);   // equivalent to no specification
 
Important Rule:
  If an exception exits a function declared noexcept, std::terminate() is 
called immediately.
 
  Stack unwinding does NOT continue past the noexcept boundary.
*/


void safe_function() noexcept
{
    std::cout << "safe_function() executed\n";
    // No exception thrown → OK
}

void dangerous_function() noexcept
//                        ^~~~~~~~
//                  This means that the exception cannot propagate.
//               Otherwise, std::terminate() will be called immediately and
//               program ends 
{
    std::cout << "dangerous_function() about to throw\n";
    throw std::runtime_error("Error inside noexcept function");
//  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// warning: 'throw' will always call 'terminate' [-Wterminate]
}


int main()
{
    safe_function();   // safe_function() executed
 
    // Uncommenting this will terminate the program:
 //   dangerous_function();
    // Because it is marked noexcept and it throws
    // so std::terminate() is called immediately

    return 0;
}

/*
IMPORTANT:
    1. noexcept means:
            "This function promises not to throw."

    2. If an exception escapes a noexcept function:
            → std::terminate() is called immediately.

    3. Destructors are implicitly noexcept(true) by default.
            If a destructor throws during stack unwinding: → std::terminate() is called.

    4. Move constructors should usually be noexcept.
            This enables better performance in STL containers.

    5. noexcept is part of the function type.
            It affects overload resolution and template behavior.

    6. noexcept is NOT checked at compile-time.
            It is a runtime guarantee.
            Violating it results in termination, not a compiler error.

Best Practice:
    - Mark move constructors noexcept.
    - Mark functions noexcept when they truly cannot throw.
    - Never allow exceptions to escape destructors.
*/
