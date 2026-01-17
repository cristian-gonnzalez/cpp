/** Class data layout (optimizing for size)
 *  
 */
#include <iostream>

/*

Alignment:
Every object type has an alignment requirement, which specifies the byte
boundary on which objects of that type may be allocated.

Use alignof(T) to query the alignment requirement of a type, and reorder
member fields to reduce padding and optimize size.

 Alignment:
   Every object type has an alignment requirement, representing the number of bytes 
between successive addresses at which objects of this type can be allocated.

  Use alignof(T) to query the aligment of a type and re-order member fields to reduce
padding and optmize size

*/
struct GameState                //                          GameState:
{                               //
    bool checkpoint;            // 1 byte         |   bool   |   1 byte + 3 bytes of padding 
    float score;                // 4 bytes        |          |    
    short number_of_players;    // 2 bytes        |          |   
                                //---------       |__________|  
                                // 7 bytes        |  float   |   4 bytes
                                //                |          | 
   // padding and aligment                        |          |
};                              //                |__________| 
                                //                |  short   |   2 bytes + 2 bytes of padding   
                                //                |          |
                                //                |          |
                                //                |__________|
                                //                             -----------------------
                                //                              12 bytes

struct GameStateOptimized
{
    //   We defines the                           GameStateOptimized:   
    // variables from the 
    // largest to the smallest                    |  float   |   4 bytes 
    float score;                // 4 bytes        |          |                       
    short number_of_players;    // 2 bytes        |          |
    bool checkpoint;            // 1 byte         |__________|
                                //---------       |  short   |   2 bytes
                                // 7 bytes        |__________|
                                //                |   bool   |   1 byte + 1 byte of padding 
   // padding and aligment                        |__________|
};                              //                             -----------------------
                                //                               8 bytes


struct UDT
{
    double _double;           // 8 bytes           -> this the largest type ()
    short  _short;            // 2 bytes
    bool   _bool1;            // 1 byte
    bool   _bool2;            // 1 byte
    bool   _bool3;            // 1 byte
                              //---------
                              // 13 bytes

                              // + 3 bytes of padding  
   // padding and aligment
};


int main()
{
    std::cout << "sizeof GameState         : " << sizeof( GameState ) << " bytes\n";          // sizeof GameState         : 12 bytes
    std::cout << "sizeof GameStateOptimized: " << sizeof( GameStateOptimized ) << " bytes\n"; // sizeof GameStateOptimized: 8 bytes

    std::cout << "aligment_of GameState         : " << alignof( GameState ) << std::endl;           // aligment_of GameState         : 4
    std::cout << "aligment_of GameStateOptimized: " << alignof( GameStateOptimized ) << std::endl;  // aligment_of GameStateOptimized: 4
                                       //              ^~~~~~~
                                       //   It returns the size that determinates the aligment
                                       // The value of the aligment is always a power of two.
                                       
    // The aligment is determinated by the largest type we have defined. 

    std::cout << "sizeof UDT     : " << sizeof( UDT ) << " bytes\n";  // sizeof UDT     : 16 bytes
    std::cout << "aligment_of UDT: " << alignof( UDT ) << std::endl;  // aligment_of UDT: 8


   return 0;
}