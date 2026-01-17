/** std::unique_ptr : A scoped smart pointer
 */

#include <iostream>
#include <memory> // unique_ptr

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
    // I cannot share a unique_ptr
    {

        std::unique_ptr<UDT> u1(new UDT);

        //         |    |
        //         |____|
        //           UDT
        //           ^ 
        //           |
        //         | * |
        //         |___|
        //          u1
       

        // I cannot copy an unique_ptr since the copy semantics is deleted
        // std::unique_ptr<UDT> u2 = u1;
        //                         ^
        //  error: unique_ptr(const unique_ptr&) = delete;


        // We are allow to 'move' a unique_ptr: transfer owernship from u1 to u2
        std::unique_ptr<UDT> u2 = std::move(u1);
                           //               ^
                           // u1 is nullptr after transfered owernship to u2       

        //         |    |
        //         |____|
        //           UDT  <-
        //                  |
        //                  |
        //      | null |  | * | 
        //      |______|  |___| 
        //          u1     u2
    }
    
    return 0;
}   