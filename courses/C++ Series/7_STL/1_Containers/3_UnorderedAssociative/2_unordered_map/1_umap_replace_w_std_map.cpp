/** STL std::unordered_map (C++11) | Modern Cpp Series Ep. 129
 */
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

//
// This is the same example we use with std::map.
// We can change to std::unordered_map and all the function will work
//

/*
std::unordered_map:
    It is an associative container that contains key-value pairs with unique keys. 
*/

struct Edge // 'Arista' in spanish
{
    unsigned long v1{999};
            //    ^
            //   vertex
    unsigned long v2{999};
            //    ^
            //   vertex
    
    Edge()
    {
    }
    Edge(unsigned long _v1, unsigned long _v2)
    : v1{_v1},v2{_v2}
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        os << "(" << e.v1 << ", " << e.v2 << ")";
        return os; 
    }
};


int main()
{                     //  Value = Custom data-type
                      //  ~~~~                  
    //std::map<std::string, Edge> mymap;
    std::unordered_map<std::string, Edge> mymap;
    //       ~~~~~~~~~~~
    //        Key    
    
    //
    // Element access
    //

    {
        // operator[]: 
        //      Access or insert specified element
  
        // If the key does not exits, it will create the pair
        mymap["edge1"] = Edge(0,0); 
        
        // Access
        std::cout << mymap["edge1"] << std::endl; // (0, 0)
        
        // Updating 
        mymap["edge1"] = Edge(1,1); 
        std::cout << mymap["edge1"] << std::endl; // (1, 1)

        // As we said, if the key does not exists, the operator[]
        // will create it. 
        // We have to be carefull since this is not the expected
        // behaviour in this line.
        std::cout << mymap["KEY_NO_EXIST"] << std::endl; // (999, 999)
    }   
        
    {
        std::string key{"edge3"};

        // at: 
        //    Access specified element with bounds checking    
        try
        {
            std::cout << mymap.at(key) << std::endl;
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << key << " out_of_range: " << e.what() << '\n';  // edge3 out_of_range: unordered_map::at
        }
    }    
    
    {
        // insert:
        //      Inserts elements or nodes(since C++17)
        // 
        // std::pair<iterator, bool> insert( P&& value );
        //                                   ~ std::pair
        mymap.insert( std::pair{ "edge2", 
                                 Edge(2L, 2L) } );

        std::cout << mymap.at("edge2") << std::endl; // (2, 2)

        // Use a structured binding, to return succesfull and retrieve an
        // iterator to where the element was inserted
        const auto [it, success] = mymap.insert( std::pair{ "edge3", 
                                                       Edge(3L, 2L) } );            
        std::cout << std::boolalpha 
                  << "[ "   << it->first 
                  << " -> " << it->second 
                  << " ] was added: " << success << std::endl;  // [ edge 3 -> (3, 2) ] was added: true
    }

    // contains: (C++20)
    //      Checks if the container contains element with specific key
    if ( mymap.contains("KEY_NO_EXIST") )
    {
        // erase:
        //    erases elements
        mymap.erase("KEY_NO_EXIST");
        std::cout << "'KEY_NO_EXIST' was erased\n"; // 'KEY_NO_EXIST' was erased

    }

    {
        // Classic iteration
        std::cout << "[";
        for(auto it= mymap.begin(); it!=mymap.end(); it++)
            std::cout << it->first << " -> " <<  it->second << ", ";
        std::cout << "]\n"; // [edge3 -> (3, 2), edge2 -> (2, 2), edge1 -> (1, 1), ]

        // Ranged-based loop: 
        std::cout << "[";
        for(const auto& e: mymap)
            std::cout << e.first << " -> " <<  e.second << ", "; 
        std::cout << "]\n"; // [edge3 -> (3, 2), edge2 -> (2, 2), edge1 -> (1, 1), ]

        // Ranged-based loop (structured bindings)
        std::cout << "[";
        for(const auto& [key, value]: mymap)
            std::cout <<key << " -> " << value << ", ";
        std::cout << "]\n"; // [edge3 -> (3, 2), edge2 -> (2, 2), edge1 -> (1, 1), ]

                  
    }

    return 0;    
}