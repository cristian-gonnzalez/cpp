/** std::unique_ptr : A scoped smart pointer
 */

#include <iostream>
#include <memory> // unique_ptr

/*

  Smart pointers address these issues about owernshi who owns the pointer and helping 
make sure that you can de-allocate or dont have to worry about when you de-allocate 
the memory

std::unique_ptr:

    - We canot share (no copies are allowed)
    - We dont have to delete:
            * Deletes within the scope

*/

class UDT
{
    public:
        UDT()
        {
            std::cout << "UDT created\n";
        }
        ~UDT()
        {
            std::cout << "UDT destroyed\n";
        }
};

int main()
{   
    {
        // The destructor is automatically called when we leave scope
        // This idea of leaving scope and having sth automatically happens is really important
        //
        // ()RAII -Scoped)
        
        // Creating this object in the stack
        UDT u1;  // UDT created

    } // UDT destroyed  
    
    {
        // Creating UDT in the heap
        std::unique_ptr<UDT> up(new UDT); // UDT created

        // We cannot call delete
        // delete up;
        //        ^~
        // error: type 'class std::unique_ptr<UDT>' argument given to 'delete', expected pointer
   

    }  // UDT destroyed 
//  ^
// The unique_ptr release the memory when leaving the scope
// I dont have to worry of calling delete 

    {
        // Create an 'array' in the heap that is pointed to, by one unique ptr
        //std::unique_ptr<UDT[]> array(new UDT[10]); 

        // Equivalent using a factory method
        //std::unique_ptr<UDT[]> array = std::make_unique<UDT[]>(10); 
        std::unique_ptr<UDT[]> array = std::make_unique<UDT[]>(10); 
                                               //              ^
                                               // Number of element  

        // NOTE:
        //  If UDT constructor has argument, you cannot create an array of UDT with unique_ptr
        //  Use std::vector instead:
        //
        //  std::vector< std::unique_ptr<UDT> > array;

    } // The array will be release automatically when it goes out of scop
    
    
    return 0;
}   