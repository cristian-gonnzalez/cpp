/** C++ Safety - Language Level Safety
 *  Modern Cpp
 */

#include <iostream>
#include <vector>

struct Point
{
    explicit Point( float value )
    : _x{value}, _y{value}
    {
        std::cout << "Point(float)\n";
    }
    explicit Point( float x, float y )
    : _x{x}, _y{y}
    {
        std::cout << "Point(float, float)\n";
    }    
    explicit Point( const Point& other )
    : _x{other._x}, _y{other._y}
    {
        std::cout << "Point(const Point&)\n";
    }

    float _x, _y;
};


int main()
{

    // Initialization:
    // 
    // 1. Direct initialization
    // 2. Copy initialization (new object) — looks like assignment, but is not assignment
    // 3. Copy List Initialization
   
    {
        // Direct Initialization
        //
        // Syntax:
        //
        // T obj(arg);
        // T obj{arg};
        //
        //      What happens:
        //          - Calls a constructor directly
        //          - No temporary objects
        //          - explicit constructors ARE allowed
        Point p(1.0f);     // direct init

        // Calls:
        //    Point(float)
    }

    {
        // Copy Initialization (new object) LOOKS LIKE ASSIGNMENT, BUT IS NOT
        // 
        // Syntax:
        // 
        // T obj = arg;
        
        {
            // Case A: arg is NOT type T
            
            //Point p = 1.0f;   // ❌ ERROR
            
            //     Standard says:
            //         When initializing a new object, copy-initialization tries to perform
            //     implicit conversion from arg to T.
            // 
            //     When you write: T obj = arg; the compiler pretends (conceptually) 
            // that you wrote: T obj(arg);  (direct-initialization attempt)
            // 
            //     float → Point requires an implicit conversion.
            //     explicit constructors block *implicit* conversions.
            //
            // Therefore:
            //     ✔ No copy_constructor
            //     ✔ No operator=
            //     ✔ No temporary object
            //     ❌ The implicit conversion is forbidden → compilation error.
        
        }
        {
            Point a(1.0f);

            // Case B: arg IS type T
            // IMPORTANT:
            //      The copy constructor is explicit in this class. (It is not common since 
            // the common practice is to mark single argument constructor as implicit)
            //
            //      A copy-initialization like:
            
            // Point b = a;   // ❌ ERROR
            
            //      requires an *implicit* call to the copy constructor.
            // Since the copy constructor is explicit, this is NOT allowed.
            
            // NOTE:
            //      However, direct-initialization does NOT require implicit conversion:
            //
            Point c(a);      // ✔ OK (direct call to explicit copy constructor)
        }
    }

    {   
        
        // 3. Copy List Initialization (new object using = {})
        // 
        // Syntax:
        //  
        // T obj = {arg};
        //
        // Behavior:
        //     - The compiler attempts an *implicit conversion* from {args} to T 
        // (Direct List Initialization).
        //
        //          Point p4{1.0f, 2.0f};
        //
        //     - Since the matching constructor Point( float x, float y ) 
        // is explicit, the conversion is NOT allowed.
        
        //Point p4 = {1.0f, 2.0f};   // ❌ ERROR
        
        //     Why:
        //         {1.0f, 2.0f} → Point(float,float)
        //         This requires implicit conversion into an explicit constructor.
        //         explicit forbids implicit conversion.
        //
        //     What gets called (conceptually):
        //          ➡ would call constructor(float,float)
        //          ❌ but explicit forbids implicit conversion
        //          ❌ no copy constructor
        //          ❌ no operator=

        // Direct initialization is allowed
        Point p4{1.0f, 2.0f};
    }
        
    return 0;
}