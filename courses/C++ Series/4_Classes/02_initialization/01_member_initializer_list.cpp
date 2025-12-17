/** Classes: Member initializer list
 */

#include <iostream>

/*
Member-initializer list:

  Syntax:

    Class::Class()
    : memberA(args), memberB(args), ...
    { }

  This performs 'direct initialization' of members variables: variables  are 'constructed directly'. 
                                                                              ^~~~~~~~~~~~~~~~~~~~   
                                                                                ^
                                             The object is created and initialized in 'one single step' 
                                           using the constructor you specify.

  Note:
    Only non-static data members can be initialized this way.

  Advantages of using the member-initializer list:
        - Avoids redundant default-construction + assignment
        - Required for const members
        - Required for references
        - Required for members without a default constructor
        - More efficient for complex types (std::string, std::vector, etc.)
*/

class U1
{
  public:                       
    U1()                                                  
    : _x(1.f), _y(2.f), _z(3.f)  // member-initializer list
    {         
        
        // _x = 0.f;
        //    ^
        // Redundant work: 2 or more steps
        //   1. _x is default-initialized (x contains garbage)
        //   2. Then you assign _x = 0.f
                   
    }

    friend std::ostream& operator<<( std::ostream& os, const U1& rhs );

  private:
    float _x,             //   Members are always initialized in declaration order,
          _y,             // regardless of the order in the member-initializer list.
          _z;             //
                          //   Declared order: _x → _y → _z 
                          //
                          //   Note:
                          //     The declaration order of variables is how the compiler will 
                          //  stored in memory. 
                      
};                 

class U2
{
  public:                       
    U2()                                                  
    : _z(3.f), _y(_z), _x(1.f) 
//             ^~      
//   The order of the member-initializer list does NOT matter
// since initialization always follows the 'declaration order'.
//
//   1. _x
//   2. _y
//   3. _z
//
//   So: _y(_z) uses the MEMBER _z BEFORE it is initialized → garbage.
//
//   The compiler may warn if the list order differs.
    {         
    }

    friend std::ostream& operator<<( std::ostream& os, const U2& rhs );

  private:
    float _x, _y, _z;
};

std::ostream& operator<<( std::ostream& os, const U1& rhs )
{
    os << "("<< rhs._x << ", " << rhs._y << ", " << rhs._z << ")"; 
    return os;
}

std::ostream& operator<<( std::ostream& os, const U2& rhs )
{
    os << "("<< rhs._x << ", " << rhs._y << ", " << rhs._z << ")"; 
    return os;
}

int main()
{
    U1 u1;
    
    std::cout << u1 << std::endl; // (1, 2, 3)
    
    U2 u2;
    std::cout << u2 << std::endl; // (1, 4.59120, 3)
                                  //     ~~~~~~~
                                  //     garbage


    return 0;
}

