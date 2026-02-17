/** Stack Unwinding
 */
#include <iostream>
#include <stdexcept>

/*
see: https://cppreference.com/w/cpp/language/exceptions.html

Stack Unwinding:
    Stack unwinding is the process that happens when an exception
is thrown and propagates up the call stack.

    When a 'throw' expression is evaluated:

        1) Execution of the current function stops immediately.
        2) Local (automatic) objects are destroyed.
        3) After destruction of local automatic objects,
           the current stack frame is removed.
        4) The runtime searches for a matching catch handler.
        5) If not found, the next stack frame is destroyed.
        6) This continues until:
               - A matching handler is found, or
               - No handler is found → std::terminate() is called.

    This multi-frame destruction process is called stack unwinding.

Important:
    Stack unwinding is NOT the same as a normal return.

Normal return:
    - Pops exactly one stack frame.
    - Execution continues after the function call.

Exception propagation:
    - May pop multiple stack frames.
    - Skips normal execution flow.
    - Transfers control directly to a matching catch block.

    During unwinding, destructors of all automatic objects
are called in reverse order of construction.
*/


struct A
{
    const char* name;
    const int level{0};

    A(const char* n, int l) 
    : name(n), level(l)
    {
        for(size_t i=0; i<level; ++i)
            std::cout << "\t";
        std::cout << "Construct " << name << std::endl;
    }

    ~A()
    {
        // Important:
        //   If a destructor throws during stack unwinding,
        // std::terminate() is immediately called.
        // 
        //   For this reason, destructors should not throw exceptions.
        for(size_t i=0; i<level; ++i)
            std::cout << "\t";
        std::cout << "Destroy " << name << std::endl;
    }
};


void h()
{
    std::cout << "\t\t\tStart of h()\n";

    // Local variable of h()
    A a("h::a", 3);

    //   h throws an exception
    // 
    //   Execution stops immediately and the runtime begins 
    // searching for a matching catch.
    //
    //   As there is not matching catch in this function,
    // the stack frame is removed and goes back to the caller
    // frame
    std::cout << "\n\t\t\t-> exception\n\n";
    throw std::runtime_error("error in h()");

    // NOTE:
    //   If an exception escapes a function declared 'noexcept',
    // std::terminate() is called immediately.
    //
    //   No further stack unwinding occurs beyond that boundary.


    // Execution never reaches here.
}


void g()
{
    std::cout << "\t\tStart of g()\n";

    // Local variable of g()
    A a("g::a", 2);

    //   As there was not matching catch in h, the runtime searches for 
    // a matching catch here.
    //
    //   But there is not catch matching in this function, so
    // the stack frame is removed and goes back to the caller
    // frame
    h();

    // This line is skipped if h() throws.
    std::cout << "\t\tEnd of g()\n";
}


void f()
{
    std::cout << "\tStart of f()\n";

    // Local variable of f
    A a("f::a", 1);

    //   As there was not matching catch in g(), the runtime searches for 
    // a matching catch here.
    //
    //   But there is not catch matching in this function so
    // the stack frame is removed and goes back to the caller
    // frame
    g();

    // This line is skipped if h() throws.
    std::cout << "\tEnd of f()\n";
}


int main()
{
    // Call stack
    //      main → f → g → h
    //
    // Now h() does:
    //
    //       throw std::runtime_error("error in h()")
    // 
    // What happens?
    // 
    // 1. h stops immediately
    //      - h's locals are destroyed
    //      - h frame is popped
    // 
    // 2. Runtime checks: does g have a matching catch?
    //    If not:
    //      - g's locals are destroyed
    //      - g frame is popped
    //
    // 3. Runtime checks: does f have a matching catch?
    //    If not:
    //      Continue...
    // 
    // This may remove multiple frames.
    // That multi-frame removal process is stack unwinding.

    try
    {
        std::cout << "Start of main try\n";
 
        // Local variable
        A a("main::a", 0);

        // If no matching handler is found in f(),
        // the exception continues propagating to main().
        f();

        // This line is skipped if f() throws.
        std::cout << "End of main try\n";
    }
    catch (const std::exception& e)
    //           ^~~~~~~~~~~~~~
    //            matching cath found
    {
        std::cout << "Caught: " << e.what() << '\n';
    }

/*
    Start of main try
    Construct main::a
        Start of f()
        Construct f::a
            Start of g()
            Construct g::a
                Start of h()
                Construct h::a

                -> exception

                Destroy h::a
            Destroy g::a
        Destroy f::a
    Destroy main::a
    Caught: error in h()
*/

    return 0;
}
