/** Function pointers
 */

#include <iostream>

//   A pointer store an address. 
//
//   An address could be of:
//
//      - a variable
//      - a function
  
int add(int a, int b)
{
    return a+b;
}

int multiply(int a, int b)
{
    return a*b;
}

int main()
{   
    std::cout << "2 + 2 = " << add(2,2) << std::endl       // 2 + 2 = 4
              << "2 * 3 = " << multiply(2,3) << std::endl; // 2 * 3 = 6

    // Functions has address
    std::cout << "address_of add: " << reinterpret_cast<void*>(add) << std::endl; // address_of add: 0x401176


    //   Instead of explicity calling these functions, we can instead have a pointer
    // to the 'add' and 'multiply' functions and even change what that pointer points
    // to over time.

    //   So, let' say at run-time we want to be able to choose one of these functions 
 
    // Creates a function pointer for functions that have a signature: 
    //
    //      int func(int, int)

//   Between paranthesis ()
//      ^~~~~  
    int (* op)(int, int);   //   I have sth that looks the signature of the 
//  ^~~  ^ ^~ ^~~~~~~~~~    // function 'add' or 'multipy': int func(int, int) 
//   |   |  |    Arguments                  
//   |   |  |     
//   |   | name of the 
//   |   | function pointer
//   |   |
//   |  * symbol indicates a pointer 
//   |  
// return type 

    // As it is a pointer, we have to point to sth
    op = add;

    std::cout << "address_of op: " 
              << reinterpret_cast<void*>(op) << std::endl; // address_of op: 0x401176
    std::cout << "2 + 2 = " << op(2,2) << std::endl;       // 2 + 2 = 4

    {
        std::cout << "1 for add or 2 for multiply: ";
        int n;
        std::cin >> n;

        if( n == 1 )
            op = add;
        else
            op =  multiply;

        std::cout << "2 op 2 = " << op(2,2) << std::endl;
    }

    // Why this is usefull?
    //
    //      It's used as a callback function for button or change behaviours.

    return 0; 
}
 