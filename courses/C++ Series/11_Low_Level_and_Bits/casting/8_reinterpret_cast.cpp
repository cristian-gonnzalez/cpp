/** C++ Casting: reinterpret_cast
 */
#include <iostream>
#include <cstring>  // std::memcpy

/*
  reinterpret_cast is the most dangerous C++ cast.

  It performs a low-level reinterpretation of the bit pattern of an object
as another type, without any semantic or safety checks.

  Key properties:
    - No runtime checks
    - No compile-time guarantees of correctness
    - Often results in undefined behavior if misused
    - Primarily intended for low-level, platform-specific code
      (e.g., OS kernels, drivers, serialization, memory-mapped I/O)

  reinterpret_cast does NOT convert values — it reinterprets bits.

*/

struct GameState
{ 
    int  level;                // 4 bytes
    int  health;               // 4 bytes
    int  points;               // 4 bytes
    bool game_complete;        // 1 byte
    bool boss_defeated;        // 1 byte
                               // 2 bytes of padding
};


int main()
{
    {
        float pi{3.14f};

        //   C-style casts are dangerous because they can perform a combination of:
        //     - const_cast
        //     - static_cast
        //     - reinterpret_cast
        //   depending on context, with unclear intent.
        //
        //   In this case, the cast behaves like a static_cast<float -> int>
        std::cout << (int)pi << std::endl;                        // 3    

        // reinterpret_cast:
        //   Treats the memory occupied by 'pi' as if it were an int.
        //   This does NOT convert 3.14 to an int.
        //   It simply interprets the raw IEEE-754 bit pattern as an integer.
        //
        // ⚠️ WARNING:
        //   This violates strict aliasing rules and results in undefined behavior.
        //   It may appear to work on some platforms, but it is not portable or safe.
        std::cout << *reinterpret_cast<int*>(&pi) << std::endl;   // 1078523331
        
        // Reinterpreting the same memory back as float
        // This happens to work because the original object really is a float.
        std::cout << *reinterpret_cast<float*>(&pi) << std::endl; // 3.14

        // In conclusion, this is not the purpose of reinterpret_cast
    }
    

    // The key idea is to make 1 read from disk to get all our data instead of
    //
    //  ifstream ifs("data.bin");
    //
    //  ifs >> gs.level;
    //  ifs >> gs.health;
    //  .....

    std::cout << "size_of GameState: " 
              << sizeof(GameState) << " bytes\n"; // size_of GameState: 16 bytes

    using byte = unsigned char;
    
    byte buffer[sizeof(GameState)];

    // Simulate reading raw bytes from disk or network
    {
        GameState gs = { 66, 100, 999, false, true };
        std::memcpy( buffer, &gs, sizeof(GameState) );
    }

    // At this point, we just know we have a collection of bytes

    // time to read
    std::cout << *reinterpret_cast<int*>(buffer + 0) << std::endl       // 66
              << *reinterpret_cast<int*>(buffer + 4) << std::endl       // 100 
              << *reinterpret_cast<int*>(buffer + 8) << std::endl       // 999
              << *reinterpret_cast<bool*>(buffer + 12) << std::endl     // 0
              << *reinterpret_cast<bool*>(buffer + 13) << std::endl;    // 1

    // time to store and use data 
    GameState gs( *reinterpret_cast<GameState*>(buffer) );
    std::cout << gs.level << std::endl             // 66
              << gs.health << std::endl            // 100 
              << gs.points << std::endl            // 999
              << gs.game_complete << std::endl     // 0
              << gs.boss_defeated << std::endl;    // 1


    return 0;
}