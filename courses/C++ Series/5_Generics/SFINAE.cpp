/** SFINAE "Substitution Failure Is Not An Error" | Modern Cpp Series Ep 215
 */
#include <iostream>


// SFINAE Substitution Failure Is Not An Error
//
//  This means that the compiler is trying to take care of you when you are using templates
//
// When substituting the explicitly specified or deduced type for the template parameter fails, 
// the specialization is discarded from the overload set instead of causing a compile error.
//
// This means that there are rules for templates sustitution
//

struct IRobot
{
};

struct WalkRobot : IRobot
{
    static const char WALKABLE{};
    void walk()
    {
        std::cout << "Robot is walking\n";
    }
};

struct FlyRobot : IRobot
{
    static const char FLY{};
    void fly()
    {
        std::cout << "Robot is flying\n";
    }
};

template<class T>
void do_sth( T& r, decltype(T::WALKABLE)* = nullptr )
{
    std::cout << "Walkable version called\n";
    r.walk();
}



template<class T>
void do_sth( T& r, decltype(T::FLY)* = nullptr )
{
    std::cout << "Fly version called\n";
    r.fly();
}

/* CPPInsights

template<>
void do_sth<WalkRobot>(WalkRobot & r, const char *)
{
  std::operator<<(std::cout, "Walkable version called\n");
  r.walk();
}

template<>
void do_sth<FlyRobot>(FlyRobot & r, const char *)
{
  std::operator<<(std::cout, "Fly version called\n");
  r.fly();
}

*/

int main() 
{
    WalkRobot w;
    do_sth(w);  // Walkable version called
                // Robot is walking

    FlyRobot f;
    do_sth(f);   // Fly version called
                 // Robot is flying



    return 0;
}
