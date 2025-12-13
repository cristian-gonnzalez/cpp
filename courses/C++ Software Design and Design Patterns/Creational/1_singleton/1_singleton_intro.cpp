/** Creational patterns - Singleton Pattern | Explanation and Implementation in C++
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>

/*
    Creational design pattern:
        It is concerned with how we create objects

        It is a way to abstract or make sager a way for us to create objects.

    The singleton pattern: 
        It allows/enforces only the creation of 1 instance of an object

*/
 
class Logger
{
    public:
        Logger()
        {
            std::cout << "Logger was created\n";
        }
        ~Logger()
        {
            std::cout << "Logger was destroyed\n";    
        }
        
    private:
};

int main()
{
    // Here we have 4 instance of Logger created
    {
        Logger l1; // Logger was created
        Logger l2; // Logger was created
        Logger l3; // Logger was created
        Logger l4; // Logger was created

    } // Logger was destroyed
      // Logger was destroyed
      // Logger was destroyed
      // Logger was destroyed
    
    
    return 0;
} 