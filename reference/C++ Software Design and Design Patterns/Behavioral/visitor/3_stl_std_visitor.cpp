/** The STL has an implemetation of the Visitor patter using std::visitor (C++20)
 * 
 */

#include <iostream>
#include <string>
#include <variant>

/*
Defined in header <variant>

    template< class Visitor, class... Variants >
    constexpr R visit( Visitor&& v, Variants&&... values );   (1)   (since C++17)


    Applies the visitor v (a Callable that can be called with any combination of types from Variants) 
to the Variants values

    It is a Functional paradigm instead of an object oriented

*/


// Note:  
//    We have two different classes (MovieActor & TvActor) that are not part
//    of the same hierarchy in the same way we had in our visitor pattern example using 
//    Base/Dereived classes in an object-oriented style
//    The way we are going to enforce their relationship is by using a 
//    std::variant (The variant can hold one type or the other. It is either 
//    a MovieActor or a TvActor)
//      

/*
            std::variant<MovieActor, TvActor>
                         |  
                 ________|__________
                |                   |
            MovieActor             TvActor
*/


struct MovieActor
{
    MovieActor() = default;
    MovieActor(std::string name)
    :_name{name}
    {
    }

    std::string _name;
};

struct TvActor
{
    TvActor() = default;
    TvActor(std::string name)
    :_name{name}
    {
    }

    std::string _name;
};

// force the relationship
using Actor = std::variant<MovieActor, TvActor>;


/*
    Now, for the actual behaviour (Visitor) we are going to use functors

*/

// create the function object that acts as 'concrete visitor' 
// that handles the cases for each type in the variant. 
// This is the functionality (behaviour)
struct Sing 
{
    void operator()(const MovieActor& a) const 
    {
        std::cout << "Singing as an Movie actor\n";
    }
    void operator()(const TvActor& a) const 
    {
        std::cout << "Singing as an Tv actor\n";
    }
};

int main()
{
    // creates a variant -- effectively holding one type or the other in a 'tagged union'
    Actor a = MovieActor("Mike");

    // grabs the data that we need based on the type in the variant
    std::visit(Sing{}, a); // Singing as an Movie actor

    Actor b = TvActor("Mike");
    std::visit(Sing{}, b); // Singing as an Tv actor

    return 0;
}