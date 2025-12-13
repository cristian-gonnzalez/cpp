/** Classes: Default constructor and destructor
 */

#include <iostream>
#include <string>


// Note:
//   The compiler stops generating the default constructor if you declare 
// any constructor with parameters that makes the class no longer 
// default-constructible.
//
//   This does no affect the copy semantics and move semantics, these are 
// still generated.
//
//   For ex;
//
//  class T
//  {
//      T( int a );   <-- If I decalred this, the compiler supress the default constructor
//                      So, If I need the default constructor, I have also to declare.
//  };
//


class Student
{
  public:

    // The compiler provides these defulats if no decalred.

    // 1. Default constructor:       (FOCUS ON THIS NOW)
    //      Creates an object and default-initializes all members.
    //
    // Student( )                                  
    //         ^ 
    //       No param

    // 2. Destructor                 (FOCUS ON THIS NOW)
    //      Destroys the object and calls the destructors of its data members.
    //
    // ~Student( )                                  
    //          ^ 
    //       No param                            

    // Student::Student(const Student&)             3. Copy constructor
    // Student& operator=(const Student&);          4. Copy assignment operator

    // Student::Student(Student&&)                  5. Move constructor
    // Student& operator=(Student&&);               6. Move assignment operator 

    // This 6 member functions are also known as 'special member functions'

    // Note:
    //   When C++ generates a 'default constructor', it creates the object and then each 
    // data member is initialized using its own default behavior.
    // 
    //     - Built-in types (int, double, pointers) → not initialized (they contain garbage)
    //     - Class/struct members                   → their own default constructor is called
    //     - Members with {} or =                   → those initializers are used (in-class 
    //                                              initialization)

    //   You can also request the compiler-generated versions explicitly assigning to 
    // 'default' keyword:
    //
    // Student() = default;
    // ~Student() = default;

    void print_name()
    {
        std::cout << _name << std::endl;
    }

  private:
    std::string  _name{};
    //                ^~
    //  uses explicity value-initialization,
};

/*

Custom constructor/destructor:
  We can override those constructor and destructor. 
    
    - You write a custom constructor when you need to:

        * initialize members with non-default values
        * enforce invariants or validation
        * allocate or manage resources (files, memory, handles, etc.)

    - You define a destructor when the class owns resources that must be 
    released, such as:

        * memory allocated with new
        * file handles
        * network sockets
        * mutexes or other OS objects

            class Resource
            {
                public:
                    Resource() : data(new int[10]) {}
                    ~Resource() { delete[] data; }

                private:
                    int* data;
            };

*/

int main()
{
    Student mike;
    return 0;
}

