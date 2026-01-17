/** Classes: Basic concetps
 */

#include <iostream>
#include <string>

/*
Primitives types:
        int, char, float also knows as built-in types in the languate

Classes
  A class is a user-defined type.

    - Information hidding: public/protected/private
    - Ability to crete intances of objects and think in objects 
    in our software (OOP)


  A class is a way for a user to create a concrete type. We often think of it as a 
'blueprint', and create 'instances objects' from that blueprint. Classes consist of
attributes (member variables) and actions (member functions) that utilize the class 
blueprint

*/

// Defines a user-defined type
class Student
// ^
// By default, the access specifier is private
{
  // Access specifiers: information hidding
  //    public: 
  //    protected:
  //    private:
  
  public:
    // Constructor
    // Automatically called when an object is created (initialization)
    Student()
    {
        std::cout << "Student created\n";
    };  
    // Destructor
    // Automatically called when an object is destroyed
    ~Student()
    {
        std::cout << "Student destroyed\n";
    };  

    // member functions / methods
    void print_name() const;


    // member functions / methods
    void set_name(std::string m_name)
    //                        ^~ Adding prefix to demostrate use of 'this' keyword
    {
        this->m_name = m_name;
    //  ^~~~
    // Pointer to the current instance of the object

    }


  // Hidden 'fields' or 'attributes'
  private:
    // members variables
    std::string  m_name{};
              // ^~
              // By convention, the member variable has the prefix 'm_'
              // Or just '_' (underscore)  or the suffix '_' (underscore)
              //
              // _name
              // name_ 
};

void Student::print_name() const
//          ^^
//   scope resolution operator '::'
//     It tells me that this method is part of Student
// 
{

    std::cout << m_name << std::endl;
}

int main()
{
    {
        // Creating a new object (an instance of 'student')
        //       ^
        Student mike;  // Student created
        //  ^
        // data-type

    } // Student destroyed

    {
        Student* student = new Student; // Student created

        // Explicity calling to de-allocate
        delete student; // Student destroyed
    }
    
    return 0;
}

