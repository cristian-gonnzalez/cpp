/**
 * This is an example of serialze and deserialize.
 * We migth have to consider:
 *          - issues wof endianness
 *          - reading 'floating-point data' 
 */

#include <iostream>
#include <fstream>

struct GameObject
{
    int i_field;      // 4 bytes
    short sh_field;   // 2 bytes
    bool active;      // 1 byte
                      // -------
                      // 7 bytes -> total of bytes but if we check the size of the GameObject is 8 bytes
    
    // Note: adding this field since the size of the object is align to multiple of 2
    //       Also, you can put an 'interesting value' in padding to make it more meaningfull
    char padding[1];

    // serialize function
    void serialize(std::ostream& os) const {
        // tip´: Use 'sizeof' and the member name, in case you cnhange the type later
        os.write( reinterpret_cast<const char*>(&i_field), sizeof(i_field) );
        os.write( reinterpret_cast<const char*>(&sh_field), sizeof(sh_field) );
        os.write( reinterpret_cast<const char*>(&active), sizeof(active) );
        os.write( padding, sizeof(padding) );    
    }

    // serialize function
    void deserialize(std::istream& is) {
        // tip´: Use 'sizeof' and the member name, in case you cnhange the type later
        is.read( reinterpret_cast<char*>(&i_field), sizeof(i_field) );
        is.read( reinterpret_cast<char*>(&sh_field), sizeof(sh_field) );
        is.read( reinterpret_cast<char*>(&active), sizeof(active) );
        is.read( padding, sizeof(padding) );    
    }

    // Note: you can make this a friend, if you have private member variable/functions that you need to call
    // friend std::ostream& operator<<(std::ostream& os, const GameObject& go );
};

std::ostream& operator<<(std::ostream& os, const GameObject& go )
{
    os << std::boolalpha << go.i_field << " " << go.sh_field << " " << go.active;
    return os;
}

int main()
{
    std::cout << "sizeof GameObject: " << sizeof( GameObject ) << std::endl;

    GameObject go{50,23,1};
    std::cout << "GameObject: " << go << std::endl;

    // start a new scope -- that way our std::ostream will close
    {
        std::ofstream b_file( "data.bin" );
        go.serialize( b_file );
    }

    // reading our binary data and populating an empty game object
    {
        GameObject go2{};
        std::cout << "GameObject: " << go2 << std::endl;
        
        std::ifstream b_file( "data.bin" );
        go2.deserialize( b_file );

        std::cout << "deserialize: " << go2 << std::endl;   
    }

    return 0;
}
