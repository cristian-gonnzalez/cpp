/** Stack pop: Normal Return
 */

#include <iostream>
#include <stdexcept>

/*
Important Extra Difference between normal return and exception:

  - During normal return:
    -- The compiler knows exactly where control goes.

  - During exception:
    -- The runtime must consult exception handling metadata tables.
    -- It dynamically searches for a handler.

  Normal return removes exactly one stack frame
and transfers control to the caller.

  Exception propagation may pop multiple frames automatically while 
searching for a handler — and that process is called stack unwinding.

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

    // normal ending
    // h's local objects are destroyed
    // Control goes back to the caller frame and 
    // execution continues right after the call to h()
    return; 
}


void g()
{
    std::cout << "\t\tStart of g()\n";

    // Local variable of g()
    A a("g::a", 2);

    h();
    // As there was no exeption, the control flow goes back and continue
    // the normal excution

    std::cout << "\t\tEnd of g()\n";
}


void f()
{
    std::cout << "\tStart of f()\n";

    // Local variable of f
    A a("f::a", 1);

    // As there was no exeption, the control flow goes back and continue
    // the normal excution
    g();

    std::cout << "\tEnd of f()\n";
}


int main()
{
    // Call stack
    //      main → f → g → h
    //
    // Now h() does:
    //
    //       return
    // 
    // What happens?
    // 
    // 1. h's frame is popped 
    //      - h's local objects are destroyed
    // 
    // 2. Control goes back to g
    //    Execution continues right after the call to h()
    //
    // Important:
    //      We pop exactly one frame
    //      Control resumes at a well-defined location

    try
    {
        std::cout << "Start of main try\n";
 
        // Local variable
        A a("main::a", 0);

        // As there was no exeption, the control flow goes back and continue
        // the normal execution
        f();

        std::cout << "End of main try\n";
    }
    catch (const std::exception& e)
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
                Destroy h::a
            End of g()
            Destroy g::a
        End of f()
        Destroy f::a
    End of main try
    Destroy main::a
    */

    return 0;
}
