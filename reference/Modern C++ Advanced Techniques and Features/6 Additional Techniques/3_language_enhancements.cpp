// -std=c++20 -lpthread

/**  Language enhancements
 *
 */
#include <iostream>
#include <compare>

int return5()
{
    return 5;
}

struct Point
{
    int x, y, z;
};

struct Money
{
    int value;

    Money(int v)
    : value{v}
    {}

    
    // 3-way comparison operator <==> (C++20)
    //
    // Combines ==, !=, <, <=, >, >= into a single operator
    //
    // In traditional C++, if you want to compare an object with another of the same type, you might have overload 
    // the 6 operators (==, !=, <, <=, >, >=)
    //
    // In C++20, rahter than having 6 individual comparison operators, you can define all in once
    std::strong_ordering operator<=>(const Money& other) const
    //~~~~~~~~~~~~~~~~~~
    //    ^
    // there is a new data type called strong_ordering
    //
    // This object will either be negative, 0, or positive  such as strcmp of c library.
    //                              ^       ^       ^
    //                 if the first         |      if the first is bigger
    //                 object is smaller    |
    //                                  both are equal
    {
        return value <=> other.value;
    }

};


struct Point3d
{
    int x{6}, y{-1}, z{5};
};

int main()
{
    // Variables declarations

    // You can declare variables in 'if' and 'swicth'
    std::string s{"Hello word!"};

    if( auto m = s.find("c"); m != std::string::npos  )
    {
        std::cout << "Character found in " << m << std::endl;
    }
    else {
        // value of npos is the largest positive value it can hold
        std::cout << "Character not found: " << m << std::endl; // Character not found: 18446744073709551615 
    }

    switch( auto m = return5(); m + 1 )
    {
        case 6:
        {
            std::cout << "In the summer\n"; // In the summer

            break;
        }
        default: 
        {
            std::cout << "Not in the summer\n";
        }
    }

    // Structured binding
    // 
    // The number of identifiers must match
    //      - The number of elements in an array
    //      - The number of non-static data members in an object

    {
        int array[] = {10,20,30};

        
        auto [a,b,c] = array;  // Copies of an array
        std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl; // a: 10 b: 20 c: 30

        auto &[d,e,f] = array;  // References of each elem of an array
        std::cout << "d: " << d << " e: " << e << " f: " << f << std::endl; // d: 10 e: 20 f: 30

        const auto &[g,h,i] = array;  // Const references of each elem of an array
        std::cout << "g: " << g << " h: " << h << " i: " << i << std::endl; // g: 10 h: 20 i: 30
    }

    {
        Point p{10, 20, 30};

        auto [a,b,c] = p;  // Copies of data members 
        std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl; // a: 10 b: 20 c: 30

        auto &[d,e,f] = p;  // References of each data members
        std::cout << "d: " << d << " e: " << e << " f: " << f << std::endl; // d: 10 e: 20 f: 30

        const auto &[g,h,i] = p;  // Const references of each data members
        std::cout << "g: " << g << " h: " << h << " i: " << i << std::endl; // g: 10 h: 20 i: 30
    }


    // 3-way comparison operator <==> (C++20)

    // Combines ==, !=, <, <=, >, >= into a single operator

    Money m1{100}, m2{200};

    std::strong_ordering result = m1 <=> m2;
    if( result == 0)
    {
        std::cout << "m1 == m2" <<std::endl;
    }
    else if( result > 0) 
    {
        std::cout << "m1 > m2" <<std::endl;
    }
    else 
    {
        std::cout << "m1 < m2" <<std::endl; // m1 < m2
    }

    // Designated iInitializer
    Point3d p1;

    std::cout << "p1: { x: " << p1.x << ", y: " << p1.y << ", z: " << p1.z << " }\n"; // p1: { x: 6, y: -1, z: 5 }

    // we can change the default values
    // Allow you to set fields in an aggregate initialization
    Point3d p2 {
        .x=100,
        .y=200
    };

    std::cout << "p2: { x: " << p2.x << ", y: " << p2.y << ", z: " << p2.z << " }\n"; // p2: { x: 100, y: 200, z: 5 }


    


    return 0;
}